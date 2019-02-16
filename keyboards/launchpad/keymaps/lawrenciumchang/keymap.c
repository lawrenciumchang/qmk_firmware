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
 * |            | Down  |
 * |------------+-------|
 * |            | Sleep |
 * `--------------------'
 */
[_FUNC] = LAYOUT( \
    KC_MEDIA_REWIND, KC_UP, \
    KC_LEFT,    KC_RIGHT, \
    _______,    KC_DOWN, \
    _______,    KC_SYSTEM_SLEEP \
)

};

void matrix_init_user(void) {

}
