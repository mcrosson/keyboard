#pragma once

/**** TAP HOLD *****/
#define TAPPING_TOGGLE 2
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100
/****  END TAP HOLD *****/

/******** MOUSE KEYS **********/
#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY         16
#define MOUSEKEY_MOVE_DELTA    10
#define MOUSEKEY_INITIAL_SPEED 10
#define MOUSEKEY_BASE_SPEED    300
/******** END MOUSE KEYS ***********/

/***** Keyboard Definitions *****/
#ifdef KEYBOARD_nullbitsco_tidbit
#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }
#endif
