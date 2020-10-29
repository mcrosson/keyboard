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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * |----------------------------|
   * | 1 | 2  | 3  | 4 |          |
   * | 5 | 6  | 7  | 8 |          |
   * | 9 | 10 | 11 |              |
   * |----------------------------|
   */
[0] = LAYOUT(
  KC_NO, KC_MS_BTN2, KC_MS_UP,   KC_MS_BTN1,
  KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,
  KC_NO, KC_NO,      KC_NO
  )
};

// Standard encoder functionality
void encoder_update_user(uint8_t index, bool clockwise) {
    // Process encoder rotational movements
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_MS_WH_RIGHT);
        } else {
            tap_code(KC_MS_WH_LEFT);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
}

// Encoder press / tilt event handling
// the core lynepad implementation will trigger a matrix event if a push/tilt 
//     happens on the encoders so we can process it in the standard areas for handling key codes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (enc1Center != enc1CenterPrev) {
        if (enc1Center < ENC_TILT_THRESHOLD) {
            register_code16(RESET);
        }
        else {
            unregister_code16(RESET);
        }
    }
    if (enc2Center != enc2CenterPrev) {
        if (enc2Center < ENC_TILT_THRESHOLD) {
            register_code16(KC_MS_BTN3);
        }
        else {
            unregister_code16(KC_MS_BTN3);
        }
    }
    if (enc2Up != enc2UpPrev) {
        if (enc2Up < ENC_TILT_THRESHOLD) {
            register_code16(KC_UP);
        }
        else {
            unregister_code16(KC_UP);
        }
    }
    if (enc2Down != enc2DownPrev) {
        if (enc2Down < ENC_TILT_THRESHOLD) {
            register_code16(KC_DOWN);
        }
        else {
            unregister_code16(KC_DOWN);
        }
    }
    if (enc2Left != enc2LeftPrev) {
        if (enc2Left < ENC_TILT_THRESHOLD) {
            register_code16(KC_LEFT);
        }
        else {
            unregister_code16(KC_LEFT);
        }
    }
    if (enc2Right != enc2RightPrev) {
        if (enc2Right < ENC_TILT_THRESHOLD) {
            register_code16(KC_DOWN);
        }
        else {
            unregister_code16(KC_DOWN);
        }
    }

    // Ensure standard handling happens as we're ignoring the keycode/record values passed
    return true;
}
