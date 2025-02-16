#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY,
    _NAV,
};

enum custom_keycodes {
    MACRO_TILDE = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MACRO_TILDE:
        if (record->event.pressed) {
            // WARN: Not sure if this works
            SEND_STRING("~");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,_______,
        _______,_______,KC_Q, KC_W  , KC_E  , KC_R  , KC_T  ,                            KC_Y, KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC,_______,
        _______,KC_TAB ,LSFT_T(KC_A),LCTL_T(KC_S),LALT_T(KC_D),LGUI_T(KC_F),KC_G,        KC_H   ,RGUI_T(KC_J),LALT_T(KC_K),RCTL_T(KC_L),RSFT_T(KC_SCLN),KC_QUOT,_______,
        _______,KC_CAPS, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N   , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,MACRO_TILDE,_______,
                         KC_LBRC,KC_RBRC,
                                           _______,KC_SPC,KC_HOME,                           KC_ENT,_______,KC_TAB,_______,_______,
                                           KC_BSPC,LT(_NAV, KC_ESC),_______,                         _______,_______,_______

    ),

    [_NAV] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,_______,_______,
        _______,_______,KC_Q, KC_W  , KC_E  , KC_R  , KC_T  ,                            KC_Y, KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC,_______,
        _______,KC_TAB ,LSFT_T(KC_A),LCTL_T(KC_S),LALT_T(KC_D),LGUI_T(KC_F),KC_G,        KC_H   ,RGUI_T(KC_J),LALT_T(KC_K),RCTL_T(KC_L),RSFT_T(KC_SCLN),KC_QUOT,_______,
        _______,KC_CAPS, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N   , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,MACRO_TILDE,_______,
                         KC_LBRC,KC_RBRC,
                                           _______,KC_SPC,KC_HOME,                           KC_ENT,_______,KC_TAB,_______,_______,
                                           KC_BSPC,KC_GRV,_______,                         _______,_______,_______

    ),
};
