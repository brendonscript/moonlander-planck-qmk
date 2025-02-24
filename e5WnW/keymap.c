#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"



//Custom



enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,        
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
    CW_TOGG,        KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    LOWER,          KC_SPACE,       KC_NO,          RAISE,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, 
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_UNDS,        KC_PLUS,        KC_LCBR,        KC_RCBR,        KC_PIPE,        
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NONUS_HASH,  KC_NUBS,        KC_HOME,        KC_END,         KC_TRANSPARENT, 
    KC_COMMA,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_MINUS,       KC_EQUAL,       KC_LBRC,        KC_RBRC,        KC_BSLS,        
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT, KC_PAGE_UP,     KC_PGDN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_DELETE,      KC_TRANSPARENT, QK_AUDIO_ON,    QK_AUDIO_OFF,   AU_TOGG,        KC_TRANSPARENT, TOGGLE_LAYER_COLOR,RGB_TOG,        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, QK_BOOT,        
    KC_TRANSPARENT, KC_TRANSPARENT, QK_MUSIC_ON,    QK_MUSIC_OFF,   MU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};




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

// 5th row 6+7 column are top thumb buttons
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_moonlander(
    'L', 'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R', 'R', 
    'L', 'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R', 'R', 
    'L', 'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R', 'R', 
    'L', 'L', 'L', 'L', 'L', 'L',               'R', 'R', 'R', 'R', 'R', 'R', 
    'L', 'L', 'L', 'L', 'L',         '*','*',        'R', 'R', 'R', 'R', 'R', 
                        '*', '*', '*',     '*', '*', '*'
    );
