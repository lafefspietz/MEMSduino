

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 19 // A5 on UNO is pin 19

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 9 // 
//there are 9

// When setting up the NeoPixel library, we tell it how many pixels,  
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define U4_123 2
#define U4_456 3
#define U4_789 4
#define U4_COM 5

#define U1_1 14
#define U1_2 15
#define U1_3 16
#define U1_COM 17

#define U2_4 10
#define U2_5 11
#define U2_6 12
#define U2_COM 13

#define U3_7 6
#define U3_8 7
#define U3_9 8
#define U3_COM 9


int analog = 0;
int delta = 20;
int mode = 1;//modes are 1,2,3,4,5,6,7,8,9 which are pixel 8,7,6,5,4,3,2,1, and 0 respectively
int cycle = 0;//variable for cycling colors as test pattern with switch off

void setup() {
    Serial.begin(9600);

    pinMode(U4_COM,OUTPUT);
    pinMode(U4_123,OUTPUT);
    pinMode(U4_456,OUTPUT);
    pinMode(U4_789,OUTPUT);

    pinMode(U1_COM,OUTPUT);
    pinMode(U1_1,OUTPUT);
    pinMode(U1_2,OUTPUT);
    pinMode(U1_3,OUTPUT);

    pinMode(U2_COM,OUTPUT);
    pinMode(U2_4,OUTPUT);
    pinMode(U2_5,OUTPUT);
    pinMode(U2_6,OUTPUT);

    pinMode(U3_COM,OUTPUT);
    pinMode(U3_7,OUTPUT);
    pinMode(U3_8,OUTPUT);
    pinMode(U3_9,OUTPUT);

    digitalWrite(U1_COM,HIGH);
    digitalWrite(U2_COM,HIGH);
    digitalWrite(U3_COM,HIGH);
    digitalWrite(U4_COM,HIGH);

    digitalWrite(U4_123,HIGH);
    digitalWrite(U4_456,LOW);
    digitalWrite(U4_789,LOW);

    digitalWrite(U1_1,HIGH);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);


  
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
  if(analog > 836 - delta && analog < 836 + delta){
    delay(5);
    analog = analogRead(A4);
    if(analog > 836 - delta && analog < 836 + delta){
         mode = 2; 
    }
  }
  if(analog > 690 - delta && analog < 690 + delta){
     delay(5);
     analog = analogRead(A4);

    if(analog > 690 - delta && analog < 690 + delta){
      mode = 3;    
    }
  }

  if(analog > 569 - delta && analog < 569 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 569 - delta && analog < 569 + delta){
      mode = 4;    
    }
  }

  if(analog > 498 - delta && analog < 498 + delta){//buttons 4 and 6 at the same time with 2 fingers, like the three Stooges
     delay(1);
     analog = analogRead(A4);

    if(analog > 498 - delta && analog < 498 + delta){
      mode = -1;    
    }
  }

  if(analog > 464 - delta && analog < 464 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 464 - delta && analog < 464 + delta){
      mode = 5;    
    }
  }

  if(analog > 372 - delta && analog < 372 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 372 - delta && analog < 372 + delta){
      mode = 6;    
    }
  }

  if(analog > 283 - delta && analog < 283 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 283 - delta && analog < 283 + delta){
      mode = 7;    
    }
  }

  if(analog > 195 - delta && analog < 195 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 195 - delta && analog < 195 + delta){
      mode = 8;    
    }
  }

  if(analog > 103 - delta && analog < 103 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 103 - delta && analog < 103 + delta){
      mode = 9;    
    }
  }

  if (Serial.available()) {

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
     if(ser == 55){    //ASCII for 7
      mode = 7;
     }
     if(ser == 56){    //ASCII for 8
      mode = 8;
     }
     if(ser == 57){    //ASCII for 9
      mode = 9;
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
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(255, 0, 0));    

    digitalWrite(U4_123,HIGH);
    digitalWrite(U4_456,LOW);
    digitalWrite(U4_789,LOW);

    digitalWrite(U1_1,HIGH);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);

    
  }
  if(mode == 2){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    
    digitalWrite(U4_123,HIGH);
    digitalWrite(U4_456,LOW);
    digitalWrite(U4_789,LOW);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,HIGH);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);
 
  }
  if(mode == 3){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    
    digitalWrite(U4_123,HIGH);
    digitalWrite(U4_456,LOW);
    digitalWrite(U4_789,LOW);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,HIGH);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);    

  }
  if(mode == 4){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    
    digitalWrite(U4_123,LOW);
    digitalWrite(U4_456,HIGH);
    digitalWrite(U4_789,LOW);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,HIGH);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);    


  }
  if(mode == 5){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    

    digitalWrite(U4_123,LOW);
    digitalWrite(U4_456,HIGH);
    digitalWrite(U4_789,LOW);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,HIGH);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);    


  }
  if(mode == 6){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    

    digitalWrite(U4_123,LOW);
    digitalWrite(U4_456,HIGH);
    digitalWrite(U4_789,LOW);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,HIGH);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);

  }

  if(mode == 7){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    

    digitalWrite(U4_123,LOW);
    digitalWrite(U4_456,LOW);
    digitalWrite(U4_789,HIGH);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,HIGH);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);

 }
  if(mode == 8){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    

    digitalWrite(U4_123,LOW);
    digitalWrite(U4_456,LOW);
    digitalWrite(U4_789,HIGH);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,HIGH);
    digitalWrite(U3_9,LOW);

  }
  if(mode == 9){
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    

    digitalWrite(U4_123,LOW);
    digitalWrite(U4_456,LOW);
    digitalWrite(U4_789,HIGH);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,HIGH);

  }
