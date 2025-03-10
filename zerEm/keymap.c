#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MAC_MISSION_CONTROL,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_3,
  DANCE_1,
  DANCE_2,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                                       TG(4),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    MEH_T(KC_TAB),  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           CW_TOGG,                                        KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    ALL_T(KC_ESCAPE),MT(MOD_LALT, KC_A),MT(MOD_LCTL, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,           KC_NO,                                                                          KC_NO,          KC_H,           MT(MOD_LSFT, KC_J),MT(MOD_LGUI, KC_K),MT(MOD_LCTL, KC_L),MT(MOD_LALT, KC_SCLN),KC_QUOTE,       
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL,   LGUI(LSFT(KC_4)),LGUI(LSFT(KC_5)),KC_LEFT_ALT,    MT(MOD_LGUI, KC_SPACE),TD(DANCE_0),                                                                                                    TD(DANCE_3),    MT(MOD_RALT, KC_BSPC),MT(MOD_RGUI, KC_DELETE),TD(DANCE_1),    TD(DANCE_2),    LGUI(KC_SPACE), 
    LT(2,KC_SPACE), LT(1,KC_BSPC),  ALL_T(KC_ESCAPE),                KC_MEH,         LT(3,KC_TAB),   MT(MOD_LSFT, KC_ENTER)
  ),
  [1] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          CW_TOGG,        KC_NO,          MAC_MISSION_CONTROL,KC_NO,          KC_NO,                                          KC_NO,          KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         LGUI(KC_SPACE), KC_NO,          
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_NO,          KC_NO,                                                                          KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_MAC_UNDO,    KC_MAC_CUT,     KC_MAC_COPY,    KC_MAC_PASTE,   KC_NO,                                          LALT(KC_LEFT),  LALT(KC_DOWN),  LALT(KC_UP),    LALT(KC_RIGHT), KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_DQUO,        KC_PIPE,        KC_EQUAL,       KC_MINUS,       KC_TILD,        KC_NO,                                          KC_NO,          KC_NO,          KC_UNDS,        KC_NO,          KC_NO,          KC_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_HASH,        KC_NO,                                                                          KC_NO,          KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_DLR,         KC_COLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_EXLM,        KC_LABK,        KC_RABK,        KC_PERC,                                        KC_AT,          KC_LCBR,        KC_RCBR,        KC_SLASH,       KC_QUES,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_4,           KC_5,           KC_6,           KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                                          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_BOOT,        KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MEDIA_PLAY_PAUSE,KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          MAGIC_TOGGLE_NKRO,KC_AUDIO_MUTE,  KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_PRINT,KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
const uint16_t PROGMEM combo0[] = { MT(MOD_RALT, KC_BSPC), MT(MOD_LGUI, KC_SPACE), COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_RGUI, KC_DELETE), KC_LEFT_ALT, COMBO_END};
const uint16_t PROGMEM combo2[] = { MT(MOD_RALT, KC_BSPC), KC_LEFT_ALT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(1)),
    COMBO(combo1, TT(2)),
    COMBO(combo2, TT(3)),
};
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI, KC_SPACE):
            return g_tapping_term -100;
        case MT(MOD_RALT, KC_BSPC):
            return g_tapping_term -100;
        case MT(MOD_RGUI, KC_DELETE):
            return g_tapping_term -100;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {187,244,255}, {90,255,255}, {90,255,255}, {90,255,255}, {90,255,255}, {165,255,255}, {0,0,255}, {43,253,255}, {0,0,255}, {0,0,255}, {165,255,255}, {0,0,255}, {43,253,255}, {0,0,255}, {0,0,255}, {165,255,255}, {0,0,255}, {43,253,255}, {0,0,255}, {90,255,255}, {165,255,255}, {0,0,255}, {43,253,255}, {0,0,255}, {90,255,255}, {165,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {187,244,255}, {16,255,255}, {16,255,255}, {215,255,255}, {215,255,255}, {90,255,255}, {43,253,255}, {187,244,255}, {187,244,255}, {187,244,255}, {90,255,255}, {43,253,255}, {165,255,255}, {0,0,255}, {43,253,255}, {187,244,255}, {187,244,255}, {165,255,255}, {0,0,255}, {43,253,255}, {187,244,255}, {187,244,255}, {165,255,255}, {0,0,255}, {43,253,255}, {187,244,255}, {90,255,255}, {165,255,255}, {0,0,255}, {43,253,255}, {0,0,255}, {90,255,255}, {165,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {16,255,255}, {0,0,255}, {16,255,255}, {90,255,255}, {90,255,255}, {90,255,255}, {43,253,255} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {90,255,255}, {16,255,255}, {0,0,0}, {0,0,0}, {16,255,255}, {90,255,255}, {16,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {90,255,255}, {16,255,255}, {0,0,0}, {0,0,0}, {16,255,255}, {90,255,255}, {16,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,253,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,253,255}, {16,255,255}, {90,255,255}, {0,0,0}, {0,0,0}, {43,253,255}, {16,255,255}, {90,255,255}, {0,0,0}, {0,0,0}, {43,253,255}, {16,255,255}, {90,255,255}, {0,0,0}, {0,0,0}, {43,253,255}, {16,255,255}, {90,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {187,244,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {0,0,0}, {187,244,255}, {187,244,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {16,255,255}, {16,255,255}, {16,255,255}, {0,0,0}, {0,0,0}, {16,255,255}, {16,255,255}, {16,255,255}, {0,0,0}, {0,0,0}, {16,255,255}, {16,255,255}, {16,255,255}, {0,0,0}, {0,0,0}, {16,255,255}, {16,255,255}, {16,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {165,255,255}, {165,255,255}, {165,255,255}, {0,0,0}, {0,0,0}, {165,255,255}, {165,255,255}, {165,255,255}, {165,255,255}, {0,0,0}, {165,255,255}, {165,255,255}, {165,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {90,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {90,255,255}, {0,0,0}, {16,255,255}, {0,0,0}, {0,0,0}, {90,255,255}, {0,0,0}, {43,253,255}, {0,0,0}, {0,0,0}, {43,253,255}, {16,255,255}, {90,255,255}, {0,0,0}, {0,0,0}, {43,253,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
    case 0:
      set_layer_color(0);
      break;
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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_MISSION_CONTROL:
      HCS(0x29F);

    case TD(DANCE_0):
    case TD(DANCE_3):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
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

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LBRC);
        tap_code16(KC_LBRC);
        tap_code16(KC_LBRC);
    }
    if(state->count > 3) {
        tap_code16(KC_LBRC);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_LBRC); break;
        case DOUBLE_TAP: register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LBRC); register_code16(KC_LBRC);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_LBRC); break;
        case DOUBLE_TAP: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LBRC); break;
    }
    dance_state[0].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RBRC);
        tap_code16(KC_RBRC);
        tap_code16(KC_RBRC);
    }
    if(state->count > 3) {
        tap_code16(KC_RBRC);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_RBRC); break;
        case DOUBLE_TAP: register_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RBRC); register_code16(KC_RBRC);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_RBRC); break;
        case DOUBLE_TAP: unregister_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RBRC); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(LALT(KC_A), KC_LEFT_ALT),
        [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(KC_A), KC_LEFT_CTRL),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
