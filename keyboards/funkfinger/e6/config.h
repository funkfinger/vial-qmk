#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x8695
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    funkfinger
#define PRODUCT         e6
#define DESCRIPTION     "Six keys and an encoder"


#define MATRIX_ROWS 3
#define MATRIX_COLS 3

/* key matrix pins */
#define MATRIX_ROW_PINS { C6, D7, F6 }
#define MATRIX_COL_PINS { E6, B4, B5 }
// #define DIRECT_PINS { F6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

// #define ENCODERS_PAD_A { 36 }
// #define ENCODERS_PAD_B { 38 }
// #define ENCODER_ENABLE
#define ENCODERS_PAD_A { F7 }
#define ENCODERS_PAD_B { F5 }

#define RGB_DI_PIN B6
#ifdef RGB_DI_PIN
// #define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLED_NUM 10
#define DRIVER_LED_TOTAL 10
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_DEFAULT_VAL 100
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_MOOD
#endif

#define VIAL_KEYBOARD_UID {0xB2, 0xA7, 0x9E, 0xBA, 0x78, 0x89, 0xD0, 0x56}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }
