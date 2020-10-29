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

#define MATRIX_ROW_PINS { PC7, PF7, PF6 }
#define MATRIX_COL_PINS { PF0, PF1, PF4, PF5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW // FIXME: Double check this actually works

/* Encoders */
#define ENCODERS_PAD_A { PD0, PB5 }
#define ENCODERS_PAD_B { PD1, PD6 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN PD3
#ifdef RGB_DI_PIN
#undef RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 4
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 240
#define RGBLIGHT_SLEEP
#endif

// Definitions for encoder tilt/press support
#define ENC_TILT_THRESHOLD 3 // 0 - 1023 per the analogReadPin docs -- higher == more tilt

#define PIN_TW_SW PD2 // Center
#define PIN_RJ_SW PC6 // Center
#define PIN_RJ_DIR_A PD4 // Up
#define PIN_RJ_DIR_B PD7 // Left
#define PIN_RJ_DIR_C PB6 // Down
#define PIN_RJ_DIR_D PB4 // Right

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
