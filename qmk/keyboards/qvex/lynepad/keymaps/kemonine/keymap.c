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

enum {
    ACCEL_0 = 0,
    ACCEL_1 = 1,
    ACCEL_2 = 2,
};
static uint8_t acceleration_level = ACCEL_0;

void change_accel(void) {
    acceleration_level++;
    if (acceleration_level > ACCEL_2) {
        acceleration_level = ACCEL_0;
    }
}

// Custom key codes
enum {
    ACCEL = SAFE_RANGE,
};

// Tap Dance declarations
enum {
    TD_LAYER_BOOT,
};

void dance_layer_boot_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_on(1);
    } else {
        rgblight_disable_noeeprom();
        reset_keyboard();
    }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
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
    [0] = LAYOUT_Lynepad(
        LCTL(LALT(KC_TAB)),  KC_MS_BTN2,  KC_MS_UP,    KC_MS_BTN1,
        LGUI(KC_DOWN),       KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,
        ACCEL, TD(TD_LAYER_BOOT), KC_ESC
    ),
    [1] = LAYOUT_Lynepad(
        LCTL(LALT(KC_2)),  LCTL(KC_BSPACE),  LSFT(KC_X),  LSFT(KC_P),
        LSFT(KC_TAB),   KC_G,             KC_E,        KC_C,
        TO(0), TO(1), TO(2)
    ),
    [2] = LAYOUT_Lynepad(
        LCTL(LALT(KC_1)),  LCTL(KC_LBRACKET),  LCTL(KC_RBRACKET),  KC_W,
        LSFT(KC_TAB),      KC_Q,               LCTL(LALT(KC_R)),   KC_R,
        TO(0), TO(1), TO(2)
    )
};

// Customized HSV values for layer highlights
#define HSV_KMN_PURPLE 191, 255, 120
#define HSV_KMN_GREEN 85, 255, 120
#define HSV_KMN_YELLOW 43, 255, 120

const rgblight_segment_t PROGMEM led_underglow_purple[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_KMN_PURPLE}
);

const rgblight_segment_t PROGMEM led_underglow_green[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_KMN_GREEN}
);

const rgblight_segment_t PROGMEM led_underglow_yellow[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_KMN_YELLOW}
);

// Array of layers for management
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    led_underglow_purple,
    led_underglow_green,
    led_underglow_yellow
);

// Layer color init
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    layer_clear();
    layer_on(0);
    rgblight_enable();
    rgblight_sethsv_noeeprom(HSV_KMN_PURPLE);
}

