// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ......................................................... Mouse Pointer Layer

  [_MOUSE] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      _______ , KC_WH_L , KC_MS_U , KC_WH_R , KC_WH_U , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      ___x___ , _______ , KC_BTN3 , KC_BTN2 , KC_BTN1 , _______ ,                      _______ , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      _______ , _______ , _______ , _______ , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              _______ , _______ , _______ ,  _______ , _______ , ___fn__ 
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

// .......................................................... Application Chords

  [_EDIT] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      _______ , _______ , _______ , XCOPY   , XPASTE  , TD_PRIV ,                      _______ , KC_HOME , KC_UP   , KC_END ,  KC_PGUP , _______ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      _______ , UNDO    , CUT     , COPY    , PASTE   , TD_SEND ,                      _______ , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN , _______ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      _______ , _______ , _______ , NAK     , EOT     , DEBUG   ,                      _______ , _______ , _______ , _______ , _______ , _______ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              _______ , _______ , _______ ,  ___fn__ , _______ , _______ 
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

// ........................................................................ Test
#ifdef TEST
  [_TEST] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      KC_1    , KC_Q    , KC_Y    , KC_O    , KC_U    , KC_COLN ,                      KC_G    , KC_D    , KC_N    , KC_M    , KC_X    , KC_1    ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      KC_2    , KC_J    , KC_H    , KC_E    , KC_A    , KC_TILD ,                      KC_C    , KC_T    , KC_R    , KC_S    , KC_W    , KC_2    ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      KC_3    , KC_Z    , KC_MINS , KC_QUOT , KC_K    , KC_COMM ,                      KC_B    , KC_P    , KC_L    , KC_F    , KC_V    , KC_3    ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              KC_0    , LT_I    , KC_2    ,  KC_3    , KC_4    , KC_5 
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),
#endif
