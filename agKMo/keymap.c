#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "i18n.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
  _LAYER7,
  _LAYER8,
  _LAYER9,
  _LAYER10,
  _LAYER11,
  _LAYER12,
  _LAYER13,
  _LAYER14,
  _LAYER15,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Use with visual selection (Ctrl+R to paste)
//
// F22 - QK_REP
// '<,'>s/KC_F22/QK_REP
//
// F23 - QK_AREP
// '<,'>s/KC_F23/QK_AREP
//
// F24 - QK_LEAD
// '<,'>s/KC_F24/QK_LEAD
//
// Run all replacements
// '<,'>s/KC_F22/QK_REP/g | '<,'>s/KC_F23/QK_AREP/g | '<,'>s/KC_F24/QK_LEAD/g

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    ALL_T(KC_ESCAPE),MT(MOD_LALT, KC_A),MT(MOD_LCTL, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,           KC_H,           MT(MOD_LSFT, KC_J),MT(MOD_LGUI, KC_K),MT(MOD_LCTL, KC_L),MT(MOD_LALT, KC_SCLN),MEH_T(KC_QUOTE),
    MT(MOD_LSFT, KC_TAB),KC_Z,           KC_X,           KC_C,           MT(MOD_LALT, KC_V),KC_B,           KC_N,           MT(MOD_LALT, KC_M),KC_COMMA,       KC_DOT,         KC_SLASH,       MT(MOD_LSFT, KC_ENTER),
    QK_LEAD,         MO(5),          TT(4),          ALL_T(KC_TAB),  LT(_LOWER, KC_ENTER),KC_SPACE,       KC_NO,          LT(_RAISE, KC_BSPC),MEH_T(KC_ESCAPE),QK_AREP,         QK_REP,         TD(DANCE_0)
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_NO,          KC_NO,          CW_TOGG,        KC_NO,          KC_NO,          KC_NO,          LGUI(KC_R),     KC_MAC_UNDO,    KC_MAC_COPY,    KC_MAC_CUT,     KC_MAC_PASTE,   QK_LLCK,        
    DM_PLY2,        KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_BSPC,        DM_PLY1,        
    DM_REC2,        KC_NO,          KC_RIGHT_ALT,   KC_MEH,         KC_HYPR,        KC_NO,          LALT(KC_LEFT),  LGUI(KC_RIGHT), LGUI(KC_LEFT),  LALT(KC_RIGHT), KC_INSERT,      DM_REC1,        
    DM_RSTP,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LGUI(LCTL(LSFT(KC_W)))),KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DM_RSTP
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_BSLS,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_TILD,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_ASTR,        KC_PERC,        KC_EQUAL,       KC_LPRN,        KC_RPRN,        KC_PLUS,        KC_MINUS,       KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_TRANSPARENT, 
    KC_AT,          KC_PIPE,        KC_EXLM,        KC_LABK,        KC_RABK,        KC_AMPR,        KC_COLN,        KC_HYPR,        KC_MEH,         KC_RIGHT_ALT,   KC_NO,          KC_TRANSPARENT, 
    KC_UNDS,        KC_HASH,        KC_DLR,         KC_CIRC,        KC_TRANSPARENT, KC_EQUAL,       KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_NO,          KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_MINUS,       KC_EQUAL,       KC_TRANSPARENT, 
    KC_HYPR,        MT(MOD_LALT, KC_1),MT(MOD_LCTL, KC_2),MT(MOD_LGUI, KC_3),MT(MOD_LSFT, KC_4),KC_5,           KC_6,           MT(MOD_LSFT, KC_7),MT(MOD_LGUI, KC_8),MT(MOD_LCTL, KC_9),MT(MOD_LALT, KC_0),KC_MEH,         
    KC_NO,          OSM(MOD_LALT),  KC_NO,          KC_NO,          KC_PLUS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          OSM(MOD_LALT),  KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK
  ),

  [_LAYER4] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_NO,          KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_LLCK,        
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_RIGHT_ALT,   KC_MEH,         KC_HYPR,        KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER5] = LAYOUT_planck_grid(
    RGB_TOG,        RGB_SPD,        RGB_SPI,        KC_NO,          KC_NO,          RGB_SAD,        RGB_SAI,        RGB_HUD,        RGB_HUI,        RGB_VAD,        RGB_VAI,        RGB_MODE_FORWARD,
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_NO,          KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_RIGHT_ALT,   KC_MEH,         KC_HYPR,        KC_NO,          KC_NO,          KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER6] = LAYOUT_planck_grid(
    KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_PSCR,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_LLCK,        
    KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_SCRL,        KC_NO,          KC_NO,          KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_TRANSPARENT, 
    KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PAUSE,       KC_NO,          KC_NO,          KC_HYPR,        KC_MEH,         KC_RIGHT_ALT,   KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER7] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_NO,          KC_NO,          EE_CLR,         QK_BOOT,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_PRINT,KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          CM_TOGG,        KC_NO,          KC_NO,          MAGIC_TOGGLE_NKRO,TO(0),          TO(9),          TO(8),          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER8] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    MEH_T(KC_ESCAPE),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_TAB,         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_TAB,         LT(10,KC_ENTER),KC_SPACE,       KC_NO,          LT(11,KC_BSPC), KC_ESCAPE,      KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL
  ),

  [_LAYER9] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    MEH_T(KC_ESCAPE),KC_A,           MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_G,           KC_H,           MT(MOD_LSFT, KC_J),MT(MOD_LCTL, KC_K),MT(MOD_LALT, KC_L),KC_SCLN,        MEH_T(KC_QUOTE),
    MT(MOD_LSFT, KC_TAB),KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       MT(MOD_LSFT, KC_ENTER),
    KC_LEFT_GUI,    TT(14),         TT(13),         MEH_T(KC_TAB),  LT(10,KC_ENTER),KC_SPACE,       KC_NO,          LT(11,KC_BSPC), MEH_T(KC_ESCAPE),KC_NO,          KC_NO,          TD(DANCE_1)
  ),

  [_LAYER10] = LAYOUT_planck_grid(
    KC_NO,          KC_NO,          CW_TOGG,        KC_NO,          KC_NO,          KC_NO,          LCTL(KC_Y),     KC_PC_UNDO,     KC_PC_COPY,     KC_PC_CUT,      KC_PC_PASTE,    LALT(LCTL(LSFT(KC_BSLS))),
    KC_MEH,         KC_NO,          KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_BSPC,        KC_MEH,         
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          LCTL(KC_LEFT),  LCTL(KC_DOWN),  LCTL(KC_UP),    LCTL(KC_RIGHT), KC_INSERT,      KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          TT(12),         KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),

  [_LAYER11] = LAYOUT_planck_grid(
    KC_BSLS,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_TILD,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_ASTR,        KC_PERC,        KC_EQUAL,       KC_LPRN,        KC_RPRN,        KC_PLUS,        KC_MINUS,       KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_NO,          KC_MEH,         
    KC_AT,          KC_PIPE,        KC_EXLM,        KC_LABK,        KC_RABK,        KC_AMPR,        KC_COLN,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_UNDS,        KC_HASH,        KC_DLR,         KC_CIRC,        TT(12),         KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),

  [_LAYER12] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_BSLS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_0,           KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_NO,          KC_NO,          KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_NO,          KC_MEH,         
    KC_MINUS,       KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),

  [_LAYER13] = LAYOUT_planck_grid(
    KC_NO,          KC_NO,          KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,     KC_NO,          KC_NO
  ),

  [_LAYER14] = LAYOUT_planck_grid(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_NO,          KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_NO,          KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),

  [_LAYER15] = LAYOUT_planck_grid(
    KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_PSCR,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_SCRL,        KC_NO,          KC_NO,          KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_NO,          KC_MEH,         
    KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PAUSE,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT
  ),

};

