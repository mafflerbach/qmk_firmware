/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "drashna.h"
#include "analog.h"
#include "pointing_device.h"

#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4
#define KC_X0 LT(_FN, KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
		KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_MINS,        KC_EQL, KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
		KC_CAPS, KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_LBRC,        KC_RBRC,  KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_QUOT,
		KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_MUTE,        KC_MSTP, KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_VOLD,        KC_VOLU, KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
		MO(_FN3), MO(_FN3), KC_LALT, MO(_FN1), KC_LCTL, KC_SPC, KC_LGUI,        MO(_FN2),KC_ESC, KC_LCTL, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

};
// clang-format on

// Joystick
// Set Pins
// uint8_t xPin  = 8;   // VRx / /B4
// uint8_t yPin  = 7;   // VRy // B5
uint8_t swPin = C1;  // SW

// Set Parameters
uint16_t minAxisValue = 0;
uint16_t maxAxisValue = 1023;

uint8_t maxCursorSpeed = 3;
uint8_t precisionSpeed = 1;
uint8_t speedRegulator = 10;  // Lower Values Create Faster Movement

int8_t xPolarity = -1;
int8_t yPolarity = -1;

uint8_t cursorTimeout = 10;

int16_t xOrigin, yOrigin;

uint16_t lastCursor = 0;

int16_t axisCoordinate(uint8_t pin, uint16_t origin) {
    int8_t  direction;
    int16_t distanceFromOrigin;
    int16_t range;

    int16_t position = analogReadPin(pin);

    if (origin == position) {
        return 0;
    } else if (origin > position) {
        distanceFromOrigin = origin - position;
        range              = origin - minAxisValue;
        direction          = -1;
    } else {
        distanceFromOrigin = position - origin;
        range              = maxAxisValue - origin;
        direction          = 1;
    }

    float   percent    = (float)distanceFromOrigin / range;
    int16_t coordinate = (int16_t)(percent * 100);
    if (coordinate < 0) {
        return 0;
    } else if (coordinate > 100) {
        return 100 * direction;
    } else {
        return coordinate * direction;
    }
}

int8_t axisToMouseComponent(uint8_t pin, int16_t origin, uint8_t maxSpeed, int8_t polarity) {
    int coordinate = axisCoordinate(pin, origin);
    if (coordinate == 0) {
        return 0;
    } else {
        float percent = (float)coordinate / 100;
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
            return percent * precisionSpeed * polarity * (abs(coordinate) / speedRegulator);
        } else {
            return percent * maxCursorSpeed * polarity * (abs(coordinate) / speedRegulator);
        }

    if (!readPin(D1)) {
            return percent * precisionSpeed * polarity * (abs(coordinate) / speedRegulator);
    } else {
            return percent * maxCursorSpeed * polarity * (abs(coordinate) / speedRegulator);
    }

    }
}

void pointing_device_task(void) {
    report_mouse_t report = pointing_device_get_report();

    // todo read as one vector
    if (timer_elapsed(lastCursor) > cursorTimeout) {
        lastCursor = timer_read();
        report.x   = axisToMouseComponent(B4, xOrigin, maxCursorSpeed, xPolarity);
        report.y   = axisToMouseComponent(B5, yOrigin, maxCursorSpeed, yPolarity);
    }
    //
    if (!readPin(C1)) {
        report.buttons |= MOUSE_BTN1;
    } else {
        report.buttons &= ~MOUSE_BTN1;
    }

    pointing_device_set_report(report);
    pointing_device_send();
}

void matrix_init_keymap(void) {
    // init pin? Is needed?
    setPinInputHigh(C1);
    // Account for drift
    xOrigin = analogReadPin(B4);
    yOrigin = analogReadPin(B5);
}
