/* Copyright 2019 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum Layers {
    _BASE    = 0,
    _LOWER   = 1,
    _RAISE   = 2,
    _ADJUST  = 3,
    _FN      = 4,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define F_FN   LT(_FN, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_LSFT,  KC_A,     KC_S,     KC_D,     F_FN,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_SFTENT,
                                            LOWER,    KC_RALT,  KC_SPC,   KC_SPC,   RAISE
  ),
  
  [_LOWER] = LAYOUT(
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  _______,  _______,  _______,  _______,  _______,            KC_LEFT,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
    _______,  _______,  _______,  _______,  _______,  _______,            KC_HOME, S(KC_NUHS),KC_HOME,  KC_END,   _______,  _______,
                                            _______,  _______,  KC_ENT,   _______,   _______
  ),
  
  [_RAISE] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_TAB,   _______,  _______,  _______,  _______,  _______,            KC_F1,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,  KC_RGUI,  KC_RGUI,  KC_RALT,  KC_CAPS,  _______,            KC_F7,    KC_NUHS,  KC_NUBS,  KC_PGUP,  KC_PGDN,  _______,
                                            _______,  _______,  KC_BSPC,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  _______,  RGB_TOG,            _______,  _______,  _______,  _______,  _______,  _______,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,            RESET,    _______,  _______,  _______,  _______,  _______,
                                            _______,  _______,  _______,  _______,  _______
  ),
    [_FN] = LAYOUT(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_NO,    KC_NO,    KC_UP,    KC_NO,    KC_PSCR,  KC_NO,
    _______,  _______,  _______,  _______,  _______,  _______,            KC_NO,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO,    KC_BSLS,
    _______,  _______,  _______,  _______,  _______,  _______,            _______,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    _______,
                                            _______,  _______,  KC_BSPC,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    switch(get_highest_layer(layer_state)){
      case 0: //Layer 0
        if (!clockwise) { // Remove ! to reverse direction
          tap_code_delay(KC_AUDIO_VOL_UP, 10);
        } else {
          tap_code_delay(KC_AUDIO_VOL_DOWN, 10);
        }
        break;
      case 1: //Lower
        if (!clockwise) {
          tap_code(KC_WH_L);
        } else {
          tap_code(KC_WH_R);
        }
        break;
      case 4: //FN Layer
        if (!clockwise) {
          tap_code(KC_PGUP);
        } else {
          tap_code(KC_PGDN);
        }
        break;
      default:
        if (!clockwise) {
          tap_code_delay(KC_AUDIO_VOL_UP, 10);
        } else {
          tap_code_delay(KC_AUDIO_VOL_DOWN, 10);
        }
        break;
    }
  
  return true;}
}

// clang-format on

#if defined(PERMISSIVE_HOLD_PER_KEY)

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
            return true;
        case RSFT_T(KC_SPC):
            return true;
        default:
            return false;
    }
}

#endif

