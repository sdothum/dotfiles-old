
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// .............................................................. CapsLock Layer

  [_TTCAPS] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  , HS_COLN , S(KC_Y) , S(KC_O) , S(KC_U) , KC_MINS ,                      S(KC_G) , S(KC_D) , S(KC_N) , S(KC_M) , S(KC_Z) ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+
       __x__  , S(KC_Q) , S(KC_H) , S(KC_E) , TT_A    , S(KC_W) ,                      S(KC_C) , TT_T    , S(KC_R) , S(KC_S) , S(KC_V) ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+
       __x__  , S(KC_J) , KC_COMM , KC_DOT  , S(KC_K) , KC_QUOT ,                      S(KC_B) , S(KC_P) , S(KC_L) , S(KC_F) , S(KC_X) ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              TT_ESC  , TT_I    , TT_TAB  ,  KC_ENT  , TT_SPC  , KC_BSPC 
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

  [_TTBASEL] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  , HS_COLN , KC_Y    , KC_O    , KC_U    , KC_MINS ,                      KC_G    , KC_D    , KC_N    , KC_M    , KC_Z    ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+
       __x__  , KC_Q    , KC_H    , KC_E    ,  __x__  , KC_W    ,                      KC_C    , KC_T    , KC_R    , KC_S    , KC_V    ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+
       __x__  , KC_J    , KC_COMM , KC_DOT  , KC_K    , KC_QUOT ,                      KC_B    , KC_P    , KC_L    , KC_F    , KC_X    ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                               __x__  , KC_I    , KC_TAB  ,  KC_ENT  , KC_SPC  , KC_DEL  
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

  [_TTBASER] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  , KC_SCLN , KC_Y    , KC_O    , KC_U    , KC_UNDS ,                      KC_G    , KC_D    , KC_N    , KC_M    , KC_Z    ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+
       __x__  , KC_Q    , KC_H    , KC_E    , KC_A    , KC_W    ,                      KC_C    ,  __x__  , KC_R    , KC_S    , KC_V    ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+
       __x__  , KC_J    , KC_GRV  , HS_TILD , KC_K    , KC_DQT  ,                      KC_B    , KC_P    , KC_L    , KC_F    , KC_X    ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                               __x__  , KC_I    , BKTAB   ,  KC_ENT  , KC_SPC  , KC_BSPC 
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

// ....................................................... Numberic Keypad Layer

  [_TTNUMBER] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
#ifdef UPPER_HEX
       __x__  ,   ___   , S(KC_A) , ACT_B   , S(KC_C) ,   ___   ,                      KC_SLSH , KC_4    , KC_5    , KC_9    , KC_ASTR ,  __x__  ,
#else                                                                                                                    
       __x__  ,   ___   , KC_A    , ACT_B   , KC_C    ,   ___   ,                      KC_SLSH , KC_4    , KC_5    , KC_9    , KC_ASTR ,  __x__  ,
#endif                                                                                                                   
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  , OS_GUI  , CT_D    , AT_E    , ST_F    ,   ___   ,                      TD_DOT  , KC_1    , KC_2    , KC_3    , KC_MINS ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   , KC_LBRC , AST_G   , KC_RBRC ,   ___   ,                      TD_COMM , KC_8    , KC_6    , KC_7    , KC_PLUS ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              TT_ESC  , KC_SPC  ,   ___   ,  KC_BSLS , KC_0    , KC_EQL 
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

// ............ .................................................. Function Keys

  [_TTFNCKEY] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,                        ___   , KC_F4 ,   KC_F5 ,   KC_F9   , KC_F12  ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  , OS_GUI ,  OS_CTL ,  OS_ALT ,  OS_SFT ,    ___   ,                        ___   , KC_F1 ,   KC_F2 ,   KC_F3   , KC_F11  ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,                        ___   , KC_F8 ,   KC_F6 ,   KC_F7   , KC_F10  ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              TT_ESC  ,   ___   ,   ___   ,    ___   ,   ___   ,   ___   
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

// ....................................................................... Regex

  [_TTREGEX] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   , KC_DOT  , KC_ASTR , KC_AMPR , KC_PLUS ,                      TD_ASTR , KC_LBRC , KC_CIRC , KC_RBRC ,   ___   ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   , KC_QUES , KC_EXLM , KC_SLSH , KC_PIPE ,                      KC_QUES , KC_LPRN , KC_DLR ,  KC_RPRN ,   ___   ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   , HS_LT   , HS_GT   , KC_PERC , KC_AT   ,                      KC_PIPE , KC_LCBR , KC_HASH , KC_RCBR ,   ___   ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              TT_ESC  , HS_EQL  , KC_BSLS ,  KC_ENT  , KC_BSLS , KC_DEL  
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

// ............................................................ Navigation Layer

  [_TTCURSOR] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,                        ___   , KC_HOME , KC_UP   , KC_END ,  KC_PGUP ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  , OS_GUI  , OS_CTL  , OS_ALT  , OS_SFT  ,   ___   ,                        ___   , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,                        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              TT_ESC  ,   ___   ,   ___   ,    ___   ,   ___   ,   ___   
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

// ............................................................... Mouse Actions

  [_TTMOUSE] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,                        ___   , KC_WH_L , KC_MS_U , KC_WH_R , KC_WH_U ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   , KC_BTN3 , KC_BTN2 , KC_BTN1 ,   ___   ,                        ___   , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,                        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              TT_ESC  ,   ___   ,   ___   ,    ___   ,   ___   ,   ___   
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),
