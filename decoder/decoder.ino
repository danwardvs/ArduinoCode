
int countdown = 500;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH); 
  digitalWrite(12, HIGH); 
  digitalWrite(11, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(countdown);  // wait for a second
  digitalWrite(13, LOW); 
  digitalWrite(12, LOW); 
  digitalWrite(11, LOW);// turn the LED off by making the voltage LOW
  delay(countdown);    // wait for a second
  
}
