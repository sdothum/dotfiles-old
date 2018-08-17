
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// .............................................................. CapsLock Layer

  // ,-----------------------------------------------------------------------------------.
  // |   ;  |   Y  |   O  |   U  |   Z  |  Fn  | Caps |   G  |   D  |   N  |   M  |   X  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |   Q  |   H  |   E  |   A  |   .  |Cursor| Mouse|   C  |   T  |   R  |   S  |   W  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |   J  |   -  |   '  |   K  |   ,  |  Num | Regex|   B  |   P  |   L  |   F  |   V  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |      |      |      |  Esc |   I  |      |      | Space| Bksp |      |      |      |
  // `-----------------------------------------------------------------------------------'

  [_TTCAPS] = {
    {KC_SCLN, S(KC_Y), S(KC_O), S(KC_U), S(KC_Z), CNTR_TL, CNTR_TR, S(KC_G), S(KC_D), S(KC_N), S(KC_M), S(KC_X)},
    {S(KC_Q), S(KC_H), S(KC_E), S(KC_A), KC_DOT,  CNTR_HL, CNTR_HR, S(KC_C), S(KC_T), S(KC_R), S(KC_S), S(KC_W)},
    {S(KC_J), KC_MINS, KC_QUOT, S(KC_K), KC_COMM, CNTR_BL, CNTR_BR, S(KC_B), S(KC_P), S(KC_L), S(KC_F), S(KC_V)},
    {_______, _______, _______, TT_ESC,  S(KC_I), _______, _______, ST_SPC,  KC_BSPC, _______, _______, _______},
  },

// ......................................................... Number Keypad Layer

  // .-----------------------------------------------------------------------------------.
  // |      |   F  |   E  |   D  |      |      |      |   /  |   7  |   8  |   9  |   *  |
  // |-----------------------------------------------------------------------------------|
  // |  GUI |   C  |   B  |   A  |      |      |      |   .  |   4  |   5  |   6  |   -  |
  // |-----------------------------------------------------------------------------------|
  // |      |   #  |   G  |   \  |      |      |      |   ,  |   1  |   2  |   3  |   +  |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |  f() | Space|      |      |   0  |   =  |      |      |      |
  // |      |      |      |  f() | Space|      |      |   =  |   0  |      |      |      |
  // '-----------------------------------------------------------------------------------'

  [_TTNUMBER] = {
    {_______, KC_F,    MT_E,    KC_D,    _______, ___x___, ___x___, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_ASTR},
    {OS_GUI,  CT_C,    AT_B,    ST_A,    _______, ___x___, ___x___, TD_DOT,  KC_4,    KC_5,    KC_6,    KC_MINS},
    {_______, KC_HASH, SM_G,    KC_BSLS, _______, ___x___, ___x___, TD_COMM, KC_1,    KC_2,    KC_3,    KC_PLUS},
#ifdef THUMB_0
    {_______, _______, _______, TT_ESC,  KC_SPC,  _______, _______, KC_0,    KC_EQL,  _______, _______, _______},
#else
    {_______, _______, _______, TT_ESC,  KC_SPC,  _______, _______, KC_EQL,  KC_0,    _______, _______, _______},
#endif
  },

// ............ .................................................. Function Keys

  // .-----------------------------------------------------------------------------------.
  // |      |      |      |      |      |      |      |      |  F7  |  F8  |  F9  |  F12 |
  // |-----------------------------------------------------------------------------------|
  // |  GUI | Ctrl |  Alt | Shift|      |      |      |      |  F4  |  F5  |  F6  |  F11 |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F10 |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |  f() |      |      |      |   +  |      |      |      |      |
  // '-----------------------------------------------------------------------------------'

  [_TTFNCKEY] = {
    {_______, _______, _______, _______, _______, ___x___, ___x___, _______, KC_F7,   KC_F8,   KC_F9,   KC_F12 },
    {OS_GUI,  OS_CTL,  OS_ALT,  OS_SFT,  _______, ___x___, ___x___, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11 },
    {_______, _______, _______, _______, _______, ___x___, ___x___, _______, KC_F1,   KC_F2,   KC_F3,   KC_F10 },
    {_______, _______, _______, TT_ESC,  _______, _______, _______, KC_PLUS, _______, _______, _______, _______},
  },

// ....................................................................... Regex

  // ,-----------------------------------------------------------------------------------.
  // |      |   .  |   *  |   &  |   ~  |      |      |   `  |   [  |   ^  |   ]  |      |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |      |   <  |   %  |   >  |   ?  |      |      |   |  |   (  |   $  |   )  |      |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |      |   :  |   @  |   !  |   /  |      |      |   \  |   {  |   #  |   }  |      |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |      |      |      |  f() |   =  |      |      |   +  | Space|      |      |      |
  // `-----------------------------------------------------------------------------------'

  [_TTREGEX] = {
    {___x___, KC_DOT,  KC_ASTR, KC_AMPR, KC_TILD, ___x___, ___x___, KC_GRV,  KC_LBRC, KC_CIRC, KC_RBRC, ___x___},
    {___x___, KC_LT,   KC_PERC, KC_GT,   KC_QUES, ___x___, ___x___, KC_PIPE, KC_LPRN, KC_DLR,  KC_RPRN, ___x___},
    {___x___, KC_COLN, KC_AT,   KC_EXLM, KC_SLSH, ___x___, ___x___, KC_BSLS, KC_LCBR, KC_HASH, KC_RCBR, ___x___},
    {_______, _______, _______, TT_ESC,  KC_EQL,  _______, _______, KC_PLUS, KC_SPC,  _______, _______, _______},
  },

// ............................................................ Navigation Layer

  // .-----------------------------------------------------------------------------------.
  // |      |      |      |      |      |      |      |      | Home |  Up  |  End | PgUp |
  // |-----------------------------------------------------------------------------------|
  // |  GUI | Ctrl |  Alt | Shift|      |      |      |      | Left | Down | Right| PgDn |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |  f() |      |      |      |      |      |      |      |      |
  // '-----------------------------------------------------------------------------------'

  [_TTCURSOR] = {
    {_______, _______, _______, _______, _______, ___x___, ___x___, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP},
    {OS_GUI,  OS_CTL,  OS_ALT,  OS_SFT,  _______, ___x___, ___x___, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN},
    {_______, _______, _______, _______, _______, ___x___, ___x___, _______, _______, _______, _______, _______},
    {_______, _______, _______, TT_ESC,  _______, _______, _______, _______, _______, _______, _______, _______},
  },

// ............................................................... Mouse Actions

  // .-----------------------------------------------------------------------------------.
  // |      |      |      |      |      |      |      |      | Left |  Up  | Right|  Up  |
  // |-----------------------------------------------------------------------------------|
  // |      | Btn3 | Btn2 | Btn1 |      |      |      |      | Left | Down | Right| Down |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // |-----------------------------------------------------------------------------------|
  // |      |      |      |  f() |      |      |      |      |      |      |      |      |
  // '-----------------------------------------------------------------------------------'

  [_TTMOUSE] = {
    {_______, _______, _______, _______, _______, ___x___, ___x___, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U},
    {_______, KC_BTN3, KC_BTN2, KC_BTN1, _______, ___x___, ___x___, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D},
    {_______, _______, _______, _______, _______, ___x___, ___x___, _______, _______, _______, _______, _______},
    {_______, _______, _______, TT_ESC,  _______, _______, _______, _______, _______, _______, _______, _______},
  },
