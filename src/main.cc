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

#include <Arduino.h>
#include <ButtonEvent.h>
#include <FastLEDController.h>
#include <FlashColorPreset.h>
#include <PulseColorPreset.h>
#include <SolidColorPreset.h>

#include <memory>

#include "config.h"

auto controller =
    std::make_shared<LightShow::FastLEDController>(CONFIG_NEOPIXEL_COUNT);

auto preset_flash = std::make_shared<LightShow::FlashColorPreset>(
    controller, 0xFF, 0, 0, 10000);
auto preset_solid =
    std::make_shared<LightShow::SolidColorPreset>(controller, 0xFF, 0, 0);
auto preset_pulse = std::make_shared<LightShow::PulseColorPreset>(
    controller, 0xFF, 0, 0, 10000, 100);
auto preset_blank = std::make_shared<LightShow::Preset>();

std::shared_ptr<LightShow::Preset> current_preset = preset_blank;

/**
 * Set the NeoPixel corresponding to the pushed button to red.
 * @param sender the button that emitted this event
 */
void OnButtonDown(ButtonInformation *sender) {
  if (sender->pin == 4) {
    current_preset = preset_flash;
  } else if (sender->pin == 5) {
    current_preset = preset_pulse;
  }
}

/**
 * Perform initial hardware setup and event registration.
 */
void setup() {
  for (auto i = 0; i < CONFIG_PLAYLIST_NUM_BUTTONS; i++) {
    // register the button press events
    ButtonEvent.addButton(CONFIG_PLAYLIST_FIRST_BUTTON_PIN + i, OnButtonDown,
                          nullptr, nullptr, 100, nullptr, 0);

    // circuit playground express buttons have an internal pulldown resister
    // which should be enabled to correctly indicate when they are pressed
    // (call this after addButton, because it sets the mode to INPUT)
    pinMode(CONFIG_PLAYLIST_FIRST_BUTTON_PIN + i, INPUT_PULLDOWN);
  }

  // reset to black LEDs
  controller->Stop();

  current_preset->Start();
}

/**
 * Run the main application loop.
 */
void loop() {
  current_preset->Loop();

  // check the button event loop
  ButtonEvent.loop();
}
