#include QMK_KEYBOARD_H

#include "keymap_japanese.h"

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
     * |Caps  |Alt  |Gui  |      Space          |Lft|Rgt|Dn |Up  |
     * `---------------------------------------------------------'
     */
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
        FN_CAPS, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_LEFT, KC_RGHT, KC_DOWN, KC_UP),
    /*
     * ,---------------------------------------------------------.
     * |ESC| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins  |
     * |---------------------------------------------------------|
     * |Bspc |*1 |*2 |   |   |   |   |   |PSC|SCL|PAU|   |   |   |
     * |---------------------------------------------------------|
     * |Ctrl  |VOD|VLU|MUT|   |   |MsL|MsD|MsU|MsR|   |   |      |
     * |---------------------------------------------------------|
     * |        |Bt1|Bt2|   |   |Bot|   |   |   |   |  \ |       |
     * |---------------------------------------------------------|
     * |      |Alt  |Menu |                     |Hom|End|PgD|PgU |
     * `---------------------------------------------------------'
     * *1: Turn off key overrides
     * *2: Turn on key overrides
     */
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
        _______, KO_OFF,  KO_ON,   _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______,
        KC_RCTL, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,          _______,
        _______, KC_BTN1, KC_BTN2, _______, _______, QK_BOOT, _______, _______, _______, _______, _______,                   _______,
        _______, KC_RALT, KC_RGUI,                            _______,                            KC_HOME, KC_END,  KC_PGDN, KC_PGUP),
};
// clang-format on

const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, JP_AT);
const key_override_t circ_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, JP_CIRC);
const key_override_t ampr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, JP_AMPR);
const key_override_t astr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, JP_ASTR);
const key_override_t lprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, JP_LPRN);
const key_override_t rprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, JP_RPRN);
const key_override_t unds_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, JP_UNDS);
const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0, KC_EQL, JP_EQL, ~0, MOD_MASK_SHIFT);
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, JP_PLUS);
const key_override_t lbrc_key_override = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, ~0, MOD_MASK_SHIFT);
const key_override_t lcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, JP_LCBR);
const key_override_t rbrc_key_override = ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, ~0, MOD_MASK_SHIFT);
const key_override_t rcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, JP_RCBR);
const key_override_t bsls_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, ~0, MOD_MASK_SHIFT);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE);
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);
const key_override_t quot_key_override = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_QUOT, ~0, MOD_MASK_SHIFT);
const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO);
const key_override_t grv_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_GRV, ~0, MOD_MASK_SHIFT | MOD_MASK_ALT);
const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, JP_TILD);
const key_override_t zkhk_key_override = ko_make_basic(MOD_MASK_ALT, KC_GRV, JP_ZKHK);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &at_key_override,
    &circ_key_override,
    &ampr_key_override,
    &astr_key_override,
    &lprn_key_override,
    &rprn_key_override,
    &unds_key_override,
    &eql_key_override,
    &plus_key_override,
    &lbrc_key_override,
    &lcbr_key_override,
    &rbrc_key_override,
    &rcbr_key_override,
    &bsls_key_override,
    &pipe_key_override,
    &coln_key_override,
    &quot_key_override,
    &dquo_key_override,
    &grv_key_override,
    &tild_key_override,
    &zkhk_key_override,
    NULL // Null terminate the array of overrides!
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
    case KC_DEL:
        {
            static bool bskey_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_BSPC);
                    bskey_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (bskey_registered) {
                    unregister_code(KC_DEL);
                    bskey_registered = false;
                    return false;
                }
            }
            return true;
        }
    }
    return true;
};
