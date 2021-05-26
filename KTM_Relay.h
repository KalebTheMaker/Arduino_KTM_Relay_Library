#ifndef KTM_RELAY_LIB_H
#define KTM_RELAY_LIB_H

#include <Arduino.h>

class KTM_Relay {
  public:
    KTM_Relay(int pin);
    void on();
    void off();
    bool getState();
  private:
    int _inputPin;
    bool _state;
    int getDigitalState();
};

#endif