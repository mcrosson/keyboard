#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include QMK_KEYBOARD_H

#define TAPPING_TERM 200

#define CAPS_LED 30
#define LALT_LED 60

#define RGB_KMN_NO_COLOR 0, 0, 0
#define RGB_KMN_CYAN 128, 255, 255
#define RGB_KMN_PRPL 215, 195, 42
#define RGB_KMN_CYAN_HILIGHT 0, 191, 255

#define HS_KMN_ORANGE 10,255
#define HS_KMN_CYAN 128, 255

keymap_config_t keymap_config;
rgb_config_t rgb_matrix_config;

uint8_t cur_dance(qk_tap_dance_state_t *state);
void al_finished(qk_tap_dance_state_t *state, void *user_data);
void al_reset(qk_tap_dance_state_t *state, void *user_data);

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP
};

enum td_keycodes {
    LAYERS // Our example key: `MOD(1)` when held, `TG(2)` when tapped. Add additional keycodes for each tapdance.
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, al_finished, al_reset)
};

const uint8_t PROGMEM layercolors[][2] = {
    [0] = {HS_KMN_ORANGE},
    [1] = {HS_KMN_CYAN},
    [2] = {HS_KMN_CYAN}
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_65_ansi_blocker(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME,
                                     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
                                     LM(1, MOD_LALT), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
                                     KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END,
                                     KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, TD(LAYERS), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
        [1] = LAYOUT_65_ansi_blocker(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL,
                                     KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_INS,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MEDIA_PLAY_PAUSE, KC_RSFT, KC_VOLU, KC_MUTE,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, RGB_VAD, KC_VOLD, RGB_VAI),
        [2] = LAYOUT_65_ansi_blocker(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_NO, KC_NO, KC_NO, KC_MS_UP, KC_NO, KC_NO, KC_NO, KC_MS_WH_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_NO, KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_NO, KC_NO, KC_MS_BTN1, KC_MS_BTN2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_LSFT, KC_NO, KC_X, KC_C, KC_V, KC_NO, KC_NO, KC_MS_WH_DOWN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_LCTL, KC_NO, TG(2), KC_NO, TG(2), KC_NO, KC_NO, KC_NO, KC_NO),
};

const uint8_t PROGMEM ledcolors[][DRIVER_LED_TOTAL][3] = {
    [1] = {
        {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN},
        {RGB_KMN_CYAN}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN},
        {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_CYAN},
        {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_CYAN}, {RGB_KMN_NO_COLOR}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN},
        {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN},
        // Underglow == 38 LEDS
        {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, 
        {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, 
        {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, 
        {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}, {RGB_KMN_CYAN}
    },
    [2] = {
        {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR},
        {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR},
        {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR},
        {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR},
        {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_PRPL}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR}, {RGB_KMN_NO_COLOR},
        // Underglow == 38 LEDS
        {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, 
        {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, 
        {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, 
        {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}, {RGB_KMN_PRPL}
    },
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    rgb_matrix_config.raw = pgm_read_dword(EECONFIG_RGB_MATRIX);

    rgb_matrix_enable();
    rgb_matrix_sethsv(10, 255, 95);
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) return DOUBLE_TAP;
    else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap al_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void al_finished(qk_tap_dance_state_t *state, void *user_data) {
    al_tap_state.state = cur_dance(state);
    switch (al_tap_state.state) {
        case SINGLE_TAP:
            layer_on(1); // Activate layer 1 immediately since we probably are holding this down ; if released it'll go away fast and shouldn't be an issue
            break;
        case SINGLE_HOLD:
            layer_on(1); // Activate layer 1 since that's what the intent is
            break;
        case DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(2)) {
                // If already set, then switch it off
                layer_off(2);
            } else {
                // If not already set, then switch the layer on
                layer_on(2);
            }
            break;
    }
}

void al_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (al_tap_state.state == SINGLE_HOLD) {
        layer_off(1); // Reset state appropriately
    }
    al_tap_state.state = 0;
}

// Set the colors for individual LEDs for a given layer
void set_leds_color( int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    uint8_t val = pgm_read_byte(&ledcolors[layer][i][2]);
    // if the brightness of the led is set to 0 in the map,
    // the value is not overriden with global controls, allowing the led
    // to appear turned off
    HSV hsv = { .h = pgm_read_byte(&ledcolors[layer][i][0]), .s = pgm_read_byte(&ledcolors[layer][i][1]), .v = val == 0 ? 0 : rgb_matrix_config.hsv.v};
    RGB rgb = hsv_to_rgb( hsv );
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

// Set the colors for ALL LEDs for a given layer
void set_layer_color( uint8_t layer ) {
  HSV hsv = { .h = pgm_read_byte(&layercolors[layer][0]), .s = pgm_read_byte(&layercolors[layer][1]), .v = rgb_matrix_config.hsv.v};
  RGB rgb = hsv_to_rgb( hsv );
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

// Override standard rgb colorization stuff
void rgb_matrix_indicators_user(void) {
  uint32_t mode = rgblight_get_mode();
  // assign colors if the matrix is on and the current mode
  // is SOLID COLORS => No animations running
  if(rgb_matrix_config.enable == 1 && mode == RGB_MATRIX_SOLID_COLOR) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_leds_color(1);
        break;
      case 2:
        set_leds_color(2);
        break;
    }
  }
  if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    rgb_matrix_set_color(CAPS_LED, RGB_KMN_CYAN_HILIGHT);
  }
}

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
