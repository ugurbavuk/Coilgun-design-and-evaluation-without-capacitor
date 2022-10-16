/*
	CoilGun.cpp
  ver. 2021.01
  build 202101.01
      not commercial
  Descriptions:
  MosFET Firmware
*/
// include this library's description file
#include <Adafruit_ST7735.h>  // Library for ST7735
#include <Adafruit_GFX.h>   // Core graphics library
#include <avr/interrupt.h>  //
#include <avr/pgmspace.h>   //
#include <stdint.h>         //  
#include <math.h>           //
#include <SPI.h>            //

// include this library's description file
#include "CoilFET.h"    // Library for projectile
#include "CoilGun.h" 	  //
#include "Icons.h" 		  // Icons 

CoilFET* drvFET;			  //

// For 0.96" and 1.8" TFT with ST7735 use:
Adafruit_ST7735* tft;

#define TFT_CS    10
#define TFT_RST    9
#define TFT_DC     8

//
uint8_t const     intrPin   = 2;
uint8_t const     stock     = 9;
volatile uint8_t  magazine;
bool  flagMode;

//
void fallingMode() {
  flagMode = false;  // !flagMode;
}

//
class Counter {
  public :
    uint8_t count;
    Counter() : count(0) {};
    ~Counter() {};

    void set_count(uint8_t bullets) {
      count = bullets;
    }

    void dec_count() {
      count--;
    }

    int get_count() {
      return count;
    }
}; Counter* slot;

//
CoilGun::CoilGun() {
  // Constructor
}

CoilGun::~CoilGun() {
  // Destructor
}

void CoilGun::barHorizontal(uint8_t hx, uint8_t hy, uint8_t nx, uint16_t color) {
  for (uint8_t n = 0; n < nx; n++) {
    // horizontal color bar
    tft -> fillRect(hx + n * 12, hy, 9, 21, color);
    delay(40);
  }
}

void CoilGun::barVertical(uint8_t hx, uint8_t hy, uint8_t ny, uint16_t color) {
  for (uint8_t n = 0; n < ny; n++) {
    // vertical color bar, DARKGREY CYAN PINK DARKCYAN OLIVE
    tft -> fillRect(hx , tft -> height() - hy - (n * 10), 19, 7, color);
    delay(40);
  }
}

void CoilGun::setIconsBullet() {
  tft -> drawBitmap(7,  1, Bullet , 36, 48, BLUE);
}

void CoilGun::setIconsBattery() {
  tft -> drawBitmap(3, 59, Battery , 45, 21, PINK);
}
//*******************************
void CoilGun::Initialize() {
  pinMode(intrPin, INPUT_PULLUP);
  digitalWrite(intrPin, HIGH);
  attachInterrupt(digitalPinToInterrupt(intrPin), fallingMode, FALLING);
  slot = new Counter();
  slot -> set_count(stock);
  drvFET = new CoilFET();   //
  drvFET -> initFETs();     //
  flagMode = true;
}
//******************************************

void CoilGun::setDisplay() {
  // constructor Adafruit ST7735 TFT library
  tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
  // initialize ST7735S TFT display
  tft -> initR(INITR_MINI160x80);//
  tft -> invertDisplay(true);
  tft -> fillScreen(BLACK);
  tft -> setRotation(1);
}

void CoilGun::setOpening() {
  tft -> fillScreen(BLACK);
  tft -> drawBitmap(36, 0, Submarine, 78, 78, MAROON);
  delay(470);
  tft -> fillScreen(BLACK);
  tft -> setCursor(23, 33);
  tft -> setTextColor(DARKGREEN);
  tft -> setTextSize(2);
  tft -> println("CoilGun II");
  delay(470);

  tft -> fillScreen(BLACK);
  tft->setCursor(23, 23);
  tft->setTextColor(DARKGREEN);
  tft->setTextSize(2);
  tft->println("CoilGun II");
  barHorizontal(4, 55, 14, BLUE); // color bar
  barHorizontal(4, 55, 14, DARKGREEN);  // color bar
  barHorizontal(4, 55, 14, BLACK); // color bar

  tft -> fillScreen(BLACK);
  setIconsBullet();
  setIconsBattery();
  barHorizontal(59, 17, 8, MAROON); // color bar
  barHorizontal(59, 17, 8, BLUE); // color bar
  barHorizontal(59, 59, 8, MAROON); // color bar
  barHorizontal(59, 59, 8, PINK);  // color bar
  barHorizontal(59, 17, 8, BLACK); // color bar
  delay(470);
}

void CoilGun::rsdPrint(uint8_t nb, uint16_t color) {
  tft -> setTextColor(color);
  tft -> setTextSize(6);
  tft -> fillRect(99, 8, 35, 49, BLACK);
  tft -> setCursor(99, 8);
  tft -> print(nb);
}
//******************************************
void CoilGun::shotControl() {
  magazine = slot -> get_count();
  rsdPrint(magazine, BLUE);
  if (magazine != 0) {
    if (!flagMode) {
      drvFET -> runFETs();		// shot projectile();
      slot -> dec_count();		// last projectile status
      flagMode = true;
    }
    barHorizontal(59, 59, 8, MAROON);  // color bar
  }
  else {
    rsdPrint(magazine, BLUE);
    slot -> set_count(stock);
    magazine = slot -> get_count();
    barHorizontal(59, 59, 8, PINK);  // color bar
  }
}
