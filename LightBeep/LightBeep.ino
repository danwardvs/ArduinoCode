int lightPin = 0;  //define a pin for Photo resistor
int ledPin=12;     //define a pin for LED
int isLightOn=false;
int hasBeeped=true;
int beepDelay=30;

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( ledPin, OUTPUT );
}

void loop()
{
   
    analogWrite(ledPin, analogRead(lightPin)/4);  //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   if(analogRead(lightPin)>50){
       
       if(isLightOn==false){
        hasBeeped=false;
        isLightOn=true;
       }
   }

   if(analogRead(lightPin)<=50){
        if(isLightOn==true){
          hasBeeped=false;
          isLightOn=false;
       }
   }
   if(hasBeeped==false){
      
      if(isLightOn)Serial.println("Light is on"); 
      if(!isLightOn)Serial.println("Light is off"); 
      
      for(int i=0; i<4; i++){
      digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(beepDelay);              // wait for a second
      digitalWrite(ledPin, LOW);
      delay(beepDelay);
      hasBeeped=true; 
      }
    
   }
    
    
   delay(5); //short delay for faster response to light.
}               
