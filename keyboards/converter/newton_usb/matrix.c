// Copyright 2023 cheer4u (@cheer4u-code)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "matrix.h"
#include "debug.h"
#include "uart.h"

void matrix_init_custom(void) {
    uart_init(9600);
}

uint8_t matrix_scan_custom(matrix_row_t current_matrix[]) {
    if (!uart_available()) return false;
    uint8_t code = uart_read();

    debug_hex(code);
    debug(" ");

    uint8_t row = (code >> 3) & 0xF;
    // row 0x8-0xE are unused.
    // to reduce memory, change row 0xF to 0x8.
    if (row & 0x08) {
        row = 0x08;
    }
    uint8_t col = code & 0x07;
    bool changed = false;
    if (code & 0x80) {
        // Make scancode because key was pressed
        if (!matrix_is_on(row, col)) {
            current_matrix[row] |= (1 << col);
            changed = true;
        }
    } else {
        // Break scancode because key is released
        if (matrix_is_on(row, col)) {
            current_matrix[row] &= ~(1 << col);
            changed = true;
        }
    }

    return changed;
}
