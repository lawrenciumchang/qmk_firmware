// Below layout is based upon /u/That-Canadian's planck layout
#include "launchpad.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

#define _FUNC 15

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

enum custom_keycodes {
  SNAPCAM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------------------------.
 * |    Play/Pause   |  Next Track |
 * |-----------------+-------------|
 * |  Brightness Up  |   Vol Up    |
 * |-----------------+-------------|
 * | Brightness Down |   Vol Down  |
 * |-----------------+-------------|
 * |   FUNC Layer    |    Mute     |
 * `-------------------------------'
 */
[_QWERTY] = LAYOUT(   \
    KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD, \
    KC_PAUS,             KC__VOLUP, \
    KC_SLCK,             KC__VOLDOWN, \
    MO(_FUNC),           KC__MUTE  \
),

/* Function
 * ,--------------------.
 * | Prev Track |  Up   |
 * |------------+-------|
 * |    Left    | Right |
 * |------------+-------|
 * | Snap Camera| Down  |
 * |------------+-------|
 * |            | Sleep |
 * `--------------------'
 */
[_FUNC] = LAYOUT( \
    KC_MEDIA_REWIND, KC_UP, \
    KC_LEFT,    KC_RIGHT, \
    SNAPCAM,    KC_DOWN, \
    _______,    KC_SYSTEM_SLEEP \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SNAPCAM:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_LALT);
        register_code(KC_KP_0);
      } else {
        unregister_code(KC_LCTRL);
        unregister_code(KC_LALT);
        unregister_code(KC_KP_0);
      }
      return false;
      break;
  }
  return true;
}
