#pragma once

#ifdef USE_ESP32

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "ble_keyboard.h"
#include <string>

namespace esphome {
namespace ble_keyboard {
template<typename... Ts> class Esp32BleKeyboardPrintAction : public Action<Ts...> {
 public:
  explicit Esp32BleKeyboardPrintAction(Esp32BleKeyboard *ble_keyboard) : ble_keyboard_(ble_keyboard) {}
  TEMPLATABLE_VALUE(std::string, text)

  void play(Ts... x) override { this->ble_keyboard_->press(this->text_.value(x...)); }

 protected:
  Esp32BleKeyboard *ble_keyboard_;
};

template<typename... Ts> class Esp32BleKeyboardPressAction : public Action<Ts...> {
 public:
  explicit Esp32BleKeyboardPressAction(Esp32BleKeyboard *ble_keyboard) : ble_keyboard_(ble_keyboard) {}
  TEMPLATABLE_VALUE(int, code)

  void play(Ts... x) override { this->ble_keyboard_->press(this->code_.value(x...)); }

 protected:
  Esp32BleKeyboard *ble_keyboard_;
};

template<typename... Ts> class Esp32BleKeyboardReleaseAction : public Action<Ts...> {
 public:
  explicit Esp32BleKeyboardReleaseAction(Esp32BleKeyboard *ble_keyboard) : ble_keyboard_(ble_keyboard) {}

  void play(Ts... x) override { this->ble_keyboard_->release(); }

 protected:
  Esp32BleKeyboard *ble_keyboard_;
};
}  // namespace ble_keyboard
}  // namespace esphome

#endif