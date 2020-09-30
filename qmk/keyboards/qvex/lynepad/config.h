/*
Copyright 2020 KemoNine

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4B42 // FIXME: Update to match Lynepad
#define PRODUCT_ID      0x6067 // FIXME: Update to match Lynepad
#define DEVICE_VER      0x0002 // FIXME: Update to match Lynepad
#define MANUFACTURER    QVEX
#define PRODUCT         Lynepad
#define DESCRIPTION     Macro Keypad

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D0, D1, D2, D3, D4, D5, D6} // FIXME: Update to match Lynepad
#define MATRIX_COL_PINS { B0, B1, B2, B3, B4, B5 } // FIXME: Update to match Lynepad
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW // FIXME: Update to match Lynepad

/* Encoders */
#define ENCODERS_PAD_A { E1, E3 } // FIXME: Update to match Lynepad
#define ENCODERS_PAD_B { E2, E4 } // FIXME: Update to match Lynepad

/* number of backlight levels */
#define BACKLIGHT_PIN C0 // FIXME: Update to match Lynepad
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN D1 // FIXME: Update to match Lynepad
#ifdef RGB_DI_PIN
#undef RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 4
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 240
#define RGBLIGHT_SLEEP
#endif
