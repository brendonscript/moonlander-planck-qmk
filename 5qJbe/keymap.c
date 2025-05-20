#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE




enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_0_255,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};



// F22 - QK_REP
// %s/QK_REP/QK_REP/g
// F23 - QK_AREP
// %s/QK_AREP/QK_AREP/g
// F24 - QK_LEAD
// %s/QK_LEAD/QK_LEAD/g


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                                       TT(6),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    ALL_T(KC_ESCAPE),MT(MOD_LALT, KC_A),MT(MOD_LCTL, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,           LALT(KC_A),                                                                     LCTL(KC_A),     KC_H,           MT(MOD_LSFT, KC_J),MT(MOD_LGUI, KC_K),MT(MOD_LCTL, KC_L),MT(MOD_LALT, KC_SCLN),MEH_T(KC_QUOTE),
    MT(MOD_LSFT, KC_TAB),KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       MT(MOD_RSFT, KC_ENTER),
    CW_TOGG,        TT(5),          KC_DELETE,      KC_TAB,         MT(MOD_LALT, KC_SPACE),TT(4),                                                                                                          TT(7),          MT(MOD_LALT, KC_BSPC),KC_ESCAPE,      KC_MAC_COPY,    KC_MAC_PASTE,   TD(DANCE_0),    
    LT(2, KC_SPACE),MT(MOD_LSFT, KC_TAB),OSM(MOD_HYPR),                  OSM(MOD_MEH),   MT(MOD_LSFT, KC_BSPC),LT(3, KC_ENTER)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MEH_T(KC_ESCAPE),MT(MOD_LALT, KC_A),MT(MOD_LCTL, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LSFT, KC_J),MT(MOD_LCTL, KC_K),MT(MOD_LCTL, KC_L),MT(MOD_LALT, KC_SCLN),ALL_T(KC_QUOTE),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_GUI,    KC_PC_COPY,     KC_PC_PASTE,    TD(DANCE_1),    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    LALT(LGUI(LCTL(LSFT(KC_BSLS)))),KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          LALT(LGUI(LCTL(LSFT(KC_W)))),KC_PSCR,        KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          LGUI(KC_R),     KC_MAC_UNDO,    KC_MAC_COPY,    KC_MAC_CUT,     KC_MAC_PASTE,   KC_NO,          
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_NO,          KC_CAPS,                                                                        QK_LLCK,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_BSPC,        KC_TRANSPARENT, 
    KC_NO,          KC_NO,          KC_RIGHT_ALT,   OSM(MOD_HYPR),  OSM(MOD_MEH),   KC_NO,                                          LALT(KC_LEFT),  LGUI(KC_LEFT),  LGUI(KC_RIGHT), LALT(KC_RIGHT), KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                                                                                                          CW_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,                          LCTL(KC_A),     LALT(KC_A),     MO(4)
  ),
  [3] = LAYOUT_moonlander(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_PLUS,                                        KC_EQUAL,       KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, 
    KC_ASTR,        KC_AMPR,        KC_PERC,        KC_LCBR,        KC_RCBR,        KC_BSLS,        KC_COLN,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_UNDS,        KC_CIRC,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_EQUAL,       KC_HASH,                                                                        QK_LLCK,        KC_NO,          KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_TRANSPARENT, 
    KC_AT,          KC_PIPE,        KC_EXLM,        KC_LBRC,        KC_RBRC,        KC_PLUS,                                        KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HYPR,        
    KC_HASH,        KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          
    MO(4),          KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                                          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_0,           KC_4,           KC_5,           KC_6,           KC_NO,          KC_NO,          KC_NO,                                                                          QK_LLCK,        KC_NO,          KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_TRANSPARENT, 
    KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,                                          KC_NO,          OSM(MOD_HYPR),  OSM(MOD_MEH),   KC_NO,          OSM(MOD_LALT),  KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_NO,          KC_TRANSPARENT,                                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_NO,          KC_TRANSPARENT,                                                                 QK_LLCK,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          KC_TRANSPARENT, 
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_NO,          KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_MS_BTN1,     KC_MS_BTN3,     KC_NO,                          KC_NO,          KC_NO,          KC_MS_BTN2
  ),
  [6] = LAYOUT_moonlander(
    RGB_TOG,        HSV_0_0_255,    RGB_MODE_FORWARD,KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    TOGGLE_LAYER_COLOR,RGB_SAI,        RGB_SPI,        RGB_HUI,        RGB_VAI,        KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    RGB_SLD,        RGB_SAD,        RGB_SPD,        RGB_HUD,        RGB_VAD,        KC_NO,          KC_NO,                                                                          QK_LLCK,        KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_moonlander(
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F11,                                         KC_F12,         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,          
    KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_PSCR,        KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_NO,          KC_NO,          KC_NO,                                                                          QK_LLCK,        KC_NO,          KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_TRANSPARENT, 
    KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PAUSE,       KC_NO,                                          KC_NO,          OSM(MOD_HYPR),  OSM(MOD_MEH),   OSM(MOD_LALT),  OSM(MOD_RALT),  KC_HYPR,        
    KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_moonlander(
    KC_NO,          TO(0),          TO(1),          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          EE_CLR,         QK_BOOT,        KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          QK_LLCK,        KC_NO,          QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_PRINT,KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          CM_TOGG,        KC_NO,          KC_NO,                                          MAGIC_TOGGLE_NKRO,KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_GRAVE, KC_1, KC_0, KC_MINUS, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_W, KC_I, KC_N, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, OSL(8)),
    COMBO(combo1, TG(1)),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255} },

    [2] = { {208,139,255}, {0,0,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {208,139,255}, {208,139,255}, {0,0,255}, {0,0,255}, {208,139,255}, {208,139,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {0,0,255}, {208,139,255}, {0,0,255}, {208,139,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {208,139,255}, {208,139,255}, {0,0,255}, {0,0,255}, {208,139,255}, {208,139,255}, {208,139,255}, {0,0,255}, {0,0,255}, {208,139,255}, {208,139,255}, {208,139,255}, {208,139,255}, {0,0,255}, {208,139,255}, {208,139,255}, {208,139,255}, {0,0,255}, {0,0,255}, {247,218,204}, {208,139,255}, {208,139,255}, {208,139,255}, {208,139,255} },

    [3] = { {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {187,244,255}, {0,0,255}, {187,244,255}, {187,244,255}, {0,0,255}, {187,244,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {187,244,255}, {187,244,255}, {187,244,255}, {187,244,255}, {0,0,255}, {187,244,255}, {0,0,255}, {187,244,255}, {187,244,255}, {0,0,255}, {0,0,255}, {0,0,255}, {187,244,255}, {0,0,255}, {247,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [4] = { {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {0,0,255}, {152,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {152,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {152,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {0,0,255}, {152,255,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {152,255,255}, {0,0,255}, {131,255,255}, {0,0,255}, {0,0,255}, {152,255,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {152,255,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {247,218,204}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [5] = { {0,0,255}, {0,0,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {247,218,204}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [6] = { {208,218,204}, {208,218,204}, {208,218,204}, {0,0,255}, {0,0,255}, {208,218,204}, {208,218,204}, {208,218,204}, {0,0,255}, {0,0,255}, {208,218,204}, {208,218,204}, {208,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {208,218,204}, {208,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {208,218,204}, {208,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {131,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {131,255,255}, {0,0,255}, {208,218,204}, {208,218,204}, {247,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [7] = { {0,0,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {208,139,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {208,139,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {208,139,255}, {16,255,255}, {16,255,255}, {16,255,255}, {16,255,255}, {208,139,255}, {16,255,255}, {0,0,255}, {16,255,255}, {0,0,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {16,255,255}, {16,255,255}, {0,0,255}, {208,139,255}, {0,0,255}, {16,255,255}, {16,255,255}, {0,0,255}, {208,139,255}, {0,0,255}, {16,255,255}, {16,255,255}, {0,0,255}, {208,139,255}, {0,0,255}, {16,255,255}, {16,255,255}, {0,0,255}, {208,139,255}, {0,0,255}, {16,255,255}, {16,255,255}, {0,0,255}, {208,139,255}, {0,0,255}, {0,0,255}, {0,0,255}, {208,139,255}, {0,0,255}, {247,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [8] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {87,199,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,0,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {16,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {90,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {43,253,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {16,255,255}, {0,0,255}, {0,0,255}, {247,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

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
        case DOUBLE_TAP: register_code16(LALT(LCTL(LGUI(LSFT(KC_W))))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_SPACE)); register_code16(LGUI(KC_SPACE));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_W))))); break;
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
        case DOUBLE_TAP: register_code16(LALT(LCTL(LSFT(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LSFT(KC_W)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
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

    case LGUI_T(KC_D):
      if (other_keycode == KC_W || other_keycode == KC_R) {
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

