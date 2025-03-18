#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "i18n.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_0_0_255,
};


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// F22 - QK_REP
// %s/QK_REP/QK_REP/g
// F23 - QK_AREP
// %s/QK_AREP/QK_AREP/g
// F24 - QK_LEAD
// %s/QK_LEAD/QK_LEAD/g
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,        
    ALL_T(KC_ESCAPE),MT(MOD_LALT, KC_A),MT(MOD_LCTL, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,           KC_H,           MT(MOD_LSFT, KC_J),MT(MOD_LGUI, KC_K),MT(MOD_LCTL, KC_L),MT(MOD_LALT, KC_SCLN),MEH_T(KC_QUOTE),
    MT(MOD_LSFT, KC_TAB),KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
    CW_TOGG,        LGUI(KC_SPACE), KC_LEFT_CTRL,   KC_LEFT_ALT,    LOWER,          MT(MOD_LSFT, KC_SPACE),KC_NO,          RAISE,          KC_LEFT_GUI,    QK_REP,         QK_AREP,         QK_LEAD
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, CW_TOGG,        KC_PSCR,        KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_LEFT),  LGUI(KC_DOWN),  LGUI(KC_UP),    LGUI(KC_RIGHT), LGUI(KC_SPACE), KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MAC_UNDO,    KC_MAC_CUT,     KC_MAC_COPY,    KC_MAC_PASTE,   KC_TRANSPARENT, LALT(KC_LEFT),  LALT(KC_DOWN),  LALT(KC_UP),    LALT(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_DQUO,        KC_PIPE,        KC_HASH,        KC_TILD,        KC_NO,          KC_AT,          KC_UNDS,        KC_CIRC,        KC_DLR,         KC_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LABK,        KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_EQUAL,       KC_COLN,        KC_RPRN,        KC_RCBR,        KC_RBRC,        KC_RABK,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_MINUS,       KC_GRAVE,       KC_ASTR,        KC_PERC,        KC_NO,          KC_AMPR,        KC_NO,          KC_BSLS,        KC_QUES,        KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_NO,          KC_TRANSPARENT, KC_0,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER4] = LAYOUT_planck_grid(
    KC_TRANSPARENT, RGB_SAI,        RGB_HUI,        RGB_VAI,        RGB_SPI,        KC_TRANSPARENT, AU_TOGG,        MU_TOGG,        MU_NEXT,        KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_SAI,        RGB_HUD,        RGB_VAD,        RGB_SPD,        KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, HSV_0_0_255,    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_SLD,        RGB_MODE_FORWARD,KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER5] = LAYOUT_planck_grid(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_NO,          
    KC_NO,          KC_NO,          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_NO,          KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_BTN3,     KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    TO(0),          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_MS_BTN1,     KC_TRANSPARENT, KC_NO,          KC_MS_BTN2,     KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),

  [_LAYER6] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, EE_CLR,         QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(4),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, CM_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, MAGIC_TOGGLE_NKRO,TO(5),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_PRINT
  ),

};

const uint16_t PROGMEM combo0[] = { MT(MOD_LSFT, KC_SPACE), KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_GRAVE, KC_Q, KC_P, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_DELETE),
    COMBO(combo1, TG(6)),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {0,0,255}, {0,0,255}, {188,255,255}, {188,255,255}, {0,0,255}, {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,255}, {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [2] = { {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {74,255,255}, {0,0,255}, {74,255,255}, {74,255,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [3] = { {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [4] = { {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {74,255,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,255}, {41,255,255}, {41,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {131,255,255}, {0,0,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [5] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {16,255,255}, {41,255,255}, {74,255,255}, {0,0,255}, {0,0,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {0,0,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [6] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,245,245}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {41,255,255}, {74,255,255}, {16,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    case HSV_0_0_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(0,0,255);
        }
        return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



// Custom

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_planck_grid(
    'L','L','L','L','L','L','R','R','R','R','R','R',        
    'L','L','L','L','L','L','R','R','R','R','R','R',        
    'L','L','L','L','L','L','R','R','R','R','R','R',        
    'L','L','L','L','L','*','*','R','R','R','R','R'        
  );


bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
  // Exceptionally allow some one-handed chords for hotkeys.
  switch (tap_hold_keycode) {
    case LSFT_T(KC_J):
      if (other_keycode == KC_SCLN) {
        return true;
      }
      break;
    // case LGUI_T(KC_D):
    //   if (other_keycode == KC_A) {
    //     return true;
    //   }
    //   break;
    // case LCTL_T(KC_S):
    //   if (other_keycode == KC_D) {
    //     return true;
    //   }
    //   break;
    case LCTL_T(KC_L):
      if (other_keycode == KC_U) {
        return true;
      }
      break;
  }
  // Otherwise defer to the opposite hands rule.
  return get_chordal_hold_default(tap_hold_record, other_record);
}

void leader_start_user(void) {
  // Do something when the leader key is pressed
}

void leader_end_user(void) {
  if (leader_sequence_two_keys(KC_L, KC_W)) {
    // Toggle Windows Layer
    layer_invert(1);
  } else if (leader_sequence_two_keys(KC_L, KC_R)) {
    layer_invert(7);
  } else if (leader_sequence_two_keys(KC_L, KC_V)) {
    layer_invert(5);
  } else if (leader_sequence_two_keys(KC_L, KC_M)) {
    layer_move(0);
  } else if (leader_sequence_two_keys(KC_C, KC_W)) {
    // CW_TOGG
    caps_word_toggle();
  } else if (leader_sequence_two_keys(KC_C, KC_A)) {
    SEND_STRING("=>");
  } else if (leader_sequence_two_keys(KC_C, KC_N)) {
    SEND_STRING("!=");
  } else if (leader_sequence_two_keys(KC_C, KC_E)) {
    SEND_STRING("==");
  } else if (leader_sequence_two_keys(KC_C, KC_B)) {
    SEND_STRING("{}" SS_TAP(X_LEFT));
  } else if (leader_sequence_two_keys(KC_C, KC_C)) {
    SEND_STRING("()" SS_TAP(X_LEFT));
  } else if (leader_sequence_two_keys(KC_C, KC_S)) {
    SEND_STRING("[]" SS_TAP(X_LEFT));
  } else if (leader_sequence_two_keys(KC_C, KC_P)) {
    SEND_STRING("<>" SS_TAP(X_LEFT));
  } else if (leader_sequence_two_keys(KC_S, KC_S)) {
    if (layer_state_is(1)) {
      tap_code16(KC_PSCR);
    } else {
      tap_code16(LGUI(LSFT(KC_4)));
    }
  } else if (leader_sequence_one_key(KC_X)) {
    tap_code16(KC_DELETE);
  } else if (leader_sequence_two_keys(KC_T, KC_T)) {
    tap_code16(LCTL(KC_A));
  } else if (leader_sequence_two_keys(KC_T, KC_W)) {
    tap_code16(LALT(KC_A));
  } else if (leader_sequence_two_keys(KC_V, KC_Y)) {
    SEND_STRING(SS_TAP(X_ESCAPE) "gg" SS_LSFT("v") SS_LSFT("g"));
  }
}
