#include QMK_KEYBOARD_H

#define _BASE 0
#define _EXT 1
#define _FN 2

enum tap_dance_keycodes {
  TD_PSCR = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_PSCR] = ACTION_TAP_DANCE_DOUBLE(KC_PSCR, KC_CAPS)
};

#define FN_BSPC LT(_FN, KC_BSPC)
#define FN_ENT RSFT_T(KC_ENT)
#define FN_SPC LSFT_T(KC_SPC)

#define APP_NEXT LALT(KC_TAB)
#define APP_PREV LSFT(LALT(KC_TAB))
#define DSK_NEXT LGUI(LCTL(KC_RIGHT))
#define DSK_PREV LGUI(LCTL(KC_LEFT))
#define TAB_NEXT LCTL(KC_PGUP)
#define TAB_PREV LCTL(KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_TILDE,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                           KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_UNDS ,KC_EQUAL,TD_PSCR ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                           KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                           KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOTE,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_LALT ,         KC_RALT ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RCTL ,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LGUI ,TT(_EXT),FN_SPC  ,                  FN_ENT  ,FN_BSPC ,KC_APP
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_EXT] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_GRAVE,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                           KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,KC_PGUP ,KC_LCBR ,KC_LBRC ,KC_LPRN ,                           KC_RPRN ,KC_RBRC ,KC_RCBR ,KC_MINUS,KC_PLUS ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,KC_HOME ,KC_PGDN ,KC_END  ,KC_INS  ,KC_DEL  ,                           KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,_______ ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         KC_MUTE ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______ ,_______ ,_______ ,                  _______ ,_______ ,_______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F11  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                           KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F12  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,RGB_TOG ,RGB_HUI ,RGB_SAI ,RGB_VAI ,_______ ,                           DSK_NEXT,APP_NEXT,TAB_NEXT,_______ ,_______ ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,RGB_MOD ,RGB_HUD ,RGB_SAD ,RGB_VAD ,_______ ,                           DSK_PREV,APP_PREV,TAB_PREV,_______ ,_______ ,_______ ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         RESET   ,KC_MPRV ,KC_MPLY ,KC_MNXT ,KC_MSTP ,_______ ,_______ ,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______ ,_______ ,_______ ,                  _______ ,_______ ,_______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

void encoder_update_user (uint8_t index, bool clockwise) {
  switch (biton32(layer_state)) {
    case _EXT:
      clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
      break;
    default:
      clockwise ? tap_code(KC_WH_D) : tap_code(KC_WH_U);
      break;
  }
}
