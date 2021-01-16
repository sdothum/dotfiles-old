// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
//
// To flash corne / chimera / planck firmware
// ═════════════════════════
//   Reset keyboard or press hw reset button on base
//
//   cd qmk_firmware/keyboards/<keyboard>
//   sudo make KEYMAP=<keymap> dfu
//
//   sudo make clean           (good practice before flashing)
//   sudo make KEYMAP=<keymap> (to compile check)
//
// Package requirements (for arch linux)
// ═════════════════════════════════════
//   avr-gcc-atmel
//   avr-libc-atmel
//   dfu-programmer
//
// Notes
// ═════
//   ** E R G O   W I D E   S P L I T ** Layout
//
//   Autocompletion tap dance key pairs (),[],{} are available from the
//   number/symbol layer, as well as, numerous (un)shift key values
//
//   #define PRIVATE_STRING includes private_string.h, a user defined code
//   block for the PRIV tap dance e.g. SEND_STRING("secret messape"),
//   see function private()
//
// Code
// ════
//   This source is shamelessly based on the "default" planck layout
//
//   #ifdef/#endif block structures are not indented, as syntax highlighting
//   in vim is sufficient for identification
//
//   c++ commenting style is used throughout
//
// Change history
// ══════════════
//   See http://thedarnedestthing.com/colophon
//
//                === N O T E ===
//
// sudo CPATH=<keymap.c directory>/common make ...

// Hardware
// ═════════════════════════════════════════════════════════════════════════════

#ifdef CORNE
#define KEYMAP LAYOUT
#include QMK_KEYBOARD_H
#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif
extern uint8_t is_master;
#endif

#ifdef CHIMERA
// #include "config.h"
#include "chimera_ergo_42.h"
// #include "action_layer.h"
// #include "eeconfig.h"
// extern keymap_config_t keymap_config;
#endif

#ifdef PLANCK
#include "config.h"
#include "planck.h"
#include "action_layer.h"
#ifdef STENO_ENABLE
#include "keymap_steno.h"
#endif
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "eeconfig.h"
#endif

// Keymaps
// ═════════════════════════════════════════════════════════════════════════════

extern keymap_config_t keymap_config;

// ...................................................................... Layers

enum keyboard_layers {
  _BASE = 0
 ,_SHIFT
 ,_TTCAPS
 ,_SYMGUI
 ,_REGEX
 ,_MOUSE
 ,_NUMBER
 ,_FNCKEY
 ,_EDIT
 ,_TTBASEL
 ,_TTBASER
 ,_TTFNCKEY
 ,_TTCURSOR
 ,_TTMOUSE
 ,_TTNUMBER
 ,_TTREGEX
#ifdef PLANCK
 ,_PLOVER
 ,_ADJUST
#endif
#ifdef TEST
 ,_TEST
#endif
 ,_END_LAYERS
};

// .................................................................... %eycodes

