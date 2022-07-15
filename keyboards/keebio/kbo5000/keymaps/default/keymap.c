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

//make keebio/kbo5000/rev1:default:flash --jobs 16
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_ansi(
    KC_GRV,             KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS,
    LCTL(KC_S),  KC_ESC,  KC_1,    KC_2,       KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_CAPS, KC_DEL,  KC_INS,
    LCTL(KC_4),      KC_TAB,  KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_PGUP,
    LCTL(KC_X),  KC_BSPC, KC_A,    KC_S,       KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_END,  KC_PGDN,
    LCTL(KC_V),  KC_LSFT,          KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,
    LCTL(KC_C),  KC_LCTL, _______, KC_LGUI, KC_LALT,   KC_SPC,  KC_SPC,                   REPEAT,  MO(LAYER_SYMBOLS), DF(LAYER_CANARY), KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [LAYER_SYMBOLS] = LAYOUT_ansi(
    QK_REBOOT,        KC_CAPS, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    QK_BOOTLOADER, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,       _______, _______, KC_PLUS,   KC_LT, KC_ASTR, KC_EXLM,                   KC_AMPR, KC_LPRN, KC_LCBR, KC_LBRC, _______, _______, _______, _______, _______, _______,
    _______,       _______, KC_QUES, KC_MINS,   KC_GT, KC_SLSH, KC_PIPE,                   KC_HASH, KC_RPRN, KC_RCBR, KC_RBRC, _______, _______,          _______, _______, _______,
    _______,       _______,          _______, KC_COLN,  KC_EQL, KC_SCLN, KC_BSLS,          KC_DQUO, KC_UNDS, _______, _______, _______,          _______,          _______,
    _______,       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,                   _______, _______, _______, _______
  ),

  [LAYER_CANARY] = LAYOUT_ansi(
    _______,          _______, _______, _______, _______, _______, _______,                _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,    KC_W,    KC_L,    KC_Y,    KC_P,    KC_K,                            KC_Z,    KC_X,    KC_O,    KC_U, KC_SCLN, _______, _______, _______, _______, _______,
    _______, _______,    KC_C,    KC_R,    KC_S,    KC_T,    KC_B,                            KC_F,    KC_N,    KC_E,    KC_I,    KC_A, _______,          _______, _______, _______,
    _______, _______,             KC_J,    KC_V,    KC_D,    KC_G,  KC_Q,                     KC_M,    KC_H, KC_SLSH, KC_COMM, KC_DOT,          _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,                          _______, _______, DF(LAYER_QWERTY), _______,                   _______, _______, _______, _______
  ),
  [LAYER_QWERTY_HOTKEYS] = LAYOUT_ansi(
    KC_GRV,             KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS,
    _______,  KC_ESC,  KC_1,    KC_2,       KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_CAPS, KC_DEL,  KC_INS,
    _______,  KC_TAB,  KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_PGUP,
    _______,  KC_BSPC, KC_A,    KC_S,       KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_END,  KC_PGDN,
    _______,  KC_LSFT,          KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,
    _______,  KC_LCTL, _______, KC_LGUI, KC_LALT,   KC_SPC,  KC_SPC,                   REPEAT, _______,  _______, KC_RGUI,                   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
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

/*void post_process_record_user(uint16_t keycode, keyrecord_t *record) {  
};*/