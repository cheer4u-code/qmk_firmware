// Copyright 2024 cheer4u (@cheer4u-code)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "matrix.h"
#include "wait.h"
//#include "debug.h"
//#include "uart.h"

#include "button.h"

static matrix_row_t matrix[MATRIX_ROWS];

__attribute__((weak)) void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__((weak)) void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}

inline bool matrix_is_on(uint8_t row, uint8_t col) {
    return (matrix[row] & ((matrix_row_t)1 << col));
}

matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

void matrix_print(void) {

}

void matrix_init(void) {
    for (uint8_t i=0; i < MATRIX_ROWS; i++) matrix[i] = 0x00;
    matrix_init_kb();
}

uint8_t matrix_scan(void) {
    bool changed = false;

    uint8_t row = 0;
    uint8_t col = 0;

    bool bootsel = get_bootsel_button();
    if (bootsel) {
        if (!matrix_is_on(row, col)) {
            matrix[row] |= (1 << col);
            changed = true;
        }
    } else {
        if (matrix_is_on(row, col)) {
            matrix[row] &= ~(1 << col);
            changed = true;
        }
    }
    matrix_scan_kb();
    //wait_ms(30);

    return changed;
}
