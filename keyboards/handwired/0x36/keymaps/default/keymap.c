#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _SYM,
    _NUM,
    _FUN,
};

static bool is_home_row_mod(uint16_t keycode) {
    switch (keycode) {
        case LGUI_T(KC_A):
        case LALT_T(KC_S):
        case LCTL_T(KC_D):
        case LSFT_T(KC_F):
        case RSFT_T(KC_J):
        case RCTL_T(KC_K):
        case RALT_T(KC_L):
        case RGUI_T(KC_SCLN):
            return true;
        default:
            return false;
    }
}

static bool is_thumb_layer_tap(uint16_t keycode) {
    switch (keycode) {
        case LT(_NAV, KC_SPC):
        case LT(_SYM, KC_ENT):
        case LT(_NUM, KC_BSPC):
        case LT(_FUN, KC_DEL):
            return true;
        default:
            return false;
    }
}

static bool is_flow_roll_key(uint16_t keycode) {
    switch (get_tap_keycode(keycode)) {
        case KC_A ... KC_Z:
        case KC_COMM:
        case KC_DOT:
        case KC_SCLN:
        case KC_SLSH:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
        LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,           KC_H,           RSFT_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN),
        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                        KC_ESC,         LT(_NAV, KC_SPC), KC_TAB,       LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC), LT(_FUN, KC_DEL)
    ),

    [_NAV] = LAYOUT(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_CAPS,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        XXXXXXX,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END,         KC_INS,
                                        _______,        _______,        XXXXXXX,        KC_ENT,         KC_BSPC,        KC_DEL
    ),

    [_SYM] = LAYOUT(
        KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        KC_DQUO,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_PLUS,        XXXXXXX,        KC_RSFT,        KC_RCTL,        KC_RALT,        KC_RGUI,
        KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_PIPE,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                        KC_LPRN,        KC_RPRN,        KC_UNDS,        _______,        XXXXXXX,        XXXXXXX
    ),

    [_NUM] = LAYOUT(
        KC_LBRC,        KC_7,           KC_8,           KC_9,           KC_RBRC,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        KC_QUOT,        KC_4,           KC_5,           KC_6,           KC_EQL,         XXXXXXX,        KC_RSFT,        KC_RCTL,        KC_RALT,        KC_RGUI,
        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_BSLS,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                        KC_DOT,         KC_0,           KC_MINS,        XXXXXXX,        _______,        XXXXXXX
    ),

    [_FUN] = LAYOUT(
        KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PSCR,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        QK_BOOT,
        KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_PAUS,        XXXXXXX,        KC_RSFT,        KC_RCTL,        KC_RALT,        KC_RGUI,
        KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_SCRL,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                        KC_APP,         KC_SPC,         KC_TAB,         XXXXXXX,        XXXXXXX,        _______
    )
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    if (is_home_row_mod(keycode)) {
        return false;
    }
    if (is_thumb_layer_tap(keycode)) {
        return true;
    }
    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (is_home_row_mod(keycode)) {
        return 190;
    }
    if (is_thumb_layer_tap(keycode)) {
        return 160;
    }
    return TAPPING_TERM;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    if (!is_home_row_mod(keycode)) {
        return 0;
    }
    if (is_flow_roll_key(keycode) && is_flow_roll_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
}
