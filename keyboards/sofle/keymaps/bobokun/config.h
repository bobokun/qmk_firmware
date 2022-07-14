
#pragma once

//#define USE_MATRIX_I2C


/* Select hand configuration */

//#define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS
//#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 100
#endif
#define ENCODER_DIRECTION_FLIP

#define RGBLIGHT_SLEEP
//
#define RGBLIGHT_LAYERS


/* ws2812 RGB LED */
#define RGB_DI_PIN D3

//#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 4
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SPLIT
#define RGBLED_NUM 72  // Number of LEDs
#define RGBLED_SPLIT { 36, 36 } // haven't figured out how to use this yet
//#define DRIVER_LED_TOTAL 72
//#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define RGBLIGHT_EFFECT_STATIC_LIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#endif

#define SPLIT_MODS_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define OLED_FONT_H "oled/oledfont.c"

#define CMK 1
#define NUM 2
#define SYM 3
#define FNC 4
