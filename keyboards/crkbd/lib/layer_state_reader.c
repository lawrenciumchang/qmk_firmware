
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

#define L_BASE 0
#define L_LOWER 8
#define L_RAISE 16
#define L_GAME 32
#define L_NAV 96
#define L_ADJUST 65536
#define L_ADJUST_TRI 65560

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
  case 1:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Base");
    break;
  case L_RAISE:
  case 17:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
  case 9:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_GAME:
  case 33:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game");
    break;
  case L_NAV:
  case 97:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Nav");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undefined-%ld", layer_state);
  }

  return layer_state_str;
}
