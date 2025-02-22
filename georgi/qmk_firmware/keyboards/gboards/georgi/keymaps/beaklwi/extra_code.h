
// shorter version max refactoring (defaults removed: does not change code size)

void cap(const struct Chord* self) {
  switch (*self->state) {
  case ACTIVATED:
    tap_key(self->value1);
    tap_key(self->value2);
    break;
  case DEACTIVATED:
    current_pseudolayer = CAPS;
    *self->state = IN_ONE_SHOT;
    break;
  case FINISHED:
  case PRESS_FROM_ACTIVE:
    current_pseudolayer = CAPS;
    a_key_went_through = false;
    break;
  case RESTART:
    if (a_key_went_through) {
      current_pseudolayer = self->pseudolayer;
    } else {
      *self->state = IN_ONE_SHOT;
    }
  }
}

static uint16_t postfix = KC_G;
static uint8_t postcap = 0;
static uint16_t pairs[][3] = { {KC_NO, KC_LBRC, KC_RBRC}, {KC_LSFT, KC_9, KC_0}, {KC_LSFT, KC_LCBR, KC_RCBR} };
static uint8_t bracket = 0;

void output(int16_t modifier, int16_t keycode) {
  key_in(modifier);
  tap_key(keycode);
  key_out(modifier);
}

void hexpad(const struct Chord* self) {
  switch (*self->state) {
  case ACTIVATED:
    switch (self->value1) {
    case 0:
      switch (self->value2) {
      case 1:
        postfix = postfix == KC_G ? KC_SPC : KC_G;
        break;
      case 2:
        bracket = (bracket == 0) ? 1 : ((bracket == 1) ? 2 : 0);
        break;
      case 0:
        current_pseudolayer = BEAKL;
        if (!postcap) {
          break;
        }
      case 3:
        tap_key(KC_CAPS);
        postcap = !postcap;
      }
      break;
    case 1:
      output(postcap == 0 ? KC_LSFT : KC_NO, postfix);
      break;
    case 2:
      output(pairs[bracket][0], pairs[bracket][self->value2]);
    }
  }
}

static uint8_t harmonic = 0;

#define interval(k) if (record->event.pressed) { harmonic |= k; if (harmonic == 3) { layer_move(0); return false; } } else { harmonic &= ~k; } break

bool process_steno_user(uint16_t keycode, keyrecord_t *record) { 
  switch (keycode) {
  case STN_FN:
    interval(1);
  case STN_PWR:
    interval(2);
  }
  return true;
}

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}

// json paste

void cap(const struct Chord* self) {\n   switch (*self->state) {\n   case ACTIVATED:\n     tap_key(self->value1);\n     tap_key(self->value2);\n     break;\n   case DEACTIVATED:\n     current_pseudolayer = CAPS;\n     *self->state = IN_ONE_SHOT;\n     break;\n   case FINISHED:\n   case PRESS_FROM_ACTIVE:\n     current_pseudolayer = CAPS;\n     a_key_went_through = false;\n     break;\n   case RESTART:\n     if (a_key_went_through) {\n       current_pseudolayer = self->pseudolayer;\n     } else {\n       *self->state = IN_ONE_SHOT;\n     }\n   }\n }\n \n static uint16_t postfix = KC_G;\n static uint8_t postcap = 0;\n static uint16_t pairs[][3] = { {KC_NO, KC_LBRC, KC_RBRC}, {KC_LSFT, KC_9, KC_0}, {KC_LSFT, KC_LCBR, KC_RCBR} };\n static uint8_t bracket = 0;\n \n void output(int16_t modifier, int16_t keycode) {\n   key_in(modifier);\n   tap_key(keycode);\n   key_out(modifier);\n }\n \n void hexpad(const struct Chord* self) {\n   switch (*self->state) {\n   case ACTIVATED:\n     switch (self->value1) {\n     case 0:\n       switch (self->value2) {\n       case 1:\n         postfix = postfix == KC_G ? KC_SPC : KC_G;\n         break;\n       case 2:\n         bracket = (bracket == 0) ? 1 : ((bracket == 1) ? 2 : 0);\n         break;\n       case 0:\n         current_pseudolayer = BEAKL;\n         if (!postcap) {\n           break;\n         }\n       case 3:\n         tap_key(KC_CAPS);\n         postcap = !postcap;\n       }\n       break;\n     case 1:\n       output(postcap == 0 ? KC_LSFT : KC_NO, postfix);\n       break;\n     case 2:\n       output(pairs[bracket][0], pairs[bracket][self->value2]);\n     }\n   }\n }\n \n static uint8_t harmonic = 0;\n \n #define interval(k) if (record->event.pressed) { harmonic |= k; if (harmonic == 3) { layer_move(0); return false; } } else { harmonic &= ~k; } break\n \n bool process_steno_user(uint16_t keycode, keyrecord_t *record) { \n   switch (keycode) {\n   case STN_FN:\n     interval(1);\n   case STN_PWR:\n     interval(2);\n   }\n   return true;\n }\n \n void matrix_init_user() {\n   steno_set_mode(STENO_MODE_GEMINI);\n }\n 
