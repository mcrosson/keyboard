#include "lynepad.h"

#include <print.h>

void keyboard_pre_init_kb(void) {
    // Encoder pins
    setPinInput(PIN_TW_SW);
    setPinInput(PIN_RJ_SW);
    setPinInput(PIN_RJ_DIR_A);
    setPinInput(PIN_RJ_DIR_C);
    setPinInput(PIN_RJ_DIR_B);
    setPinInput(PIN_RJ_DIR_D);

    // Matrix pins
    setPinInput(C7);
    setPinInput(F7);
    setPinInput(F6);
    setPinInput(F0);
    setPinInput(F1);
    setPinInput(F4);
    setPinInput(F5);
}

// void keyboard_post_init_user(void) {
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
// }

int16_t enc1Center = 1;
int16_t enc1CenterPrev = 1;
int16_t enc2Center = 1;
int16_t enc2CenterPrev = 1;
int16_t enc2Up = 1;
int16_t enc2UpPrev = 1;
int16_t enc2Down = 1;
int16_t enc2DownPrev = 1;
int16_t enc2Left = 1;
int16_t enc2LeftPrev = 1;
int16_t enc2Right = 1;
int16_t enc2RightPrev = 1;

void matrix_scan_kb(void) {
    enc1CenterPrev = enc1Center;
    enc1Center = readPin(PIN_TW_SW);

    enc2CenterPrev = enc2Center;
    enc2Center = readPin(PIN_RJ_SW);
    enc2UpPrev = enc2Up;
    enc2Up = readPin(PIN_RJ_DIR_A);
    enc2DownPrev = enc2Down;
    enc2Down = readPin(PIN_RJ_DIR_C);
    enc2LeftPrev = enc2Left;
    enc2Left = readPin(PIN_RJ_DIR_B);
    enc2RightPrev = enc2Right;
    enc2Right = readPin(PIN_RJ_DIR_D);

    // printf("==================\n");
    // print("Encoders\n");
    // uprintf("    E1CP: %d\n", enc1CenterPrev);
    // uprintf("    E1C: %d\n", enc1Center);
    // uprintf("    E2CP: %d\n", enc2CenterPrev);
    // uprintf("    E2C: %d\n", enc2Center);
    // uprintf("    E2UP: %d\n", enc2UpPrev);
    // uprintf("    E2U: %d\n", enc2Up);
    // uprintf("    E2DP: %d\n", enc2DownPrev);
    // uprintf("    E2D: %d\n", enc2Down);
    // uprintf("    E2LP: %d\n", enc2LeftPrev);
    // uprintf("    E2L: %d\n", enc2Left);
    // uprintf("    E2RP: %d\n", enc2RightPrev);
    // uprintf("    E2R: %d\n", enc2Right);
    // print("Rows\n");
    // uprintf("    C7: %d\n", readPin(C7));
    // uprintf("    F7: %d\n", readPin(F7));
    // uprintf("    F6: %d\n", readPin(F6));
    // print("Cols\n");
    // uprintf("    F0: %d\n", readPin(F0));
    // uprintf("    F1: %d\n", readPin(F1));
    // uprintf("    F4: %d\n", readPin(F4));
    // uprintf("    F5: %d\n", readPin(F5));

    // Ensure any user customizations are called (for some reason this wasn't happening by default)
    matrix_scan_user();
}
