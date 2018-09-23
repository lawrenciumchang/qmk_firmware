#include QMK_KEYBOARD_H

/* For some reason, the Gherkin flashes everything upside down, so all keymaps are made in reverse here. */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
		KC_RSFT, KC_M, KC_N, KC_B, LT(3, KC_SPC), LT(2, KC_ENT), KC_V, KC_C, KC_X, SFT_T(KC_Z),
    MO(1), KC_L, KC_K, KC_J, KC_H, KC_G, KC_F, KC_D, KC_S, LT(1, KC_A),
    KC_P, KC_O, KC_I, KC_U, KC_Y, KC_T, KC_R, KC_E, KC_W, KC_Q
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_CAPS, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS, KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_ESC,
    KC_TRNS, KC_RGHT, KC_DOWN, KC_LEFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_BSPC, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_QUOT, KC_SCLN, KC_DOT, KC_COMM, KC_TRNS, KC_TRNS, KC_PLUS, KC_UNDS, KC_TILD, KC_PIPE,
    KC_DQUO, KC_COLN, KC_RABK, KC_LABK, KC_RBRC, KC_LBRC, KC_EQL, KC_MINS, KC_GRV, KC_BSLS,
    KC_RPRN, KC_LPRN, KC_ASTR, KC_AMPR, KC_CIRC, KC_PERC, KC_DLR, KC_HASH, KC_AT, KC_EXLM
  ),

  [3] = LAYOUT_ortho_3x10(
    KC_SLSH, KC_3, KC_2, KC_1, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_VOLD,
    KC_QUES, KC_6, KC_5, KC_4, KC_RCBR, KC_LCBR, KC_MNXT, KC_MPLY, KC_MPRV, KC_VOLU,
    KC_0, KC_9, KC_8, KC_7, KC_6, KC_5, KC_4, KC_3, KC_2, KC_1
  )

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  keyevent_t event = record->event;
    (void)event;

  switch (id) {

  }
  return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  } else {
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 0); PORTB &= ~(1 << 0);
  } else {
    DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
