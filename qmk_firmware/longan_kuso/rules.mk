MCU                =   GD32VF103
BOARD              =   SIPEED_LONGAN_NANO
LTO_ENABLE         =   yes
EXTRAFLAGS         += -O3
# Default clock is 96MHz, 120MHz is out of spec but possible.
OPT_DEFS           += -DOVERCLOCK_120MHZ

# YAEMK source files
LAYOUTS = _4x12

# Debugging
EXTRAFLAGS     += -g
ALLOW_WARNINGS =   yes

# QMK features
REGISTER_MULTIPLE_KEYEVENTS_ENABLE = yes
CONSOLE_ENABLE                     = no
DEBOUNCE_TYPE                      = asym_eager_defer_pk
EEPROM_DRIVER                      = transient # eeprom emulation not yet available
ENCODER_ENABLE                     = yes
EXTRAKEY_ENABLE                    = yes
KEYBOARD_SHARED_EP                 = yes
MOUSEKEY_ENABLE                    = yes
NKRO_ENABLE                        = yes
OLED_DRIVER_ENABLE                 = no
RGBLIGHT_DRIVER                    = WS2812
RGBLIGHT_ENABLE                    = yes
VIA_ENABLE                         = no
WPM_ENABLE                         = no
WS2812_DRIVER                      = pwm
