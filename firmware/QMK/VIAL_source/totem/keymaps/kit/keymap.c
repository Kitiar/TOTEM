/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀
                                                           ▀  ▀  ▀    K I T

▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H
#include "keymap_us_extended.h"
#include "keymap_russian.h"

// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                             │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                                                                         │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

enum custom_layers {
    _USA = 0,  // 0 nested layer
    _RUS,      // 0 nested layer
    _SPECIAL,  // 1 nested layer
    _NUMBER,   // 1 nested layer
    _NAVIGATE, // 2 nested layer
};

// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ d e f i n e   t i m e r s                                                                                         │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

enum custom_timers {
    T_LCTL,
    T_LALT,
    T_LSFT,
    T_RSFT,
    T_RCTL,
    T_RALT,
    T_NUM_TIMERS
};

static uint16_t timers[T_NUM_TIMERS];

// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ d e f i n e   c u s t o m   k e y c o d e s                                                                       │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

enum custom_keycodes {
    SET_USA = SAFE_RANGE,
    SET_RUS,
    CH_LCBR,  /* { */
    CH_RCBR,  /* } */
    CH_LBRC,  /* [ */
    CH_RBRC,  /* ] */
    CH_LPRN,  /* ( */
    CH_RPRN,  /* ) */
    CH_LABK,  /* < */
    CH_RABK,  /* > */
    CH_QUOT,  /* ' */
    CH_DQUO,  /* " */
    CH_SLSH,  /* / */
    CH_BSLS,  /* \ */
    CH_CIRC,  /* ^ */
    CH_PIPE,  /* | */
    CH_GRV,   /* ` */
    CH_TILD,  /* ~ */
    CH_HASH,  /* # */
    CH_AT,    /* @ */
    CH_AMPR,  /* & */
    CH_DLR,   /* $ */
    CH_EXLM,  /* ! */
    CH_QUES,  /* ? */
    CH_NUM,   /* № */
    CH_PERC,  /* % */

    CH_C_S,    /* LCTR / S    */
    CH_C_YERU, /* LCTR / Ы    */
    CH_C_DLR,  /* LCTR / $    */
    CH_C_F6,   /* LCTR / F6   */
    CH_C_HOME, /* LCTR / HOME */

    CH_C_D,    /* LALT / D    */
    CH_C_VE,   /* LALT / В    */
    CH_C_SCLN, /* LALT / ;    */
    CH_C_F7,   /* LALT / F7   */
    CH_C_PGDN, /* LALT / PGDN */

    CH_C_F,    /* LSFT / F    */
    CH_C_A,    /* LSFT / А    */
    CH_C_COMM, /* LSFT / ,    */
    CH_C_F8,   /* LSFT / F8   */
    CH_C_END,  /* LSFT / END */

    CH_C_J,    /* RSFT / J    */
    CH_C_O,    /* RSFT / О    */
    CH_C_DOT,  /* RSFT / .    */
    CH_C_P4,   /* RSFT / 4    */
    CH_C_LEFT, /* RSFT / ←    */

    CH_C_K,    /* RALT / K    */
    CH_C_EL,   /* RALT / Л    */
    CH_C_COLN, /* RALT / :    */
    CH_C_P5,   /* RALT / 5    */
    CH_C_DOWN, /* RALT / ↓    */

    CH_C_L,    /* RCTR / L    */
    CH_C_DE,   /* RCTR / Д    */
    CH_C_EXLM, /* RCTR / !    */
    CH_C_P6,   /* RCTR / 6    */
    CH_C_RGHT  /* RCTR / →    */
};

// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ d e f i n e   t a p   d a n c i n g   k e y c o d e s                                                             │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

