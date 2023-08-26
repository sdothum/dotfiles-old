// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ......................................................... Mouse Pointer Layer

  [_MOUSE] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,                        ___   , KC_WH_L , KC_MS_U , KC_WH_R , KC_WH_U ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   , KC_BTN3 , KC_BTN2 , KC_BTN1 ,   ___   ,                        ___   , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
       __x__  ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,                        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,  __x__  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                                ___   ,   ___   ,   ___   ,    ___   ,   ___   ,  __x__  
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

// .......................................................... Application Chords

  [_EDIT] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
        ___   ,   ___   ,   ___   , XCOPY   , XPASTE  , TD_PRIV ,                        ___   , KC_HOME , KC_UP   , KC_END ,  KC_PGUP ,   ___   ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
        ___   , UNDO    , CUT     , COPY    , PASTE   , TD_SEND ,                        ___   , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN ,   ___   ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
        ___   ,   ___   ,   ___   , NAK     , EOT     , DEBUG   ,                        ___   ,   ___   ,   ___   ,   ___   ,   ___   ,   ___   ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                                ___   ,   ___   ,   ___   ,   __x__  ,   ___   ,   ___   
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),

// ........................................................................ Test
#ifdef TEST
  [_TEST] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      KC_1    , KC_Q    , KC_Y    , KC_O    , KC_U    , KC_COLN ,                      KC_G    , KC_D    , KC_N    , KC_M    , KC_Z    , KC_1    ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      KC_2    , KC_J    , KC_H    , KC_E    , KC_A    , KC_TILD ,                      KC_C    , KC_T    , KC_R    , KC_S    , KC_B    , KC_2    ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      KC_3    , KC_X    , KC_MINS , KC_QUOT , KC_K    , KC_COMM ,                      KC_W    , KC_P    , KC_L    , KC_F    , KC_V    , KC_3    ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              KC_0    , LT_I    , KC_2    ,  KC_3    , KC_4    , KC_5 
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),
#endif
