
/*
*  This program uses the Arduino UNO to control a set of digital lines which set the state of 
*  the 6 port switches available from CryoElec using a set of 6 buttons and displays the state with a set of 
*  6 programmable RGB LEDs, using the NeoPixel system from Adafruit.  The Arduino is always listening to both the 
*  serial(at 9600 baud) and the buttons via a single shared analog line to a voltage ladder from 5 volts to ground.  
*  Mode 0 sets all outputs to off, and mode -1 also sets them off but with a whimsical test pattern on the lights. Modes 1 through 6 
*  set the switch into states from RF 1 through RF 6. 
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

#define bit1 2
#define bit2 3
#define bit3 4
#define bit4 5
#define bit5 6
#define bit6 7
#define bit7 8
#define bit8 9
#define bit9 10
#define bit10 11
#define bit11 12
#define bit12 13


int analog = 0;// variable which reads out the analog input from the button ladder
int delta = 20;//the acceptable difference between an analog value and an expected button state value
int mode = 1;//modes are 1,2,3,4,5,6 which are pixel 5,4,3,2,1, and 0 respectively, mode 0 is off, mode -1 is color cycle with all switches off
int cycle = 0;//variable for cycling colors as test pattern with switch off

void setup() {
    Serial.begin(9600);//set the baud rate to 9600 baud.

    //Set all bits to digital output mode:
    pinMode(bit1,OUTPUT);
    pinMode(bit2,OUTPUT);
    pinMode(bit3,OUTPUT);
    pinMode(bit4,OUTPUT);
    pinMode(bit5,OUTPUT);
    pinMode(bit6,OUTPUT);
    pinMode(bit7,OUTPUT);
    pinMode(bit8,OUTPUT);
    pinMode(bit9,OUTPUT);
    pinMode(bit10,OUTPUT);
    pinMode(bit11,OUTPUT);
    pinMode(bit12,OUTPUT);

    //set all pins low to start off with
    digitalWrite(bit1,LOW);
    digitalWrite(bit2,LOW);
    digitalWrite(bit3,LOW);
    digitalWrite(bit4,LOW);
    digitalWrite(bit5,LOW);
    digitalWrite(bit6,LOW);
    digitalWrite(bit7,LOW);
    digitalWrite(bit8,LOW);
    digitalWrite(bit9,LOW);
    digitalWrite(bit10,LOW);
    digitalWrite(bit11,LOW);
    digitalWrite(bit12,LOW);
  
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
       mode = 1;      
    }
  }
  if(analog > 784 - delta && analog < 784 + delta){
    delay(5);
    analog = analogRead(A4);
    if(analog > 784 - delta && analog < 784 + delta){
         mode = 2; 
    }
  }
  if(analog > 596 - delta && analog < 596 + delta){
     delay(5);
     analog = analogRead(A4);

    if(analog > 596 - delta && analog < 596 + delta){
      mode = 3;    
    }
  }

  if(analog > 437 - delta && analog < 437 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 437 - delta && analog < 437 + delta){
      mode = 4;    
    }
  }

  if(analog > 290 - delta && analog < 290 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 290 - delta && analog < 290 + delta){
      mode = 5;    
    }
  }

  if(analog > 158 - delta && analog < 158 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 158 - delta && analog < 158 + delta){
      mode = 6;    
    }
  }

  if(analog > 188 - delta && analog < 188 + delta){//press 6 and 5 at the same time to initiate this test state
     analog = analogRead(A4);
     mode = -1;    
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
     if(ser == 52){    //ASCII for 4
      mode = 4;
     }
     if(ser == 53){    //ASCII for 5
      mode = 5;
     }
     if(ser == 54){    //ASCII for 6
      mode = 6;
     }
     if(ser == 99){    //ASCII for c, which stands for "cycle"
      mode = -1;
     }

  }

  if(mode == 1){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(255, 0, 0));    

    digitalWrite(bit1,HIGH);
    digitalWrite(bit2,HIGH);
    digitalWrite(bit3,LOW);
    digitalWrite(bit4,LOW);
    digitalWrite(bit5,HIGH);
    digitalWrite(bit6,HIGH);
    digitalWrite(bit7,LOW);
    digitalWrite(bit8,LOW);
    digitalWrite(bit9,LOW);
    digitalWrite(bit10,LOW);
    digitalWrite(bit11,LOW);
    digitalWrite(bit12,LOW);
    
  }
  if(mode == 2){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    

    digitalWrite(bit1,HIGH);
    digitalWrite(bit2,HIGH);
    digitalWrite(bit3,LOW);
    digitalWrite(bit4,LOW);
    digitalWrite(bit5,HIGH);
    digitalWrite(bit6,LOW);
    digitalWrite(bit7,HIGH);
    digitalWrite(bit8,LOW);
    digitalWrite(bit9,LOW);
    digitalWrite(bit10,LOW);
    digitalWrite(bit11,LOW);
    digitalWrite(bit12,LOW);
 
  }
  if(mode == 3){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    

    digitalWrite(bit1,HIGH);
    digitalWrite(bit2,HIGH);
    digitalWrite(bit3,LOW);
    digitalWrite(bit4,LOW);
    digitalWrite(bit5,HIGH);
    digitalWrite(bit6,LOW);
    digitalWrite(bit7,LOW);
    digitalWrite(bit8,HIGH);
    digitalWrite(bit9,LOW);
    digitalWrite(bit10,LOW);
    digitalWrite(bit11,LOW);
    digitalWrite(bit12,LOW);

  }
  if(mode == 4){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
  
    digitalWrite(bit1,HIGH);
    digitalWrite(bit2,LOW);
    digitalWrite(bit3,LOW);
    digitalWrite(bit4,HIGH);
    digitalWrite(bit5,LOW);
    digitalWrite(bit6,LOW);
    digitalWrite(bit7,LOW);
    digitalWrite(bit8,LOW);
    digitalWrite(bit9,HIGH);
    digitalWrite(bit10,HIGH);
    digitalWrite(bit11,LOW);
    digitalWrite(bit12,LOW);


  }
  if(mode == 5){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    
    digitalWrite(bit1,HIGH);
    digitalWrite(bit2,LOW);
    digitalWrite(bit3,LOW);
    digitalWrite(bit4,HIGH);
    digitalWrite(bit5,LOW);
    digitalWrite(bit6,LOW);
    digitalWrite(bit7,LOW);
    digitalWrite(bit8,LOW);
    digitalWrite(bit9,HIGH);
    digitalWrite(bit10,LOW);
    digitalWrite(bit11,HIGH);
    digitalWrite(bit12,LOW);


  }
  if(mode == 6){
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    

    digitalWrite(bit1,HIGH);
    digitalWrite(bit2,LOW);
    digitalWrite(bit3,LOW);
    digitalWrite(bit4,HIGH);
    digitalWrite(bit5,LOW);
    digitalWrite(bit6,LOW);
    digitalWrite(bit7,LOW);
    digitalWrite(bit8,LOW);
    digitalWrite(bit9,HIGH);
    digitalWrite(bit10,LOW);
    digitalWrite(bit11,LOW);
    digitalWrite(bit12,HIGH);
  }

  if(mode == 0){
    
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));      
    digitalWrite(bit1,LOW);
    digitalWrite(bit2,LOW);
    digitalWrite(bit3,LOW);
    digitalWrite(bit4,LOW);
    digitalWrite(bit5,LOW);
    digitalWrite(bit6,LOW);
    digitalWrite(bit7,LOW);
    digitalWrite(bit8,LOW);
    digitalWrite(bit9,LOW);
    digitalWrite(bit10,LOW);
    digitalWrite(bit11,LOW);
    digitalWrite(bit12,LOW);
  }

  if(mode == -1){
    
    //this is the same as mode 0, but it adds color cycles for a test pattern.  
    //change this to be anything you want, it has no impact on function.
    pixels.setPixelColor(0, pixels.Color(cycle, (cycle + 85)%256, (cycle + 177)%256));    
    pixels.setPixelColor(1, pixels.Color(cycle + 42, (cycle + 85 + 42)%256, (cycle + 177 + 42)%256));    
    pixels.setPixelColor(2, pixels.Color(cycle + 2*42, (cycle + 85 + 2*42)%256, (cycle + 177 + 2*42)%256));    
    pixels.setPixelColor(3, pixels.Color(cycle + 3*42, (cycle + 85 + 3*42)%256, (cycle + 177 + 3*42)%256));    
    pixels.setPixelColor(4, pixels.Color(cycle + 4*42, (cycle + 85 + 4*42)%256, (cycle + 177 + 4*42)%256));    
    pixels.setPixelColor(5, pixels.Color(cycle + 5*42, (cycle + 85 + 5*42)%256, (cycle + 177 + 5*42)%256));      
    digitalWrite(bit1,LOW);
    digitalWrite(bit2,LOW);
    digitalWrite(bit3,LOW);
    digitalWrite(bit4,LOW);
    digitalWrite(bit5,LOW);
    digitalWrite(bit6,LOW);
    digitalWrite(bit7,LOW);
    digitalWrite(bit8,LOW);
    digitalWrite(bit9,LOW);
    digitalWrite(bit10,LOW);
    digitalWrite(bit11,LOW);
    digitalWrite(bit12,LOW);
    cycle++;
    if(cycle > 255){
      cycle = 0;
    }
    delay(1);
  }

  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop


}
