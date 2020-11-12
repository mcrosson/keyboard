/* Copyright 2020 Jay Greco
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
#include "remote_kb.h"
#include "bitc_led.h"

enum custom_keycodes {
  PROG = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base layer (numpad)
  [0] = LAYOUT(
                      TO(1),         PROG,           KC_NO, \
  LCTL(LALT(KC_TAB)), LGUI(KC_DOWN), KC_NO,          KC_AUDIO_VOL_UP, \
  KC_MS_BTN1,         KC_MS_UP,      KC_MS_BTN2,     KC_AUDIO_VOL_DOWN, \
  KC_MS_LEFT,         KC_MS_DOWN,    KC_MS_RIGHT,    KC_MS_BTN3, \
  KC_NO,              KC_MS_WH_LEFT, KC_MS_WH_RIGHT, KC_ESC  \
  ),

  // Function layer (numpad)
  [1] = LAYOUT(
             TO(0),   PROG,      KC_KP_SLASH,
    KC_KP_7, KC_KP_8, KC_KP_9,   KC_KP_ASTERISK,
    KC_KP_4, KC_KP_5, KC_KP_6,   KC_KP_MINUS,
    KC_KP_1, KC_KP_2, KC_KP_3,   KC_KP_PLUS,
    KC_NO,   KC_KP_0, KC_KP_DOT, KC_KP_ENTER
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_record_remote_kb(keycode, record);

  switch(keycode) {
    case PROG:
      if (record->event.pressed) {
        set_bitc_LED(LED_ON);
        rgblight_disable_noeeprom();
        bootloader_jump(); //jump to bootloader
      }
    break;

    default:
    break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    if (layer_state_is(0)) {
      tap_code(KC_MS_WH_UP);
    }
    else if (layer_state_is(1)) {
      tap_code(KC_AUDIO_VOL_UP);
    }
  } else {
    if (layer_state_is(0)) {
      tap_code(KC_MS_WH_DOWN);
    }
    else if (layer_state_is(1)) {
      tap_code(KC_AUDIO_VOL_DOWN);
    }
  }  
}

void led_set_kb(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_NUM_LOCK))
    set_bitc_LED(LED_ON);
  else
    set_bitc_LED(LED_DIM);
}

// Customized HSV values for layer highlights
#define HSV_KMN_PURPLE 191, 255, 120
#define HSV_KMN_GREEN 85, 255, 120

const rgblight_segment_t PROGMEM led_underglow_purple[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_KMN_PURPLE}
);

const rgblight_segment_t PROGMEM led_underglow_green[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_KMN_GREEN}
);

// Array of layers for management
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    led_underglow_purple,
    led_underglow_green
);

// Layer color init
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    layer_clear();
    layer_on(0);
    rgblight_sethsv_noeeprom(HSV_KMN_PURPLE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        register_code(KC_NLCK);
        rgblight_set_layer_state(1, layer_state_cmp(state, 1));
        break;
    default: //  for any other layers, or the default layer
        unregister_code(KC_NLCK);
        rgblight_set_layer_state(0, layer_state_cmp(state, 0));
        break;
    }
  return state;
}
