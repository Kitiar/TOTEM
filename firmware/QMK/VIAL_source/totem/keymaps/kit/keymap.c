/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀
                                                           ▀  ▀  ▀  D E F A U L T

▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘

enum totem_layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes { COLEMAK = SAFE_RANGE, QWERTY, LOWER, RAISE, ADJUST, OS_SWAP, MAKE_H, SNAP };

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS QWERTY ├──────────────────┐

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define CTL_S MT(MOD_LCTL, KC_S)
#define ALT_D MT(MOD_LALT, KC_D)
#define CTL_D MT(MOD_LCTL, KC_D)
#define SHT_F MT(MOD_LSFT, KC_F)

// RIGHT HAND HOME ROW MODS QWERTY ├─────────────────┐

#define SHT_J MT(MOD_RSFT, KC_J)
#define CTL_K MT(MOD_LCTL, KC_K)
#define ALT_K MT(MOD_LALT, KC_K)
#define CTL_L MT(MOD_LCTL, KC_L)
#define ALT_L MT(MOD_LALT, KC_L)
#define GUI_S MT(MOD_LGUI, KC_SCLN)

// LEFT HAND HOME ROW MODS COLEMAK ├─────────────────┐

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_R MT(MOD_LALT, KC_R)
#define CTL_S MT(MOD_LCTL, KC_S)
#define SHT_T MT(MOD_LSFT, KC_T)

// RIGHT HAND HOME ROW MODS COLEMAK ├────────────────┐

#define SHT_N MT(MOD_RSFT, KC_N)
#define CTL_E MT(MOD_LCTL, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define GUI_O MT(MOD_LGUI, KC_O)

