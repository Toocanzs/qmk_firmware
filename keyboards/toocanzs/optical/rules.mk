# MCU name
MCU = STM32F303

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = yes       # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes          # Enable N-Key Rollover

AUDIO_ENABLE = no          # Audio output

COMBO_ENABLE = no
LTO_ENABLE = yes

ENCODER_ENABLE = no

LAYOUTS_HAS_RGB = no
RGB_MATRIX_SUPPORTED = no
RGBLIGHT_SUPPORTED = no
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BAKCLIGHT_SUPPORTED = no

EXTRAFLAGS += -flto
CUSTOM_MATRIX = yes
SRC += matrix.c