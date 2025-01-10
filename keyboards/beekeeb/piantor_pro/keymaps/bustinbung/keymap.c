// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "oneshot.h"

#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define TD_BOOT TD(TD_DOUBLE_BOOT)

enum layer_names {
    COL,
    QWT,
    SYM,
    NAV,
    NUM
};

enum keycodes {
    OS_SFT = SAFE_RANGE,
    OS_CTL,
    OS_ALT,
    OS_GUI
};

enum {
    TD_DOUBLE_BOOT
};

void double_tap_boot(tap_dance_state_t *state, void *user_data) {
    if (state -> count >= 2) {
        reset_keyboard();
    }
}

tap_dance_action_t tap_dance_actions[] = {
    // Double tap for boot
    [TD_DOUBLE_BOOT] = ACTION_TAP_DANCE_FN(double_tap_boot),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SCLN,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           LA_NAV,  KC_SPC,   KC_NO,      KC_NO, KC_LSFT,  LA_SYM
                                      //`--------------------------'  `--------------------------'

  ),

    [QWT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           LA_NAV,  KC_SPC,   KC_NO,      KC_NO, KC_LSFT,  LA_SYM
                                      //`--------------------------'  `--------------------------'
  ),

    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_LBRC, KC_MINS,  KC_EQL, KC_RBRC, KC_TILD,                       KC_GRV,   KC_AT, KC_HASH, KC_PERC, KC_CIRC,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR,  KC_ESC,                      KC_ASTR,  OS_CTL,  OS_SFT,  OS_ALT,  OS_GUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_PIPE, KC_UNDS, KC_PLUS, KC_SLSH,  KC_DLR,                      XXXXXXX, KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_VOLU,                      TD_BOOT, KC_HOME, KC_PGUP, KC_PGDN,  KC_END,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+-----------------+--------+--------|
        KC_NO,  OS_GUI,  OS_ALT,  OS_SFT,  OS_CTL, KC_VOLD,                       KC_ENT, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,                       KC_TAB, KC_BSPC,  KC_DEL, KC_CAPS, XXXXXXX,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_7,    KC_5,    KC_3,    KC_1,    KC_9,                         KC_8,    KC_0,    KC_2,    KC_4,    KC_6,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  OS_GUI,  OS_ALT,  OS_SFT,  OS_CTL,  KC_F11,                       KC_F10,  OS_CTL,  OS_ALT,  OS_SFT,  OS_GUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,                        KC_F8,  KC_F12,   KC_F2,   KC_F4,   KC_F6,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYM:
        case LA_NAV:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYM:
        case LA_NAV:
        case KC_LSFT:
        case OS_GUI:
        case OS_ALT:
        case OS_SFT:
        case OS_CTL:
            return true;
        default:
            return false;
    }
}

oneshot_state os_sft_state = os_up_unqueued;
oneshot_state os_ctl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(&os_sft_state, KC_LSFT, OS_SFT, keycode, record);
    update_oneshot(&os_ctl_state, KC_LCTL, OS_CTL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}
