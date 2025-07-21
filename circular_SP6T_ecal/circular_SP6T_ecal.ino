
/*
Controller code for MM4250
All code Public Domain
written at NIST, Boulder 2025
Lafe Spietz
*/


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 18 // A5 on UNO is pin 19

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10 // 
//there are 9

// When setting up the NeoPixel library, we tell it how many pixels,  
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DSUB1 2
#define DSUB2 3
#define DSUB3 4
#define DSUB4 5
#define DSUB5 6
#define DSUB6 7
#define DSUB7 8
#define DSUB8 9

#define DSUB9 14
#define DSUB10 15
#define DSUB11 16
#define DSUB12 17

#define DSUB14 A8
#define DSUB15 A9
#define DSUB16 A10
#define DSUB17 A11

#define DSUB18 A0
#define DSUB19 A1
#define DSUB20 A2
#define DSUB21 A3
#define DSUB22 A4
#define DSUB23 A5
#define DSUB24 A6
#define DSUB25 A7

int analog = 0;//123456 SELECT A12
int analogEcal = 0;// analog state variable of the button analog control line for the E-cal, read from analog pin A13

int delta = 20;
int mode = 0;//mode 0 is all off, modes 1,2,3,4,5,6 are set to all the DUT ports symmetrially.  mode 7 is thru, modes 8,9, and 10 are short, open, and load
int cycle = 0;//variable for cycling colors as test pattern with switch off


void setup() {
  Serial.begin(9600);

  pinMode(DSUB1,OUTPUT);
  pinMode(DSUB2,OUTPUT);
  pinMode(DSUB3,OUTPUT);
  pinMode(DSUB4,OUTPUT);
  pinMode(DSUB5,OUTPUT);
  pinMode(DSUB6,OUTPUT);
  pinMode(DSUB7,OUTPUT);
  pinMode(DSUB8,OUTPUT);
  pinMode(DSUB9,OUTPUT);
  pinMode(DSUB10,OUTPUT);
  pinMode(DSUB11,OUTPUT);
  pinMode(DSUB12,OUTPUT);
  pinMode(DSUB14,OUTPUT);
  pinMode(DSUB15,OUTPUT);
  pinMode(DSUB16,OUTPUT);
  pinMode(DSUB17,OUTPUT);
  pinMode(DSUB18,OUTPUT);
  pinMode(DSUB19,OUTPUT);
  pinMode(DSUB20,OUTPUT);
  pinMode(DSUB21,OUTPUT);
  pinMode(DSUB22,OUTPUT);
  pinMode(DSUB23,OUTPUT);
  pinMode(DSUB24,OUTPUT);
  pinMode(DSUB25,OUTPUT);

  digitalWrite(DSUB1,LOW);
  digitalWrite(DSUB2,LOW);
  digitalWrite(DSUB3,LOW);
  digitalWrite(DSUB4,LOW);
  digitalWrite(DSUB5,LOW);
  digitalWrite(DSUB6,LOW);
  digitalWrite(DSUB7,LOW);
  digitalWrite(DSUB8,LOW);
  digitalWrite(DSUB9,LOW);
  digitalWrite(DSUB10,LOW);
  digitalWrite(DSUB11,LOW);
  digitalWrite(DSUB12,LOW);
  digitalWrite(DSUB14,LOW);
  digitalWrite(DSUB15,LOW);
  digitalWrite(DSUB16,LOW);
  digitalWrite(DSUB17,LOW);
  digitalWrite(DSUB18,LOW);
  digitalWrite(DSUB19,LOW);
  digitalWrite(DSUB20,LOW);
  digitalWrite(DSUB21,LOW);
  digitalWrite(DSUB22,LOW);
  digitalWrite(DSUB23,LOW);
  digitalWrite(DSUB24,LOW);
  digitalWrite(DSUB25,LOW);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

}


