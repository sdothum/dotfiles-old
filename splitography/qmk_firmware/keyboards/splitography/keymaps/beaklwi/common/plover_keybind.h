// sdothum - 2016 (c) wtfpl

// simple window manager specific plover keybind hook

// toggle plover application, see herbstluftwm/config/appbinds
register_code  (KC_LGUI);
register_code  (KC_LCTL);
TAP            (KC_EQL);
unregister_code(KC_LCTL);
unregister_code(KC_LGUI);
