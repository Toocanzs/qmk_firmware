#include "quantum.h"
#include "matrix.h"
#include <stdint.h>
#include "debounce.h"
#include <print.h>

//make toocanzs/optical:default:flash --jobs 16
static matrix_row_t cooked_matrix[MATRIX_ROWS];

void matrix_init(void) {
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

uint8_t matrix_scan(void) {
    bool matrix_has_changed = false;

    matrix_scan_quantum();

    return matrix_has_changed;
}

__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}