// Adjust layers based on which is active
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ACCEL:
      if (record->event.pressed) {
        switch(acceleration_level) {
            case ACCEL_0:
                register_code16(KC_ACL0);
                break;
            case ACCEL_1:
                register_code16(KC_ACL1);
                break;
            case ACCEL_2:
                register_code16(KC_ACL2);
                break;
        }
      } else {
        switch(acceleration_level) {
            case ACCEL_0:
                unregister_code16(KC_ACL0);
                break;
            case ACCEL_1:
                unregister_code16(KC_ACL1);
                break;
            case ACCEL_2:
                unregister_code16(KC_ACL2);
                break;
        }
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

// Standard encoder functionality
void encoder_update_user(uint8_t index, bool clockwise) {
    // Process encoder rotational movements
    if (index == 0) { /* First encoder */
        if (clockwise) {
            if (layer_state_is(0)) {
                tap_code(KC_MS_WH_UP);
            }
            else if (layer_state_is(1)) {
                tap_code(KC_LBRACKET);
            }
            else if (layer_state_is(2)) {
                register_code16(KC_LCTRL);
                register_code16(KC_MINUS);
                unregister_code16(KC_MINUS);
                unregister_code16(KC_LCTRL);
            }
        } else {
            if (layer_state_is(0)) {
                tap_code(KC_MS_WH_DOWN);
            }
            else if (layer_state_is(1)) {
                tap_code(KC_RBRACKET);
            }
            else if (layer_state_is(2)) {
                register_code16(KC_LCTRL);
                register_code16(KC_EQUAL);
                unregister_code16(KC_EQUAL);
                unregister_code16(KC_LCTRL);
            }
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            if (layer_state_is(0)) {
                tap_code(KC_AUDIO_VOL_DOWN);
            }
            else if (layer_state_is(1)) {
                register_code16(KC_LCTRL);
                register_code16(KC_MINUS);
                unregister_code16(KC_MINUS);
                unregister_code16(KC_LCTRL);
            }
            else if (layer_state_is(2)) {
                register_code16(KC_LSFT);
                register_code16(KC_UP);
                unregister_code16(KC_UP);
                unregister_code16(KC_LSFT);
            }
        } else {
            if (layer_state_is(0)) {
                tap_code(KC_AUDIO_VOL_UP);
            }
            else if (layer_state_is(1)) {
                register_code16(KC_LCTRL);
                register_code16(KC_EQUAL);
                unregister_code16(KC_EQUAL);
                unregister_code16(KC_LCTRL);
            }
            else if (layer_state_is(2)) {
                register_code16(KC_LSFT);
                register_code16(KC_DOWN);
                unregister_code16(KC_DOWN);
                unregister_code16(KC_LSFT);
            }
        }
    }
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
        if (enc1Center < ENC_TILT_THRESHOLD) {
            if (layer_state_is(0)) {
                change_accel();
            }
        }
    }
    if (enc2Center != enc2CenterPrev) {
        if (enc2Center < ENC_TILT_THRESHOLD) {
        }
        else {
        }
        /*
         * Encoder sets ALL values when center is pressed so bail out at this point\
         * to avoid the rest of the encoder buttons registering events
         */
        return;
    }
    if (enc2Up != enc2UpPrev) {
        if (enc2Up < ENC_TILT_THRESHOLD) {
            if (layer_state_is(0)) {
                register_code16(KC_MS_WH_UP);
            }
            else if (layer_state_is(1)) {
                register_code16(KC_UP);
            }
        }
        else {
            if (layer_state_is(0)) {
                unregister_code16(KC_MS_WH_UP);
            }
            else if (layer_state_is(1)) {
                unregister_code16(KC_UP);
            }
        }
    }
    if (enc2Down != enc2DownPrev) {
        if (enc2Down < ENC_TILT_THRESHOLD) {
            if (layer_state_is(0)) {
                register_code16(KC_MS_WH_DOWN);
            }
            else if (layer_state_is(1)) {
                register_code16(KC_DOWN);
            }
        }
        else {
            if (layer_state_is(0)) {
                unregister_code16(KC_MS_WH_DOWN);
            }
            else if (layer_state_is(1)) {
                unregister_code16(KC_DOWN);
            }
        }
    }
    if (enc2Left != enc2LeftPrev) {
        if (enc2Left < ENC_TILT_THRESHOLD) {
            if (layer_state_is(0)) {
                register_code16(KC_MS_WH_LEFT);
            }
            else if (layer_state_is(1) || layer_state_is(2)) {
                register_code16(KC_LEFT);
            }
        }
        else {
            if (layer_state_is(0)) {
                unregister_code16(KC_MS_WH_LEFT);
            }
            else if (layer_state_is(1) || layer_state_is(2)) {
                unregister_code16(KC_LEFT);
            }
        }
    }
    if (enc2Right != enc2RightPrev) {
        if (enc2Right < ENC_TILT_THRESHOLD) {
            if (layer_state_is(0)) {
                register_code16(KC_MS_WH_RIGHT);
            }
            else if (layer_state_is(1) || layer_state_is(2)) {
                register_code16(KC_RIGHT);
            }
        }
        else {
            if (layer_state_is(0)) {
                unregister_code16(KC_MS_WH_RIGHT);
            }
            else if (layer_state_is(1) || layer_state_is(2)) {
                unregister_code16(KC_RIGHT);
            }
        }
    }
}
