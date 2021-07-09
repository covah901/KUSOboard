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
    _DFn   = 0, /* Default normal */
    _DFa   = 1, /* Default ACAD */
    _LRn   = 2, /* Lower normal */
    _LRa   = 3, /* Lower ACAD */
    _RSn   = 4, /* Raise normal */
    _RSa   = 5, /* Raise ACAD */
    _FN    = 6, /* Fn layer */
    _KBD   = 7, /* Keyboard settings */
    _RGB   = 8, /* RGB light settings */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DFn] = LAYOUT(
    LT(_FN,KC_ESC),  KC_Q,            KC_W,            KC_E,      KC_R,             KC_T,                        KC_Y,            KC_U,      KC_I,       KC_O,             KC_P,            LT(_FN,KC_MINS),
    LT(_LRn,KC_ENT), KC_A,            KC_S,            KC_D,      KC_F,             KC_G,                        KC_H,            KC_J,      KC_K,       KC_L,             KC_SCLN,         LT(_LRn,KC_QUOT),
    LCTL_T(KC_TAB),  LGUI_T(KC_Z),    LALT_T(KC_X),    KC_C,      KC_V,             KC_B,                        KC_N,            KC_M,      KC_COMM,    RALT_T(KC_DOT),   RGUI_T(KC_SLSH), RCTL_T(KC_BSLS),
                                                                  LT(_LRn,KC_BSPC), LT(_RSn,KC_SPC), DF(_DFa),   LT(_RSn,KC_SPC), LT(_LRn,KC_BSPC)

  ),
  
  [_DFa] = LAYOUT( 
    LT(_FN,KC_ESC),  KC_Q,            KC_W,            KC_E,      KC_R,             KC_T,                        KC_COMM,         KC_7,      KC_8,       KC_9,             KC_PPLS,         LT(_FN,KC_PMNS),
    LT(_LRn,KC_ENT), KC_A,            KC_S,            KC_D,      KC_F,             KC_G,                        KC_DOT,          KC_4,      KC_5,       KC_6,             KC_PAST,         RSFT_T(KC_EQL),
    LCTL_T(KC_TAB),  LGUI_T(KC_Z),    LALT_T(KC_X),    KC_C,      LSFT_T(KC_V),     RSFT_T(KC_B),                KC_0,            KC_1,      KC_2,       RALT_T(KC_3),     RGUI_T(KC_PSLS), RCTL_T(KC_PENT),
                                                                  LT(_LRa,KC_BSPC), LT(_RSa,KC_SPC), DF(_DFn),   LT(_RSa,KC_SPC), LT(_LRa,KC_BSPC)
  ),
  
  [_LRn] = LAYOUT(
    KC_PLUS,         KC_EXLM,         KC_AT,           KC_HASH,   KC_DLR,           KC_PERC,                     KC_CIRC,         KC_AMPR,   KC_ASTR,     KC_LPRN,         KC_RPRN,         KC_TILD,
    LSFT_T(KC_EQL),  KC_1,            KC_2,            KC_3,      KC_4,             KC_5,                        KC_6,            KC_7,      KC_8,        KC_9,            KC_0,            RSFT_T(KC_GRV),
    LCTL_T(KC_LBRC), LGUI_T(KC_HOME), LALT_T(KC_PGDN), KC_PGUP,   KC_END,           KC_INS,                      KC_DEL,          KC_LEFT,   KC_UP,       RALT_T(KC_DOWN), RGUI_T(KC_RGHT), RCTL_T(KC_RBRC),
                                                                  MO(_KBD),         KC_PENT,         KC_SLCK,    KC_PENT,         MO(_KBD)
  ),
  
  [_LRa] = LAYOUT(
    KC_PLUS,         KC_F1,           KC_F2,           KC_F3,     KC_F4,            KC_F5,                       KC_F11,         KC_F12,     KC_F13,      KC_F14,          KC_F15,          KC_ESC,
    LSFT_T(KC_EQL),  KC_F6,           KC_F7,           KC_F8,     KC_F9,            KC_F10,                      KC_F16,         KC_F17,     KC_F18,      KC_F19,          KC_F20,          KC_RSFT,
    LCTL_T(KC_LBRC), KC_HOME,         KC_PGDN,         KC_PGUP,   KC_END,           KC_INS,                      KC_DEL,         KC_LEFT,    KC_UP,       KC_DOWN,         KC_RGHT,         RCTL_T(KC_RBRC),
                                                                  MO(_KBD),         KC_PENT,         KC_SLCK,    KC_PENT,        MO(_KBD)
  ),

  [_RSn] = LAYOUT(
    LSFT(KC_ESC),    LSFT(KC_Q),     LSFT(KC_W),      LSFT(KC_E), LSFT(KC_R),      LSFT(KC_T),                   RSFT(KC_Y),     RSFT(KC_U), RSFT(KC_I), RSFT(KC_O),      RSFT(KC_P),       KC_UNDS,
    LSFT(KC_ENT),    LSFT(KC_A),     LSFT(KC_S),      LSFT(KC_D), LSFT(KC_F),      LSFT(KC_G),                   RSFT(KC_H),     RSFT(KC_J), RSFT(KC_K), RSFT(KC_L),      KC_COLN,          KC_DQUO,
    C_S_T(KC_TAB),   LSFT(KC_Z),     LSFT(KC_X),      LSFT(KC_C), LSFT(KC_V),      LSFT(KC_B),                   RSFT(KC_N),     RSFT(KC_M), KC_LT,      LCA_T(KC_GT),    SGUI_T(KC_QUES),  C_S_T(KC_PIPE),
                                                                  KC_DEL,          MO(_KBD),        KC_CAPS,     MO(_KBD),       KC_DEL
  ),

  [_RSa] = LAYOUT(
    KC_MINS,         KC_P,           KC_O,            KC_I,       KC_U,            KC_Y,                         KC_SCLN,        KC_AMPR,    KC_ASTR,    KC_LPRN,         KC_RPRN,          KC_UNDS,
    KC_QUOT,         KC_SCLN,        KC_L,            KC_K,       KC_J,            KC_H,                         KC_COLN,        KC_DLR,     KC_PERC,    KC_CIRC,         KC_LT,            KC_GT,
    RCTL(KC_BSLS),   RGUI(KC_SLSH),  RALT(KC_DOT),    KC_COMM,    LSFT_T(KC_M),    RSFT_T(KC_N),                 KC_TILD,        KC_EXLM,    KC_AT,      KC_HASH,         KC_QUES,          KC_TAB,
                                                                  KC_DEL,          MO(_KBD),        KC_CAPS,     MO(_KBD),       KC_DEL
  ),

  [_FN] = LAYOUT(
    KC_TRNS,         KC_F1,          KC_F2,           KC_F3,      KC_F4,           KC_F5,                        KC_F6,          KC_F7,      KC_F8,      KC_F9,           KC_F10,           KC_TRNS,
    KC_NO,           KC_F11,         KC_F12,          KC_F13,     KC_F14,          KC_F15,                       KC_F16,         KC_F17,     KC_F18,     KC_F19,          KC_F20,           KC_NO,
    KC_NO,           KC_F21,         KC_F22,          KC_F23,     KC_F24,          KC_NO,                        KC_NO,          KC_NO,      KC_NO,      KC_NO,           KC_NO,            KC_NO,
                                                                  KC_NO,           KC_NO,           KC_NLCK,     KC_NO,          KC_NO
  ),

  [_KBD] = LAYOUT(
    KC_NO,           KC_NO,          KC_NO,           EEP_RST,    RESET,           KC_NO,                        KC_NO,          KC_NO,      KC_NO,      KC_NO,           KC_PSCR,          KC_NO,
    KC_NO,           KC_NO,          KC_SLCK,         DEBUG,      KC_NO,           KC_NO,                        KC_NO,          KC_NO,      KC_NO,      TG(_RGB),        KC_NO,            KC_NO,
    KC_NO,           KC_NO,          KC_NO,           KC_CAPS,    KC_NO,           KC_PAUS,                      KC_NLCK,        KC_NO,      KC_NO,      KC_NO,           KC_NO,            KC_NO,
                                                                  KC_TRNS,         KC_TRNS,         KC_MUTE,     KC_TRNS,        KC_TRNS
  ),

  [_RGB] = LAYOUT(
    RGB_TOG,         KC_NO,          KC_NO,           RGB_SPI,    KC_NO,           KC_NO,                        KC_NO,          KC_NO,      KC_NO,      KC_NO,           KC_NO,            KC_NO,
    RGB_MOD,         KC_NO,          RGB_SAI,         RGB_SPD,    KC_NO,           KC_NO,                        RGB_HUI,        KC_NO,      KC_NO,      TG(_RGB),        KC_NO,            KC_NO,
    RGB_RMOD,        KC_NO,          RGB_SAD,         KC_NO,      KC_NO,           RGB_VAI,                      RGB_HUD,        KC_NO,      KC_NO,      KC_NO,           KC_NO,            KC_NO,
                                                                  KC_NO,           RGB_VAD,         KC_NO,       KC_NO,          KC_NO
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    switch(get_highest_layer(layer_state)){
      case 0: //DFn
        if (!clockwise) { // Remove ! to reverse direction
          tap_code(KC_LEFT);
        } else {
          tap_code(KC_RGHT);
        }
        break;
      case 1: //DFa
        if (!clockwise) {
          tap_code(KC_LEFT);
        } else {
          tap_code(KC_RGHT);
        }
        break;
      case 2: //LRn
        if (!clockwise) {
          tap_code(KC_WH_L);
        } else {
          tap_code(KC_WH_R);
        }
        break;
      case 3: //LRa
        if (!clockwise) {
          tap_code(KC_WH_L);
        } else {
          tap_code(KC_WH_R);
        }
        break;
      case 4: //RSn
        if (!clockwise) {
          tap_code(KC_UP);
        } else {
          tap_code(KC_DOWN);
        }
        break;
      case 5: //RSa
        if (!clockwise) {
          tap_code(KC_UP);
        } else {
          tap_code(KC_DOWN);
        }
        break;
      case 6: //FN
        if (!clockwise) {
          tap_code(KC_BRIU);
        } else {
          tap_code(KC_BRID);
        }
        break;
      case 7: //KBD
        if (!clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;
      default:
        if (!clockwise) {
          tap_code(KC_WH_U);
        } else {
          tap_code(KC_WH_D);
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