#define LOWER LT(_LOWER, KC_TAB)
#define RAISE LT(_RAISE, KC_ESC)
#define ADJUST MO(_ADJUST)

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //  ┌─────────────────────────────────────────────────┐
    /*  │*/ [_QWERTY] = LAYOUT(                         //│           ╭╮╭╮ ╭╮╭╮
    //  └─────────────────────────────────────────────────┘           │╰╯╰─╯╰╯│
    //            ┌──────────┬──────────┬──────────┬──────────┬───────╨──┐ ┌──╨───────┬──────────┬──────────┬──────────┬──────────┐
    //            │     Q    │     W    │     E    │     R    │     T    │ │     Y    │     U    │     I    │     O    │     P    │
    /*    ╌┄┈┈──═*/   KC_Q   ,   KC_W   ,   KC_E   ,   KC_R   ,   KC_T    ,    KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   ,   KC_P   ,
    //            ├──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //            │     A    │     S    │     D    │     F    │     G    │ │     H    │     J    │     K    │     L    │    ; :   │
    /*           */   KC_A   ,   CTL_S  ,   ALT_D  ,   SHT_F  ,   KC_G    ,    KC_H   ,   SHT_J  ,   ALT_K  ,   CTL_L  ,  KC_SCLN ,
    //            │          │   CTRL   │    ALT   │   SHIFT  │          │ │          │   SHIFT  │    ALT   │   CTRL   │          │
    // ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐
    // │    ESC   │     Z    │     X    │     C    │     V    │     B    │ │     N    │     M    │     ,    │     .    │     /    │    GUI   │
    /**/  KC_ESC  ,   KC_Z   ,   KC_X   ,   KC_C   ,   KC_V   ,   KC_B    ,    KC_N   ,   KC_M   ,  KC_COMM ,  KC_DOT  ,  KC_SLSH , KC_RGUI  ,
    // └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │    DEL   │    TAB   │  SPACE   │ │  ENTER   │    ESC   │ BACKSPACE│
    /*                                 */  KC_DEL  ,   LOWER  ,  KC_SPC   ,   KC_ENT  ,   RAISE  , KC_BSPC  ),
    //                                  │          │ MC LOWER │          │ │          │ MC RAISE │          │
    //                                  └──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┘

    //  ┌─────────────────────────────────────────────────┐
    /*  │*/ [_LOWER] = LAYOUT(                          //│           ╭╮╭╮ ╭╮╭╮
    //  └─────────────────────────────────────────────────┘           │╰╯╰─╯╰╯│
    //            ┌──────────┬──────────┬──────────┬──────────┬───────╨──┐ ┌──╨───────┬──────────┬──────────┬──────────┬──────────┐
    //            │ CAPS LCK │  NUMLCK  │     ↑    │     =    │     {    │ │     }    │     7    │     8    │     9    │     +    │
    /*    ╌┄┈┈──═*/  KC_CAPS ,  KC_NUM  ,   KC_UP  ,  KC_EQL  ,  KC_LCBR  ,   KC_RCBR ,   KC_P7  ,   KC_P8  ,   KC_P9  ,  KC_PPLS ,
    //            ├──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //            │   PG UP  │     ←    │     ↓    │     →    │     [    │ │     ]    │     4    │     5    │     6    │     -    │
    /*           */  KC_PGUP ,  KC_LEFT ,  KC_DOWN ,  KC_RGHT ,  KC_LBRC  ,   KC_RBRC ,   KC_P4  ,   KC_P5  ,   KC_P6  ,  KC_MINS ,
    // ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐
    // │    ESC   │  PG DOWN │   HOME   │   SAVE   │   END    │     (    │ │     )    │     2    │     3    │     3    │     *    │    GUI   │
    /**/ _______  ,  KC_PGDN ,  KC_QUOT ,  C(KC_S) ,  KC_END  , KC_LPRN   ,   KC_RPRN ,   KC_P1  ,   KC_P2  ,   KC_P3  ,  KC_PAST ,  _______ ,
    // └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │    DEL   │          │  SPACE   │ │  ENTER   │    ESC   │ BACKSPACE│
    /*                                 */  _______ ,  _______ ,  _______  ,   _______ ,  ADJUST  , _______  ),
    //                                  │          │          │          │ │          │ MC ADJUST│          │
    //                                  └──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┘

    //  ┌─────────────────────────────────────────────────┐
    /*  │*/ [_RAISE] = LAYOUT(                          //│           ╭╮╭╮ ╭╮╭╮
    //  └─────────────────────────────────────────────────┘           │╰╯╰─╯╰╯│
    //            ┌──────────┬──────────┬──────────┬──────────┬───────╨──┐ ┌──╨───────┬──────────┬──────────┬──────────┬──────────┐
    //            │    F9    │    F10   │    F11   │    F12   │          │ │          │          │          │          │          │
    /*    ╌┄┈┈──═*/   KC_F9  ,  KC_F10  ,  KC_F11  ,  KC_F12  ,  XXXXXXX  ,   XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,
    //            ├──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┤
    //            │    F5    │    F6    │    F7    │    F8    │          │ │          │   SHIFT  │    ALT   │   CTRL   │          │
    /*           */   KC_F5  ,   KC_F6  ,   KC_F7  ,   KC_F8  ,  XXXXXXX  ,   XXXXXXX ,  KC_RSFT ,  KC_RALT ,  KC_RCTL ,  XXXXXXX ,
    // ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐
    // │    ESC   │    F1    │    F2    │    F3    │    F4    │          │ │          │          │          │          │          │    GUI   │
    /**/  _______ ,   KC_F1  ,   KC_F2  ,   KC_F3  ,   KC_F4  ,  XXXXXXX  ,   XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  _______ ,
    // └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
    //                                  │    DEL   │    TAB   │  SPACE   │ │  ENTER   │          │ BACKSPACE│
    /*                                 */  _______ ,  ADJUST  , _______   ,  _______  , _______  , _______  ),
    //                                  │          │ MC ADJUST│          │ │          │          │          │
    //                                  └──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┘

    /*
      ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

      ┌─────────────────────────────────────────────────┐
      │ A D J U S T                                     │      ╭╮╭╮╭╮╭╮
      └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
                ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
        ╌┄┈┈───═╡    !    │    @    │    #    │    $    │    %    ││    ^    │    &    │    Ü    │    °    │    /    │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │    Ä    │    è    │    SZ   │    é    │         ││         │    ¥    │    €    │    £    │    Ö    │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │         │    `    │    ~    │   CUE   │         │         ││         │         │         │ DM REC1 │ DM STOP │ DM PLY1 │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │  GIPHY  │ ADJUST  │    ▼    ││    ▼    │    ▼    │    ▼    │
                                    └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

    [_ADJUST] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, RALT(KC_U), RALT(KC_3), KC_BSLS, RALT(KC_A), RALT(KC_F), RALT(KC_S), RALT(KC_G), XXXXXXX, XXXXXXX, LSFT(RALT(KC_4)), RALT(KC_5), RALT(KC_4), RALT(KC_O), XXXXXXX, LSFT(KC_GRV), KC_TILD, RALT(KC_C), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1, DM_RSTP, DM_PLY1, _______, ADJUST, _______, _______, _______, _______),
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                    keymap_config.swap_lctl_lgui = true; // ─── MAC
                } else {
                    keymap_config.swap_lctl_lgui = false; // ─── WIN
                }
                eeconfig_update_keymap((void *) &keymap_config.raw);
                clear_keyboard(); // ──── clear to prevent stuck keys
                return false;
            }

            // ┌─────────────────────────────────────────────────┐
            // │ l a y e r                                       │
            // └─────────────────────────────────────────────────┘

//        case COLEMAK:
//            if (record->event.pressed) {
//                set_single_persistent_default_layer(_COLEMAK);
//            }
//            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

            // ┌─────────────────────────────────────────────────┐
            // │ q m k                                           │
            // └─────────────────────────────────────────────────┘

        case MAKE_H:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -kb totem -km default");
                tap_code(KC_ENTER);
            }
            break;

            // ┌─────────────────────────────────────────────────┐
            // │ p r o d u c t i v i t y                         │
            // └─────────────────────────────────────────────────┘

        case SNAP:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4")))); // MAC
                } else {
                    SEND_STRING(SS_LSFT(SS_LWIN("S"))); // WIN
                }
            }
            break;
    }
    return true;
}
/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


                                                          ██████
                                                            ██  ▄▄▄▄
                                                            ██ ██▀▀██
                                                            ▀▀ ██▄▄██
                                                        ██████  ▀▀▀▀
                                                          ██ ▄▄▄▄▄▄
                                                          ██ ██▀▀▀▀
                                                          ██ ██████
                                                             ██▄▄▄▄
                                                             ▀▀▀▀▀▀
                                                           ████████
                                                           ██ ██ ██
                                                           ██ ██ ██
                                                           ▀▀ ▀▀ ▀▀
                                                          ████████

*/
