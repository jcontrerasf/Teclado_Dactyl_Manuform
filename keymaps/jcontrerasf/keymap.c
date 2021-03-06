#include QMK_KEYBOARD_H
#include "sendstring_spanish.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _AEIOU 1
#define _NUMPAD 2
#define _FN 3


// Some basic macros
#define TASK   LCTL(LSFT(KC_ESC))
#define TAB_R  LCTL(KC_TAB)
#define TAB_L  LCTL(LSFT(KC_TAB))
#define TAB_RO LCTL(LSFT(KC_T))


enum custom_keycodes {
    MC_FRAC = SAFE_RANGE,
    MC_W,
    MC_OHM,
    MC_PI,
    MC_ALPHA,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_FRAC:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_ALGR("'") "frac");
        }
        break;

    case MC_W:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(SS_ALGR("'") "omega");
        }
        break;

    case MC_OHM:
        if (record->event.pressed) {
           SEND_STRING(SS_ALGR("'") "Omega");
        }
        break;
    case MC_PI:
        if (record->event.pressed) {
           SEND_STRING(SS_ALGR("'") "pi");
        }
        break;
    case MC_ALPHA:
        if (record->event.pressed) {
           SEND_STRING(SS_ALGR("'") "alpha");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        // left hand
        KC_GRV,         KC_1,    KC_2,    KC_3,   KC_4,   KC_5,
        LT(_FN, KC_ESC),KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,
        KC_LSFT,        KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
        KC_LCTL,        KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
                                KC_NUBS, LT(_NUMPAD, TAB_L),
                                          KC_LALT,  LCTL(KC_RALT), KC_LBRC,
                                                    KC_SPC, KC_LGUI,
        // right hand
                        KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,
                        KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC,
                        KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_UP,
                        KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_DOWN,  KC_RGHT,
                                          KC_SLASH, KC_LEFT,    
             KC_BSPC, KC_DEL, KC_RSFT,
             KC_ENT,  KC_SPC
    ),

    [_AEIOU] = LAYOUT_5x7(
        // left hand
        KC_GRV,         KC_1,    KC_2,    KC_3,   KC_4,   KC_5,
        LT(_FN, KC_ESC),KC_K,    KC_G,    KC_B,   KC_P,   KC_Q,
        KC_LSFT,        KC_A,    KC_E,    KC_I,   KC_O,   KC_U,
        KC_LCTL,        KC_Z,    KC_X,    KC_C,   KC_V,   KC_F,
                                KC_NUBS, LT(_NUMPAD, TAB_L),
                                          KC_LALT,  LCTL(KC_RALT), KC_LBRC,
                                                    KC_SPC, KC_LGUI,
        // right hand
                        KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,
                        KC_Y,    KC_J,    KC_T,     KC_M,     KC_W,     KC_LBRC,
                        KC_L,    KC_S,    KC_R,     KC_N,     KC_D,     KC_UP,
                        KC_SCLN, KC_H,    KC_COMM,  KC_DOT,   KC_DOWN,  KC_RGHT,
                                          KC_SLASH, KC_LEFT,    
             KC_BSPC, KC_DEL, KC_RSFT,
             KC_ENT,  KC_SPC
    ),

    [_NUMPAD] = LAYOUT_5x7(
        // left hand
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    MC_PI,      KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,    MC_ALPHA,   MC_OHM,     KC_TRNS,   KC_WH_L,   KC_WH_R,
        KC_TRNS,    KC_TRNS,    MC_W,       KC_TRNS,   KC_TRNS,   KC_EQL,
                                MC_FRAC,    KC_TRNS,
                                                       KC_TRNS,  KC_TRNS, KC_WH_U,
                                                                 KC_BTN3, KC_WH_D,
        // right hand
                        KC_MPRV,    KC_MPLY,    KC_MNXT,     KC_MUTE,     KC_PSLS,    KC_PAST,
                        KC_KP_7,    KC_KP_8,    KC_KP_9,     KC_VOLU,     KC_PMNS,    KC_PPLS,
                        KC_KP_4,    KC_KP_5,    KC_KP_6,     KC_VOLD,     KC_END,     KC_RBRC,
                        KC_KP_1,    KC_KP_2,    KC_KP_3,     KC_PDOT,     KC_QUOT,    KC_NUHS,
                                                KC_KP_0,     KC_HOME,    
             KC_TRNS, KC_BRIU, KC_TRNS,
             LGUI(LSFT(KC_S)), KC_BRID
    ),

    [_FN] = LAYOUT_5x7(
        // left hand
        KC_TRNS,    RGB_M_P,    RGB_M_SW,    RGB_M_TW,   RGB_VAI,   KC_5,
        KC_TRNS,    RGB_TOG,    RGB_M_SN,    RGB_HUI,    RGB_VAD,   KC_T,
        KC_TRNS,    RGB_M_B,    RGB_M_K,     RGB_HUD,    KC_F,   KC_G,
        KC_TRNS,    RGB_M_R,    RGB_M_X,     RGB_SAI,    KC_V,   KC_B,
                                RGB_M_G,     RGB_SAD,
                                          KC_PSCR,  KC_TRNS, KC_SPC,
                                                    KC_END, KC_HOME,
        // right hand
                        KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_GRV,
                        KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
                        KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                        DF(_QWERTY),DF(_AEIOU),    KC_COMM,  KC_DOT,   KC_SLSH,  KC_TRNS,
                                          KC_LEFT,  KC_UP,    
             KC_BSPC, KC_ENT, KC_LALT,
             KC_PGUP, KC_PGDN
    ),
};
