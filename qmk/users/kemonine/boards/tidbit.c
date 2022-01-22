#include QMK_KEYBOARD_H

#ifdef KEYBOARD_tidbit

/**** Override Defalt keymap completely *****/
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

#define _BASE 0
#define _FUNC 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
           TO(_FUNC), KC_NO,     KC_KP_SLASH, 
  KC_KP_7, KC_KP_8,   KC_KP_9,   KC_KP_ASTERISK, 
  KC_KP_4, KC_KP_5,   KC_KP_6,   KC_KP_MINUS, 
  KC_KP_1, KC_KP_2,   KC_KP_3,   KC_KP_PLUS, 
  KC_NO,   KC_KP_0,   KC_KP_DOT, KC_KP_ENTER  
  ),

  [_FUNC] = LAYOUT(
             TO(_BASE), PROG,    KC_NO,
    KC_NO,   KC_NO,     RGB_MOD, KC_NO,
    KC_NO,   KC_NO,     RGB_HUI, KC_NO,
    KC_NO,   KC_NO,     RGB_SAI, KC_NO,
    KC_NO,   KC_NO,     RGB_VAI, KC_NO
  ),
};

/***** Nuke unneeded functionality *****/

void matrix_init_user(void) {
}

void matrix_scan_user(void) { 
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

#endif
