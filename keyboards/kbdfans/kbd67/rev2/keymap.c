#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include QMK_KEYBOARD_H

#define HSV_KMN_ORANGE 10,255, 95
#define HSV_KMN_CYAN 128, 255, 95
#define HSV_KMN_PURPLE 191, 255, 95

keymap_config_t keymap_config;

uint8_t cur_dance(qk_tap_dance_state_t *state);
void al_finished(qk_tap_dance_state_t *state, void *user_data);
void al_reset(qk_tap_dance_state_t *state, void *user_data);

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_65_ansi_blocker(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME,
                                     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
                                     LM(1, MOD_LALT), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN,
                                     KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END,
                                     KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, TD(LAYERS), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
        [1] = LAYOUT_65_ansi_blocker(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_INS,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MEDIA_PLAY_PAUSE, KC_RSFT, KC_VOLU, KC_MUTE,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, RGB_VAD, KC_VOLD, RGB_VAI),
        [2] = LAYOUT_65_ansi_blocker(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_NO, KC_NO, KC_NO, KC_MS_UP, KC_NO, KC_NO, KC_NO, KC_MS_WH_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_NO, KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_NO, KC_NO, KC_MS_BTN1, KC_MS_BTN2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_LSFT, KC_NO, KC_X, KC_C, KC_V, KC_NO, KC_NO, KC_MS_WH_DOWN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_LCTL, KC_NO, TG(2), KC_NO, TG(2), KC_NO, KC_NO, KC_NO, KC_NO),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

// Override standard rgb colorization stuff
void rgb_matrix_indicators_user(void) {
  // assign colors if the matrix is on and the current mode
  // is SOLID COLORS => No animations running
  uint8_t layer = biton32(layer_state);
  switch (layer) {
    case 0:
      rgblight_sethsv(HSV_KMN_ORANGE);
      break;
    case 1:
      rgblight_sethsv(HSV_KMN_CYAN);
      break;
    case 2:
      rgblight_sethsv(HSV_KMN_PURPLE);
      break;
  }
}

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
