// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "backlight.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _LW 1
#define _RS 2
#define _SC 3
#define _SCCAM 4
#define _SCSETCAM 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, M(0),    KC_LGUI, KC_LALT, MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_RS] = { /* RAISE */
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(_SC), KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END}
},
[_LW] = { /* LOWER */
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(_SC), KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},
[_SC] = { /* STARCRAFT */
  {KC_ESC,  KC_1,    KC_2, KC_3, KC_4,  KC_T,       KC_F2,   KC_I,          KC_F9,   KC_F10,  KC_F11,  DF(_QW)},
  {KC_TAB,  KC_5,    KC_6, KC_7, KC_F,  KC_G,       KC_H,    KC_J,          KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_Z,    KC_X,    KC_8, KC_9, KC_V,  KC_B,       KC_N,    KC_M,          KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LALT, KC_A, KC_S, KC_F1, MO(_SCCAM), KC_LSFT, MO(_SCSETCAM), KC_TRNS, KC_TRNS, M(1),    M(0)   }
},
[_SCCAM] = { /* STARCRAFT RECALL CAM */
  {KC_NO,   KC_F5,   KC_F6,       KC_F7,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_NO,   KC_F8,   LSFT(KC_F5), LSFT(KC_F6), KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_NO,   KC_NO,   LSFT(KC_F7), LSFT(KC_F8), KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_NO,   KC_NO,   KC_NO,       KC_NO,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(3),    M(2)}
},
[_SCSETCAM] = { /* STARCRAFT SET CAM */
  {KC_NO,   LCTL(KC_F5), LCTL(KC_F6),       LCTL(KC_F7),       KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_NO,   LCTL(KC_F8), LCTL(LSFT(KC_F5)), LCTL(LSFT(KC_F6)), KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_NO,   KC_NO,       LCTL(LSFT(KC_F7)), LCTL(LSFT(KC_F8)), KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_NO,   KC_NO,       KC_NO,             KC_NO,             KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(3),    M(2)}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
        case 1:
          if (record->event.pressed) {
            return MACRO(I(1), T(ENT), T(G), T(L), T(SPC), T(H), T(F), T(ENT), END);
          }
        break;
        case 2:
          if (record->event.pressed) {
            return MACRO(I(1), T(ENT), T(G), T(G), T(ENT), T(F10), T(N), END);
          }
        break;
        case 3:
          if (record->event.pressed) {
            return MACRO(I(1), T(ENT), T(G), T(G), T(ENT), END);
          }
        break;
      }
    return MACRO_NONE;
};
