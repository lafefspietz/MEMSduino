

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

// Which pin on the Arduino is connected to the NeoPixels?

#define PIN 59 // MEGA
//#define PIN 19 // UNO

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 6 // 
//there are 6

// When setting up the NeoPixel library, we tell it how many pixels,  
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

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


int analog = 0;
int delta = 20;
int mode = 1;//modes are 1,2,3,4,5,6,7,8,9 which are pixel 8,7,6,5,4,3,2,1, and 0 respectively


void setup() {
    Serial.begin(115200);


  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

/*
    pinMode(2,OUTPUT);// DSUB 8,  U4 -> U1
    pinMode(3,OUTPUT);// DSUB 9,  U4 -> U2
    pinMode(4,OUTPUT);// DSUB 10, U4 -> U3
    pinMode(5,OUTPUT);// DSUB 11, U4 COM
    pinMode(6,OUTPUT);// DSUB 14, U3 -> port 7
    pinMode(7,OUTPUT);// DSUB 15, U3 -> port 8
    pinMode(8,OUTPUT);// DSUB 16, U3 -> port 9
    pinMode(9,OUTPUT);// DSUB 17, U3 COM
    pinMode(10,OUTPUT);//DSUB 18, U2 -> 4 
    pinMode(11,OUTPUT);//DSUB 19, U2 -> 5
    pinMode(12,OUTPUT);//DSUB 20, U2 -> 6
    pinMode(13,OUTPUT);//DSUB 21, U2 COM
    pinMode(14,OUTPUT);//DSUB 22, U1 -> 1
    pinMode(15,OUTPUT);//DSUB 23, U1 -> 2
    pinMode(16,OUTPUT);//DSUB 24, U1 -> 3
    pinMode(17,OUTPUT);//DSUB 25, U1 COM
*/

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
  analog = analogRead(A4);
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
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


  if (Serial.available()) {

    //for more info on this code see http://adam-meyer.com/arduino/arduino-serial
    //read serial as ascii integer
     int ser = Serial.read();
    //    Serial.println(ser);
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
  
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop

//    Serial.println(analog);

}
