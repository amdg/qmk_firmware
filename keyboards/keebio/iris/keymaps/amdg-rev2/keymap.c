#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum {
  TD_SCLN = 0,
  TD_SLSH,
  TD_COMM,
  TD_DOT
};

void td_dot_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_DOT);
  } else {
    register_code (KC_LSFT);
    register_code (KC_EQUAL);
  }
};

void td_dot_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_DOT);
  } else {
    unregister_code (KC_LSFT);
    unregister_code (KC_EQUAL);
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOTE),
  [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
  [TD_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINUS),
  [TD_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dot_finished, td_dot_reset)
};

#define _BASE 0
#define _SYM 1
#define _FN 2

#define ________ KC_TRNS
#define ___XX___ KC_NO

#define FN_BSPC LT(_FN, KC_BSPC)
#define FN_ENT RSFT_T(KC_ENT)
#define FN_ESC RALT_T(KC_ESC)
#define FN_SPC LSFT_T(KC_SPC)
#define FN_TAB LALT_T(KC_TAB)

#define CTL_LEFT LCTL(KC_LEFT)
#define CTL_RIGHT LCTL(KC_RIGHT)
#define CTL_UP LCTL(KC_UP)
#define CTL_DOWN LCTL(KC_DOWN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------+                          ,--------+--------+--------+--------+--------+--------.
       KC_TILDE,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                           KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_UNDS ,KC_EQUAL,KC_CAPS ,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
       KC_LBRC ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                           KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_RBRC ,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
       KC_LPRN ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                           KC_H    ,KC_J    ,KC_K    ,KC_L    ,TD(TD_SCLN),KC_RPRN ,
    //|--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------|
       KC_LCTL ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,FN_TAB  ,         FN_ESC  ,KC_N    ,KC_M    ,TD(TD_COMM),TD(TD_DOT),TD(TD_SLSH),KC_RCTL ,
    //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
                                           KC_LGUI ,TT(_SYM),FN_SPC  ,         FN_ENT  ,FN_BSPC ,KC_RGUI 
    //                                    `--------+--------+--------'        `--------+--------+--------'
  ),

  [_SYM] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------+                          ,--------+--------+--------+--------+--------+--------.
       KC_GRAVE,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                           KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,___XX___,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
       ___XX___,___XX___,KC_INS  ,KC_HOME ,KC_PGUP ,___XX___,                           ___XX___,___XX___,___XX___,___XX___,___XX___,___XX___,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
       ___XX___,___XX___,KC_DEL  ,KC_END  ,KC_PGDN ,___XX___,                           KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,___XX___,___XX___,
    //|--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------|
       ________,___XX___,___XX___,___XX___,___XX___,___XX___,________,         ________,___XX___,___XX___,________,________,___XX___,________,
    //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
                                           ________,________,FN_SPC  ,         FN_ENT  ,________,________
    //                                    `--------+--------+--------'        `--------+--------+--------'
  ),

  [_FN] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------+                          ,--------+--------+--------+--------+--------+--------.
       KC_MUTE ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                           KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,___XX___,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
       KC_VOLU ,___XX___,KC_MS_U ,___XX___,KC_WH_U ,___XX___,                           ___XX___,KC_BTN1 ,KC_BTN3 ,KC_BTN2 ,___XX___,___XX___,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
       KC_VOLD ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,___XX___,                           CTL_LEFT,CTL_DOWN,CTL_UP  ,CTL_RIGHT,KC_QUOTE,___XX___,
    //|--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------|
       ________,___XX___,___XX___,___XX___,___XX___,___XX___,________,         ________,___XX___,___XX___,KC_MINUS,KC_PLUS ,KC_BSLS ,________,
    //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
                                           ________,________,KC_LSFT ,         KC_RSFT ,________,________
    //                                    `--------+--------+--------'        `--------+--------+--------'
  )
};
