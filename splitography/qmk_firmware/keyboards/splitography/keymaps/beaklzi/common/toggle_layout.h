
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = KEYMAP( 

// .............................................................. CapsLock Layer

  [_TTCAPS] = KEYMAP( 
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      S(KC_Z) , S(KC_Y) , S(KC_O) , S(KC_U) , KC_COLN ,  __x__  ,  __x__  , S(KC_G) , S(KC_D) , S(KC_N) , S(KC_M) , S(KC_X) ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      S(KC_Q) , S(KC_H) , S(KC_E) , TT_A    , KC_DOT  ,  __x__  ,  __x__  , S(KC_C) , TT_T    , S(KC_R) , S(KC_S) , S(KC_W) ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      S(KC_J) , KC_MINS , KC_QUOT , S(KC_K) , KC_COMM ,  __x__  ,  __x__  , S(KC_B) , S(KC_P) , S(KC_L) , S(KC_F) , S(KC_V) ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   , TT_ESC  , TT_I    , TT_SPC  , KC_BSPC ,   ___   ,   ___   ,   ___   ,   ___   
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),

  [_TTBASEL] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------- 
      KC_Z    , KC_Y    , KC_O    , KC_U    , KC_COLN ,  __x__  ,  __x__  , KC_G    , KC_D    , KC_N    , KC_M    , KC_X    ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      KC_Q    , KC_H    , KC_E    ,  __x__  , KC_DOT  ,  __x__  ,  __x__  , KC_C    , KC_T    , KC_R    , KC_S    , KC_W    ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      KC_J    , KC_MINS , KC_QUOT , KC_K    , KC_COMM ,  __x__  ,  __x__  , KC_B    , KC_P    , KC_L    , KC_F    , KC_V    ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,  __x__  , KC_I    , TT_SPC  , KC_DEL  ,   ___   ,   ___   ,   ___   ,   ___   
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),

  [_TTBASER] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------- 
      KC_Z    , KC_Y    , KC_O    , KC_U    , KC_SCLN ,  __x__  ,  __x__  , KC_G    , KC_D    , KC_N    , KC_M    , KC_X    ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      KC_Q    , KC_H    , KC_E    , KC_A    , KC_TILD ,  __x__  ,  __x__  , KC_C    ,  __x__  , KC_R    , KC_S    , KC_W    ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      KC_J    , KC_UNDS , KC_DQT  , KC_K    , KC_GRV  ,  __x__  ,  __x__  , KC_B    , KC_P    , KC_L    , KC_F    , KC_V    ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,  __x__  , KC_I    , TT_SPC  , KC_BSPC ,   ___   ,   ___   ,   ___   ,   ___   
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),

// ....................................................... Numberic Keypad Layer

  [_TTNUMBER] = KEYMAP( 
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
#ifdef UPPER_HEX
        ___   , S(KC_F) , ACT_E   , S(KC_D) ,   ___   ,  __x__  ,  __x__  , KC_SLSH , KC_7    , KC_8    , KC_9    , KC_ASTR ,
#else
        ___   , KC_F    , ACT_E   , KC_D    ,   ___   ,  __x__  ,  __x__  , KC_SLSH , KC_7    , KC_8    , KC_9    , KC_ASTR ,
#endif
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      OS_GUI  , CT_C    , AT_B    , ST_A    ,   ___   ,  __x__  ,  __x__  , TD_DOT  , KC_4    , KC_5    , KC_6    , KC_MINS ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   , KC_LBRC , AST_G   , KC_RBRC ,   ___   ,  __x__  ,  __x__  , TD_COMM , KC_1    , KC_2    , KC_3    , KC_PLUS ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   , TT_ESC  , KC_SPC  , KC_0    , KC_BSLS ,   ___   ,   ___   ,   ___   ,   ___   
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),

// ............ .................................................. Function Keys

  [_TTFNCKEY] = KEYMAP( 
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_F7   , KC_F8   , KC_F9   , KC_F12  ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      OS_GUI  , OS_CTL  , OS_ALT  , OS_SFT  ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_F4   , KC_F5   , KC_F6   , KC_F11  ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_F1   , KC_F2   , KC_F3   , KC_F10  ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   , TT_ESC  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),

// ....................................................................... Regex

  [_TTREGEX] = KEYMAP( 
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   , KC_DOT  , KC_ASTR , KC_AMPR , KC_PIPE ,  __x__  ,  __x__  , KC_ASTR , KC_LBRC , KC_CIRC , KC_RBRC ,   ___   ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   , KC_LT   , KC_PERC , KC_GT   , KC_QUES ,  __x__  ,  __x__  , KC_QUES , KC_LPRN , KC_DLR  , KC_RPRN ,   ___   ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   , KC_PLUS , KC_AT   , KC_SLSH , KC_EXLM ,  __x__  ,  __x__  , KC_PIPE , KC_LCBR , KC_HASH , KC_RCBR ,   ___   ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   , TT_ESC  , TD_EQL  , KC_BSLS , KC_DEL  ,   ___   ,   ___   ,   ___   ,   ___   
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),

// ............................................................ Navigation Layer

  [_TTCURSOR] = KEYMAP( 
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_HOME , KC_UP   , KC_END  , KC_PGUP ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
      OS_GUI  , OS_CTL  , OS_ALT  , OS_SFT  ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,  __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   , TT_ESC  ,   ___   ,  __x__  ,  __x__  ,   ___   ,   ___   ,   ___   ,   ___   
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),

// ............................................................... Mouse Actions

  [_TTMOUSE] = KEYMAP( 
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_WH_L , KC_MS_U , KC_WH_R , KC_WH_U ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   , KC_BTN3 , KC_BTN2 , KC_BTN1 ,   ___   ,  __x__  ,  __x__  ,   ___   , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,  __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
        ___   ,   ___   ,   ___   ,   ___   , TT_ESC  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   
  // ---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------
  ),
