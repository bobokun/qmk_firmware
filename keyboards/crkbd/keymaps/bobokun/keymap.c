#include QMK_KEYBOARD_H
#include "layers.h"
#include "oleds.h"
#include "brain.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI,   KC_SPC,  LOWER,      RAISE,  KC_ENT,  KC_LALT \
                                      //`--------------------------'  `--------------------------'

  ),


  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  LALT(KC_TAB), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PGUP,  KC_HOME,  KC_UP,  KC_END, KC_GESC,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,                       KC_BSLS,  KC_GRV, KC_LBRC, KC_RBRC, XXXXXXX, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_LGUI,   KC_SPC,  LOWER,      RAISE,  KC_ENT,  KC_LALT \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_VOLU,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_VOLD,  KC_F11,  KC_F12, RGB_VAD, RGB_TOG, RGB_VAI,                     RGB_RMOD, RGB_MOD, KC_MPRV, KC_MPLY, KC_MNXT, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_LGUI,   KC_SPC,  LOWER,      RAISE,  KC_ENT,  KC_LALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  EEP_RST, XXXXXXX,KC_NLCK, KC_CLCK, KC_SLCK,                       DJMAX, KC_BTN1, KC_UP, KC_BTN2, KC_WH_U, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_D, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_LGUI,   KC_SPC,  LOWER,      RAISE,  KC_ENT,  KC_LALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_DJMAX] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GESC,   KC_F1,  KC_F10,    KC_E,    KC_E,    KC_1,                         KC_2,    KC_I,    KC_I, XXXXXXX, KC_PGUP, QWERTY,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,   KC_F9,    KC_S,    KC_D,    KC_F, XXXXXXX,                        KC_F5,    KC_J,    KC_K,    KC_L, KC_PGDN, KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    KC_LSFT,   KC_F8, XXXXXXX, XXXXXXX, KC_LALT, XXXXXXX,                      XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_SPC, KC_LCTL,  LOWER,       RAISE, KC_RCTL , KC_ENT  \
                                      //`--------------------------'  `--------------------------'

  )
};
