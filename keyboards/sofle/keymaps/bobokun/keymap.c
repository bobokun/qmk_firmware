#include <stdio.h>
#include QMK_KEYBOARD_H

bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
bool is_win_snap_active = false; // ADD this near the begining of keymap.c


enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY = 0,
    _PLOVER,
    _DJMAX,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_DJMAX,
    KC_PLOVER,
    EXT_PLV,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /LOWER  /       \RAISE \  |Enter | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,  KC_WFWD , KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                 KC_LGUI,KC_LALT,KC_LCTL, KC_SPC, KC_LOWER,      KC_RAISE,  KC_ENT, KC_RCTL, KC_RALT, KC_RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  PLAY |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /LOWER  /       \RAISE \  |Enter | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12, \
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_MPLY,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______, \
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______\
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------| PLAY  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /LOWER  /       \RAISE \  |Enter | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______, \
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_BSPC, \
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC, \
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  KC_MPLY,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______, \
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RESET|      |      |      |      |MACWIN|                    |DJMAX |      |      |      |      |PLOVER|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG| HUI | SAI  | VAI  |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------| MPLY  |    |RGB_TOG|------+------+------+------+------+------|
 * |RGB_MOD| HUD | SAD  | VAD  |      |      |-------|    |-------|T_NKRO| PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /LOWER  /       \RAISE \  |Enter | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  QK_BOOT, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, CG_TOGG,                   KC_DJMAX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLOVER, \
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, KC_MPLY,     RGB_TOG, MAGIC_TOGGLE_NKRO, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  ),

/*
 * Plover layer (http://opensteno.org)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |                    |   #  |   #  |   #  |   #  |   #  |  #   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  FN  |   S  |   T  |   P  |   H  |   *  |                    |   *  |   F  |   P  |   L  |   T  |  D   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |-------.    ,-------|   *  |   R  |   B  |   G  |   S  |  Z   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | EXIT |  PWR |  A   |   O  | / LOWER /       \ RAISE\  |   E  |  U   | RES1 | RES2 |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_PLOVER] = LAYOUT( \
    STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,                STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC , \
    STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,               STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR , \
    XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,               STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                   EXT_PLV, STN_PWR, STN_A, STN_O, KC_LOWER,       KC_RAISE,  STN_E, STN_U,  STN_RE1, STN_RE2 \
),

[_DJMAX] = LAYOUT( \
QK_GESC, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
KC_TAB,   KC_F1,   KC_F10,    KC_E,   KC_E,     KC_1,                        KC_2,    KC_I,    KC_I, XXXXXXX, KC_PGUP, XXXXXXX, \
KC_TAB,   KC_F9,     KC_S,    KC_D,   KC_F,  XXXXXXX,                       KC_F5,    KC_J,    KC_K,    KC_L, KC_PGDN, KC_DEL, \
KC_LSFT,  KC_F8, XXXXXXX, XXXXXXX, KC_LALT,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, \
                 KC_QWERTY, _______, KC_SPC, KC_LCTL, KC_LOWER,     KC_RAISE, KC_RCTL , KC_ENT , _______, _______ \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        extern uint32_t oled_tap_timer;
        oled_tap_timer = timer_read32();
    }
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                if (is_alt_tab_active) {
                    unregister_code(KC_LALT);
                    is_alt_tab_active = false;
                }
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                if (is_alt_tab_active) {
                    unregister_code(KC_LALT);
                    is_alt_tab_active = false;
                }
                if (is_win_snap_active) {
                    tap_code_delay(KC_ESC,80);
                    unregister_code(KC_LGUI);
                    is_win_snap_active = false;
                }
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_DJMAX:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DJMAX);
            }
            return false;
        case KC_PLOVER:
            if (record->event.pressed) {
                layer_on(_PLOVER);
            }
            return false;
        case EXT_PLV:
            if (record->event.pressed) {
                layer_off(_PLOVER);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    //left encoder
    if (index == 0) {

        switch (get_highest_layer(layer_state)) {
            case _LOWER:
            case _RAISE:
                if (clockwise) {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    tap_code16(KC_TAB);
                } else {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    tap_code16(S(KC_TAB));
                }
                break;
            case _ADJUST:
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
	}
    //right encoder
    else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _LOWER:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            case _RAISE:
                if (clockwise) {
                    if (!is_win_snap_active) {
                        is_win_snap_active = true;
                        register_code(KC_LGUI);
                    }
                    tap_code16(KC_RIGHT);
                } else {
                    if (!is_win_snap_active) {
                        is_win_snap_active = true;
                        register_code(KC_LGUI);
                    }
                    tap_code16(KC_LEFT);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            }
    }
    return true;
}

#endif

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_UNSURE:
            break;
        case OS_MACOS:
        case OS_IOS:
            keymap_config.swap_lctl_lgui = true;
            break;
        case OS_WINDOWS:
        case OS_LINUX:
            keymap_config.swap_lctl_lgui = false;
            break;
    }
    return true;
}
// void keyboard_post_init_user(void) {
//   // Set default layer based on the detected OS after a 500 ms delay.
//   uint32_t get_host_os(uint32_t trigger_time, void* cb_arg) {
//     switch (detected_host_os()) {
//       case OS_UNSURE:  // Don't change default layer if unsure.
//         break;
//       case OS_MACOS:   // On Mac, set default layer to BASE_MAC.
//       case OS_IOS:
//         set_single_persistent_default_layer(BASE_MAC);
//         break;
//       default:         // On Windows and Linux, set to BASE_WIN.
//         set_single_persistent_default_layer(BASE_WIN);
//         break;
//     }
//     return 0;
//   }
//   defer_exec(500, get_host_os, NULL);
// }
