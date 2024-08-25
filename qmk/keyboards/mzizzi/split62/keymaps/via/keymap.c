#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_default(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LEFT_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI, KC_NO,
        KC_NO, KC_SPACE, KC_BACKSPACE,

        KC_MINUS, KC_0, KC_9, KC_8, KC_7, KC_6,
        KC_BACKSLASH, KC_P, KC_O, KC_I, KC_U, KC_Y,
        KC_QUOTE, KC_SEMICOLON, KC_L, KC_K, KC_J, KC_H,
        KC_RIGHT_SHIFT, KC_SLASH, KC_DOT, KC_COMMA, KC_M, KC_N,
        KC_RIGHT_CTRL, KC_RIGHT_ALT, KC_RIGHT_GUI, KC_NO,
        KC_NO, KC_SPACE, KC_ENTER
    )
};
