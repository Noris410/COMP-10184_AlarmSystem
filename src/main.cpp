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
  
 
  val1 = digitalRead(PIN_PIR);  
      if (val1 == HIGH) {            // check if the input is HIGH
         
      
        if (pirState == LOW) {
          
          Serial.println("Motion detected!");
          
          pirState = HIGH;
           digitalWrite(LED_BUILTIN, LOW);  
        delay(10000);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10000); 
        digitalWrite(LED_BUILTIN, LOW);  
        delay(10000);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10000); 
        digitalWrite(LED_BUILTIN, LOW);  
        delay(10000);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10000); 
        }
      } else {
        digitalWrite(LED_BUILTIN, HIGH); // turn LED OFF
        if (pirState == HIGH){
          // we have just turned of
          Serial.println("no motion detected!");
          // We only want to print on the output change, not state
          pirState = LOW;
        }
      }

} 