#include "planck.h"

enum planck_layers {
  _BASE,
  _L1,
  _L2
};

enum planck_keycodes {
  BASE,
  L1,
  L2
};


#define __ KC_TRNS
#define L1 MO(_L1)
#define L2 MO(_L2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
 * ,-------------------------------------------------------------------------------------.
 * |  Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |   L1  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | "/L1  |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * |Sft/Esc|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |   L2  | Ctrl | Alt  | GUI  |    Enter    |    Space    | GUI  | Alt  | Caps |  L2   |
 * `-------------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_2x2u(
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    L1,            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(L1, KC_QUOT),
    SFT_T(KC_ESC), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    L2,            KC_LCTL, KC_LALT, KC_LGUI, KC_ENT,           KC_SPC,           KC_RGUI, KC_RALT, KC_CAPS, L2
),

/* Layer 1
 * ,-------------------------------------------------------------------------------------.
 * |  __   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |  Up  |   (  |   )  |  Del  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  __   |   \  |   `  |   -  |   =  |   [  |   ]  | Left | Down |Right |   *  |  __   |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * |  __   |   |  |   ~  |   _  |   +  |   {  |   }  |  __  |  __  |  __  |  __  |  __   |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |  __   |  __  |  __  |  __  |      __     |      __     |  __  |  __  |  __  |  __   |
 * `-------------------------------------------------------------------------------------'
 */
[_L1] = LAYOUT_planck_2x2u(
    __, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_UP,   KC_LPRN, KC_RPRN, KC_DEL,
		__, KC_BSLS, KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_ASTR, __,
		__, KC_PIPE, KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, __,      __,      __,      __,      __,
		__, __,      __,      __,      __,               __,               __,      __,      __,      __
),

/* Layer 2
 * ,-------------------------------------------------------------------------------------.
 * |  __   |  __  |  __  |  __  |  __  |  __  |  __  |  __  |  7   |  8   |  9   | Sleep |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  __   |  __  |  __  |  __  |  __  |  __  |  __  |  __  |  4   |  5   |  6   | VolUp |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * |  __   | Prev | Play | Next | Mute |  __  |  __  |  __  |  1   |  2   |  3   |VolDown|
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |  __   |  __  |  __  |  __  |      __     |      __     |  0   |  0   |  .   |  __   |
 * `-------------------------------------------------------------------------------------'
 */
[_L2] = LAYOUT_planck_2x2u(
    __, __,      __,      __,      __,      __, __,   __, KC_7, KC_8, KC_9,   KC_SLEP,
		__, __,      __,      __,      __,      __, __,   __, KC_4, KC_5, KC_6,   KC_VOLU,
		__, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, __, __,   __, KC_1, KC_2, KC_3,   KC_VOLD,
		__, __,      __,      __,      __,          __,       KC_0, KC_0, KC_DOT, __
)

};
