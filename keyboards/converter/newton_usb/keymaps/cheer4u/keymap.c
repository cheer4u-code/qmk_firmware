#include QMK_KEYBOARD_H

#define FN_CAPS LT(1, KC_CAPS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,---------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Del  |
     * |---------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| \ |
     * |---------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter |
     * |---------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift   |
     * |---------------------------------------------------------|
     * |Caps  |Al   |Gui  |      Space          |Lft|Rgt|Dn |Up  |
     * `---------------------------------------------------------'
     */
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
        FN_CAPS, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_LEFT, KC_RGHT, KC_DOWN, KC_UP),
    /*
     * ,---------------------------------------------------------.
     * |ESC| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins  |
     * |---------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |PSC|SCL|PAU|   |   |   |
     * |---------------------------------------------------------|
     * |Ctl   |VOD|VLU|MUT|   |   |   |   |   |   |   |   |      |
     * |---------------------------------------------------------|
     * |        |   |   |   |   |Bot|   |   |   |   |  \ |       |
     * |---------------------------------------------------------|
     * |      |Alt   |Menu|                     |Hom|End|PgD|PgU |
     * `---------------------------------------------------------'
     */
    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______,
        KC_RCTL, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,          _______,
        _______, KC_BTN1, KC_BTN2, _______, _______, QK_BOOT, _______, _______, _______, _______, _______,                   _______,
        _______, KC_RALT, KC_RGUI,                            _______,                            KC_HOME, KC_END,  KC_PGDN, KC_PGUP),
};
// clang-format on

const key_override_t tilde_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));
const key_override_t alt_grave_key_override = ko_make_basic(MOD_MASK_ALT, KC_ESC, A(KC_GRV));
const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DEL, KC_BSPC);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &tilde_key_override,
    &alt_grave_key_override,
    &backspace_key_override,
    NULL // Null terminate the array of overrides!
};
