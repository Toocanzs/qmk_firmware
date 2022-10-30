#include QMK_KEYBOARD_H

enum custom_keycodes {
    REPEAT = SAFE_RANGE,
};
enum My_Layers {
    LAYER_QWERTY = 0,
    LAYER_SYMBOLS,
    LAYER_CANARY,
    LAYER_QWERTY_HOTKEYS
};


#define LAYOUT_ansi( \
_KC_ESC,       _KC_F1, _KC_F2, _KC_F3, _KC_F4, _KC_F5, _KC_F6,  _KC_F7, _KC_F8, _KC_F9, _KC_F10, _KC_F11, _KC_F12, _KC_PSCR, _KC_SLCK, _KC_PAUS, \
_KC_GRV, _KC_1, _KC_2, _KC_3, _KC_4, _KC_5, _KC_6, _KC_7, _KC_8, _KC_9, _KC_0, _KC_MINS, _KC_EQL, _KC_BSPC, _KC_DEL, _KC_INS, \
_KC_TAB,  _KC_Q,    _KC_W,       _KC_E,    _KC_R,    _KC_T,    _KC_Y,  _KC_U,    _KC_I,    _KC_O,    _KC_P,    _KC_LBRC, _KC_RBRC, _KC_BSLS, _KC_HOME, _KC_PGUP, \
_KC_CAPS, _KC_A,    _KC_S,       _KC_D,    _KC_F,    _KC_G,    _KC_H,  _KC_J,    _KC_K,    _KC_L,    _KC_SCLN, _KC_QUOT,          _KC_ENT,  _KC_END,  _KC_PGDN, \
_KC_LSFT,          _KC_Z,       _KC_X,    _KC_C,    _KC_V,    _KC_B,  _KC_N,    _KC_M,    _KC_COMM, _KC_DOT,  _KC_SLSH,          _KC_RSFT,          _KC_UP, \
_KC_LCTL, _KC_LGUI, _KC_LALT, _KC_SPC, _LAYER,  _REPEAT, _IDK, _KC_RGUI, _KC_RCTL, _KC_LEFT, _KC_DOWN, _KC_RGHT \
) \
{ \
  { _KC_F3,   _KC_F11,  _KC_GRV,  _KC_MINS, _KC_TAB, _KC_I,    _KC_CAPS, _KC_K,    _KC_LSFT, _KC_COMM,    _KC_LCTL, _IDK }, \
  { _KC_F2,   _KC_F10,  _KC_1,    _KC_0,    _KC_Q,   _KC_O,    _KC_A,    _KC_L,    _KC_Z,      _KC_DOT,   _KC_LGUI, _______}, \
  { _KC_F1,   _KC_F9,   _KC_2,    _KC_9 ,   _KC_W,   _KC_P,    _KC_S,    _KC_SCLN, _KC_X,      _KC_SLSH,  _KC_LALT, _______}, \
  { _KC_ESC,  _KC_F8,   _KC_3,    _KC_8 ,   _KC_E,   _KC_LBRC, _KC_D,    _KC_QUOT, _KC_C,      _KC_RSFT,  _KC_SPC,  _KC_RGHT}, \
  { _KC_F7,   _KC_PAUS, _KC_4,    _KC_EQL,  _KC_R,   _KC_RBRC, _KC_F,    _KC_ENT,  _KC_V,      _______,    _LAYER,  _KC_DOWN }, \
  { _KC_F6,   _KC_SLCK, _KC_5,    _KC_BSPC, _KC_T,   _KC_BSLS, _KC_G,    _KC_PGUP, _KC_B,      _______,   _REPEAT,  _KC_LEFT }, \
  { _KC_F5,   _KC_PSCR, _KC_6,    _KC_INS,  _KC_Y,   _KC_DEL,  _KC_H,    _KC_PGDN, _KC_N,      _______,   _IDK,     _KC_RCTL }, \
  { _KC_F4,   _KC_F12,  _KC_7,    _KC_HOME, _KC_U,   _KC_END,  _KC_J,    _______, _KC_M,       _KC_UP,    _KC_RGUI,  _______ } \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_QWERTY] = LAYOUT_ansi(KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, 
                    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_INS, 
                    KC_TAB,  KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_PGUP, 
                    KC_CAPS, KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_END,  KC_PGDN, 
                    KC_LSFT,          KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP, 
                    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, REPEAT, MO(LAYER_SYMBOLS), DF(LAYER_CANARY), KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
    [LAYER_SYMBOLS] = LAYOUT_ansi(_______,       _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, 
                    _______, QK_REBOOT, QK_BOOTLOADER, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
                    _______, _______,    _______,       _______,    _______,    _______,    _______,  _______,    _______,    _______,   _______, _______, _______, _______, _______,  _______, 
                    _______, _______,    _______,       _______,    _______,    _______,    _______,  _______,    _______,    _______,   _______, _______,          _______,  _______, _______, 
                    _______,             _______,       _______,    _______,    _______,    _______,  _______,    _______,    _______,   _______, _______,          _______,           _______, 
                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______),
    [LAYER_CANARY] = LAYOUT_ansi(_______,       _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, 
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
                    _______, KC_W,    KC_L,  KC_Y,    KC_P,    KC_K,    KC_Z,  KC_X,    KC_O,    KC_U,   KC_SCLN, _______, _______, _______, _______,  _______, 
                    _______, KC_C,    KC_R,  KC_S,    KC_T,    KC_B,    KC_F,  KC_N,    KC_E,    KC_I,   KC_A, _______,          _______,  _______, _______, 
                    _______,          KC_J,  KC_V,    KC_D,    KC_G,    KC_Q,  KC_M,    KC_H,    KC_SLSH,   KC_COMM, KC_DOT,          _______,           _______, 
                    _______, _______, _______, _______, _______,    _______, DF(LAYER_QWERTY), _______, _______, _______, _______, _______),
    [LAYER_QWERTY_HOTKEYS] = LAYOUT_ansi(KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, 
                    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_INS, 
                    KC_TAB,  KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_PGUP, 
                    KC_CAPS, KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_END,  KC_PGDN, 
                    KC_LSFT,          KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP, 
                    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, _______,  REPEAT, _______, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
};

uint16_t last_key_pressed = KC_NO;
bool next_shift = false;

#define DEFAULT_LAYER_IS(layer) (biton32(default_layer_state) == layer)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool default_layer_is_qwerty = DEFAULT_LAYER_IS(LAYER_QWERTY);
    
    if ((get_mods() & MOD_MASK_CTRL) && !default_layer_is_qwerty) {
        set_oneshot_layer(LAYER_QWERTY_HOTKEYS, ONESHOT_START);
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
    
    if (record->event.pressed) {
        if (next_shift) {
            next_shift = false;
            add_oneshot_mods(MOD_LSFT);
        }
        if (keycode == REPEAT) {
            if ((last_key_pressed == KC_SPC || last_key_pressed == KC_ENTER) && !default_layer_is_qwerty) {
                next_shift = true;
            }
            else {
                tap_code(last_key_pressed);
            }
            return false;
        }
        else {
            last_key_pressed = keycode;
            return true;
        }
    }

    return true;
};
