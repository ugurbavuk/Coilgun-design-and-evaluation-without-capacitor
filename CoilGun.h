/*
	CoilGun.h
  ver. 2021.01
  build 202101.01
     *not commercial
  Descriptions:   
  MosFET Firmware
*/

//
#define DEG_TO_RAD	 	0.017453292519943295769236907684886
#define RAD_TO_DEG 		57.295779513082320876798154814105

// some original color definitions
#define BLACK       0x0000  ///<   0,   0,   0
#define WHITE       0xFFFF  ///< 255, 255, 255
#define RED         0xF800  ///< 255,   0,   0
#define GREEN       0x07E0  ///<   0, 255,   0
#define BLUE        0x001F  ///<   0,   0, 255
#define NAVY        0x000F  ///<   0,   0, 123
#define DARKGREEN   0x03E0  ///<   0, 125,   0
#define DARKCYAN    0x03EF  ///<   0, 125, 123
#define MAROON      0x7800  ///< 123,   0,   0
#define PURPLE      0x780F  ///< 123,   0, 123
#define OLIVE       0x7BE0  ///< 123, 125,   0
#define LIGHTGREY   0xC618  ///< 198, 195, 198
#define DARKGREY    0x7BEF  ///< 123, 125, 123
#define CYAN        0x07FF  ///<   0, 255, 255
#define MAGENTA     0xF81F  ///< 255,   0, 255
#define YELLOW      0xFFE0  ///< 255, 255,   0
#define ORANGE      0xFD20  ///< 255, 165,   0
#define GREENYELLOW 0xAFE5  ///< 173, 255,  41
#define PINK        0xFC18  ///< 255, 130, 198
#define POISON      0x68FF

#ifndef CoilGun_h
#define CoilGun_h

class CoilGun {
  public:
    // Constructor
    CoilGun();
    // Destructor
    ~CoilGun();
    
    //
    void barHorizontal(uint8_t hx, uint8_t hy, uint8_t nx, uint16_t color);
    void barVertical(uint8_t hx, uint8_t hy, uint8_t ny, uint16_t color);
    void setIconsBullet();
    void setIconsBattery();
    void Initialize();
    void setDisplay();
    void setOpening();
    void rsdPrint(uint8_t nb, uint16_t color);
    void shotControl();
};
#endif
