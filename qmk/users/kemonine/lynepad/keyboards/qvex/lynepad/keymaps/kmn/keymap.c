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

// Tap Dance declarations
enum tap_dances {
    TD_LAYER_BOOT,
    TAP_DANCE_ACTIONS_COUNT /* Utility to get TD_xxx count */
};

void dance_layer_boot_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // no-op
    } else {
        rgblight_disable_noeeprom();
        reset_keyboard();
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[TAP_DANCE_ACTIONS_COUNT] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LAYER_BOOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layer_boot_finished, NULL),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * |----------------------------|
   * | 1 | 2  | 3  | 4 |          |
   * | 5 | 6  | 7  | 8 |          |
   * | 9 | 10 | 11 |              |
   * |----------------------------|
   */
    [0] = LAYOUT(
        LCTL(KC_Z), KC_NO, KC_NO,      LCTL(KC_Y),
        LCTL(KC_C), KC_NO, LCTL(KC_E), LCTL(KC_F),
        LCTL(KC_Z), TD(TD_LAYER_BOOT), LCTL(KC_Y)
    )
};

// Customized HSV values for layer highlights
#define HSV_KMN_PURPLE 191, 255, 120

// Layer color init
void keyboard_post_init_user(void) {
    layer_clear();
    layer_on(0);
    rgblight_enable();
    rgblight_sethsv_noeeprom(HSV_KMN_PURPLE);
}

// Standard encoder functionality
bool  encoder_update_user(uint8_t index, bool clockwise) {
    // Process encoder rotational movements
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(MS_WHLU);
        } else {
            tap_code(MS_WHLD);
        }
    }
    return false;
}

// Encoder press / tilt event handling
// the core lynepad implementation will update the below variables on each matrix scan
// Update the various codes below for customizing the tilt / push config

extern int16_t enc1Center;
extern int16_t enc1CenterPrev;
extern int16_t enc2Center;
extern int16_t enc2CenterPrev;
extern int16_t enc2Up;
extern int16_t enc2UpPrev;
extern int16_t enc2Down;
extern int16_t enc2DownPrev;
extern int16_t enc2Left;
extern int16_t enc2LeftPrev;
extern int16_t enc2Right;
extern int16_t enc2RightPrev;

void matrix_scan_user(void) {
    if (enc1Center != enc1CenterPrev) {
    }
    if (enc2Center != enc2CenterPrev) {
        /*
         * Encoder sets ALL values when center is pressed so bail out at this point\
         * to avoid the rest of the encoder buttons registering events
         */
        return;
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
            register_code16(KC_RIGHT);
        }
        else {
            unregister_code16(KC_RIGHT);
        }
    }
}