void loop() {

  pixels.clear(); // Set all pixel colors to 'off'
  analog = analogRead(A12);//
  Serial.println(analog);
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
if(analog > 1024 - delta){
    delay(1);
    analog = analogRead(A12);
    if(analog > 1023 - delta){
       mode = 1;//symmetric port 1
    }
  }
  if(analog > 786 - delta && analog < 786 + delta){
    delay(5);
    analog = analogRead(A12);
    if(analog > 786 - delta && analog < 786 + delta){
         mode = 2;//symmetric port 2
    }
  }
  if(analog > 601 - delta && analog < 601 + delta){
    delay(5);
    analog = analogRead(A12);
    if(analog > 601 - delta && analog < 601 + delta){
      mode = 3;//symmetric port 3    
    }
  }

  if(analog > 444 - delta && analog < 444 + delta){
    delay(1);
    analog = analogRead(A12);
    if(analog > 444 - delta && analog < 444 + delta){
      mode = 4;//symmetric port 4
    }
  }

  if(analog > 300 - delta && analog < 300 + delta){
    delay(1);
    analog = analogRead(A12);
    if(analog > 300 - delta && analog < 300 + delta){
      mode = 5;//symmetric port 5
    }
  }

  if(analog > 155 - delta && analog < 155 + delta){
     delay(1);
     analog = analogRead(A12);
    if(analog > 155 - delta && analog < 155 + delta){
      mode = 6;//symmetric port 6
    }
  }

  analogEcal = analogRead(A13);
  if(analogEcal > 1023 - delta){
    delay(1);
    analogEcal = analogRead(A13);
    if(analogEcal > 1023 - delta){
      mode = 8;//short
    }
  }

  if(analogEcal > 715 - delta && analogEcal < 715 + delta){
    delay(1);
    analogEcal = analogRead(A13);
    if(analogEcal > 715 - delta && analogEcal < 715 + delta){
      mode = 9;//open
    }
  }

  if(analogEcal > 465 - delta && analogEcal < 465 + delta){
    delay(1);
    analogEcal = analogRead(A13);
    if(analogEcal > 465 - delta && analogEcal < 465 + delta){
      mode = 10;//load
    }
  }

  if(analogEcal > 237 - delta && analogEcal < 237 + delta){
    delay(1);
    analogEcal = analogRead(A13);
    if(analogEcal > 237 - delta && analogEcal < 237 + delta){
      mode = 7;//thru(ECAL DUT)
    }
  }

  if (Serial.available()) {

    //read serial as ascii integer
    int ser = Serial.read();
    //Serial.println(ser);
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
    if(ser == 115){    //ASCII for s
      mode = 8;
     }
     if(ser == 111){    //ASCII for o
      mode = 9;
     }
     if(ser == 108){    //ASCII for l
      mode = 10;
     }
     if(ser == 116){    //ASCII for t
      mode = 7;
     }

  }

  if(mode == 1){
    //PORT1
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(255, 0, 0));    
    
    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
  //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);

    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB24,HIGH);


  }
  if(mode == 2){
    //PORT2
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    

    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
    //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);

    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB16,HIGH);


  }
  if(mode == 3){
    //PORT 3
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(7, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    

    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
  //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);

    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB20,HIGH);

  }
  if(mode == 4){
    //PORT 4
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));    

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    

    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
  //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);

    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB19,HIGH);
  }
  if(mode == 5){
    //PORT 5
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    

    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
  //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);
    
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB21,HIGH);    

  }
  if(mode == 6){
    //PORT 6
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    
    
    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
  //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);
    
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);    
    
       
  }

  if(mode == 0){
    //TURN EVERYTHING OFF
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));  

    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
    //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);
  
  }
    
  if(mode == 8){
    //SHORT
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));  

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 255, 0));    
    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));  

    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
    //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);

    digitalWrite(DSUB12,HIGH);
   
  }
  if(mode == 9){    
    //OPEN
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 255, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    

    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));  

    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
    //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);
      
    
  }
  if(mode == 10){
    //LOAD
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 255, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));  

    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));      
    
    //close all switches
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB2,HIGH);
    digitalWrite(DSUB3,HIGH);
    digitalWrite(DSUB4,HIGH);
    digitalWrite(DSUB5,HIGH);
    digitalWrite(DSUB6,HIGH);
    digitalWrite(DSUB7,HIGH);
    digitalWrite(DSUB8,HIGH);
    digitalWrite(DSUB9,HIGH);
    digitalWrite(DSUB10,HIGH);
    digitalWrite(DSUB11,HIGH);
    digitalWrite(DSUB12,HIGH);
    //NEVER SEND VOLTAGE TO PINS 14 OR 15, THEY ARE GROUND!
    digitalWrite(DSUB16,HIGH);
    digitalWrite(DSUB17,HIGH);
    digitalWrite(DSUB18,HIGH);
    digitalWrite(DSUB19,HIGH);
    digitalWrite(DSUB20,HIGH);
    digitalWrite(DSUB21,HIGH);
    digitalWrite(DSUB22,HIGH);
    digitalWrite(DSUB23,HIGH);
    digitalWrite(DSUB24,HIGH);
    digitalWrite(DSUB25,HIGH);
    delay(25);

    digitalWrite(DSUB1,LOW);
    digitalWrite(DSUB2,LOW);
    digitalWrite(DSUB3,LOW);
    digitalWrite(DSUB4,LOW);
    digitalWrite(DSUB5,LOW);
    digitalWrite(DSUB6,LOW);
    digitalWrite(DSUB7,LOW);
    digitalWrite(DSUB8,LOW);
    digitalWrite(DSUB9,LOW);
    digitalWrite(DSUB10,LOW);
    digitalWrite(DSUB11,LOW);
    digitalWrite(DSUB12,LOW);
    digitalWrite(DSUB14,LOW);
    digitalWrite(DSUB15,LOW);
    digitalWrite(DSUB16,LOW);
    digitalWrite(DSUB17,LOW);
    digitalWrite(DSUB18,LOW);
    digitalWrite(DSUB19,LOW);
    digitalWrite(DSUB20,LOW);
    digitalWrite(DSUB21,LOW);
    digitalWrite(DSUB22,LOW);
    digitalWrite(DSUB23,LOW);
    digitalWrite(DSUB24,LOW);
    digitalWrite(DSUB25,LOW);
    
    digitalWrite(DSUB1,HIGH);
    digitalWrite(DSUB5,HIGH);
    
     
  }
  if(mode == 7){    
    //THRU  
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0)); 

    pixels.setPixelColor(3, pixels.Color(0, 255, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));  

    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));      
   
   
  }
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop


}
