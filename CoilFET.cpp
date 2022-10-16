/*
  CoilFET.cpp
 	ver. 2021.01
	build 202101.0X /
		not commercial
  Descriptions:
	MosFET Firmware
*/
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// include this library's description file
#include "CoilFET.h"
//#include "Kinetics.h"

// declare which constants used
uint8_t const  drvPinFET04 = 6;
uint8_t const  drvPinFET03 = 5;
uint8_t const  drvPinFET02 = 4;
uint8_t const  drvPinFET01 = 3;

// declare which variables we will be using
volatile uint16_t  delayON04;
volatile uint16_t  delayON03;
volatile uint16_t  delayON02;
volatile uint16_t  delayON01;

volatile uint16_t  delayOFF04;
volatile uint16_t  delayOFF03;
volatile uint16_t  delayOFF02;
volatile uint16_t  delayOFF01;

bool  flagFET04 = false;
bool  flagFET03 = false;
bool  flagFET02 = false;
bool  flagFET01 = false;

CoilFET::CoilFET() {
  // Constructor
  // gates -> ON times
  delayON04  = 40000;     // test
  delayON03  = 40000;     // test
  delayON02  = 40000;     // test
  delayON01  = 40000;     // test
  // gates -> OFF times
  delayOFF04 = 40;       // test
  delayOFF03 = 30;       // test
  delayOFF02 = 20;       // test
  delayOFF01 = 10;       // test
}

CoilFET::~CoilFET() {
  // Destructor
}

void CoilFET::initFETs() {
  pinMode(drvPinFET04, OUTPUT);
  pinMode(drvPinFET03, OUTPUT);
  pinMode(drvPinFET02, OUTPUT);
  pinMode(drvPinFET01, OUTPUT);
  //
  digitalWrite(drvPinFET04, LOW);
  digitalWrite(drvPinFET03, LOW);
  digitalWrite(drvPinFET02, LOW);
  digitalWrite(drvPinFET01, LOW);
}

void CoilFET::loadFETs(uint8_t channel, uint16_t delayON, uint16_t delayOFF) {
  digitalWrite(channel, HIGH); delayMicroseconds(delayON);
  digitalWrite(channel, LOW);  delayMicroseconds(delayOFF);
}

void CoilFET::runFETs() {
  loadFETs(drvPinFET04, delayON01, delayOFF01);   // drvPinFET01 = 6;
  loadFETs(drvPinFET03, delayON02, delayOFF02);   // drvPinFET01 = 5;
  loadFETs(drvPinFET02, delayON03, delayOFF03);   // drvPinFET01 = 4;
  loadFETs(drvPinFET01, delayON04, delayOFF04);   // drvPinFET01 = 3;
  //if (!flagMode) {
}
