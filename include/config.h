// MIT License
//
// Copyright (c) 2022 Cameron King
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation files
// (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software,
// and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
/// @file

#ifndef ARDUINO_BUILD_LIGHT_SCENES_POC_CONFIG_H
#define ARDUINO_BUILD_LIGHT_SCENES_POC_CONFIG_H

/// The NeoPixel PIN
static const int CONFIG_NEOPIXEL_PIN = PIN_A1;

/// The data pin used by FastLED
#define LIGHTSHOW_FASTLED_DATA_PIN PIN_A1

/// The number of NeoPixels connected
static const int CONFIG_NEOPIXEL_COUNT = 30;

/// How many pins will be mapped to Digital Inputs for playlist buttons
static const int CONFIG_PLAYLIST_NUM_BUTTONS = 2;

/// Which pin is the first Digital Pin to use for button events
static const int CONFIG_PLAYLIST_FIRST_BUTTON_PIN = 4;

#endif  // ARDUINO_BUILD_LIGHT_SCENES_POC_CONFIG_H
