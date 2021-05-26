#include <Arduino.h>
#include "KTM_Relay.h"

KTM_Relay::KTM_Relay(int pin) {
  _inputPin = pin;
  pinMode(_inputPin, OUTPUT);

}

void KTM_Relay::on() {
  digitalWrite(_inputPin, HIGH);
  _state = getDigitalState();
}

void KTM_Relay::off() {
  digitalWrite(_inputPin, LOW);
  _state = getDigitalState();
}

bool KTM_Relay::getState() {
  return getDigitalState();
}

int KTM_Relay::getDigitalState() {
  uint8_t bit = digitalPinToBitMask(_inputPin);
  uint8_t port = digitalPinToPort(_inputPin);
  if (port == NOT_A_PIN) {
    return LOW;
  }

  return (*portOutputRegister(port) & bit) ? HIGH : LOW;
}