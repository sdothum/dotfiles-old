
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// .................................................. Symbols / Navigation Layer

  [_SYMGUI] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      ___x___ , _______ , KC_DOT  , KC_ASTR , KC_AMPR , KC_PIPE ,                      _______ , KC_HOME , KC_UP   , KC_END ,  KC_PGUP , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      ___x___ , OS_GUI  , HS_LT   , TD_PERC , HS_GT   , KC_QUES ,                      _______ , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      ___x___ , _______ , KC_PLUS , KC_AT   , KC_EXLM , KC_SLSH ,                      _______ , _______ , _______ , _______ , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              KC_ESC  , KC_BSLS , TD_EQL  ,  _______ , ___fn__ , _______ 
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),


// ................................................................. Regex Layer

  [_REGEX] = KEYMAP(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      TD_ASTR , KC_LBRC , KC_CIRC , KC_RBRC , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      KC_PIPE , KC_LPRN , KC_DLR ,  KC_RPRN , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
      ___x___ , _______ , _______ , _______ , _______ , _______ ,                      KC_SLSH , KC_LCBR , KC_HASH , KC_RCBR , _______ , ___x___ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- 
                                              _______ , ___fn__ , _______ ,  KC_ENT  , KC_BSLS , KC_DEL 
  //                                         ---------+---------+---------  ---------+---------+--------- 
  ),
