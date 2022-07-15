# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
LTO_ENABLE = yes
SPLIT_KEYBOARD = yes
COMBO_ENABLE = no
DEFAULT_FOLDER = keebio/kbo5000/rev1

# The following were added in an attempt to fix a crash
SHARED_EP_ENABLE = yes
KEYBOARD_SHARED_EP = yes
MOUSE_SHARED_EP = no
WAIT_FOR_USB = yes