const uint16_t PROGMEM combo0[] = { KC_GRAVE, KC_Q, KC_P, KC_MINUS, COMBO_END};
const uint16_t PROGMEM combo1[] = { ALL_T(KC_TAB), LT(_RAISE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_GRAVE, KC_Q, KC_P, KC_MINUS, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_GRAVE, KC_MINUS, KC_P, KC_Q, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, OSL(7)),
    COMBO(combo1, KC_DELETE),
    COMBO(combo2, TO(7)),
    COMBO(combo3, TO(7)),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {0,0,0}, {0,0,0}, {252,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {252,255,232}, {41,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {252,255,232}, {41,255,255}, {41,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {234,255,255}, {234,255,255}, {234,255,255}, {234,255,255}, {252,255,232}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255} },

    [2] = { {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {74,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {74,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {74,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {252,255,232} },

    [4] = { {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {252,255,232}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0} },

    [5] = { {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {252,255,232}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {252,255,232}, {252,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {131,255,255}, {234,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255} },

    [9] = { {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255} },

    [10] = { {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [11] = { {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [12] = { {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [13] = { {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0} },

    [14] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {252,255,232}, {252,255,232}, {252,255,232}, {0,0,0}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {252,255,232}, {252,255,232}, {252,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [15] = { {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
    case 10:
      set_layer_color(10);
      break;
    case 11:
      set_layer_color(11);
      break;
    case 12:
      set_layer_color(12);
      break;
    case 13:
      set_layer_color(13);
      break;
    case 14:
      set_layer_color(14);
      break;
    case 15:
      set_layer_color(15);
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

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


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


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_SPACE));
        tap_code16(LGUI(KC_SPACE));
        tap_code16(LGUI(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_SPACE));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_SPACE)); break;
        case SINGLE_HOLD: layer_on(6); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_SPACE)); register_code16(LGUI(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_SPACE)); register_code16(LGUI(KC_SPACE));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(6)) {
            layer_off(6);
          }
        break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_SPACE));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD: layer_on(15); break;
        case DOUBLE_TAP: register_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD:
          if(!is_layer_locked(15)) {
            layer_off(15);
          }
        break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};

// Custom

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_planck_grid(
    'L','L','L','L','L','L','R','R','R','R','R','R',        
    'L','L','L','L','L','L','R','R','R','R','R','R',        
    'L','L','L','L','L','L','R','R','R','R','R','R',        
    '*','*','*','*','*','*','*','*','*','*','*','*'        
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
  if (leader_sequence_two_keys(KC_C, KC_W)) {
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
