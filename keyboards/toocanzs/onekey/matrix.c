#include "quantum.h"
#include "matrix.h"
#include <stdint.h>
#include "debounce.h"
#include <print.h>
#include "analog.h"

//make toocanzs/onekey/blackpill_f411:default --jobs 16

//static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
//static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

//static matrix_row_t raw_matrix[MATRIX_ROWS];
static matrix_row_t cooked_matrix[MATRIX_ROWS];

void matrix_init(void) {

    /*for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        setPinInput(row_pins[i]);
    }

    for (uint8_t i = 0; i < MATRIX_COLS; i++) {
        setPinOutput(col_pins[i]);
        writePinLow(col_pins[i]);
    }
    */

    debounce_init(MATRIX_ROWS);


    // Turn on board LED
    setPinOutput(C13);
    writePinHigh(C13);
    matrix_init_quantum();
}
// Assuming 96 Mhz each nop is 0.010416666666667 us which means 96 nops = 1us
#define NOP() __asm__ volatile("nop")
#define NOP10() NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
#define NOP1us() NOP10();NOP10();NOP10();NOP10();NOP10();NOP10();NOP10();NOP10();NOP10();NOP();NOP();NOP();NOP();NOP();NOP(); // 96 nops
#define NOP5us() NOP1us();NOP1us();NOP1us();NOP1us();NOP1us();
void matrix_io_delay(void) {
    NOP1us();
    NOP1us();
    NOP1us();
}

matrix_row_t matrix_get_row(uint8_t row) {
    return cooked_matrix[row];
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

inline uint16_t read_port_b(void) {
    return GPIOB->IDR;
}

#define CHANGE_ROW_BIT(matrix_row, bit_number, x) matrix_row = (matrix_row & ~(MATRIX_ROW_SHIFTER << (bit_number))) | ((x) << (bit_number));

uint8_t matrix_scan(void) {
    bool matrix_has_changed = false;
    /*
    for (uint8_t column_index = 0; column_index < MATRIX_COLS; column_index++) {
        writePinHigh(col_pins[column_index]);
        matrix_io_delay();
        for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
            matrix_row_t last_row_value    = raw_matrix[row_index];
            matrix_row_t current_row_value = last_row_value;

            uint8_t on_off_bit = readPin(row_pins[row_index]) ? 0 : 1; // NOTE: We treat low as pressed, high as unpressed
            CHANGE_ROW_BIT(current_row_value, column_index, on_off_bit);
            
            matrix_has_changed |= last_row_value != current_row_value;
            raw_matrix[row_index] = current_row_value;
        }
        writePinLow(col_pins[column_index]);
    }

    debounce(raw_matrix, cooked_matrix, MATRIX_ROWS, matrix_has_changed);
*/

    setPinInputLow(B0);
    static bool last_value = false;
    bool pin_value = readPin(B0);

    static int blah = 0;
    if (last_value != pin_value) {
        int16_t port_b = read_port_b();
        if (pin_value) {
            printf("%d: 1   ", blah++);
            print_bin_reverse8((unsigned int) port_b);
            print("\n");
        }
        else {
            printf("%d: 0   ", blah++);
            print_bin_reverse8((unsigned int) port_b);
            print("\n");
        }
            
        last_value = pin_value;
    }
    

    matrix_scan_quantum();

    return matrix_has_changed;
}

__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}
