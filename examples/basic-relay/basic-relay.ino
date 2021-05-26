int dly = 500;
#include "KTM_Relay.h"

KTM_Relay relay(2);

void setup() {
  Serial.begin(115200);
}

void loop() {


  relay.on();
  Serial.println(relay.getState());
  delay(dly);
  relay.off();
  Serial.println(relay.getState());
  delay(dly);
}
