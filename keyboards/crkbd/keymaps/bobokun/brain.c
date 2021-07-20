#include "bongo.c"

extern keymap_config_t keymap_config;

// Has RGB?
#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

// Has Oled?
#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;
#include <stdio.h>
#endif

uint8_t prev = _QWERTY;
uint32_t desired;
uint32_t default_desired;
int RGB_current_mode;

// clang-format on
void matrix_init_user(void) {
  desired = rgb_matrix_config.mode;
  default_desired = rgb_matrix_config.mode;
}


#ifdef OLED_DRIVER_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (is_keyboard_master()) {
//         return OLED_ROTATION_270;  // flips the display 270 degrees if master
//     }
//     return rotation;
// }
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  }
    else {
    return OLED_ROTATION_180;
  }
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    render_space();
    render_logo();
    render_space();
    render_default_layer_state();
}

void render_status_secondary(void) {
    /* Show Keyboard Layout  */
    render_anim();
}

// Oled Sleeps
void oled_task_user(void) {
   if (timer_elapsed32(oled_timer) > 60000) {
      oled_off();
      return;
}

// Establishing Sides
#ifndef SPLIT_KEYBOARD
    else { oled_on(); }
#endif

    if (is_keyboard_master()) {
        render_status_main();
    } else {
        render_status_secondary();
    }
}
#endif


int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

// Oled Wakes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
#endif
    // set_timelog();
}

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        desired = default_desired;
        rgb_matrix_mode_noeeprom(desired);
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case DJMAX:
          if (record->event.pressed) {
            desired = RGB_MATRIX_TYPING_HEATMAP;
            persistent_default_layer_set(1UL<<_DJMAX);
            update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
          }
          return false;
    case RGB_MOD:
          if (record->event.pressed) {
             uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                if (shifted) {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                    rgblight_step_reverse();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                    rgb_matrix_step_reverse();
#        endif
                } else {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                    rgblight_step();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                    rgb_matrix_step();
#        endif
                }
            desired = rgb_matrix_config.mode;
            default_desired = desired;
          }
          return false;
    case RGB_RMOD:
          if (record->event.pressed) {
             uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                if (shifted) {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                    rgblight_step();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                    rgb_matrix_step();
#        endif
                } else {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                    rgblight_step_reverse();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                    rgb_matrix_step_reverse();
#        endif
                }
            desired = rgb_matrix_config.mode;
            default_desired = desired;
          }
          return false;
  }


  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
	  switch (layer) {
        case _RAISE:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(128, 255, rgb_matrix_config.hsv.v);
            break;
        case _LOWER:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(28, 255, rgb_matrix_config.hsv.v);
            break;
        case _ADJUST:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(0, 0, rgb_matrix_config.hsv.v);
            break;
        default: //  for any other layers, or the default layer
            rgb_matrix_mode_noeeprom(desired);
            break;
	  }
  return state;
}
