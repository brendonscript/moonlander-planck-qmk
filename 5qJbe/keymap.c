#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE




enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_0_255,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  MAC_MISSION_CONTROL,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
};



// F22 - QK_REP
// %s/QK_REP/QK_REP/g
// F23 - QK_AREP
// %s/QK_AREP/QK_AREP/g
// F24 - QK_LEAD
// %s/QK_LEAD/QK_LEAD/g
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                                       TG(8),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    TD(DANCE_0),    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TD(DANCE_1),                                    TD(DANCE_3),    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    ALL_T(KC_ESCAPE),MT(MOD_LALT, KC_A),MT(MOD_LCTL, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,           TD(DANCE_2),                                                                    TD(DANCE_4),    KC_H,           MT(MOD_LSFT, KC_J),MT(MOD_LGUI, KC_K),MT(MOD_LCTL, KC_L),MT(MOD_LALT, KC_SCLN),MEH_T(KC_QUOTE),
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           LT(2,KC_B),                                     LT(3,KC_N),     KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT, 
    CW_TOGG,        TG(6),          KC_APPLICATION, MT(MOD_LCTL, KC_TAB),MT(MOD_LALT, KC_SPACE),QK_AREP,                                                                                                         QK_REP,         MT(MOD_LGUI, KC_BSPC),QK_LEAD,         LGUI(LSFT(KC_4)),LGUI(LSFT(KC_5)),LGUI(KC_SPACE), 
    MT(MOD_LSFT, KC_SPACE),LT(2,KC_TAB),   TT(4),                          QK_LEAD,         LT(3,KC_ENTER), MT(MOD_LSFT, KC_BSPC)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MEH_T(KC_ESCAPE),KC_A,           MT(MOD_LCTL, KC_S),MT(MOD_LALT, KC_D),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LALT, KC_K),MT(MOD_LCTL, KC_L),KC_SCLN,        MEH_T(KC_QUOTE),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_GUI,    MT(MOD_LCTL, KC_SPACE),QK_AREP,                                                                                                         QK_REP,         MT(MOD_LALT, KC_BSPC),QK_LEAD,         KC_PSCR,        KC_NO,          LALT(KC_SPACE), 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 QK_LEAD,         KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          CW_TOGG,        KC_PSCR,        MAC_MISSION_CONTROL,KC_NO,          KC_NO,                                          KC_NO,          LGUI(KC_LEFT),  KC_PGDN,        KC_PAGE_UP,     LGUI(KC_RIGHT), KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_NO,          KC_NO,                                                                          KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_MAC_UNDO,    KC_MAC_CUT,     KC_MAC_COPY,    KC_MAC_PASTE,   KC_TRANSPARENT,                                 LALT(KC_LEFT),  LALT(KC_DOWN),  LALT(KC_UP),    LALT(KC_RIGHT), KC_NO,          KC_TRANSPARENT, 
    LALT(KC_A),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          LCTL(KC_A),     
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,                 QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_DQUO,        KC_PIPE,        KC_HASH,        KC_TILD,        KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AT,          KC_UNDS,        KC_CIRC,        KC_DLR,         KC_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LABK,        KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_EQUAL,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_COLN,        KC_RPRN,        KC_RCBR,        KC_RBRC,        KC_RABK,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_MINUS,       KC_GRAVE,       KC_ASTR,        KC_PERC,                                        KC_TRANSPARENT, KC_AMPR,        KC_NO,          KC_SLASH,       KC_QUES,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,                 QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,          KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          KC_4,           KC_5,           KC_6,           KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                                          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_NO,          KC_NO,          KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,                 QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    ST_MACRO_0,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_6,     
    KC_TRANSPARENT, KC_AT,          LCTL(KC_W),     KC_TRANSPARENT, LCTL(KC_R),     KC_TRANSPARENT, KC_LCBR,                                        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_I),     LCTL(KC_O),     KC_COLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     KC_TRANSPARENT, KC_LPRN,                                                                        KC_RPRN,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_4,     KC_TRANSPARENT, ST_MACRO_5,     KC_TRANSPARENT, KC_LABK,                                        KC_RABK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,                 QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_NO,          KC_NO,                                                                          KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                                                                                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_MS_BTN1,     KC_MS_BTN3,     KC_NO,                          QK_LLCK,        TO(0),          KC_MS_BTN2
  ),
  [7] = LAYOUT_moonlander(
    KC_TRANSPARENT, HSV_0_0_255,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,                                        AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAI,        RGB_HUI,        RGB_VAI,        RGB_SPI,        TOGGLE_LAYER_COLOR,                                MU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, RGB_SAD,        RGB_HUD,        RGB_VAD,        RGB_SPD,        RGB_SLD,                                                                        MU_NEXT,        KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,                                KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,                 QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          EE_CLR,         QK_BOOT,        KC_NO,          KC_NO,                                          TO(1),          TO(7),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          CM_TOGG,        KC_NO,          KC_NO,                                          MAGIC_TOGGLE_NKRO,KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_PRINT,KC_NO,          KC_NO,          
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,                 QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
const uint16_t PROGMEM combo0[] = { MT(MOD_LSFT, KC_BSPC), LT(2,KC_TAB), COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LSFT, KC_SPACE), LT(3,KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo2[] = { MT(MOD_LSFT, KC_SPACE), MT(MOD_LSFT, KC_BSPC), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, OSL(2)),
    COMBO(combo1, OSL(3)),
    COMBO(combo2, KC_DELETE),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [2] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {188,255,255}, {0,0,255}, {0,0,255}, {90,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {16,255,255}, {90,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {16,255,255}, {90,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {16,255,255}, {90,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {188,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {43,253,255}, {16,255,255}, {90,255,255}, {0,0,255}, {0,0,255}, {43,253,255}, {16,255,255}, {90,255,255}, {0,0,255}, {0,0,255}, {43,253,255}, {16,255,255}, {90,255,255}, {0,0,255}, {0,0,255}, {43,253,255}, {16,255,255}, {90,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255} },

    [3] = { {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {187,244,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255} },

    [4] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {16,255,255}, {16,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {16,255,255}, {16,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {16,255,255}, {16,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {16,255,255}, {16,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {165,255,255}, {165,255,255}, {165,255,255}, {0,0,255}, {0,0,255}, {165,255,255}, {165,255,255}, {165,255,255}, {165,255,255}, {0,0,255}, {165,255,255}, {165,255,255}, {165,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255} },

    [5] = { {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {131,255,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255} },

    [6] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {41,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {74,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {0,245,245}, {0,245,245}, {0,0,255} },

    [7] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {74,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {74,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {74,255,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {74,255,255}, {16,255,255}, {131,255,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {90,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {90,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {90,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {43,253,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {43,253,255}, {0,0,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255} },

    [8] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {43,253,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {90,255,255}, {0,0,255}, {187,244,255}, {0,0,255}, {16,255,255}, {0,0,255}, {131,255,255}, {74,255,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255} },

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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_Q) SS_DELAY(100) SS_TAP(X_A)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_Z));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_D));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_A)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Z) SS_DELAY(100) SS_TAP(X_Z));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_C));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_Q) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_LSFT(SS_TAP(X_1))  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case MAC_MISSION_CONTROL:
      HCS(0x29F);

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

static tap dance_state[5];

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
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_LCBR);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LCBR); break;
        case DOUBLE_TAP: register_code16(KC_LABK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_LABK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case DOUBLE_TAP: register_code16(KC_LBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case DOUBLE_TAP: unregister_code16(KC_LBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_RCBR);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_RCBR); break;
        case DOUBLE_TAP: register_code16(KC_RABK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RCBR); register_code16(KC_RCBR);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_RCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_RABK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RCBR); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RPRN);
        tap_code16(KC_RPRN);
        tap_code16(KC_RPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_RPRN);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_RPRN); break;
        case DOUBLE_TAP: register_code16(KC_RBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RPRN); register_code16(KC_RPRN);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_RPRN); break;
        case DOUBLE_TAP: unregister_code16(KC_RBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RPRN); break;
    }
    dance_state[4].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
};




// Custom

// 5th row 6+7 column are top thumb buttons
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_moonlander(
    'L', 'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R', 'R', 
    'L', 'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R', 'R', 
    'L', 'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R', 'R', 
    'L', 'L', 'L', 'L', 'L', 'L',               'R', 'R', 'R', 'R', 'R', 'R', 
    '*', '*', '*', '*', '*',         '*','*',        '*', '*', '*', '*', '*', 
    '*', '*', '*',     '*', '*', '*'
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

