#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _L1 1
#define _L2 2

enum custom_keycodes {
  BASE,
  L1,
  L2
};

#define __ KC_TRNS
#define L1 MO(_L1)
#define L2 MO(_L2)

// NOTE: Keymappings are mirrored by row. For some reason,zgbatttttttrrffrttttttttttb flashing to the Levinson mirrored everything on both master and slave unit.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ortho_4x12( \
  KC_BSPC,  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    KC_TAB, \
  LT(L1, KC_QUOT),  KC_SCLN,    KC_L,    KC_K,    KC_J,    KC_H,    KC_G,    KC_F,    KC_D,    KC_S,    KC_A, L1, \
  KC_RSFT, KC_SLSH,    KC_DOT,    KC_COMM,    KC_M,    KC_N,    KC_B,    KC_V,    KC_C, KC_X,  KC_Z, SFT_T(KC_ESC) , \
  L2,  KC_CAPS, KC_RALT, KC_RGUI, KC_SPC,   KC_SPC,  KC_ENT,  KC_ENT,   KC_LGUI, KC_LALT, KC_LCTL,   L2 \
),

[_L1] = LAYOUT_ortho_4x12( \
  KC_DEL,  KC_RPRN,    KC_LPRN,    KC_UP,    KC_AMPR,    KC_CIRC,    KC_PERC,    KC_DLR,    KC_HASH,    KC_AT,    KC_EXLM,    __, \
  __,  KC_ASTR,    KC_RGHT,    KC_DOWN,    KC_LEFT,    KC_RBRC,    KC_LBRC,    KC_EQL,    KC_MINS,    KC_GRV,    KC_BSLS, __, \
  __, __,    __,    __,    __,    KC_RCBR,    KC_LCBR,    KC_PLUS,    KC_UNDS, KC_TILD,  KC_PIPE, __ , \
  __,  __, __, __, __,   __,  __,  __,   __, __, __,   __ \
),

[_L2] = LAYOUT_ortho_4x12( \
  KC_BSPC,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_SLEP, \
  KC_VOLU,  KC_PAUS,    KC_6,    KC_5,    KC_4,    KC_DOT,    __,    __,    __,    __,    __, __, \
  KC_VOLD, KC_SLCK,    KC_3,    KC_2,    KC_1,    KC_0,    __,    KC_MUTE,    KC_MNXT, KC_MPLY,  KC_MPRV, __ , \
  __,  __, __, __, __,   __,  __,  __,   __, __, __,   __ \
)

};
