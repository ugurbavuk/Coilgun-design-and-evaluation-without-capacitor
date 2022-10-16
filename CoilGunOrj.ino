/*
  CoilGun II
  ver. 2021.01
  build 202101.01
      not commercial
  Descriptions:
  MosFET Firmware
	This is a free software with NO WARRANTY 
	Use it at your own risk!
*/
#include "CoilGun.h" // Library for FETs

CoilGun* coilgun;


void setup() {
  coilgun = new CoilGun();
  coilgun -> Initialize();
  coilgun -> setDisplay();
  coilgun -> setOpening();
}

void loop() {
  coilgun -> shotControl();
  //delay(10);
}
