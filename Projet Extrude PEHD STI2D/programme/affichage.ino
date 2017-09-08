#include <OLED_I2C.h>

OLED ecran(SDA,SCL);
extern uint8_t SmallFont[];

void setupAffichage() {
  ecran.begin();
  ecran.setFont(SmallFont);
  ecran.setBrightness(207);
}

void loopAffichage() {
  ecran.clrScr();
  ecran.print("TEMPERATURE BUSE :", 0, 0);
  ecran.print("100 C", 70, 9);
  ecran.print("ETAT RESERVOIR :", 0, 20);
  ecran.print("PLEIN", 70, 30);
  ecran.print("VITESSE ROT.MOT :", 0, 43);
  ecran.printNumF((float)motorSpeed/255*100, 0, 70, 54);
  ecran.print("%", 70+6*4, 54);
  ecran.update();

}

  
