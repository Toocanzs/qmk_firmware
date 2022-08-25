#include "quantum.h"
#include "matrix.h"
#include <stdint.h>
#include <print.h>

// make toocanzs/optical:default:flash --jobs 16
// make toocanzs/optical:default --jobs 16
static matrix_row_t cooked_matrix[MATRIX_ROWS];
//static matrix_row_t matrix[MATRIX_ROWS];

void matrix_init(void) {
    setPinInput(B0);
    setPinInput(B1);
    setPinInput(B2);
    setPinInput(B3);
    setPinInput(B4);
    setPinInput(B5);
    setPinInput(B6);
    setPinInput(B7);
    setPinInput(B8);
    setPinInput(B9);
    setPinInput(B10);
    setPinInput(B11);
    matrix_init_quantum();
}
// Assuming 72 Mhz each nop is ~13.89ns
// SN74HCS251 has a transition time of about 30ns or so
// so 3 nops should do it
#define NOP() __asm__ volatile("nop")
inline void matrix_io_delay(void) {
    NOP();
    NOP();
    NOP();
}

matrix_row_t matrix_get_row(uint8_t row) {
    return 0;//matrix[row];
}

void matrix_print(void)
{
    print("\nMATRIX:\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        print_hex8(row); print(": ");
        print_bin_reverse8(matrix_get_row(row));
        print("\n");
    }
}

// BSRR includes 16 bits for reset and 16 bits for set
// If both reset and set bits are set then the reset is ignored
// We can use this to not touch any other ports by always reseting the ones we use (PA0, PA1, PA2) and then
// we set the bits we want to set
// So setting PA0 = 1, PA1 = 0, PA2 = 1 is just GPIOA->BSRR = BSRR_TEMPLATE | 0b101
uint32_t BSRR_TEMPLATE = 0b111 << 16; 

// For whatever reason something like `GPIOA->BSRR = 5;` gives an error `incompatible types when assigning to type 'volatile union <anonymous>' from type 'int'`
// and changing it to a uint32_t does not help.
// So I guess we'll just get the pointer ourselves? I don't understand this one
// Now you have to do `*GPIOA_BSRR = 5;`
volatile uint32_t * const GPIOA_BSRR = (volatile uint32_t * const) &(GPIOA->BSRR);
//volatile uint32_t * const GPIOB_IDR  = (volatile uint32_t * const) &(GPIOB->IDR); // TODO: REMOVE

uint8_t matrix_scan(void) {
    bool matrix_has_changed = false;

    for (uint32_t multiplexer_index = 0; multiplexer_index < 8; multiplexer_index++) {
        
        *GPIOA_BSRR = BSRR_TEMPLATE | ( (uint32_t) multiplexer_index); // Write the address to the multiplexers
        matrix_io_delay(); // Wait for propagation
        uint16_t multiplexer_results = (GPIOB->IDR) & 0b111111111111; // Read 12 multiplexers
        matrix_has_changed |= multiplexer_results != cooked_matrix[multiplexer_index];
        cooked_matrix[multiplexer_index] = multiplexer_results;
    }
    
    matrix_scan_quantum();

    if (matrix_has_changed) {
        print("\nMATRIX:\n");  // TODO: REMOVE
    }

    return matrix_has_changed;
}

__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}
