
/*
*  This program uses the Arduino UNO to control a set of 2 SP3T switches in a pair configuration
*  Lafe Spietz, NIST, 2025
*  Version with dual switches and a single supply for the 8 total lines for the 2 switches. Connect the ground by means of the fridge shield.  
*  February 2025 custom for Jake Davidson in the highspeed waveform metrology group at NIST
*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// It is very important to change this based on if you have a Mega or UNO, since the A5 pin maps to different digital output pins
// A5 maps to 19 on the UNO and 59 on the Mega  

//#define PIN 59 // MEGA 
#define PIN 19 // UNO

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 6 // 
//there are 6

// When setting up the NeoPixel library, we tell it how many pixels,  
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


//define bit numbers on the Cryoelec controller and map them to Arduino pins

#define switch1_common 2 // DSUB PIN 1
#define switch1_RF1 3    // DSUB PIN 2
#define switch1_RF2 4    // DSUB PIN 3
#define switch1_RF3 5    // DSUB PIN 4
#define switch2_common 6 // DSUB PIN 5
#define switch2_RF1 7    // DSUB PIN 6
#define switch2_RF2 8    // DSUB PIN 7
#define switch2_RF3 9    // DSUB PIN 8

int analog = 0;// variable which reads out the analog input from the button ladder
int delta = 20;//the acceptable difference between an analog value and an expected button state value

int mode = 1;//modes are 1, 2, or 3, which are:
//mode 1: from RF1 on switch 1 to RF3 on switch 2
//mode 2: from RF2 on switch 1 to RF2 on switch 2
//mode 3: from RF3 on switch 1 to RF1 on switch 2


void setup() {
  Serial.begin(9600);//set the baud rate to 9600 baud.

  //Set all bits to digital output mode:
  pinMode(switch1_common,OUTPUT);
  pinMode(switch1_RF1,OUTPUT);
  pinMode(switch1_RF2,OUTPUT);
  pinMode(switch1_RF3,OUTPUT);
  pinMode(switch2_common,OUTPUT);
  pinMode(switch2_RF1,OUTPUT);
  pinMode(switch2_RF2,OUTPUT);
  pinMode(switch2_RF3,OUTPUT);

  //set all pins low to start off with except common pins, which are high
  digitalWrite(switch1_common,HIGH);
  digitalWrite(switch1_RF1,LOW);
  digitalWrite(switch1_RF2,LOW);
  digitalWrite(switch1_RF3,LOW);
  digitalWrite(switch2_common,HIGH);
  digitalWrite(switch2_RF1,LOW);
  digitalWrite(switch2_RF2,LOW);
  digitalWrite(switch2_RF3,LOW);

   

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
  pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
  pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
  pixels.setPixelColor(5, pixels.Color(0, 0, 0));   
  
}





void loop() {


  pixels.clear(); // Set all pixel colors to 'off'
  analog = analogRead(A4);//read the analog voltage from the button ladder
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
  // compare the analog value to all of the various button state values.  
  // This is a probe to see which node on a many-stage voltage divider
  //  is connected to the analog pin, which tests which button is pressed.
  // We check again after a milisecond to make sure the button state 
  // is stable and is not part of a transient signal.
  // There are two if statements for each value to ensure that the user has 
  // held the button in that state for at least a millisecond, 
  // in order to prevent responding to transient signal values

  if(analog > 1024 - delta){
    delay(1);
    analog = analogRead(A4);
    if(analog > 1023 - delta){
      mode = 1;
    }
  }
  if(analog > 784 - delta && analog < 784 + delta){
    delay(1);
    analog = analogRead(A4);
    if(analog > 784 - delta && analog < 784 + delta){
      mode = 2;
    }
  }
  if(analog > 596 - delta && analog < 596 + delta){
     delay(1);
     analog = analogRead(A4);
    if(analog > 596 - delta && analog < 596 + delta){
      mode = 3;
    }
  }



  if (Serial.available()) {

    //read serial as ascii integer
     int ser = Serial.read();
     if(ser == 48){    //ASCII for 0
      mode = 0;
     }    
     if(ser == 49){    //ASCII for 1
       mode = 1;
     }
     if(ser == 50){    //ASCII for 2
       mode = 2;
     }
     if(ser == 51){    //ASCII for 3
       mode = 3;
     }

  }

  if(mode == 1){
    pixels.setPixelColor(5, pixels.Color(0, 155, 0));//path 1 green
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    digitalWrite(switch1_RF1,HIGH);
    digitalWrite(switch1_RF2,LOW);
    digitalWrite(switch1_RF3,LOW);    
    digitalWrite(switch2_RF1,LOW);
    digitalWrite(switch2_RF2,LOW);
    digitalWrite(switch2_RF3,HIGH);    

  }
  if(mode == 2){
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));
    pixels.setPixelColor(4, pixels.Color(0, 155, 0));//path 2 green
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    digitalWrite(switch1_RF1,LOW);
    digitalWrite(switch1_RF2,HIGH);
    digitalWrite(switch1_RF3,LOW);    
    digitalWrite(switch2_RF1,LOW);
    digitalWrite(switch2_RF2,HIGH);
    digitalWrite(switch2_RF3,LOW);     
  }
  if(mode == 3){
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 155, 0));//path 3 green
    digitalWrite(switch1_RF1,LOW);
    digitalWrite(switch1_RF2,LOW);
    digitalWrite(switch1_RF3,HIGH);    
    digitalWrite(switch2_RF1,HIGH);
    digitalWrite(switch2_RF2,LOW);
    digitalWrite(switch2_RF3,LOW);        
  }
  if(mode == 0){
    
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));      
    
    digitalWrite(switch1_RF1,LOW);
    digitalWrite(switch1_RF2,LOW);
    digitalWrite(switch1_RF3,LOW);    
    digitalWrite(switch2_RF1,LOW);
    digitalWrite(switch2_RF2,LOW);
    digitalWrite(switch2_RF3,LOW);    

  }

  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop


}
