
#include <Arduino.h>

const byte interruptpin = 0;



ICACHE_RAM_ATTR void ICACHE_RAM_ATTR ISRoutine ();

void setup () {
 Serial.begin(115200);
 pinMode(interruptpin,INPUT_PULLUP);
 pinMode(LED_BUILTIN,OUTPUT);
 attachInterrupt(digitalPinToInterrupt(interruptpin),ISRoutine,FALLING);

}

void loop () {

 // Repeatative code here

}

void ISRoutine () {
   digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
