/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

typedef union {
    uint32_t raw;
    struct {
        uint8_t dpi_config;
    };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;
extern uint16_t          dpi_array[];

enum ploopy_keycodes {
    NO_OP = QK_KB_0,
    DRAG_SCROLL,
    DPI_RESET,
    DPI_UP,
    DPI_DOWN,
    BOOT_COMBO_1,
    BOOT_COMBO_2,
    LAYER_BASE_COMBO_1,
    LAYER_BASE_COMBO_2,
    LAYER_RIGHT_COMBO_1,
    LAYER_RIGHT_COMBO_2,
    LAYER_LEFT_COMBO_1,
    LAYER_LEFT_COMBO_2,
    LAYER_MACROPAD_COMBO_1,
    LAYER_MACROPAD_COMBO_2,
    LAYER_MACROPAD_COMBO_3,
    LAYER_MACROPAD_COMBO_4,
    LAYER_SABER_COMBO_1,
    LAYER_SABER_COMBO_2,
    GUI_CTL_T_COMBO_1,
    GUI_CTL_T_COMBO_2,
};

bool encoder_update_user(uint8_t index, bool clockwise);
bool encoder_update_kb(uint8_t index, bool clockwise);
void toggle_drag_scroll(void);
void cycle_dpi(void);
