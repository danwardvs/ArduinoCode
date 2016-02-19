/* Blink without Delay

 Turns on and off a light emitting diode (LED) connected to a digital
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.

 Th
 by Paul Stoffregen
 modified 11 Nov 2013
 by Scott Fitzgerald


 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to set a pin number :
const int ledPin =  12;      // the number of the LED pin


// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// constants won't change :
const int update_rate = 1000;           // interval to get data from PC

int serial_data;

void setup() {
  Serial.begin(9600);  
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();

  serial_data = Serial.parseInt();

 
    if (serial_data==1) {
      digitalWrite(12, HIGH);
    }else if(serial_data==2){
      digitalWrite(12, LOW);
   }

    
    
    
    //delay(100);
  
}

