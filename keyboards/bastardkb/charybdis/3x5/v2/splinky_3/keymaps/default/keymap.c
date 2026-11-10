// Copyright Francesco Raso (@0xfraso)
//
// Handwired Charybdis Nano (dual 0xCB Helios) — plain QMK keymap.
// Converted from charybdis_nano.layout.json (the saved VIA layout backup).
//
// LAYOUT is row-interleaved: L-top, R-top, L-home, R-home, L-bottom, R-bottom,
// thumbs. Backup slot order per half is L->R; right-half backup rows are
// stored outer->inner so they map reversed onto LAYOUT positions.
//
// Layers:
//   0  base        QWERTY + home-row mods
//   1  function    TAB (left thumb)
//   2  navigation  SPC (left thumb)
//   3  media/RGB   ESC (left thumb), RESET on B
//   4  pointer     Z or / hold: mouse buttons, DPI, sniping, drag-scroll, RESET
//   5  numeral     BSPC (right thumb)
//   6  symbols     ENT (right thumb)

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_Y, KC_U, KC_I, KC_O, KC_P,
    MT(MOD_LGUI,KC_A), MT(MOD_LALT,KC_S), MT(MOD_LCTL,KC_D), MT(MOD_LSFT,KC_F), KC_G,
    KC_H, MT(MOD_LSFT | MOD_RSFT,KC_J), MT(MOD_LCTL | MOD_RCTL,KC_K), MT(MOD_LALT,KC_L), MT(MOD_LGUI | MOD_RGUI,KC_SCLN),
    LT(4,KC_Z), KC_X, KC_C, KC_V, KC_B,
    KC_N, KC_M, KC_COMM, KC_DOT, LT(4,KC_SLSH),
    LT(3,KC_ESC), LT(2,KC_SPC), LT(1,KC_TAB), LT(6,KC_ENT), LT(5,KC_BSPC)
),
[1] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
    KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_PAUS, KC_F1, KC_F2, KC_F3, KC_F10,
    KC_NO, KC_NO, _______, KC_NO, KC_DEL
),
[2] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DEL,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS,
    KC_NO, _______, KC_NO, KC_ENT, KC_BSPC
),
[3] = LAYOUT(
    TG(7), QK_RGB_MATRIX_MODE_PREVIOUS, QK_RGB_MATRIX_TOGGLE, QK_RGB_MATRIX_MODE_NEXT, KC_NO,
    KC_NO, QK_RGB_MATRIX_MODE_PREVIOUS, QK_RGB_MATRIX_TOGGLE, QK_RGB_MATRIX_MODE_NEXT, KC_NO,
    KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT,
    KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT,
    KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    _______, KC_MPLY, KC_MSTP, KC_MSTP, KC_MPLY
),
[4] = LAYOUT(
    KC_NO, KC_NO, KC_NO, POINTER_DEFAULT_DPI_REVERSE, POINTER_SNIPING_DPI_REVERSE,
    POINTER_SNIPING_DPI_FORWARD, POINTER_DEFAULT_DPI_FORWARD, KC_NO, KC_NO, KC_SLEP,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
    KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    _______, DRAGSCROLL_MODE, SNIPING_MODE, KC_NO, QK_BOOT,
    QK_BOOT, KC_NO, SNIPING_MODE, DRAGSCROLL_MODE, _______,
    MS_BTN2, MS_BTN1, MS_BTN3, MS_BTN2, MS_BTN1
),
[5] = LAYOUT(
    KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_QUOT, KC_4, KC_5, KC_6, KC_EQL,
    KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_DOT, KC_0, KC_MINS, KC_NO, _______
),
[6] = LAYOUT(
    S(KC_LBRC), S(KC_7), S(KC_8), S(KC_9), S(KC_RBRC),
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    S(KC_QUOT), S(KC_4), S(KC_5), S(KC_6), S(KC_EQL),
    KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_BSLS),
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    S(KC_9), S(KC_0), S(KC_MINS), _______, KC_NO
),
[7] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_H, KC_J, KC_K, KC_L, KC_SCLN,
    KC_LSFT, KC_LCTL, KC_X, KC_C, KC_V,
    KC_N, KC_M, KC_COMM, KC_DOT, TO(0),
    KC_ESC, KC_SPC, MS_BTN1, KC_ENT, KC_BSPC
),
};
// clang-format on
