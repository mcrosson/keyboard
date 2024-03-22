// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once

//////////
// std ardux custom layer
#define ARDUX_STD_LAYER_CUS_LEFT \
STD_LEADING_NONES \
KC_PSCR,            KC_VOLU,          KC_WWW_HOME,        KC_WWW_BACK, \
STD_BETWEEN_ROW_ONE_TWO_NONES \
KC_TRNS,          KC_VOLD,          KC_WWW_SEARCH,      KC_MUTE      \
STD_TRAILING_NONES

//////////
// big ardux custom layer
#ifndef ARDUX_BIG_LAYER_CUS_LEFT
#ifdef ARDUX_TWO_THUMB
#define ARDUX_BIG_LAYER_CUS_LEFT_THUMBS KC_NO, KC_NO
#endif
#ifndef ARDUX_TWO_THUMB
#define ARDUX_BIG_LAYER_CUS_LEFT_THUMBS KC_NO, KC_NO, KC_NO
#endif
#endif

#define ARDUX_BIG_LAYER_CUS_LEFT \
BIG_LEADING_NONES \
KC_PSCR,            KC_VOLU,          KC_WWW_HOME,           KC_WWW_BACK,          KC_NO,            \
BIG_BETWEEN_ROW_ONE_TWO_NONES \
KC_TRNS,          KC_VOLD,          KC_WWW_SEARCH,          KC_MUTE,          KC_NO,            \
BIG_BETWEEN_ROW_TWO_THREE_NONES \
KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            \
BIG_BETWEEN_ROW_THREE_THUMBS_NONES \
ARDUX_BIG_LAYER_CUS_LEFT_THUMBS \
BIG_TRAILING_NONES

//////////
// big ardux number layer
#ifndef ARDUX_BIG_LAYER_NUM_LEFT
#ifdef ARDUX_TWO_THUMB
#define ARDUX_BIG_LAYER_NUM_LEFT_THUMBS KC_UNDS, KC_SPACE
#endif
#ifndef ARDUX_TWO_THUMB
#define ARDUX_BIG_LAYER_NUM_LEFT_THUMBS KC_TAB, KC_UNDS, KC_SPACE
#endif
#endif

#define ARDUX_BIG_LAYER_NUM_LEFT \
BIG_LEADING_NONES \
KNUM_T4,          KNUM_T3,          KNUM_T2,          KNUM_T1,          KC_MINUS,            \
BIG_BETWEEN_ROW_ONE_TWO_NONES \
KNUM_B4,          KNUM_B3,          KNUM_B2,          KNUM_B1,          KC_SLASH,            \
BIG_BETWEEN_ROW_TWO_THREE_NONES \
KC_NO,            KC_NO,            KC_NO,            KC_TAB,            KC_COLON,            \
BIG_BETWEEN_ROW_THREE_THUMBS_NONES \
ARDUX_BIG_LAYER_NUM_LEFT_THUMBS \
BIG_TRAILING_NONES

//////////
// big ardux mouse layer
#define ARDUX_BIG_LAYER_MSE_LEFT_THUMBS
#define ARDUX_BIG_LAYER_MSE_LEFT \
KC_NO, KMSE_T4, KMSE_T3, KMSE_T2, KMSE_T1, KC_NO,        KC_NO, KMSE_T1, KMSE_T2,  KMSE_T3, KMSE_T4, KC_NO, \
KC_NO, KMSE_B4, KMSE_B3, KMSE_B2, KMSE_B1, KC_NO,        KC_NO, KMSE_B3, KMSE_B2,  KMSE_B1, KMSE_B4, KC_NO, \
KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, \
                         KC_NO,   KC_NO,   KC_NO,        KC_NO, KC_NO, KC_NO
