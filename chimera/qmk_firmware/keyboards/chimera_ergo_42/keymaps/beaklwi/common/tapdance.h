
// tap dance keys
enum tap_dance {
  _ASTR = 0
 ,_COMM
 ,_DOT
#ifndef EQLEQL
 ,_EQL
#endif
#ifdef HASKELL
 ,_COLN
 ,_GT
 ,_LT
#endif
 ,_PASTE
 ,_PRIV
 ,_SEND
 ,_TILD
 ,_XPASTE
};

#define TD_ASTR   TD(_ASTR)
#define TD_COMM   TD(_COMM)
#define TD_DOT    TD(_DOT)
#ifndef EQLEQL
#define TD_EQL    TD(_EQL)
#endif
#ifdef HASKELL
#define TD_COLN   TD(_COLN)
#define TD_GT     TD(_GT)
#define TD_LT     TD(_LT)
#endif
#define TD_PASTE  TD(_PASTE)
#define TD_PRIV   TD(_PRIV)  // compile time macro string, provided in private_string.h
#define TD_SEND   TD(_SEND)  // config.h defined macro string
#ifdef UNIX
#define TD_TILD   TD(_TILD)
#endif
#define TD_XPASTE TD(_XPASTE)
