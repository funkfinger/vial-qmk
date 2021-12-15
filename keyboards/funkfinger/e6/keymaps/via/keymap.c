#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( \
        KC_1,   KC_2,    KC_3,    \
        KC_4,   KC_5,    KC_6,    \
                         MO(1)    \
    ),

    [1] = LAYOUT( \
          RESET,   KC_TRNS,    KC_TRNS,    \
        KC_TRNS,   KC_TRNS,    KC_TRNS,    \
                                 MO(1)     \
    ),

    [2] = LAYOUT( \
          RESET,   KC_TRNS,    KC_TRNS,    \
        KC_TRNS,   KC_TRNS,    KC_TRNS,    \
                                 MO(1)     \
    ),

    [3] = LAYOUT( \
          RESET,   KC_TRNS,    KC_TRNS,    \
        KC_TRNS,   KC_TRNS,    KC_TRNS,    \
                                 MO(1)     \
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