if(mode == 0){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    

    digitalWrite(U4_123,LOW);
    digitalWrite(U4_456,LOW);
    digitalWrite(U4_789,LOW);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);

  }
if(mode == -1){

    //this is the same as mode 0, but it adds color cycles for a test pattern.  
    //change this to be anything you want, it has no impact on function.
    pixels.setPixelColor(0, pixels.Color(cycle, (cycle + 85)%256, (cycle + 177)%256));    
    pixels.setPixelColor(1, pixels.Color(cycle + 28, (cycle + 85 + 28)%256, (cycle + 177 + 42)%256));    
    pixels.setPixelColor(2, pixels.Color(cycle + 2*28, (cycle + 85 + 2*28)%256, (cycle + 177 + 2*28)%256));    
    pixels.setPixelColor(3, pixels.Color(cycle + 3*28, (cycle + 85 + 3*28)%256, (cycle + 177 + 3*28)%256));    
    pixels.setPixelColor(4, pixels.Color(cycle + 4*28, (cycle + 85 + 4*28)%256, (cycle + 177 + 4*28)%256));    
    pixels.setPixelColor(5, pixels.Color(cycle + 5*28, (cycle + 85 + 5*28)%256, (cycle + 177 + 5*28)%256));    
    pixels.setPixelColor(6, pixels.Color(cycle + 6*28, (cycle + 85 + 6*28)%256, (cycle + 177 + 6*28)%256));    
    pixels.setPixelColor(7, pixels.Color(cycle + 7*28, (cycle + 85 + 7*28)%256, (cycle + 177 + 7*28)%256));    
    pixels.setPixelColor(8, pixels.Color(cycle + 8*28, (cycle + 85 + 8*28)%256, (cycle + 177 + 8*28)%256));    
    


    digitalWrite(U4_123,LOW);
    digitalWrite(U4_456,LOW);
    digitalWrite(U4_789,LOW);

    digitalWrite(U1_1,LOW);
    digitalWrite(U1_2,LOW);
    digitalWrite(U1_3,LOW);
 
    digitalWrite(U2_4,LOW);
    digitalWrite(U2_5,LOW);
    digitalWrite(U2_6,LOW);

    digitalWrite(U3_7,LOW);
    digitalWrite(U3_8,LOW);
    digitalWrite(U3_9,LOW);
    cycle++;
    if(cycle > 255){
      cycle = 0;
    }
    delay(10);
  }
  
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop

  //Serial.println(analog);

}
