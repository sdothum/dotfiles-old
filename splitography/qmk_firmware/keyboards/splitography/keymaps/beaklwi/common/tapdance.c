// sdothum - 2016 (c) wtfpl

#include "config.h"  // for ale linter
#include "tapdance.h"

// Tap Dance
// ═════════════════════════════════════════════════════════════════════════════

// .......................................................... Tap Dance Keycodes

qk_tap_dance_action_t tap_dance_actions[] = {
  [_ASTR]   = ACTION_TAP_DANCE_FN_ADVANCED     (NULL, asterisk, asterisk_reset)
 ,[_COMM]   = ACTION_TAP_DANCE_FN_ADVANCED     (NULL, comma, comma_reset)
 ,[_DOT]    = ACTION_TAP_DANCE_FN_ADVANCED     (NULL, dot, dot_reset)
#ifndef EQLEQL
 ,[_EQL]    = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, equal, equal_reset, HASKELL_TERM)
#endif
#ifdef HASKELL
 ,[_COLN]   = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, colon, colon_reset, HASKELL_TERM)
 ,[_GT]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, greater, greater_reset, HASKELL_TERM)
 ,[_LT]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, lesser, lesser_reset, HASKELL_TERM)
#endif
#ifdef UNIX
 ,[_TILD]   = ACTION_TAP_DANCE_FN_ADVANCED     (NULL, tilde, tilde_reset)
#endif
 ,[_PASTE]  = ACTION_TAP_DANCE_FN_ADVANCED     (NULL, paste, paste_reset)
 ,[_PRIV]   = ACTION_TAP_DANCE_FN              (private)
 ,[_PUB]    = ACTION_TAP_DANCE_FN              (public)
 ,[_XPASTE] = ACTION_TAP_DANCE_FN_ADVANCED     (NULL, xpaste, xpaste_reset)
};

// ............................................................ Tap Dance Macros

#define TAPS               (state->count > 1)
#define TAP_DOWN           (state->pressed)
#define SHIFT(k)           register_code(KC_LSFT); register_code(k)
#define UNSHIFT(k)         unregister_code(k);     unregister_code(KC_LSFT)

// taps -> string else ..
#define DANCE_TAP(s, u, k) if (TAPS)   { send_string  (s); } \
                           else if (u) { SHIFT        (k); } \
                           else        { register_code(k); } \
                           reset_tap_dance(state); return

// .......................................................... Double Tap Strings

void asterisk(STATE, void *user_data)
{
  DANCE_TAP(".*", UPPER, KC_8);
}

void asterisk_reset(STATE, void *user_data)
{
  UNSHIFT(KC_8);
}

void colon(STATE, void *user_data)
{
  if (MOD_DOWN(KC_RSFT)) {  // handle like map_shift()
#ifdef EMOJI
    DANCE_TAP(" :-", LOWER, KC_SCLN);
#else
    register_code(KC_SCLN);
#endif
  } else {
#ifdef HASKELL
    DANCE_TAP(" :: ", UPPER, KC_SCLN);
#else
    SHIFT(KC_SCLN); 
#endif
  }
  reset_tap_dance(state);
}

void colon_reset(STATE, void *user_data)
{
  unregister_code(KC_SCLN);
  UNSHIFT        (KC_SCLN);
  if (MOD_DOWN(KC_RSFT)) { register_code(KC_RSFT); }  // restore HOME_T, see process_record_user() TD_COLN
}

#ifndef EQLEQL
void equal(STATE, void *user_data)
{
  DANCE_TAP("=~", LOWER, KC_EQL);
}

void equal_reset(STATE, void *user_data)
{
  unregister_code(KC_EQL);
}
#endif

#ifdef HASKELL
void greater(STATE, void *user_data)
{
  DANCE_TAP(" -> ", UPPER, KC_DOT);
}

void greater_reset(STATE, void *user_data)
{
  UNSHIFT(KC_DOT);
}

void lesser(STATE, void *user_data)
{
  DANCE_TAP(" <- ", UPPER, KC_COMM);
}

void lesser_reset(STATE, void *user_data)
{
  UNSHIFT(KC_COMM);
}
#endif

#ifdef UNIX
void tilde(STATE, void *user_data)
{
  DANCE_TAP("~/", UPPER, KC_GRV);
}

void tilde_reset(STATE, void *user_data)
{
  UNSHIFT(KC_GRV);
}
#endif

// ........................................................ Double Tap Character

void comma(STATE, void *user_data)
{
#ifdef COMMASPACE
  DANCE_TAP(", ", LOWER, KC_COMM);
#else
  if (TAPS) { register_code(KC_SCLN); }
  else      { register_code(KC_COMM); }
  reset_tap_dance(state);
#endif
}

void comma_reset(STATE, void *user_data)
{
  unregister_code (KC_COMM);
  unregister_code (KC_SCLN);
}

void dot(STATE, void *user_data)
{
  if (TAPS) { SHIFT        (KC_SCLN); }
  else      { register_code(KC_DOT); }
  reset_tap_dance(state);
}

void dot_reset(STATE, void *user_data)
{
  unregister_code(KC_DOT);
  UNSHIFT        (KC_SCLN);
}

// ............................................................... Paste Actions

#define IRC_ENTER _delay_ms(10); TAP(KC_ENT)
#define CTL_V     register_code(KC_LCTL); TAP(KC_V); unregister_code(KC_LCTL)

void paste(STATE, void *user_data)
{
  if (TAPS)          { CTL_V; IRC_ENTER; }
  else if (TAP_DOWN) { register_code(KC_LCTL); register_code(KC_V); }
  else               { CTL_V; }
  reset_tap_dance(state);
}

void paste_reset(STATE, void *user_data)
{
  unregister_code(KC_V);
  unregister_code(KC_LCTL);
}

// compile time macro strings, see functions/hardware qmk script
void private(STATE, void *user_data)
{
  if (TAPS) { SEND_STRING(PRIVATE_STRING); }
  reset_tap_dance(state);
}

void public(STATE, void *user_data)
{
  if (TAPS) { SEND_STRING(PUBLIC_STRING); }
  reset_tap_dance(state);
}

#define CTL_SFT_V register_code(KC_LCTL); TAP_SHIFT(KC_V); unregister_code(KC_LCTL)

void xpaste(STATE, void *user_data)
{
  if (TAPS)          { CTL_SFT_V; IRC_ENTER; }
  else if (TAP_DOWN) { register_code(KC_LCTL); SHIFT(KC_V); }
  else               { CTL_SFT_V; }
  reset_tap_dance(state);
}

void xpaste_reset(STATE, void *user_data)
{
  UNSHIFT        (KC_V);
  unregister_code(KC_LCTL);
}