enum {
    TD_IE_YO = 0, /* Е / Ё */
    TD_SHA_SHCH,  /* Ш / Щ */
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘

// ┌── DRAFT LAYER ────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │┌── LEFT HAND ────────────────────────────────────────────────────────────────────────────────────────────────────┐│
// │└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
// │┌── RIGHT HAND ───────────────────────────────────────────────────────────────────────────────────────────────────┐│
// │└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

// ┌── SWITCH LANGUAGE MACRO NAMES ────────────────────────────────────────────────────────────────────────────────────┐
/* │*/ #define SWITCH_USA LCTL(LSFT(KC_1))                                                                          // │
/* │*/ #define SWITCH_RUS LCTL(LSFT(KC_2))                                                                          // │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

// ┌── SWITCH MACRO NAMES ─────────────────────────────────────────────────────────────────────────────────────────────┐
/* │*/ #define SPEC_TAB LT(_SPECIAL,  KC_TAB)                                                                       // │
/* │*/ #define NUM_ESC  LT(_NUMBER,   KC_ESC)                                                                       // │
/* │*/ #define NAV_ESC  LT(_NAVIGATE, KC_ESC)                                                                       // │
/* │*/ #define NAV_TAB  LT(_NAVIGATE, KC_TAB)                                                                       // │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

// ┌── RUS LAYER MACRO NAMES ──────────────────────────────────────────────────────────────────────────────────────────┐
// │┌── LEFT HAND ────────────────────────────────────────────────────────────────────────────────────────────────────┐│
/* ││*/ #define IE_YO       TD(TD_IE_YO)                                                                           // ││
// │└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
// │┌── RIGHT HAND ───────────────────────────────────────────────────────────────────────────────────────────────────┐│
/* ││*/ #define SHA_SHCH    TD(TD_SHA_SHCH)                                                                        // ││
// │└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ T A P   D A N C E   A C T I O N S                                                                                 │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

tap_dance_action_t tap_dance_actions[] = {
    [TD_IE_YO] = ACTION_TAP_DANCE_DOUBLE(RU_IE, RU_YO),
    [TD_SHA_SHCH] = ACTION_TAP_DANCE_DOUBLE(RU_SHA, RU_SHCH),
};

// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                     │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//  ┌─────────────────────────────────────────────────┐
/*  │*/ [_USA] = LAYOUT(                            //│           ╭╮╭╮ ╭╮╭╮
//  └─────────────────────────────────────────────────┘           │╰╯╰─╯╰╯│
//            ┌──────────┬──────────┬──────────┬──────────┬───────╨──┐ ┌──╨───────┬──────────┬──────────┬──────────┬──────────┐
//            │     Q    │     W    │     E    │     R    │     T    │ │     Y    │     U    │     I    │     O    │     P    │
/*    ╌┄┈┈──═*/   US_Q   ,   US_W   ,   US_E   ,   US_R   ,   US_T    ,    US_Y   ,   US_U   ,   US_I   ,   US_O   ,   US_P   ,
//            ├──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┤
//            │     A    │     S    │     D    │     F    │     G    │ │     H    │     J    │     K    │     L    │          │
/*           */   US_A   ,  CH_C_S  ,  CH_C_D  ,  CH_C_F  ,   US_G    ,    US_H   ,  CH_C_J  ,  CH_C_K  ,  CH_C_L  ,  XXXXXXX ,
//            │          │   CTRL   │    ALT   │   SHIFT  │          │ │          │   SHIFT  │    ALT   │   CTRL   │          │
// ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐
// │    RUS   │     Z    │     X    │     C    │     V    │     B    │ │     N    │     M    │          │          │          │    GUI   │
/**/  SET_RUS ,   US_Z   ,   US_X   ,   US_C   ,   US_V   ,   US_B    ,    US_N   ,   US_M   ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX , KC_RGUI  ,
// └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
//                                  │    DEL   │    TAB   │   SPACE  │ │  ENTER   │    ESC   │ BACKSPACE│
/*                                 */  KC_DEL  , SPEC_TAB ,  KC_SPC   ,   KC_ENT  ,  NUM_ESC , KC_BSPC  ),
//                                  │          │  SPECIAL │          │ │          │  NUMBER  │          │
//                                  └──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┘

//  ┌─────────────────────────────────────────────────┐
/*  │*/ [_RUS] = LAYOUT(                            //│           ╭╮╭╮ ╭╮╭╮
//  └─────────────────────────────────────────────────┘           │╰╯╰─╯╰╯│
//            ┌──────────┬──────────┬──────────┬──────────┬───────╨──┐ ┌──╨───────┬──────────┬──────────┬──────────┬──────────┐
//            │     Й    │     Ц    │     У    │     К    │     Е    │ │     Н    │     Г    │     Ш    │     З    │     Х    │
/*    ╌┄┈┈──═*/  RU_SHTI ,  RU_TSE  ,   RU_U   ,   RU_KA  ,   IE_YO  ,    RU_EN  ,  RU_GHE   , SHA_SHCH ,   RU_ZE  ,   RU_HA  ,
//            │          │          │          │          │     Ё    │ │          │          │     Щ    │          │          │
//            ├──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┤
//            │     Ф    │     Ы    │     В    │     А    │     П    │ │     Р    │     О    │     Л    │     Д    │     Ж    │
/*           */   RU_EF  , CH_C_YERU,  CH_C_VE ,  CH_C_A  ,   RU_PE   ,    RU_ER  ,  CH_C_O  ,  CH_C_EL ,  CH_C_DE ,  RU_ZHE  ,
//            │          │   CTRL   │    ALT   │   SHIFT  │          │ │          │   SHIFT  │    ALT   │   CTRL   │          │
// ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐
// │   DF US  │     Я    │     Ч    │     С    │     М    │     И    │ │     Т    │     Ь    │     Б    │     Ю    │     Ъ    │     Э    │
/**/  SET_USA ,   RU_YA  ,  RU_CHE  ,   RU_ES  ,   RU_EM  ,   RU_I   ,    RU_TE  ,   RU_SOFT ,   RU_BE  ,   RU_YU  ,  RU_HARD ,   RU_E   ,
// └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
//                                  │    DEL   │    TAB   │   SPACE  │ │   ENTER  │    ESC   │ BACKSPACE│
/*                                 */  KC_DEL  , SPEC_TAB ,  KC_SPC   ,   KC_ENT  ,  NUM_ESC , KC_BSPC  ),
//                                  │          │  SPECIAL │          │ │          │  NUMBER  │          │
//                                  └──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┘

//  ┌─────────────────────────────────────────────────┐
/*  │*/ [_SPECIAL] = LAYOUT(                        //│           ╭╮╭╮ ╭╮╭╮
//  └─────────────────────────────────────────────────┘           │╰╯╰─╯╰╯│
//            ┌──────────┬──────────┬──────────┬──────────┬───────╨──┐ ┌──╨───────┬──────────┬──────────┬──────────┬──────────┐
//            │     `    │     ~    │     _    │     <    │     {    │ │     }    │     >    │     -    │     |    │     #    │
/*    ╌┄┈┈──═*/  CH_GRV  ,  CH_TILD ,  KC_UNDS ,  CH_LABK ,  CH_LCBR  ,   CH_RCBR ,  CH_RABK ,  KC_MINS ,  CH_PIPE ,  CH_HASH ,
//            ├──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┤
//            │     &    │     $    │     ;    │     ,    │     (    │ │     )    │     .    │     :    │     !    │     ?    │
/*           */  CH_AMPR , CH_C_DLR , CH_C_SCLN, CH_C_COMM, CH_LPRN   ,   CH_RPRN , CH_C_DOT , CH_C_COLN, CH_C_EXLM,  CH_QUES ,
// ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐
// │    @     │     &    │     $    │     \    │     "    │     [    │ │     ]    │     '    │     /    │     !    │     ?    │     №    │
/**/  CH_AT   ,  CH_AMPR ,  CH_DLR  ,  CH_BSLS , CH_DQUO  ,  CH_LBRC  ,   CH_RBRC ,  CH_QUOT ,  CH_SLSH ,  CH_EXLM ,  CH_QUES ,  CH_NUM  ,
// └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
//                                  │    DEL   │    TAB   │   SPACE  │ │   ENTER  │    ESC   │ BACKSPACE│
/*                                 */  _______ ,  _______ ,  _______  ,   _______ ,  NAV_ESC , _______  ),
//                                  │          │          │          │ │          │ NAVIGATE │          │
//                                  └──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┘

//  ┌─────────────────────────────────────────────────┐
/*  │*/ [_NUMBER] = LAYOUT(                         //│           ╭╮╭╮ ╭╮╭╮
//  └─────────────────────────────────────────────────┘           │╰╯╰─╯╰╯│
//            ┌──────────┬──────────┬──────────┬──────────┬───────╨──┐ ┌──╨───────┬──────────┬──────────┬──────────┬──────────┐
//            │    F9    │    F10   │    F11   │    F12   │     ^    │ │     *    │     7    │     8    │     9    │     /    │
/*    ╌┄┈┈──═*/   KC_F9  ,  KC_F10  ,  KC_F11  ,  KC_F12  ,  CH_CIRC  ,   KC_PAST ,   KC_P7  ,   KC_P8  ,   KC_P9  ,  CH_SLSH ,
//            ├──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┤
//            │    F5    │    F6    │    F7    │    F8    │     =    │ │     +    │     4    │     5    │     6    │     -    │
/*           */   KC_F5  ,  CH_C_F6 ,  CH_C_F7 ,  CH_C_F8 ,  KC_EQL   ,   KC_PPLS ,  CH_C_P4 ,  CH_C_P5 ,  CH_C_P6 ,  KC_MINS ,
//            │          │   CTRL   │    ALT   │   SHIFT  │          │ │          │   SHIFT  │    ALT   │   CTRL   │          │
// ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐
// │          │    F1    │    F2    │    F3    │    F4    │          │ │     0    │     1    │     2    │     3    │          │     %    │
/**/  XXXXXXX ,   KC_F1  ,   KC_F2  ,   KC_F3  ,   KC_F4  ,  XXXXXXX  ,    KC_P0  ,   KC_P1  ,   KC_P2  ,   KC_P3  ,  XXXXXXX  ,  CH_PERC ,
// └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
//                                  │    DEL   │    TAB   │   SPACE  │ │   ENTER  │    ESC   │ BACKSPACE│
/*                                 */  _______ ,  NAV_TAB ,  _______  ,   _______ ,  _______ , _______  ),
//                                  │          │ NAVIGATE │          │ │          │          │          │
//                                  └──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┘

//  ┌─────────────────────────────────────────────────┐
/*  │*/ [_NAVIGATE] = LAYOUT(                       //│           ╭╮╭╮ ╭╮╭╮
//  └─────────────────────────────────────────────────┘           │╰╯╰─╯╰╯│
//            ┌──────────┬──────────┬──────────┬──────────┬───────╨──┐ ┌──╨───────┬──────────┬──────────┬──────────┬──────────┐
//            │ CAPS LCK │ PRIN SCR │   PG UP  │          │          │ │          │          │     ↑    │  INSERT  │  NUMLCK  │
/*    ╌┄┈┈──═*/  KC_CAPS ,  KC_PSCR ,  KC_PGUP ,  XXXXXXX ,  XXXXXXX  ,   XXXXXXX ,  XXXXXXX ,   KC_UP  ,  KC_INS  ,  KC_NUM ,
//            ├──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┤
//            │          │   HOME   │  PG_DOWN │    END   │          │ │          │     ←    │     ↓    │     →    │          │
/*           */  XXXXXXX , CH_C_HOME, CH_C_PGDN, CH_C_END ,  XXXXXXX  ,   XXXXXXX , CH_C_LEFT, CH_C_DOWN, CH_C_RGHT,  XXXXXXX ,
//            │          │   CTRL   │    ALT   │   SHIFT  │          │ │          │   SHIFT  │    ALT   │   CTRL   │          │
// ┌──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┐
// │          │          │          │          │          │          │ │          │          │          │          │          │          │
/**/  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX  ,   XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,  XXXXXXX ,
// └──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤ ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┘
//                                  │    DEL   │    TAB   │   SPACE  │ │   ENTER  │    ESC   │ BACKSPACE│
/*                                 */  _______ ,  _______ ,  _______  ,   _______ ,  _______ , _______  ),
//                                  │          │          │          │ │          │          │          │
//                                  └──────────┴──────────┴──────────┘ └──────────┴──────────┴──────────┘
};

// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                       │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

void send_symbol(uint16_t usa_code, uint16_t rus_code) {
  switch (get_highest_layer(default_layer_state)) {
    case _USA: tap_code16(usa_code); break;
    case _RUS: tap_code16(rus_code); break;
  }
}

void send_usa_symbol(uint16_t usa_code) {
  switch (get_highest_layer(default_layer_state)) {
    case _USA: tap_code16(usa_code); break;
    case _RUS:
        tap_code16(SWITCH_USA);
        wait_ms(25);
        tap_code16(usa_code);
        wait_ms(10);
        tap_code16(SWITCH_RUS);
        break;
  }
}

void send_rus_symbol(uint16_t rus_code) {
  switch (get_highest_layer(default_layer_state)) {
    case _USA:
        tap_code16(SWITCH_RUS);
        wait_ms(25);
        tap_code16(rus_code);
        wait_ms(10);
        tap_code16(SWITCH_USA);
        break;
    case _RUS: tap_code16(rus_code); break;
  }
}

bool process_mod_user(uint16_t mod, uint16_t timer_idx, keyrecord_t *record) {
  if (record->event.pressed) {
    timers[timer_idx] = timer_read();
    register_mods(MOD_BIT(mod));
  } else {
    unregister_mods(MOD_BIT(mod));
    if (timer_elapsed(timers[timer_idx]) < TAPPING_TERM) {
        return true;
    }
  }
  return false;
}

