/*
  CoilFET.h
	ver. 2021.01
  build 202101.0X / 
	build 202101.0X / 
		*not commercial
  Descriptions:		
	MosFET Firmware
	
*/
// ensure this library description is only included once
#ifndef CoilFET_h
#define CoilFET_h

class CoilFET {
  public:
    // Constructor
    CoilFET();
    // Destructor
    ~CoilFET();
    // Functions
    void initFETs();
		void loadFETs(uint8_t channel, uint16_t delayON, uint16_t delayOFF); 
		void runFETs();
};
#endif
