//**************************************************************//
//  Name    : shiftOutCode, Hello World
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis
//  Date    : 25 Oct, 2006
//  Modified: 23 Mar 2010
//  Version : 2.0
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255
//****************************************************************
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

byte leds;
/*boolean trig = true;
unsigned char type;*/

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  /*if(trig) {
    type = LSBFIRST;
  }
  else {
    type = MSBFIRST;
  }*/
  chaser();
  //trig = !trig;
}
  // count from 0 to 255 and display the number
  // on the LEDs
  /*for(int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    // take the latchPin low so
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(1000);
  }*/

  /*digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 3);
  digitalWrite(latchPin, HIGH);*/

  /*for(int n=0;n<256;n++) { 
    //shiftOut(dataPin, clockPin, LSBFIRST, n);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, n);
    digitalWrite(latchPin, HIGH);
    n*=2;
    //shiftOut(dataPin, clockPin, LSBFIRST, n/2);
    digitalWrite(latchPin, LOW);
    delay(150);
  }*/

void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void chaser() {
  leds=0;
  for(int i=0;i<8;i++) {
    bitSet(leds, i);
    if(i!=0) {
      bitClear(leds, i-1);
    }
    updateShiftRegister();
    delay(500);
  }
}