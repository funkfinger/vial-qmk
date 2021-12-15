// #include QMK_KEYBOARD_H
#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT( \
        KC_1,   KC_2,    KC_3,    \
        KC_4,   KC_5,    KC_6,    \
                         KC_X     \
    ),

    [1] = LAYOUT( \
        KC_A,   KC_B,    KC_C,    \
        KC_D,   KC_E,    KC_F,    \
                         KC_X     \
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

#ifdef ENCODER_ENABLE
#include "encoder.h"
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC__VOLUP);
    } else {
        tap_code(KC__VOLDOWN);
    }
    return false;
}

#endif
