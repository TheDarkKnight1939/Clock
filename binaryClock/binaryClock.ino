#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "RTClib.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

RTC_DS1307 RTC;

int HH = 0;
int Hx = 0;
int xH = 0;
int MM = 0;
int Mx = 0;
int xM = 0;
int Sec = 0;
int Sx = 0;
int xS = 0;

void setup() {
  Serial.begin(57600);
  Wire.begin();
  RTC.begin();
  matrix.begin(0x70);
}

void loop() {
  // Setup
  DateTime now = RTC.now();
  matrix.setRotation(0);
  matrix.clear();
  matrix.drawRect(0,0, 2,8, LED_ON);
  matrix.drawRect(6,0, 2,8, LED_ON);
  matrix.setBrightness(1);


  // hour splitter
  HH = now.hour();
  if (HH >=10) {
    Hx = HH/10;
    xH = HH%10;
  }
  if (HH < 10) {
    Hx = 0;
    xH = HH;
  }
  int a1 = Hx;
  Hx = Hx/2;
  int a2 = Hx;
  Hx = Hx/2;
  int a3 = Hx;
  Hx = Hx/2;
  int a4 = Hx;
  
  int a5 = xH;
  xH = xH/2;
  int a6 = xH;
  xH = xH/2;
  int a7 = xH;
  xH = xH/2;
  int a8 = xH;

  // minute printer
  if (a1%2 == 1) {
    matrix.drawRect(2,0, 1,1, LED_ON);
  }
  if (a2%2 == 1) {
    matrix.drawRect(3,0, 1,1, LED_ON);
  }
  if (a3%2 == 1) {
    matrix.drawRect(4,0, 1,1, LED_ON);
  }
  if (a4%2 == 1) {
    matrix.drawRect(5,0, 1,1, LED_ON);
  }
  if (a5%2 == 1) {
    matrix.drawRect(2,1, 1,1, LED_ON);
  }
  if (a6%2 == 1) {
    matrix.drawRect(3,1, 1,1, LED_ON);
  }
  if (a7%2 == 1) {
    matrix.drawRect(4,1, 1,1, LED_ON);
  }
  if (a8%2 == 1) {
    matrix.drawRect(5,1, 1,1, LED_ON);
  }


  // minute splitter
  MM = now.minute();
  if (MM >=10) {
    Mx = MM/10;
    xM = MM%10;
  }
  if (MM < 10) {
    Mx = 0;
    xM = MM;
  }
  int b1 = Mx;
  Mx = Mx/2;
  int b2 = Mx;
  Mx = Mx/2;
  int b3 = Mx;
  Mx = Mx/2;
  int b4 = Mx;
  
  int b5 = xM;
  xM = xM/2;
  int b6 = xM;
  xM = xM/2;
  int b7 = xM;
  xM = xM/2;
  int b8 = xM;

  // minute printer
  if (b1%2 == 1) {
    matrix.drawRect(2,3, 1,1, LED_ON);
  }
  if (b2%2 == 1) {
    matrix.drawRect(3,3, 1,1, LED_ON);
  }
  if (b3%2 == 1) {
    matrix.drawRect(4,3, 1,1, LED_ON);
  }
  if (b4%2 == 1) {
    matrix.drawRect(5,3, 1,1, LED_ON);
  }
  if (b5%2 == 1) {
    matrix.drawRect(2,4, 1,1, LED_ON);
  }
  if (b6%2 == 1) {
    matrix.drawRect(3,4, 1,1, LED_ON);
  }
  if (b7%2 == 1) {
    matrix.drawRect(4,4, 1,1, LED_ON);
  }
  if (b8%2 == 1) {
    matrix.drawRect(5,4, 1,1, LED_ON);
  }


  // second splitter
  Sec = now.second();
  if (Sec >=10) {
    Sx = Sec/10;
    xS = Sec%10;
  }
  if (Sec < 10) {
    Sx = 0;
    xS = Sec;
  }
  int c1 = Sx;
  Sx = Sx/2;
  int c2 = Sx;
  Sx = Sx/2;
  int c3 = Sx;
  Sx = Sx/2;
  int c4 = Sx;
  
  int c5 = xS;
  xS = xS/2;
  int c6 = xS;
  xS = xS/2;
  int c7 = xS;
  xS = xS/2;
  int c8 = xS;

  // minute printer
  if (c1%2 == 1) {
    matrix.drawRect(2,6, 1,1, LED_ON);
  }
  if (c2%2 == 1) {
    matrix.drawRect(3,6, 1,1, LED_ON);
  }
  if (c3%2 == 1) {
    matrix.drawRect(4,6, 1,1, LED_ON);
  }
  if (c4%2 == 1) {
    matrix.drawRect(5,6, 1,1, LED_ON);
  }
  if (c5%2 == 1) {
    matrix.drawRect(2,7, 1,1, LED_ON);
  }
  if (c6%2 == 1) {
    matrix.drawRect(3,7, 1,1, LED_ON);
  }
  if (c7%2 == 1) {
    matrix.drawRect(4,7, 1,1, LED_ON);
  }
  if (c8%2 == 1) {
    matrix.drawRect(5,7, 1,1, LED_ON);
  }

  matrix.writeDisplay();
}
