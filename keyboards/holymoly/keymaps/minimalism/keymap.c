#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic QWERTY layer
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  |  -   |           |  =  |  6  |  7  |  8  |  9  |  0  | Backsp |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Upcas |  Q  |  W  |  E  |  R  |  T  |  {[  |           |  ]}   |  Y  |  U  |  I  |  O  |  P  |   '    |
 * |--------+-----+-----+-----+-----+-----|------|           |------|-----+-----+-----+-----+-----+--------|
 * |  Tab   |  A  |  S  |  D  |  F  |  G  | mute |           | stop |  H  |  J  |  K  |  L  |  ;  |  Enter |
 * |--------+-----+-----+-----+-----+-----|------|           |------|-----+-----+-----+-----+-----+--------|
 * | LShift |  Z  |  X  |  C  |  V  |  B  | vol- |           | vol+ |  N  |  M  |  ,  |  .  |  /  |  \     |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *  | fn(4)   |fn(2)| Alt |fn(1)|ctrl | win | spac |           | ESC  |fn(2)|ctrl |Left |Down | Up  | Right |
 *  `--------------------------------------------'           '--------------------------------------------'
 *
 *                                 ,-------------.           ,-------------.
 *                                 | mute | vol- |           | vol+ | stop |
 *                                 |------|------|           |------|------|
 *                                 | spac | win  |           | Fn(2)| ESC  |
 *                                 '------'------'           '------'------'
 *
 */

	[_BASE] = LAYOUT_ortho_4x12(
		KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_MINS,        KC_EQL, KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
		KC_CAPS, KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_LBRC,        KC_RBRC,  KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_QUOT,
		KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_MUTE,        KC_MSTP, KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_VOLD,        KC_VOLU, KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
		MO(_FN3), MO(_FN3), KC_LALT, MO(_FN1), KC_LCTL, KC_SPC, KC_LGUI,        MO(_FN2),KC_ESC, KC_LCTL, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
        ),

/*
 *
 *
 * ,----------------------------------------------------.      ,--------------------------------------------------------.
 * |        | F1  | F2  | F3  | F4  | F5      |         |      |       | F6    | F7     | F8     | F9     | F10  |      |
 * |--------+-----+-----+-----+-----+-------------------|      |-------+-------+--------+--------+--------+------+------|
 * |        | F11 | F12 |     |     |         |    (    |      |  )    |RGB_TOG|RGB_MOD |RGB_RMOD| RGB_M_P|      |      |
 * |--------+-----+-----+-----+-----+---------|---------|      |-------+-------+--------+--------+--------+------+------|
 * |        |     |     |     |     |         |         |      |       |RGB_HUD|RGB_HUI |RGB_VAD | RGB_VAI|      |      |
 * |--------+-----+-----+-----+-----+---------|---------|      |-------+-------+--------+--------+--------+------+------|
 * |        |     |     |     |     | KC_PWR  | KC_SLEP |      |       |RGB_SAD|RGB_SAI |RGB_SPD | RGB_SPI|      |      |
 * `--------+-----+-----+-----+-----+-------------------|      |-------+-------+--------+--------+--------+------+------'
 *  |       |     |     |     |     |KC_POWER | KC_WAKE |      |       |       |        |        |        |      |      |
 *  `---------------------------------------------------'      '--------------------------------------------------------'
 * 
 *                                     ,----------------.      ,-------------.
 *                                     | KC_PWR |KC_SLEP|      |      |      |
 *                                     |--------|-------|      |------|------|
 *                                     |        |KC_WAKE|      |      |      |
 *                                     '--------'-------'      '------'------'
 *
 *
*/

[_FN1] = LAYOUT_ortho_4x12(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,       KC_TRNS, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
    KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS,LSFT(KC_9) ,       LSFT(KC_0), RGB_TOG, RGB_MOD, RGB_RMOD, RGB_M_P, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,     KC_PGDOWN, RGB_HUD, RGB_HUI, RGB_VAD,  RGB_VAI, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLEP,       KC_TRNS, RGB_SAD, RGB_SAI, RGB_SPD,  RGB_SPI, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WAKE,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),




/*
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |        | F1  | F2  | F3  | F4  | F5  |      |           |      |  1  |  2  |  3  |  +  |     |        |
 * |--------+-----+-----+-----+-----+-----+------|           |------+-----+-----+-----+-----+-----+--------|
 * |        | F6  | F7  | F8  | F9  | F10 |  (   |           |  )   |  4  |  5  |  6  |  -  |     | Enter  |
 * |--------+-----+-----+-----+-----+-----+------|           |------|-----+-----+-----+-----+-----+--------|
 * |        | F11 | F12 |     |     |     |      |           |      |  7  |  8  |  9  |  *  |     |        |
 * |--------+-----+-----+-----+-----+-----+------|           |------|-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     |     |      |           |      |     |  0  |  .  |  /  |     |        |
 * `--------+-----+-----+-----+-----+-----+------'           `------------+-----+-----+-----+-----+--------'
 *  |      |      |     |     |     |     |      |           |      |     |     |     |     |     |       |
 *  `--------------------------------------------'           '--------------------------------------------'
 * 
 *                                 ,-------------.           ,-------------.
 *                                 |      |      |           |      |      |
 *                                 |------|------|           |------|------|
 *                                 |      |      |           |      |      |
 *                                 '------'------'           '------'------'
*/

	[_FN2] =LAYOUT_ortho_4x12(
		KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,           KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  LSFT(KC_9) ,       LSFT(KC_0), KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_TRNS, KC_PENT,
		KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_P0,   KC_PDOT, KC_PSLS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    

/*
 *
 * ,--------+-----+-----+-----+-----+-----+------,           ,--------+-----+-----+-----+-----+-----+------,
 * |        |     |     |     |     |     |PG DWN|           | PG UP  |     |     |     |     |     |      |
 * `--------+-----+-----+-----+-----+-----+------'           `--------+-----+-----+-----+-----+-----+------'
 * |        |     |     |     |     |     | INS  |           | DEL    |     |     |     |     |     |      |
 * `--------+-----+-----+-----+-----+-----+------'           `--------+-----+-----+-----+-----+-----+------'
 * |        |     |     |     |     |     |      |           |        |     |     |     |     |     |      |
 * `--------+-----+-----+-----+-----+-----+------'           `--------+-----+-----+-----+-----+-----+------'
 * |        |     |     |     |     |     |      |           |        |     |     |     |     |     |      |
 * `--------+-----+-----+-----+-----+-----+------'           `--------+-----+-----+-----+-----+-----+------'
 *  |      |      |     |     |     |     |      |           |      |     |     |     |     |     |       |
 *  `--------------------------------------------'           '--------------------------------------------'
 * 
 *                                 ,-------------.           ,-------------.
 *                                 |      |      |           |      |      |
 *                                 |------|------|           |------|------|
 *                                 |      |      |           |      |      |
 *                                 '------'------'           '------'------'
*/

	[_FN3] =LAYOUT_ortho_4x12(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDOWN,         KC_PGUP, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_WH_U, KC_MS_U, KC_WH_D, KC_TRNS, KC_INS,            KC_DEL,  LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_HOME,           KC_TRNS, LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), KC_TRNS,       KC_TRNS,
		KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS ),
    

/*
 *
 * ,--------+-----+-----+-----+-----+-----+------,           ,--------+-----+-----+-----+-----+-----+------,
 * |        |     |     |     |     |     |PG DWN|           | PG UP  |     |     |     |     |     |      |
 * `--------+-----+-----+-----+-----+-----+------'           `--------+-----+-----+-----+-----+-----+------'
 * |        |     |     |     |     |     | INS  |           | DEL    |     |     |     |     |     |      |
 * `--------+-----+-----+-----+-----+-----+------'           `--------+-----+-----+-----+-----+-----+------'
 * |        |     |     |     |     |     |      |           |        |     |     |     |     |     |      |
 * `--------+-----+-----+-----+-----+-----+------'           `--------+-----+-----+-----+-----+-----+------'
 * |        |     |     |     |     |     |      |           |        |     |     |     |     |     |      |
 * `--------+-----+-----+-----+-----+-----+------'           `--------+-----+-----+-----+-----+-----+------'
 *  |      |      |     |     |     |     |      |           |      |     |     |     |     |     |       |
 *  `--------------------------------------------'           '--------------------------------------------'
 * 
 *                                 ,-------------.           ,-------------.
 *                                 |      |      |           |      |      |
 *                                 |------|------|           |------|------|
 *                                 |      |      |           |      |      |
 *                                 '------'------'           '------'------'
*/

	[_FN4] =LAYOUT_ortho_4x12(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS )
    

};


