#include "clueboard.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define _BL 0
#define _FL 1
#define _RS 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,--------------------------------------------------------------------------.  ,----.
   * |Esc~|   1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   -|   =|    |  BS|  |PSCR|
   * |--------------------------------------------------------------------------|  |----|
   * |   Tab|   Q|   W|   E|   R|   T|   Y|   U|   I|   O|   P|   [|   ]|      \|  | DEL|
   * |--------------------------------------------------------------------------|  `----'
   * |Capslck|   A|   S|   D|   F|   G|   H|   J|   K|   L|   ;|   '|     |  Ent|
   * |-----------------------------------------------------------------------------.
   * |Shift|    |   Z|   X|   C|   V|   B|   N|   M|   ,|   .|   /|     |Shift|  UP|
   * |------------------------------------------------------------------------|----|----.
   * | Ctrl|  Gui|  Alt|      |    Space|    Space|    |  Alt| Ctrl|  _FL|LEFT|DOWN|RGHT|
   * `----------------------------------------------------------------------------------'
   */
[_BL] = KEYMAP(
  F(0),    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_TRNS, KC_BSPC,          KC_PSCR, \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,                    KC_DEL, \
  KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_TRNS,  KC_ENT,                             \
  KC_LSFT, KC_TRNS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_TRNS,  KC_RSFT,          KC_UP,            \
  KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS,          KC_SPC,KC_SPC,                        KC_TRNS,  KC_RALT,  KC_RCTL,  MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,--------------------------------------------------------------------------.  ,----.
   * |   `|  F1|  F2|  F3|  F4|  F5|  F6|  F7|  F8|  F9| F10| F11| F12|    | INS|  |BLIN|
   * |--------------------------------------------------------------------------|  |----|
   * |      |    |    |    |    |    |    |    |    |PMNS|  P7|  P8|  P9|   PAUS|  |    |
   * |--------------------------------------------------------------------------|  `----'
   * |    _RS|    |    |    |    |    |    |    |PAST|  P4|  P5|  P6|     | PPLS|
   * |-----------------------------------------------------------------------------.
   * |     |    |MPLY|MPRV|MNXT|VOLD|VOLU|MUTE|PSLS|  P1|  P2|   P3|     |PENT|PGUP|
   * |------------------------------------------------------------------------|----|----.
   * |     |     |     |     |         |         |     |   P0| PDOT|  _FL|HOME|PGDN| END|
   * `----------------------------------------------------------------------------------'
   */
[_FL] = KEYMAP(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,   KC_TRNS, KC_INS,           BL_STEP, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_P7,   KC_P8,  KC_P9,    KC_PAUS,                   KC_TRNS, \
  MO(_RS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAST, KC_P4,   KC_P5,   KC_P6,  KC_TRNS,  KC_PPLS,                            \
  KC_TRNS, KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, KC_PSLS, KC_P1,   KC_P2,   KC_P3,  KC_TRNS,  KC_PENT,           KC_PGUP,         \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,KC_TRNS,                         KC_TRNS, KC_P0,  KC_PDOT,  MO(_FL), KC_HOME,  KC_PGDN, KC_END),

  /* Keymap _RS: Reset layer
   * ,--------------------------------------------------------------------------.  ,----.
   * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |RTOG|  |RVAI|
   * |--------------------------------------------------------------------------|  |----|
   * |      |    |    |    |RESET|   |    |    |    |    |    |    |    |       |  |RVAD|
   * |--------------------------------------------------------------------------|  `----'
   * |    _RS|    |    |    |    |    |    |    |    |    |    |    |     |     |
   * |-----------------------------------------------------------------------------.
   * |  _FL|    |    |    |    |    |    |NLCK|    |    |    |    |     |  _FL|RSAI|
   * |------------------------------------------------------------------------|----|----.
   * |     |     |     |     |RGB_MOD  |RGB_MOD  |     |     |     |  _FL|RHUD|RSAD|RHUI|
   * `----------------------------------------------------------------------------------'
   */
[_RS] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, RGB_TOG,             RGB_VAI, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      RGB_VAD, \
  MO(_RS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                               \
  MO(_FL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(_FL),          RGB_SAI,             \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        RGB_MOD,   RGB_MOD,                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, RGB_HUD, RGB_SAD,    RGB_HUI),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