enum keyboard_keycodes {
  BASE = SAFE_RANGE
#ifdef PLANCK
 ,BASE1
 ,BASE2
 ,PLOVER
#endif
#ifdef ROLLOVER
 ,HOME_Q   // pseudo GUI_T(KC_Q)
 ,HOME_H   // pseudo CTL_T(KC_H)
 ,HOME_E   // pseudo ALT_T(KC_E)
 ,HOME_A   // pseudo SFT_T(KC_A)
 ,HOME_T   // pseudo SFT_T(KC_T)
 ,HOME_R   // pseudo ALT_T(KC_R)
 ,HOME_S   // pseudo CTL_T(KC_S)
#endif
 ,STAGGER  // cycle pinkie home row stagger 0 -> 1 -> 2
 ,PINKY3   // <pinkie>
 ,PINKY2   // pseudo GUI_T(<pinkie>)
 ,PINKY1   // <pinkie>
 ,KEY3     // <pinkie>
 ,KEY2     // <pinkie>
 ,KEY1     // <pinkie>
 ,SHIFT3   // SFT(<pinkie>)
 ,SHIFT2   // SFT(<pinkie>)
 ,SHIFT1   // SFT(<pinkie>)
#ifdef HASKELL
 ,HS_GT    // pseudo SFT_T(S(KC_DOT))
 ,HS_LT    // pseudo CTL_T(S(KC_COMM))
#endif
 ,HEXCASE  // capslock hex
 ,HEX_A
 ,HEX_B    // pseudo MT(MOD_LALT | MOD_LCTL, S(KC_B))
 ,HEX_C
 ,HEX_D    // pseudo CTL_T(S(KC_D))
 ,HEX_E    // pseudo ALT_T(S(KC_E))
 ,HEX_F    // pseudo SFT_T(S(KC_F))
 ,BRKTYPE  // cycle brkts [] -> () -> {}
 ,L_BRKT
 ,R_BRKT   // pseudo MT(MOD_LALT | MOD_LSFT, R_BRKT)
 ,SMART
 ,DELIM
 ,TT_ESC
 ,TT_A     // pseudo LT(_TTBASEL, S(KC_A))
 ,TT_I     // pseudo LT(_REGEX,   S(KC_I))
 ,TT_T     // pseudo LT(_TTBASER, S(KC_T))
 ,TT_SPC   // pseudo LT(_SYMGUI,  KC_SPC)
};

#ifndef ROLLOVER
#define HOME_Q  GUI_T(KC_Q)
#define HOME_H  CTL_T(KC_H)
#define HOME_E  ALT_T(KC_E)
#define HOME_A  SFT_T(KC_A)
#define HOME_T  SFT_T(KC_T)
#define HOME_R  ALT_T(KC_R)
#define HOME_S  CTL_T(KC_S)
#endif

#include "tapdance.h"

// pass through keycodes
#define __x__   KC_TRNS
#define ___     KC_NO

// tap dance macros
#ifndef EQLEQL
#define HS_EQL  TD_EQL
#else
#define HS_EQL  KC_EQL
#endif
#ifdef HASKELL
#define HS_COLN TD_COLN
#define HS_GT   TD_GT
#define HS_LT   TD_LT
#else
#define HS_COLN KC_COLN
#define HS_GT   KC_GT
#define HS_LT   KC_LT
#endif
#ifdef UNIX
#define HS_TILD TD_TILD
#else
#define HS_TILD KC_TILD
#endif

// editing macros
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define EOT     LCTL(KC_D)
#define NAK     LCTL(KC_U)
#define PASTE   TD_PASTE
#define UNDO    LCTL(KC_Z)
#define XCOPY   LCTL(LSFT(KC_C))
#define XPASTE  TD_XPASTE

// thumb keys
#define BKTAB   S (KC_TAB)
#define LT_BSPC LT(_MOUSE, KC_BSPC)
#define LT_ESC  LT(_FNCKEY, KC_ESC)
#ifdef ROLLOVER
#define LT_ENT  MO(_EDIT)    // plus mod_roll() -> LT(_EDIT, KC_ENT)
#define LT_I    MO(_REGEX)   // plus mod_roll() -> LT(_REGEX, KC_I)
#define LT_SPC  MO(_SYMGUI)  // plus mod_roll() -> LT(_SYMGUI, KC_SPC)
#else
#define LT_ENT  LT(_EDIT, KC_ENT)
#define LT_I    LT(_REGEX, KC_I)
#define LT_SPC  LT(_SYMGUI, KC_SPC)
#endif
#define LT_TAB  LT(_NUMBER, KC_TAB)

// fnkey layer macros
#define OS_ALT  OSM(MOD_LALT)
#define OS_CTL  OSM(MOD_LCTL)
#define OS_GUI  OSM(MOD_LGUI)
#define OS_SFT  OSM(MOD_LSFT)

