// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once

#define ARDUX_STD_LAYER_CUS_LEFT \
STD_LEADING_NONES \
KC_NO,            KC_VOLU,          KC_WWW_HOME,        KC_WWW_BACK, \
STD_BETWEEN_ROW_ONE_TWO_NONES \
KC_TRNS,          KC_VOLD,          KC_WWW_SEARCH,      KC_MUTE      \
STD_TRAILING_NONES

// Copy of needed defines from layers.h
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
