#include <OLED_I2C.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>

int bouton = 2;
int courant = 13;
int EtatBouton;

OLED ecran(SDA,SCL);
extern uint8_t SmallFont[];


void setup() {
  ecran.begin();
  ecran.setFont(SmallFont);
  ecran.setBrightness(207);
  
  pinMode (bouton, INPUT); //bouton
  pinMode (courant, OUTPUT);  //led jaune

}

void loop() {
  ecran.clrScr();
  ecran.print("TEMPERATURE BUSE :", 0, 0);
  ecran.print("100 C", 70, 9);
  ecran.print("ETAT RESERVOIR :", 0, 20);
  ecran.print("PLEIN", 70, 30);
  ecran.print("VITESSE ROT.MOT :", 0, 43);
  ecran.printNumF((float)124/255*100, 0, 70, 54);
  ecran.print(" %", 70+6*3, 54);
  ecran.update();

}

  
