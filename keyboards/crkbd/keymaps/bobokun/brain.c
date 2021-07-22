#include "bongo.c"

extern keymap_config_t keymap_config;
extern void eeconfig_read_rgb_matrix(void);

// Has Oled?
#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;
#include <stdio.h>
#endif

uint32_t rgb_mode;

#ifdef OLED_DRIVER_ENABLE
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
    render_default_layer_state();
    //render_space();
    render_layer_state();
    //render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    render_space();
    render_logo();
    render_space();
    render_wpm();
}

void render_status_secondary(void) {
    /* Show Keyboard Layout  */
    render_anim();
}

// Oled Sleeps
void oled_task_user(void) {
    if (is_keyboard_master()) {
        if (timer_elapsed(oled_timer) > OLED_TIMEOUT) {
            oled_off();
            return;
        }
        #ifndef SPLIT_KEYBOARD
        else {
            oled_on();
        }
        #endif
        render_status_main();
    } else {
        render_status_secondary();
    }
}

#endif


// Switches off Game layer when idle
void matrix_scan_user(void) {
     if (timer_elapsed32(oled_timer) > 300000 && timer_elapsed32(oled_timer) < 499999 ) {
     if (get_highest_layer(layer_state) == _DJMAX) {
          layer_off(_DJMAX);
          layer_on(_QWERTY);
       }
         return;
    }
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

//Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

// RGB
void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
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
            rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
            persistent_default_layer_set(1UL<<_DJMAX);
            update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
          }
          return false;
  }
  return true;
}


#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
layer_state_t layer_state_set_user(layer_state_t state) {
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
        case _DJMAX:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
            break;
        default: //  for any other layers, or the default layer
            eeconfig_read_rgb_matrix();
            rgb_matrix_mode_noeeprom(rgb_matrix_config.mode);
            break;
	  }
  return state;
}
#endif

#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif
