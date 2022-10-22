//I Noris Singa, 000812720 certify that this material is my original work. No other person's work has been 
//used without due acknowledgement. I have not made my work available to anyone else.

// COMP-10184 – Mohawk College 
// PIR Sensor Test Application 
// Turn on the blue LED with motion is detected. 


#include <Arduino.h>

// digital input pin definitions 
#define PIN_PIR D5 
#define PIN_BUTTON D6 
int pirState = LOW;
int val1 = 0;
 
 
// ************************************************************* 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure the LED output 
  pinMode(LED_BUILTIN, OUTPUT); 
 
  // PIR sensor is an INPUT 
  pinMode(PIN_PIR, INPUT); 
 
  // Button is an INPUT 
  pinMode(PIN_BUTTON, INPUT_PULLUP); 
} 
 
// ************************************************************* 
void loop() { 
  
 
  // read PIR sensor (true = Motion detected!).  As long as there 
  // is motion, this signal will be true.  About 2.5 seconds after  
  // motion stops, the PIR signal will become false. 
  val1 = digitalRead(PIN_PIR); 

  if (val1 == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
    
    if (pirState == LOW) {
      Serial.println("\nMotion detected!");
    // We only want to print on the output change, not state
      pirState = HIGH;
      delay (10000);

    }
  }else {
    digitalWrite(LED_BUILTIN, HIGH); 
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("No motion detected!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }


} 