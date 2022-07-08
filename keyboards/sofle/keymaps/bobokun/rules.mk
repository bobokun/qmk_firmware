# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE           = no  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE            = no  # Mouse keys(+4700)
EXTRAKEY_ENABLE            = yes # Audio control and System control(+450)
COMMAND_ENABLE             = no  # Commands for debug and configuration
NKRO_ENABLE                = no  # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE           = no  # Enable keyboard backlight functionality
MIDI_ENABLE                = no  # MIDI controls
AUDIO_ENABLE               = no  # Audio output on port C6
UNICODE_ENABLE             = no  # Unicode
BLUETOOTH_ENABLE           = no  # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE            = yes  # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE          = no  # Enable one-hand typing
TAP_DANCE_ENABLE 		   = no  # Enable double tapping function
ENCODER_ENABLE 			   = yes

RGB_MATRIX_ENABLE 		   = no
RGB_MATRIX_DRIVER 		   = WS2812

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
#SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
#TAP_DANCE_ENABLE= yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

EXTRAFLAGS += -flto

WPM_ENABLE = yes
LTO_ENABLE = yes

#Debug options
VERBOSE = no
CONSOLE_ENABLE = no # Console for debug(+400)
COMMAND_ENABLE = no
