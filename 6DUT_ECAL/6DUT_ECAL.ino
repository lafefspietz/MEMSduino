
/*
6DUT-ECAL. See https://github.com/lafefspietz/chipcal for documentation and the rest of the system
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

#define LEFT_1 A6
#define LEFT_2 17
#define LEFT_3 A7
#define LEFT_4 15
#define LEFT_5 A5
#define LEFT_6 16
#define RIGHT_1 A10
#define RIGHT_2 4
#define RIGHT_3 A9
#define RIGHT_4 6
#define RIGHT_5 A11
#define RIGHT_6 5
#define ON 3
#define SHORT A2
#define LOAD 9
#define THRU 8
#define LEFT_123 A3
#define LEFT_456 A4
#define LEFT_ECAL 14
#define RIGHT_123 A1
#define RIGHT_456 A0
#define RIGHT_ECAL 7

int analog = 0;//123456 SELECT A12
int analogEcal = 0;// analog state variable of the button analog control line for the E-cal, read from analog pin A13

int delta = 20;
int mode = 0;//mode 0 is all off, modes 1,2,3,4,5,6 are set to all the DUT ports symmetrially.  mode 7 is thru, modes 8,9, and 10 are short, open, and load
int cycle = 0;//variable for cycling colors as test pattern with switch off


void setup() {
  Serial.begin(9600);

  pinMode(LEFT_1,OUTPUT);
  pinMode(LEFT_2,OUTPUT);
  pinMode(LEFT_3,OUTPUT);
  pinMode(LEFT_4,OUTPUT);
  pinMode(LEFT_5,OUTPUT);
  pinMode(LEFT_6,OUTPUT);
  pinMode(RIGHT_1,OUTPUT);
  pinMode(RIGHT_2,OUTPUT);
  pinMode(RIGHT_3,OUTPUT);
  pinMode(RIGHT_4,OUTPUT);
  pinMode(RIGHT_5,OUTPUT);
  pinMode(RIGHT_6,OUTPUT);
  pinMode(ON,OUTPUT);
  pinMode(SHORT,OUTPUT);
  pinMode(LOAD,OUTPUT);
  pinMode(THRU,OUTPUT);
  pinMode(LEFT_123,OUTPUT);
  pinMode(LEFT_456,OUTPUT);
  pinMode(LEFT_ECAL,OUTPUT);
  pinMode(RIGHT_123,OUTPUT);
  pinMode(RIGHT_456,OUTPUT);
  pinMode(RIGHT_ECAL,OUTPUT);

  digitalWrite(LEFT_1,LOW);
  digitalWrite(LEFT_2,LOW);
  digitalWrite(LEFT_3,LOW);
  digitalWrite(LEFT_4,LOW);
  digitalWrite(LEFT_5,LOW);
  digitalWrite(LEFT_6,LOW);
  digitalWrite(RIGHT_1,LOW);
  digitalWrite(RIGHT_2,LOW);
  digitalWrite(RIGHT_3,LOW);
  digitalWrite(RIGHT_4,LOW);
  digitalWrite(RIGHT_5,LOW);
  digitalWrite(RIGHT_6,LOW);
  digitalWrite(ON,LOW);
  digitalWrite(SHORT,LOW);
  digitalWrite(LOAD,LOW);
  digitalWrite(THRU,LOW);
  digitalWrite(RIGHT_123,LOW);
  digitalWrite(RIGHT_456,LOW);
  digitalWrite(RIGHT_ECAL,LOW);
  digitalWrite(LEFT_123,LOW);
  digitalWrite(LEFT_456,LOW);
  digitalWrite(LEFT_ECAL,LOW);

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
       closeall();
    }
  }
  if(analog > 786 - delta && analog < 786 + delta){
    delay(5);
    analog = analogRead(A12);
    if(analog > 786 - delta && analog < 786 + delta){
         mode = 2;//symmetric port 2
         closeall();
    }
  }
  if(analog > 601 - delta && analog < 601 + delta){
    delay(5);
    analog = analogRead(A12);
    if(analog > 601 - delta && analog < 601 + delta){
      mode = 3;//symmetric port 3    
      closeall();
    }
  }

  if(analog > 444 - delta && analog < 444 + delta){
    delay(1);
    analog = analogRead(A12);
    if(analog > 444 - delta && analog < 444 + delta){
      mode = 4;//symmetric port 4
      closeall();
    }
  }

  if(analog > 300 - delta && analog < 300 + delta){
    delay(1);
    analog = analogRead(A12);
    if(analog > 300 - delta && analog < 300 + delta){
      mode = 5;//symmetric port 5
      closeall();
    }
  }

  if(analog > 155 - delta && analog < 155 + delta){
     delay(1);
     analog = analogRead(A12);
    if(analog > 155 - delta && analog < 155 + delta){
      mode = 6;//symmetric port 6
      closeall();
    }
  }

  analogEcal = analogRead(A13);
  if(analogEcal > 1023 - delta){
    delay(1);
    analogEcal = analogRead(A13);
    if(analogEcal > 1023 - delta){
      mode = 8;//short
      closeall();
    }
  }

  if(analogEcal > 715 - delta && analogEcal < 715 + delta){
    delay(1);
    analogEcal = analogRead(A13);
    if(analogEcal > 715 - delta && analogEcal < 715 + delta){
      mode = 9;//open
      closeall();
    }
  }

  if(analogEcal > 465 - delta && analogEcal < 465 + delta){
    delay(1);
    analogEcal = analogRead(A13);
    if(analogEcal > 465 - delta && analogEcal < 465 + delta){
      mode = 10;//load
      closeall();
    }
  }

  if(analogEcal > 237 - delta && analogEcal < 237 + delta){
    delay(1);
    analogEcal = analogRead(A13);
    if(analogEcal > 237 - delta && analogEcal < 237 + delta){
      mode = 7;//thru(ECAL DUT)
      closeall();
    }
  }

  if (Serial.available()) {

    //read serial as ascii integer
    int ser = Serial.read();
    //Serial.println(ser);
    if(ser == 48 || ser == 49 || ser == 50 || ser == 51 || ser == 52 || ser == 53 || ser == 53 || ser == 115 || ser == 111 || ser == 108 || ser == 116){
      closeall();
    }    
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
    //SYMMETRIC DUT 1 CONNECTION
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
    
    digitalWrite(LEFT_1,HIGH);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,HIGH);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,HIGH);
    digitalWrite(RIGHT_456,LOW);
    digitalWrite(RIGHT_ECAL,LOW);
    digitalWrite(LEFT_123,HIGH);
    digitalWrite(LEFT_456,LOW);
    digitalWrite(LEFT_ECAL,LOW);

  }
  if(mode == 2){
    //SYMMETRIC DUT 2 CONNECTION
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

    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,HIGH);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,HIGH);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,HIGH);
    digitalWrite(RIGHT_456,LOW);
    digitalWrite(RIGHT_ECAL,LOW);
    digitalWrite(LEFT_123,HIGH);
    digitalWrite(LEFT_456,LOW);
    digitalWrite(LEFT_ECAL,LOW);

  }
  if(mode == 3){
    //SYMMETRIC DUT 3 CONNECTION
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
    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,HIGH);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,HIGH);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,HIGH);
    digitalWrite(RIGHT_456,LOW);
    digitalWrite(RIGHT_ECAL,LOW);
    digitalWrite(LEFT_123,HIGH);
    digitalWrite(LEFT_456,LOW);
    digitalWrite(LEFT_ECAL,LOW);

  }
  if(mode == 4){
    //SYMMETRIC DUT 4 CONNECTION
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

    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,HIGH);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,HIGH);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,LOW);
    digitalWrite(RIGHT_456,HIGH);
    digitalWrite(RIGHT_ECAL,LOW);
    digitalWrite(LEFT_123,LOW);
    digitalWrite(LEFT_456,HIGH);
    digitalWrite(LEFT_ECAL,LOW);
  }
  if(mode == 5){
    //SYMMETRIC DUT 5 CONNECTION
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
    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,HIGH);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,HIGH);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,LOW);
    digitalWrite(RIGHT_456,HIGH);
    digitalWrite(RIGHT_ECAL,LOW);
    digitalWrite(LEFT_123,LOW);
    digitalWrite(LEFT_456,HIGH);
    digitalWrite(LEFT_ECAL,LOW);    
  }
  if(mode == 6){
    //SYMMETRIC DUT 6 CONNECTION
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
    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,HIGH);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,HIGH);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,LOW);
    digitalWrite(RIGHT_456,HIGH);
    digitalWrite(RIGHT_ECAL,LOW);
    digitalWrite(LEFT_123,LOW);
    digitalWrite(LEFT_456,HIGH);
    digitalWrite(LEFT_ECAL,LOW);    
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
    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,LOW);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,LOW);
    digitalWrite(RIGHT_456,LOW);
    digitalWrite(RIGHT_ECAL,LOW);
    digitalWrite(LEFT_123,LOW);
    digitalWrite(LEFT_456,LOW);
    digitalWrite(LEFT_ECAL,LOW);

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

    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,HIGH);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,LOW);
    digitalWrite(RIGHT_456,LOW);
    digitalWrite(RIGHT_ECAL,HIGH);
    digitalWrite(LEFT_123,LOW);
    digitalWrite(LEFT_456,LOW);
    digitalWrite(LEFT_ECAL,HIGH);
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
    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,LOW);
    digitalWrite(RIGHT_456,LOW);
    digitalWrite(RIGHT_ECAL,HIGH);
    digitalWrite(LEFT_123,LOW);
    digitalWrite(LEFT_456,LOW);
    digitalWrite(LEFT_ECAL,HIGH);

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
    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,HIGH);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,LOW);
    digitalWrite(RIGHT_456,LOW);
    digitalWrite(RIGHT_ECAL,HIGH);
    digitalWrite(LEFT_123,LOW);
    digitalWrite(LEFT_456,LOW);
    digitalWrite(LEFT_ECAL,HIGH);    
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
    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,HIGH);
    digitalWrite(RIGHT_123,LOW);
    digitalWrite(RIGHT_456,LOW);
    digitalWrite(RIGHT_ECAL,HIGH);
    digitalWrite(LEFT_123,LOW);
    digitalWrite(LEFT_456,LOW);
    digitalWrite(LEFT_ECAL,HIGH);    
  }
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop


}

void closeall(){
    //close all switches
    digitalWrite(LEFT_1,HIGH);
    digitalWrite(LEFT_2,HIGH);
    digitalWrite(LEFT_3,HIGH);
    digitalWrite(LEFT_4,HIGH);
    digitalWrite(LEFT_5,HIGH);
    digitalWrite(LEFT_6,HIGH);
    digitalWrite(RIGHT_1,HIGH);
    digitalWrite(RIGHT_2,HIGH);
    digitalWrite(RIGHT_3,HIGH);
    digitalWrite(RIGHT_4,HIGH);
    digitalWrite(RIGHT_5,HIGH);
    digitalWrite(RIGHT_6,HIGH);
    digitalWrite(ON,HIGH);
    digitalWrite(SHORT,HIGH);
    digitalWrite(LOAD,HIGH);
    digitalWrite(THRU,HIGH);
    digitalWrite(RIGHT_123,HIGH);
    digitalWrite(RIGHT_456,HIGH);
    digitalWrite(RIGHT_ECAL,HIGH);
    digitalWrite(LEFT_123,HIGH);
    digitalWrite(LEFT_456,HIGH);
    digitalWrite(LEFT_ECAL,HIGH);   
    delay(25);
    //open all switches
    digitalWrite(LEFT_1,LOW);
    digitalWrite(LEFT_2,LOW);
    digitalWrite(LEFT_3,LOW);
    digitalWrite(LEFT_4,LOW);
    digitalWrite(LEFT_5,LOW);
    digitalWrite(LEFT_6,LOW);
    digitalWrite(RIGHT_1,LOW);
    digitalWrite(RIGHT_2,LOW);
    digitalWrite(RIGHT_3,LOW);
    digitalWrite(RIGHT_4,LOW);
    digitalWrite(RIGHT_5,LOW);
    digitalWrite(RIGHT_6,LOW);
    digitalWrite(ON,LOW);
    digitalWrite(SHORT,LOW);
    digitalWrite(LOAD,LOW);
    digitalWrite(THRU,LOW);
    digitalWrite(RIGHT_123,LOW);
    digitalWrite(RIGHT_456,LOW);
    digitalWrite(RIGHT_ECAL,LOW);
    digitalWrite(LEFT_123,LOW);
    digitalWrite(LEFT_456,LOW);
    digitalWrite(LEFT_ECAL,LOW);   
    delay(25);
}
