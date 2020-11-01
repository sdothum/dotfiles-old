
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = KEYMAP( 

// ....................................................... Numberic Keypad Layer

  [_NUMBER] = KEYMAP( 
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
#ifdef UPPER_HEX
        ___   , S(KC_F) , ACT_E   , S(KC_D) ,   ___   ,  __x__  ,  __x__  , KC_SLSH , KC_4    , KC_5    , KC_9    , KC_ASTR ,
#else
        ___   , KC_F    , ACT_E   , KC_D    ,   ___   ,  __x__  ,  __x__  , KC_SLSH , KC_4    , KC_5    , KC_9    , KC_ASTR ,
#endif
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      OS_GUI  , CT_C    , AT_B    , ST_A    ,   ___   ,  __x__  ,  __x__  , TD_DOT  , KC_1    , KC_2    , KC_3    , KC_MINS ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   , KC_LBRC , AST_G   , KC_RBRC ,   ___   ,  __x__  ,  __x__  , TD_COMM , KC_8    , KC_6    , KC_7    , KC_PLUS ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  , KC_BSLS , KC_0    , KC_EQL  ,   ___   ,   ___   ,   ___   
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),

// .......................................................... Function Key Layer

  [_FNCKEY] = KEYMAP( 
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_F4   , KC_F5   , KC_F9   , KC_F12  ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      OS_GUI  , OS_CTL  , OS_ALT  , OS_SFT  ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_F1   , KC_F2   , KC_F3   , KC_F11  ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_F8   , KC_F6   , KC_F7   , KC_F10  ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,  __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,   ___
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),