// layer toggle macros
#define TGL_TL  TT(_TTFNCKEY)
#define TGL_HL  TT(_TTCAPS)
#define TGL_BL  TT(_TTMOUSE)
#define TGL_TR  TT(_TTREGEX)
#define TGL_HR  TT(_TTNUMBER)
#define TGL_BR  TT(_TTCURSOR)
#ifdef PLANCK
#define MO_ADJ  MO(_ADJUST)
#endif

#ifdef TEST
#define FLASH   TG(_TEST)
#else
#ifdef CORNE
#define FLASH   RESET
#else
#define FLASH   KC_NO
#endif
#endif

// Layers
// ═════════════════════════════════════════════════════════════════════════════

// ........................................................ Default Alpha Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#include "base_layout.h"
#ifdef PLANCK
#include "steno_layout.h"
#endif

// ...................................................... Number / Function Keys

#include "number_fkey_layout.h"

// ......................................................... Symbol / Navigation

#include "symbol_guifn_layout.h"

// ............................................................... Toggle Layers

#include "toggle_layout.h"

// .............................................................. Mouse / Chords

#include "mouse_chord_layout.h"

};

#ifdef PLANCK
// ...................................................................... Sounds

#include "sounds.h"
#endif

// User Keycode Trap
// ═════════════════════════════════════════════════════════════════════════════

#include "keycode_functions.c"
#include "tapdance.c"

// ..................................................... Dynamic Pinkie Stagger!

static uint16_t pinkies[][3] = { {KC_X, KC_V, KC_Z},    // ZVX beakl wi (row 3 -> 1)
                                 {KC_V, KC_X, KC_Z},    // ZXV beakl wi-v
                                 {KC_V, KC_Z, KC_X} };  // XZV beakl wi-x
static uint8_t  stagger      = PINKIE_STAGGER;          // pinkie on (0) home row (1,2) bottom row stagger variant, see case STAGGER

#define PINKIE(r) pinkies[stagger][r - 1]

// ............................................................... Keycode Cycle

#define LEADERCAP         { leadercap = KEY_DOWN ? 1 : 0; }
#define MOD_ROLL(m, k, c) mod_roll(record, m, 0, 0, k, c)

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
#ifdef CORNE
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
#endif

  if (reshifted && !mod_down(KC_LSFT)) { unregister_code(KC_LSFT); reshifted = 0; }  // see map_shift()

  // ............................................................ Smart Vim Goto

static uint16_t postfix    = KC_SPC;  // see case DELIM
static bool     numerating = 0;       // see case LT_TAB
static bool     smart      = 1;       // see case SMART

#ifdef SMART_DELIM
  if (numerating && smart) {
    switch (keycode) {
    case KC_0:
      LEADERCAP;  // DELIM -> 0x
    case KC_1:
    case KC_2:
    case KC_3:
    case KC_4:
    case KC_5:
    case KC_6:
    case KC_7:
    case KC_8:
    case KC_9:
      postfix = KC_G;
      break;
    case DELIM:
      break;
    default:
      postfix = KC_SPC;
    }
  } else { postfix = KC_SPC; }
