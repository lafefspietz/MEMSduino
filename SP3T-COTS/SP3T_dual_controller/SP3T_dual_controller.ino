
/*
*  This program uses the Arduino UNO to control a set of either 2 or 4 SP3T switches
*
*  Lafe Spietz, NIST, 2024
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

#define redCommon 2
#define red1_3 3
#define red2 4
#define red3_1 5
#define greenCommon 6
#define green1_3 7
#define green2 8
#define green3_1 9

int analog = 0;// variable which reads out the analog input from the button ladder
int delta = 20;//the acceptable difference between an analog value and an expected button state value
int redMode = 1;//modes are 1,2 or 3
int greenMode = 4;//modes are 4,5, or 6
int cycle = 0;//variable for cycling colors as test pattern with switch off

void setup() {
    Serial.begin(9600);//set the baud rate to 9600 baud.

    //Set all bits to digital output mode:
    pinMode(redCommon,OUTPUT);
    pinMode(red1_3,OUTPUT);
    pinMode(red2,OUTPUT);
    pinMode(red3_1,OUTPUT);
    pinMode(greenCommon,OUTPUT);
    pinMode(green1_3,OUTPUT);
    pinMode(green2,OUTPUT);
    pinMode(green3_1,OUTPUT);

    //set all pins low to start off with except common pins, which are high
    digitalWrite(redCommon,HIGH);
    digitalWrite(red1_3,LOW);
    digitalWrite(red2,LOW);
    digitalWrite(red3_1,LOW);
    digitalWrite(greenCommon,HIGH);
    digitalWrite(green1_3,LOW);
    digitalWrite(green2,LOW);
    digitalWrite(green3_1,LOW);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

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
       redMode = 1;
    }
  }
  if(analog > 784 - delta && analog < 784 + delta){
    delay(1);
    analog = analogRead(A4);
    if(analog > 784 - delta && analog < 784 + delta){
       redMode = 2;
    }
  }
  if(analog > 596 - delta && analog < 596 + delta){
     delay(1);
     analog = analogRead(A4);
    if(analog > 596 - delta && analog < 596 + delta){
      redMode = 3;
    }
  }

  if(analog > 437 - delta && analog < 437 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 437 - delta && analog < 437 + delta){
      greenMode = 4;    
    }
  }

  if(analog > 290 - delta && analog < 290 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 290 - delta && analog < 290 + delta){
      greenMode = 5;    
    }
  }

  if(analog > 158 - delta && analog < 158 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 158 - delta && analog < 158 + delta){
      greenMode = 6;    
    }
  }


  if (Serial.available()) {

    //read serial as ascii integer
     int ser = Serial.read();
     if(ser == 48){    //ASCII for 0
      redMode = 0;
      greenMode = 0;
     }    
     if(ser == 49){    //ASCII for 1
       redMode = 1;
     }
     if(ser == 50){    //ASCII for 2
       redMode = 2;
     }
     if(ser == 51){    //ASCII for 3
       redMode = 3;
     }
     if(ser == 52){    //ASCII for 4
       greenMode = 4;
     }
     if(ser == 53){    //ASCII for 5
       greenMode = 5;
     }
     if(ser == 54){    //ASCII for 6
       greenMode = 6;
     }


  }

  if(redMode == 1){
    pixels.setPixelColor(5, pixels.Color(255, 0, 0));//red path device 1 select
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    digitalWrite(red1_3,HIGH);
    digitalWrite(red2,LOW);
    digitalWrite(red3_1,LOW);    
  }
  if(redMode == 2){
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));
    pixels.setPixelColor(4, pixels.Color(255, 0, 0));//red path device 2 select
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    digitalWrite(red1_3,LOW);
    digitalWrite(red2,HIGH);
    digitalWrite(red3_1,LOW);     
  }
  if(redMode == 3){
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));//red path device 3 select    
    digitalWrite(red1_3,LOW);
    digitalWrite(red2,LOW);
    digitalWrite(red3_1,HIGH);     
  }
  if(greenMode == 4){
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));//green path device 4 select    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    digitalWrite(green1_3,HIGH);
    digitalWrite(green2,LOW);
    digitalWrite(green3_1,LOW);
  }
  if(greenMode == 5){
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 255, 0));//green path device 5 select    
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    digitalWrite(green1_3,LOW);
    digitalWrite(green2,HIGH);
    digitalWrite(green3_1,LOW);
  }
  if(greenMode == 6){
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));//green path device 6 select    
    digitalWrite(green1_3,LOW);
    digitalWrite(green2,LOW);
    digitalWrite(green3_1,HIGH);
  }

  if(redMode == 0){
    
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));      
    
    digitalWrite(red1_3,LOW);
    digitalWrite(red2,LOW);
    digitalWrite(red3_1,LOW);
    digitalWrite(green1_3,LOW);
    digitalWrite(green2,LOW);
    digitalWrite(green3_1,LOW);

  }

  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop


}