void send_mod_code(uint16_t mod, uint16_t timer_idx, uint16_t code, keyrecord_t *record) {
  if (process_mod_user(mod, timer_idx, record)) tap_code16(code);
}

void send_mod_symbol(uint16_t mod, uint16_t timer_idx, uint16_t usa_code, uint16_t rus_code, keyrecord_t *record) {
  if (process_mod_user(mod, timer_idx, record)) send_symbol(usa_code, rus_code);
}

void send_mod_usa_symbol(uint16_t mod, uint16_t timer_idx, uint16_t usa_code, keyrecord_t *record) {
  if (process_mod_user(mod, timer_idx, record)) send_usa_symbol(usa_code);
}

void send_mod_rus_symbol(uint16_t mod, uint16_t timer_idx, uint16_t rus_code, keyrecord_t *record) {
  if (process_mod_user(mod, timer_idx, record)) send_rus_symbol(rus_code);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
//┌── c u s t o m   k e y s ───────────────────────────────────────────────────────────────────────────────────────────┐
//│┌── l a y e r s ───────────────────────────────────────────────────────────────────────────────────────────────────┐│
/*││*/      case SET_USA:                                                                                           //││
/*││*/          set_single_persistent_default_layer(_USA);                                                          //││
/*││*/          tap_code16(SWITCH_USA);                                                                             //││
/*││*/          return false;                                                                                       //││
/*││*/      case SET_RUS:                                                                                           //││
/*││*/          set_single_persistent_default_layer(_RUS);                                                          //││
/*││*/          tap_code16(SWITCH_RUS);                                                                             //││
/*││*/          return false;                                                                                       //││
//│└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
//│┌── l a n g u a g e   s p e c i f i c   k e y s ───────────────────────────────────────────────────────────────────┐│
/*││*/      case CH_DQUO: send_symbol(US_DQUO, RU_DQUO); return false;                                              //││
/*││*/      case CH_SLSH: send_symbol(US_SLSH, RU_SLSH); return false;                                              //││
/*││*/      case CH_BSLS: send_symbol(US_BSLS, RU_BSLS); return false;                                              //││
/*││*/      case CH_LPRN: send_symbol(US_LPRN, RU_LPRN); return false;                                              //││
/*││*/      case CH_RPRN: send_symbol(US_RPRN, RU_RPRN); return false;                                              //││
/*││*/      case CH_EXLM: send_symbol(US_EXLM, RU_EXLM); return false;                                              //││
/*││*/      case CH_QUES: send_symbol(US_QUES, RU_QUES); return false;                                              //││
/*││*/      case CH_PERC: send_symbol(US_PERC, RU_PERC); return false;                                              //││
//│└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
//│┌── u s a   s p e c i f i c   k e y s ─────────────────────────────────────────────────────────────────────────────┐│
/*││*/      case CH_QUOT: send_usa_symbol(US_QUOT);     return false;                                               //││
/*││*/      case CH_LCBR: send_usa_symbol(US_LCBR);     return false;                                               //││
/*││*/      case CH_RCBR: send_usa_symbol(US_RCBR);     return false;                                               //││
/*││*/      case CH_LBRC: send_usa_symbol(US_LBRC);     return false;                                               //││
/*││*/      case CH_RBRC: send_usa_symbol(US_RBRC);     return false;                                               //││
/*││*/      case CH_LABK: send_usa_symbol(US_LABK);     return false;                                               //││
/*││*/      case CH_RABK: send_usa_symbol(US_RABK);     return false;                                               //││
/*││*/      case CH_GRV:  send_usa_symbol(US_GRV);      return false;                                               //││
/*││*/      case CH_TILD: send_usa_symbol(US_TILD);     return false;                                               //││
/*││*/      case CH_PIPE: send_usa_symbol(US_PIPE);     return false;                                               //││
/*││*/      case CH_HASH: send_usa_symbol(US_HASH);     return false;                                               //││
/*││*/      case CH_AT:   send_usa_symbol(US_AT);       return false;                                               //││
/*││*/      case CH_AMPR: send_usa_symbol(US_AMPR);     return false;                                               //││
/*││*/      case CH_DLR:  send_usa_symbol(US_DLR);      return false;                                               //││
/*││*/      case CH_CIRC:  send_usa_symbol(US_CIRC);    return false;                                               //││
//│└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
//│┌── r u s   s p e c i f i c   k e y s ─────────────────────────────────────────────────────────────────────────────┐│
/*││*/      case CH_NUM: send_rus_symbol(RU_NUM); return false;                                                     //││
//│└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
//└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
        }
    }
    switch (keycode) {
//┌── c u s t o m   k e y s   w i t h   m o d s ───────────────────────────────────────────────────────────────────────┐
//│┌── l e f t ───────────────────────────────────────────────────────────────────────────────────────────────────────┐│
//││┌── c o n t r o l   k e y s ─────────────────────────────────────────────────────────────────────────────────────┐││
/*│││*/ case CH_C_S:          send_mod_code(KC_LCTL, T_LCTL, US_S, record);    return false;                       //│││
/*│││*/ case CH_C_YERU:       send_mod_code(KC_LCTL, T_LCTL, RU_YERU, record); return false;                       //│││
/*│││*/ case CH_C_F6:         send_mod_code(KC_LCTL, T_LCTL, KC_F6, record);   return false;                       //│││
/*│││*/ case CH_C_HOME:       send_mod_code(KC_LCTL, T_LCTL, KC_HOME, record); return false;                       //│││
/*│││*/ case CH_C_DLR:  send_mod_usa_symbol(KC_LCTL, T_LCTL, US_DLR, record);  return false;                       //│││
//││└────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘││
//││┌── a l t   k e y s ─────────────────────────────────────────────────────────────────────────────────────────────┐││
/*│││*/ case CH_C_D:      send_mod_code(KC_LALT, T_LALT, US_D, record);             return false;                  //│││
/*│││*/ case CH_C_VE:     send_mod_code(KC_LALT, T_LALT, RU_VE, record);            return false;                  //│││
/*│││*/ case CH_C_F7:     send_mod_code(KC_LALT, T_LALT, KC_F7, record);            return false;                  //│││
/*│││*/ case CH_C_PGDN:   send_mod_code(KC_LALT, T_LALT, KC_PGDN, record);          return false;                  //│││
/*│││*/ case CH_C_SCLN: send_mod_symbol(KC_LALT, T_LALT, US_SCLN, RU_SCLN, record); return false;                  //│││
//││└────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘││
//││┌── s h i f t   k e y s ─────────────────────────────────────────────────────────────────────────────────────────┐││
/*│││*/ case CH_C_F:      send_mod_code(KC_LSFT, T_LSFT, US_F, record);             return false;                  //│││
/*│││*/ case CH_C_A:      send_mod_code(KC_LSFT, T_LSFT, RU_A, record);             return false;                  //│││
/*│││*/ case CH_C_F8:     send_mod_code(KC_LSFT, T_LSFT, KC_F8, record);            return false;                  //│││
/*│││*/ case CH_C_END:    send_mod_code(KC_LSFT, T_LSFT, KC_END, record);           return false;                  //│││
/*│││*/ case CH_C_COMM: send_mod_symbol(KC_LSFT, T_LSFT, US_COMM, RU_COMM, record); return false;                  //│││
//││└────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘││
//│└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
//│┌── r i g h t ─────────────────────────────────────────────────────────────────────────────────────────────────────┐│
//││┌── s h i f t   k e y s ─────────────────────────────────────────────────────────────────────────────────────────┐││
/*│││*/ case CH_C_J:     send_mod_code(KC_RSFT, T_RSFT, US_J, record);           return false;                     //│││
/*│││*/ case CH_C_O:     send_mod_code(KC_RSFT, T_RSFT, RU_O, record);           return false;                     //│││
/*│││*/ case CH_C_P4:    send_mod_code(KC_RSFT, T_RSFT, KC_P4, record);          return false;                     //│││
/*│││*/ case CH_C_LEFT:  send_mod_code(KC_RSFT, T_RSFT, KC_LEFT, record);        return false;                     //│││
/*│││*/ case CH_C_DOT: send_mod_symbol(KC_RSFT, T_RSFT, US_DOT, RU_DOT, record); return false;                     //│││
//││└────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘││
//││┌── a l t   k e y s ─────────────────────────────────────────────────────────────────────────────────────────────┐││
/*│││*/ case CH_C_K:      send_mod_code(KC_RALT, T_RALT, US_K, record);             return false;                  //│││
/*│││*/ case CH_C_EL:     send_mod_code(KC_RALT, T_RALT, RU_EL, record);            return false;                  //│││
/*│││*/ case CH_C_P5:     send_mod_code(KC_RALT, T_RALT, KC_P5, record);            return false;                  //│││
/*│││*/ case CH_C_DOWN:   send_mod_code(KC_RALT, T_RALT, KC_DOWN, record);          return false;                  //│││
/*│││*/ case CH_C_COLN: send_mod_symbol(KC_RALT, T_RALT, US_COLN, RU_COLN, record); return false;                  //│││
//││└────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘││
//││┌── c o n t r o l e y s ─────────────────────────────────────────────────────────────────────────────────────────┐││
/*│││*/ case CH_C_L:       send_mod_code(KC_RCTL, T_RCTL, US_L, record);             return false;                 //│││
/*│││*/ case CH_C_DE:      send_mod_code(KC_RCTL, T_RCTL, RU_DE, record);            return false;                 //│││
/*│││*/ case CH_C_P6:      send_mod_code(KC_RCTL, T_RCTL, KC_P6, record);            return false;                 //│││
/*│││*/ case CH_C_RGHT:    send_mod_code(KC_RCTL, T_RCTL, KC_RGHT, record);          return false;                 //│││
/*│││*/ case CH_C_EXLM:  send_mod_symbol(KC_RCTL, T_RCTL, US_EXLM, RU_EXLM, record); return false;                 //│││
//││└────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘││
//│└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘│
//└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
    }
    return true;
};

/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

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

  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
*/