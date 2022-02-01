/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

//Vial Keyboard UID
#define VIAL_KEYBOARD_UID {0x49, 0x5F, 0x9C, 0xB8, 0x0F, 0x67, 0x4D, 0xE6}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 13 }

#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define CAPS_LOCK_INDICATOR_COLOR RGB_RED
#    define FN_LAYER_COLOR RGB_ORANGE
#endif
