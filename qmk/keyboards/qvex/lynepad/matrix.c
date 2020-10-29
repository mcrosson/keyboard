/* Copyright 2020 KemoNine
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "analog.h"

int16_t enc1Center = 0;
int16_t enc1CenterPrev = 0;
int16_t enc2Center = 0;
int16_t enc2CenterPrev = 0;
int16_t enc2Up = 0;
int16_t enc2UpPrev = 0;
int16_t enc2Down = 0;
int16_t enc2DownPrev = 0;
int16_t enc2Left = 0;
int16_t enc2LeftPrev = 0;
int16_t enc2Right = 0;
int16_t enc2RightPrev = 0;

void matrix_init_custom(void) {
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;

    enc1CenterPrev = enc1Center;
    enc1Center = analogReadPin(PIN_TW_SW);
    if (enc1CenterPrev != enc1Center) {
        matrix_has_changed = true;
    }

    enc2CenterPrev = enc2Center;
    enc2Center = analogReadPin(PIN_RJ_SW);
    if (enc2CenterPrev != enc2Center) {
        matrix_has_changed = true;
    }

    enc2UpPrev = enc2Up;
    enc2Up = analogReadPin(PIN_RJ_DIR_A);
    if (enc2UpPrev != enc2Up) {
        matrix_has_changed = true;
    }

    enc2DownPrev = enc2Down;
    enc2Down = analogReadPin(PIN_RJ_DIR_C);
    if (enc2DownPrev != enc2Down) {
        matrix_has_changed = true;
    }

    enc2LeftPrev = enc2Left;
    enc2Left = analogReadPin(PIN_RJ_DIR_B);
    if (enc2LeftPrev != enc2Left) {
        matrix_has_changed = true;
    }

    enc2RightPrev = enc2Right;
    enc2Right = analogReadPin(PIN_RJ_DIR_D);
    if (enc2RightPrev != enc2Right) {
        matrix_has_changed = true;
    }

    return matrix_has_changed;
}
