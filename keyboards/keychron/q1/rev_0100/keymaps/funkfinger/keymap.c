/* spell-checker: disable */
/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

/* modified by funkfinger 2021-01-31 */

#include QMK_KEYBOARD_H

#include "keymap_user.h"

#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_user.h"
#endif

// clang-format off

typedef union {
  uint32_t raw;
  struct {
    bool caps_lock_light_tab :1;
    bool caps_lock_light_alphas :1;
    bool fn_layer_transparent_keys_off :1;
    bool fn_layer_color_enable :1;
  };
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
    KC_MISSION_CONTROL = USER00,
    SPOT = USER01,
    KC_LAUNCHPAD,
    KC_TASK,
    KC_FLXP,
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_82(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,   SPOT,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPACE,          KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RGUI, MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_82(
        KC_TRNS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET,              KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};



// clang-format on

void matrix_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.caps_lock_light_tab = false;
    user_config.caps_lock_light_alphas = false;
    user_config.fn_layer_transparent_keys_off = true;
    user_config.fn_layer_color_enable = false;
    eeconfig_update_user(user_config.raw);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_LWIN);
                unregister_code(KC_TAB);
            }
            return false;  // Skip all further processing of this key
        case KC_FLXP:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_E);
            } else {
                unregister_code(KC_LWIN);
                unregister_code(KC_E);
            }
            return false;  // Skip all further processing of this key
        case SPOT:  // Open Spotify
            SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
            _delay_ms(100);
            SEND_STRING("spotify app");
            _delay_ms(100);
            SEND_STRING(SS_TAP(X_ENTER));
            return false;
        default:
            return true;  // Process all other keycodes normally
    }
}


bool get_caps_lock_light_tab(void) {
    return user_config.caps_lock_light_tab;
}

bool get_caps_lock_light_alphas(void) {
    return user_config.caps_lock_light_alphas;
}

bool get_fn_layer_transparent_keys_off(void) {
    return user_config.fn_layer_transparent_keys_off;
}

bool get_fn_layer_color_enable(void) {
    return user_config.fn_layer_color_enable;
}
