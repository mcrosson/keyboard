// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once

//////////
// tweak right handed thumb so its 'space only' given ive only ever used my right thumb for space
//    i keep tapping enter by accident and its pissing me off
#ifndef ARDUX_TWO_THUMB
#define ARDUX_BIG_LAYER_BASE_RIGHT_THUMBS KC_SPC, KC_SPC, MO(LAYER_ID_BIG_SYM)
#endif

//////////
// std ardux custom layer
#define ARDUX_STD_LAYER_CUS_LEFT \
STD_LEADING_NONES \
KC_PSCR,            KC_VOLU,          KC_WWW_HOME,        KC_WWW_BACK, \
STD_BETWEEN_ROW_ONE_TWO_NONES \
KC_TRNS,          KC_VOLD,          KC_WWW_SEARCH,      KC_MUTE      \
STD_TRAILING_NONES

#define ARDUX_STD_LAYER_CUS_RIGHT \
STD_LEADING_NONES \
KC_WWW_BACK,            KC_WWW_HOME,          KC_VOLU,        KC_PSCR, \
STD_BETWEEN_ROW_ONE_TWO_NONES \
KC_MUTE,          KC_WWW_SEARCH,          KC_VOLD,      KC_TRNS      \
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

#ifndef ARDUX_BIG_LAYER_CUS_RIGHT
#ifdef ARDUX_TWO_THUMB
#define ARDUX_BIG_LAYER_CUS_RIGHT_THUMBS KC_NO, KC_NO
#endif
#ifndef ARDUX_TWO_THUMB
#define ARDUX_BIG_LAYER_CUS_RIGHT_THUMBS KC_NO, KC_NO, KC_NO
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

#define ARDUX_BIG_LAYER_CUS_RIGHT \
BIG_LEADING_NONES \
KC_NO,            KC_WWW_BACK,          KC_WWW_HOME,           KC_VOLU,          KC_PSCR,            \
BIG_BETWEEN_ROW_ONE_TWO_NONES \
KC_NO,          KC_MUTE,          KC_WWW_SEARCH,          KC_VOLD,          KC_TRNS,            \
BIG_BETWEEN_ROW_TWO_THREE_NONES \
KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            \
BIG_BETWEEN_ROW_THREE_THUMBS_NONES \
ARDUX_BIG_LAYER_CUS_RIGHT_THUMBS \
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

#ifndef ARDUX_BIG_LAYER_NUM_RIGHT
#ifdef ARDUX_TWO_THUMB
#define ARDUX_BIG_LAYER_NUM_RIGHT_THUMBS KC_SPACE, KC_UNDS
#endif
#ifndef ARDUX_TWO_THUMB
#define ARDUX_BIG_LAYER_NUM_RIGHT_THUMBS KC_SPACE, KC_UNDS, KC_TAB 
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

#define ARDUX_BIG_LAYER_NUM_RIGHT \
BIG_LEADING_NONES \
KC_MINUS,          KNUM_T1,          KNUM_T2,          KNUM_T3,          KNUM_T4,            \
BIG_BETWEEN_ROW_ONE_TWO_NONES \
KC_SLASH,          KNUM_B1,          KNUM_B2,          KNUM_B3,          KNUM_B4,            \
BIG_BETWEEN_ROW_TWO_THREE_NONES \
KC_COLON,          KC_TAB,          KC_NO,             KC_NO,            KC_NO,            \
BIG_BETWEEN_ROW_THREE_THUMBS_NONES \
ARDUX_BIG_LAYER_NUM_RIGHT_THUMBS \
BIG_TRAILING_NONES

///////////
// nav layer (same on both halves)
#define ARDUX_BIG_LAYER_NAV_LEFT_THUMBS
#define ARDUX_BIG_LAYER_NAV_LEFT  \
KC_BSPC,    KC_PGUP,    KC_HOME, KC_UP,   KC_END,   LCTL(KC_T),            LCTL(KC_T),     KC_HOME, KC_UP,   KC_END,   KC_PGUP,    KC_BSPC, \
KC_ENT,     KC_PGDN,    KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_SPACE),        LCTL(KC_SPACE), KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,    KC_ENT, \
LGUI(KC_E), LGUI(KC_E), KC_RBRC, KC_RBRC, KC_LBRC,  KC_S,                  KC_S,           KC_LBRC, KC_RBRC, KC_RBRC,  LGUI(KC_E), LGUI(KC_E), \
                               KC_DELETE, KC_ESC,   KC_SPACE,              KC_SPACE, KC_ESC, KC_DELETE

#define ARDUX_BIG_LAYER_NAV_RIGHT_THUMBS
#define ARDUX_BIG_LAYER_NAV_RIGHT \
KC_BSPC,    KC_PGUP,    KC_HOME, KC_UP,   KC_END,   LCTL(KC_T),            LCTL(KC_T),     KC_HOME, KC_UP,   KC_END,   KC_PGUP,    KC_BSPC, \
KC_ENT,     KC_PGDN,    KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_SPACE),        LCTL(KC_SPACE), KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,    KC_ENT, \
LGUI(KC_E), LGUI(KC_E), KC_RBRC, KC_RBRC, KC_LBRC,  KC_S,                  KC_S,           KC_LBRC, KC_RBRC, KC_RBRC,  LGUI(KC_E), LGUI(KC_E), \
                               KC_DELETE, KC_ESC,   KC_SPACE,              KC_SPACE, KC_ESC, KC_DELETE

//////////
// big ardux mouse layer
#define ARDUX_BIG_LAYER_MSE_LEFT_THUMBS
#define ARDUX_BIG_LAYER_MSE_LEFT \
KC_NO, KMSE_T4, KMSE_T3, KMSE_T2, KMSE_T1, KC_NO,        KC_NO, KMSE_T1, KMSE_T2,  KMSE_T3, KMSE_T4, KC_NO, \
KC_NO, KMSE_B4, KMSE_B3, KMSE_B2, KMSE_B1, KC_NO,        KC_NO, KMSE_B3, KMSE_B2,  KMSE_B1, KMSE_B4, KC_NO, \
KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, \
                         KC_NO,   KC_NO,   KC_NO,        KC_NO, KC_NO, KC_NO

#define ARDUX_BIG_LAYER_MSE_RIGHT_THUMBS
#define ARDUX_BIG_LAYER_MSE_RIGHT \
KC_NO, KMSE_T4, KMSE_T3, KMSE_T2, KMSE_T1, KC_NO,        KC_NO, KMSE_T1, KMSE_T2,  KMSE_T3, KMSE_T4, KC_NO, \
KC_NO, KMSE_B4, KMSE_B3, KMSE_B2, KMSE_B1, KC_NO,        KC_NO, KMSE_B3, KMSE_B2,  KMSE_B1, KMSE_B4, KC_NO, \
KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, \
                         KC_NO,   KC_NO,   KC_NO,        KC_NO, KC_NO, KC_NO