#endif

  // ........................................................ Home Row Modifiers

  switch (keycode) {
#ifdef ROLLOVER
  case HOME_Q:
    MOD_ROLL(KC_LGUI, KC_Q, 0);         break;
  case HOME_H:
    MOD_ROLL(KC_LCTL, KC_H, 1);         break;
  case HOME_E:
    MOD_ROLL(KC_LALT, KC_E, 2);         break;
  case HOME_A:
    LEADERCAP;  // space/enter + shift shortcut, see leader_cap()
    MOD_ROLL(KC_LSFT, KC_A, 3);         break;

  case HOME_T:
    MOD_ROLL(KC_RSFT, KC_T, 6);         break;
  case HOME_R:
    MOD_ROLL(KC_RALT, KC_R, 7);         break;
  case HOME_S:
    MOD_ROLL(KC_RCTL, KC_S, 8);         break;
  case PINKY2:
    MOD_ROLL(KC_RGUI, PINKIE(2), 9);    break;
#else
  case HOME_A:
    LEADERCAP;  // space/enter + shift shortcut, see leader_cap()
    mod_bits(record, KC_LSFT);          break;
  case HOME_T:
    mod_bits(record, KC_RSFT);          break;
  case PINKY2:
    toggle(record, KC_RGUI, PINKIE(2)); break;
#endif

  // ............................................................. Toggle Layers

static uint8_t dual_down = 0;  // dual keys down (2 -> 1 -> 0) reset on last up stroke, see case TGL_TL, TGL_TR

#define RESET(s) { if (raise_layer(record, 0, s, TOGGLE)) { dual_down = 2; return false; }                      \
                   if (dual_down)                         { dual_down--; base_layer(dual_down); return false; } \
                   tt_escape(record, keycode); }

  case TGL_TL:
    RESET(LEFT);                break;
  case TGL_TR:
    RESET(RIGHT);               break;
  case TGL_HL:
  case TGL_HR:
  case TGL_BL:
  case TGL_BR:
    tt_escape(record, keycode); break;

  // ........................................................... Left Thumb Keys

  case TT_ESC:
    base_layer(0);
    return false;  // exit TT layer
  case LT_ESC:
    if (tt_keycode)                                          { base_layer(0); return false; }
    break;

  case LT_I:
#ifdef LEFT_SPC_ENT
    if (map_shifted(record, KC_LSFT, LOWER, KC_SPC, _REGEX)) { return false; }  // non-autorepeating
#endif
#ifdef ROLLOVER
    if (MOD_ROLL(0, KC_I, 4))                                { return false; }  // MO(_REGEX) -> LT(_REGEX, KC_I)
#endif
    break;
  case TT_I:
    layer_toggle(record, _REGEX, UPPER, KC_I);
    break;

  case LT_TAB:
    numerating = KEY_DOWN ? 1 : 0;
#ifdef LEFT_SPC_ENT
    if (map_shift(record, KC_LSFT, LOWER, KC_ENT))           { return false; }
#endif
    if (map_shift(record, KC_RSFT, UPPER, KC_TAB))           { return false; }
    break;

  // .......................................................... Right Thumb Keys

#ifdef ROLLOVER
  case LT_ENT:
    leaderlayer = _EDIT;                                              // see mod_roll()
    if (MOD_ROLL(0, KC_ENT, 10))                   { return false; }  // KC_ENT -> enter shift
    break;
  case KC_ENT:
    if (MOD_ROLL(0, KC_ENT, 10))                   { return false; }  // KC_ENT from LT_ENT -> enter enter* shift
    break;

  case LT_SPC:
    leaderlayer = _SYMGUI;                                            // see mod_roll()
    if (MOD_ROLL(0, KC_SPC, 11))                   { return false; }  // KC_SPC -> space shift
    break;
#else
  case LT_ENT:
    if (leader_cap(record, _EDIT, KC_ENT))         { return false; }  // KC_ENT -> enter shift
    break;
  case KC_ENT:
    if (leader_cap(record, 0, KC_ENT))             { return false; }  // KC_ENT from LT_ENT -> enter enter* shift
    break;

  case LT_SPC:
    if (leader_cap(record, _SYMGUI, KC_SPC))       { return false; }  // KC_SPC -> space shift
    break;
#endif
  case TT_SPC:
    layer_toggle(record, _SYMGUI, LOWER, KC_SPC);
    break;
  case KC_SPC:
    if (!KEY_DOWN) { CLR_1SHOT; }  // see leader_cap()
    break;

  case LT_BSPC:
  case KC_BSPC:
    if (!KEY_DOWN) { CLR_1SHOT; }  // see leader_cap()
    if (map_shift(record, KC_LSFT, LOWER, KC_DEL)) { layer_off(_SYMGUI); return false; }  // rolling cursor to del
    if (map_shift(record, KC_RSFT, LOWER, KC_DEL)) { return false; }
    break;

  // .................................................................. HEX Keys

