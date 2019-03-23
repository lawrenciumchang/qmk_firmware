#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _L1 1
#define _L2 2

#define __ KC_TRNS
#define L1 MO(_L1)
#define L2 MO(_L2)

// Tap Dance Declarations
enum tap_dance {
  TD_LAYER,
};

void td_finished(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 1) {
    layer_on(1);
  } else {
    layer_on(2);
  }
}

void td_reset(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
      layer_off(1);
    } else {
      layer_off(2);
    }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
    Base Layer
  */
  [_BASE] = LAYOUT_arrow(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    TD(TD_LAYER), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(L1, KC_QUOT),
    SFT_T(KC_ESC), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_ENT,  KC_SPC,                    KC_RGUI, KC_RALT,  KC_CAPS, L2
  ),

  /*
    Layer 1
  */
  [_L1] = LAYOUT_arrow(
    __, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_UP,   KC_LPRN, KC_RPRN, KC_DEL,
		__, KC_BSLS, KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_ASTR, __,
		__, KC_PIPE, KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, __,      __,      __,      __,      __,
		__, __,      __,      __,      __,      __,      __,      __,      __
  ),

  /*
    Layer 2
  */
  [_L2] = LAYOUT_arrow(
    KC_SLEP, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_6,   KC_7, KC_8, KC_9, KC_0,    KC_BSPC,
		__,      __,      __,      __,      __,      __,   KC_DOT, KC_4, KC_5, KC_6, KC_PAUS, KC_VOLU,
		__,      KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, __,   KC_0,   KC_1, KC_2, KC_3, KC_SLCK, KC_VOLD,
		__, __,      __,      __,      __,      __,      __,      __,      __
  )

};
