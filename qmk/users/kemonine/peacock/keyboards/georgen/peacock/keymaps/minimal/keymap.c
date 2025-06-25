// Copyright 2024 George Norton (@george-norton)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// ---------- START lighting

#define HSV_RED_KMN 0, 255, 40
#define HSV_ORANGE_KMN 21, 255, 40
#define HSV_PURPLE_KMN 191, 255, 40

const uint8_t INDICATOR_LED = 5;

void rgb_matrix_set_color_kmn(uint8_t i, uint8_t h, uint8_t s, uint8_t v) {
    rgb_t rgb = hsv_to_rgb((hsv_t){h, s, v});
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    rgb_matrix_update_pwm_buffers();
}

void rgb_matrix_set_color_all_kmn(uint8_t h, uint8_t s, uint8_t v) {
    rgb_t rgb = hsv_to_rgb((hsv_t){h, s, v});
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
    rgb_matrix_update_pwm_buffers();
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 1:
            rgb_matrix_set_color_kmn(INDICATOR_LED, HSV_ORANGE_KMN);
            break;
        default:
            rgb_matrix_set_color_kmn(INDICATOR_LED, HSV_PURPLE_KMN);
            break;
    }
    return false;
}

// ---------- END lighting

combo_t key_combos[] = {
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(KC_NO, KC_BTN1, KC_BTN2, LT(1, KC_BTN3), KC_BTN2, KC_BTN1, KC_NO),
                                                              [1] = LAYOUT(KC_NO, EE_CLR, QK_BOOT, KC_TRNS, QK_BOOT, EE_CLR, KC_NO)};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP),  ENCODER_CCW_CW(QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_DOWN)  },
    [1] = { ENCODER_CCW_CW(QK_UNDERGLOW_VALUE_UP, QK_UNDERGLOW_VALUE_DOWN),   ENCODER_CCW_CW(QK_UNDERGLOW_VALUE_DOWN, QK_UNDERGLOW_VALUE_UP)  },
};
#endif

void keyboard_post_init_user(void) {
    // Default rgb matrix leds to solid color: purple
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_set_color_all_kmn(HSV_PURPLE);
    rgb_matrix_set_color_kmn(INDICATOR_LED, HSV_PURPLE_KMN);
}

bool shutdown_kb(bool jump_to_bootloader) {
    if (!shutdown_user(jump_to_bootloader)) {
        return false;
    }
    if (jump_to_bootloader) {
        rgb_matrix_set_color_all_kmn(HSV_RED);
        rgb_matrix_set_color_kmn(INDICATOR_LED, HSV_RED_KMN);
    }
    else {
        rgb_matrix_set_color_all_kmn(HSV_OFF);
    }
    return true;
}