static bool hexcase = HEXADECIMAL_CASE;  // hex case (0) lower case abcdef (1) upper case ABCDEF, see case HEXCASE

#ifdef ROLLOVER
#define HEX(m, m2, k, c) mod_roll(record, m, m2, hexcase, k, c)

  case HEX_A:
    HEX(0, 0, KC_A, 1);             break;
  case HEX_B:
    HEX(KC_LALT, KC_LCTL, KC_B, 2); break;
  case HEX_C:
    HEX(0, 0, KC_C, 3);             break;
  case HEX_D:
    HEX(KC_LCTL, 0, KC_D, 1);       break;
  case HEX_E:
    HEX(KC_LALT, 0, KC_E, 2);       break;
  case HEX_F:
    HEX(KC_LSFT, 0, KC_F, 3);       break;
#else
#define HEX(m, m2, k) mod_tap(record, m, m2, hexcase, k)

  case HEX_A:
    HEX(0, 0, KC_A);                break;
  case HEX_B:
    HEX(KC_LALT, KC_LCTL, KC_B);    break;
  case HEX_C:
    HEX(0, 0, KC_C);                break;
  case HEX_D:
    HEX(KC_LCTL, 0, KC_D);          break;
  case HEX_E:
    HEX(KC_LALT, 0, KC_E);          break;
  case HEX_F:
    HEX(KC_LSFT, 0, KC_F);          break;
#endif

  // ....................................................... Numpad Bracket Keys

static uint16_t brkts[][3] = { {LOWER, KC_LBRC, KC_RBRC},    // [] (side 1 -> 2)
                               {UPPER, KC_9,    KC_0},       // ()
                               {UPPER, KC_LCBR, KC_RCBR} };  // {}
static uint8_t  brktype    = 0;                              // default (0) [], see case BRKTYPE

#ifdef ROLLOVER
#define BRACKET(m, m2, s, c) mod_roll(record, m, m2, brkts[brktype][0], brkts[brktype][s], c)

  case L_BRKT:
    BRACKET(0, 0, LEFT, 1);              break;
  case R_BRKT:
    BRACKET(KC_LALT, KC_LSFT, RIGHT, 3); break;
#else
#define BRACKET(m, m2, s) mod_tap(record, m, m2, brkts[brktype][0], brkts[brktype][s])

  case L_BRKT:
    BRACKET(0, 0, LEFT);                 break;
  case R_BRKT:
    BRACKET(KC_LALT, KC_LSFT, RIGHT);    break;
#endif

  // ................................................................. Smart Key

#define POSTCASE (postfix == KC_G ? UPPER : LOWER)

#ifdef ROLLOVER
  case DELIM:
    if (leadercap) { mod_roll(record, 0, 0, LOWER, KC_X, 3); }        // 0x
    else           { mod_roll(record, 0, 0, POSTCASE, postfix, 3); }  // smart vim goto
    break;
#else
  case DELIM:
    if (leadercap) { mod_tap(record, 0, 0, LOWER, KC_X); }            // 0x
    else           { mod_tap(record, 0, 0, POSTCASE, postfix); }      // smart vim goto
    break;
#endif

  // ............................................................. Modifier Keys

#ifndef HASKELL
  case HS_GT:
    mod_tap(record, KC_LSFT, 0, UPPER, KC_DOT);  break;
  case HS_LT:
    mod_tap(record, KC_LCTL, 0, UPPER, KC_COMM); break;
#endif
  case TT_A:
    layer_toggle(record, _TTBASEL, UPPER, KC_A); break;
  case TT_T:
    layer_toggle(record, _TTBASER, UPPER, KC_T); break;

  // ......................................................... Shift Mapped Keys

