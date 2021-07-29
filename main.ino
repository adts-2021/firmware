#include <SPI.h>
#include "Ucglib.h"
#include "adts_lib.h"


Ucglib_ST7735_18x128x160_HWSPI ucg(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

//Test & Measurement
//The SuperMegaElectroMagnetic Tester
//Philip Lim
//asdasd



void draw_adi_logo()
{
  
  // get w and h
  ucg_int_t w,h;
  w = ucg.getWidth();
  h = ucg.getHeight();
  char pos[16];
  sprintf(pos, "H: %d, W: %d\n", h,w);
  Serial.write(pos);

  for (ucg_int_t c_p_x=2; c_p_x<w; c_p_x++){
    for (ucg_int_t c_p_y=0; c_p_y<h; c_p_y++){
//        ucg.clearScreen();
//        char cpos[16];
//        sprintf(cpos, "X: %d, Y: %d\n", c_p_x,c_p_y);
//        Serial.write(cpos);
        ucg.setColor(0, 113, 255);
        ucg.drawPixel(c_p_x, c_p_y);
//        delay(10);
    }  
  }
  
}


void write_text()
{
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.setFont(ucg_font_ncenR14_hr);
}

void setup(void)
{
  Serial.begin(9600);
  delay(1000);
  Serial.write("Hello World\n");

  //Initialize ucg lib
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  
  //Restore original state
  ucg.setMaxClipRange();
  ucg.undoRotate();
  ucg.setRotate90();
  ucg.clearScreen();
  ucg.setColor(0, 0, 0);
  ucg.drawBox(0, 0, ucg.getWidth(), ucg.getHeight());
}

void loop() {
  delay(500);
  draw_adi_logo();
}