#ifdef ROLLOVER
  case KC_COLN:
    LEADERCAP;  // semi/colon + space/enter + shift shortcut, see leader_cap()
    if (map_leader(record, KC_RSFT, LOWER, KC_COLN, 4)) { return false; }
    break;
#ifdef HASKELL
  case TD_COLN:
    if (mod_down(KC_RSFT)) { unregister_code(KC_RSFT); }  // *must* un-shift before tap dance processing to register unshifted keycodes
    LEADERCAP;  // semi/colon + space/enter + shift shortcut, see leader_cap()
    set_leader(record, KC_COLN, 4);
    break;
#endif

  case KC_COMM:
    LEADERCAP;  // comma + space/enter + shift shortcut, see leader_cap()
    if (map_leader(record, KC_RSFT, LOWER, KC_GRV, 4))  { return false; }
    break;
#else
  case KC_COLN:
    LEADERCAP;  // semi/colon + space/enter + shift shortcut, see leader_cap()
    if (map_shift(record, KC_RSFT, LOWER, KC_COLN))     { return false; }
    break;
#ifdef HASKELL
  case TD_COLN:
    if (mod_down(KC_RSFT)) { unregister_code(KC_RSFT); }  // *must* un-shift before tap dance processing to register unshifted keycodes
    LEADERCAP;  // semi/colon + space/enter + shift shortcut, see leader_cap()
    break;
#endif

  case KC_COMM:
    LEADERCAP;  // comma + space/enter + shift shortcut, see leader_cap()
    if (map_shift(record, KC_RSFT, LOWER, KC_GRV))      { return false; }
    break;
#endif

// ...................................................... Shift Mapped Tap Dance

#ifdef UNIX
static uint16_t td_timer = 0;  // pseudo tapdance timer

#define TAPDANCE if (KEY_DOWN) { td_timer = KEY_TAPPED(td_timer) ? 0 : timer_read(); }
#endif
#ifdef ROLLOVER
  case KC_DOT:
    LEADERCAP;  // dot + space/enter + shift shortcut, see leader_cap()
#ifdef UNIX
    TAPDANCE; if (map_leader(record, KC_RSFT, td_timer ? UPPER : LOWER, td_timer ? KC_GRV : KC_SLSH, 4)) { return false; }  // pseudo tapdance ~ -> ~/
#else
    if (map_leader(record, KC_RSFT, UPPER, KC_GRV, 4)) { return false; }
#endif
    break;
#else
  case KC_DOT:
    LEADERCAP;  // dot + space/enter + shift shortcut, see leader_cap()
#ifdef UNIX
    TAPDANCE; if (map_shift(record, KC_RSFT, td_timer ? UPPER : LOWER, td_timer ? KC_GRV : KC_SLSH)) { return false; }  // pseudo tapdance ~ -> ~/
#else
    if (map_shift(record, KC_RSFT, UPPER, KC_GRV))     { return false; }
#endif
    break;
#endif

  // ..................................................... Leader Capitalization

  case KC_EXLM:
  case KC_QUES:
    LEADERCAP;  // exclamation/question + space/enter + shift shortcut, see leader_cap()
#ifdef ROLLOVER
    if (map_leader(record, 0, LOWER, keycode, 4)) { return false; }
#endif
    break;

  // ................................................... Remaining Rollover Keys

#ifdef ROLLOVER
#define CASE_ROLL(c, k) case k: { MOD_ROLL(0, k, c); return false; }

  CASE_ROLL(1, KC_Y);  // top row 3
  CASE_ROLL(2, KC_O);
  CASE_ROLL(3, KC_U);
  CASE_ROLL(4, KC_MINS);

  CASE_ROLL(5, KC_G);
  CASE_ROLL(6, KC_D);
  CASE_ROLL(7, KC_N);
  CASE_ROLL(8, KC_M);
  case PINKY3:
    MOD_ROLL(0, PINKIE(3), 9); return false;

  CASE_ROLL(4, KC_W);  // middle row 2
  CASE_ROLL(5, KC_C);

  CASE_ROLL(0, KC_J);  // bottom row 1
  CASE_ROLL(3, KC_K);
  CASE_ROLL(4, KC_QUOT);

  CASE_ROLL(5, KC_B);
  CASE_ROLL(6, KC_P);
  CASE_ROLL(7, KC_L);
  CASE_ROLL(8, KC_F);
  case PINKY1:
    MOD_ROLL(0, PINKIE(1), 9); return false;
#endif

  // .................................................. Toggle Layer Pinkie Keys

#ifndef ROLLOVER
  case PINKY3:
#endif
  case KEY3:
    send(record, LOWER, PINKIE(3)); break;
  case KEY2:
    send(record, LOWER, PINKIE(2)); break;
#ifndef ROLLOVER
  case PINKY1:
#endif
  case KEY1:
    send(record, LOWER, PINKIE(1)); break;
  case SHIFT3:
    send(record, UPPER, PINKIE(3)); break;
  case SHIFT2:
    send(record, UPPER, PINKIE(2)); break;
  case SHIFT1:
    send(record, UPPER, PINKIE(1)); break;

  // ................................................................ Steno Keys

#ifdef PLANCK
  case PLOVER:
    steno(record);
    return false;
  case BASE1:
    if (raise_layer(record, 0, LEFT, TOGGLE))  { base_layer(0); }
    return false;
  case BASE2:
    if (raise_layer(record, 0, RIGHT, TOGGLE)) { base_layer(0); }
    return false;
#endif

  // ................................................................ Other Keys

#define CYCLE(x) if (KEY_DOWN) { x = (x == 0) ? 1 : ((x == 1) ? 2 : 0); }

  case BRKTYPE:
    CYCLE(brktype);    // see BRACKET()
    break;
  case HEXCASE:
    if (KEY_DOWN) { hexcase = !hexcase; }
    break;
  case SMART:
    if (KEY_DOWN) { smart = !smart; }
    break;
  case STAGGER:
    CYCLE(stagger);    // see PINKIE()
    break;
  // default:
  //   key_timer = 0;  // regular keycode, clear timer in keycode_functions.h
  }
  
  CLR_1SHOT;           // see leader_cap()
  return true;
}

// Initialization
// ═════════════════════════════════════════════════════════════════════════════

#ifdef CORNE
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
#endif
// SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
  iota_gfx_init(!has_usb());  // turns on the display
#endif
  base_layer(0);
}

// SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
  iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    // matrix_write_ln(matrix, read_keylogs());
    // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    // matrix_write_ln(matrix, read_host_led_state());
    // matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif
#endif

#ifdef PLANCK
void matrix_init_user(void)
{
  clear_events();
#ifdef STENO_ENABLE
  steno_set_mode(STENO_MODE_BOLT);  // or STENO_MODE_GEMINI
#endif
#ifdef AUDIO_ENABLE
  startup_user();
#endif
}

#include "audio.h"
#endif

#ifdef CHIMERA
void matrix_init_user(void)
{
  base_layer(0);
}

// Layer States
// ═════════════════════════════════════════════════════════════════════════════

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  
  switch (layer) {
  case _BASE:
    set_led_blue;    break;
  case _SHIFT:
  case _TTCAPS:
    set_led_cyan;    break;
  case _NUMBER:
  case _TTNUMBER:
    set_led_green;   break;
  case _REGEX:
  case _SYMGUI:
  case _TTREGEX:
    set_led_red;     break;
  case _MOUSE:
  case _TTCURSOR:
  case _TTMOUSE:
    set_led_magenta; break;
  case _FNCKEY:
  case _TTFNCKEY:
    set_led_green;   break;
  case _EDIT:
  default:
    set_led_yellow;  break;
  }
}
#endif
