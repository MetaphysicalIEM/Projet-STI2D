#include <math.h>

#define BTN_PLUS 7
#define BTN_MINUS 8
#define IN_1 3
#define IN_2 6
#define ENABLE 2

#define MIN_SPEED -255
#define MAX_SPEED 255
#define SPEED_PAS 5

float motorSpeed;

void setupMotor() {
  Serial.begin(9600);
  
  pinMode(BTN_PLUS, INPUT);
  pinMode(BTN_MINUS, INPUT);
  
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(ENABLE, OUTPUT);

}

boolean lirePin(unsigned char pin){
  return !digitalRead(pin);
}

void incrementeVitesse(){
  if(motorSpeed + SPEED_PAS <= MAX_SPEED){
    motorSpeed += SPEED_PAS;
  }
}

void decrementeVitesse(){
  if(motorSpeed - SPEED_PAS >= MIN_SPEED){
    motorSpeed -= SPEED_PAS;
  }  
}

void runMotor(){
  Serial.println(motorSpeed);
  if(motorSpeed == 0){
    digitalWrite(ENABLE, 0);
    analogWrite(IN_2, 0);
    analogWrite(IN_1, 0);
    Serial.println("=0");
  }else if(motorSpeed<0){
    analogWrite(IN_2, 0);
    analogWrite(IN_1, fabs(motorSpeed));
    digitalWrite(ENABLE, 1);
    Serial.println("<0");
  }else{
    analogWrite(IN_1, 0);
    analogWrite(IN_2, fabs(motorSpeed));
    digitalWrite(ENABLE, 1);
    Serial.println(">0");
  }
}

void loopMotor() {
  if(lirePin(BTN_PLUS)){
    incrementeVitesse();
  }else if(lirePin(BTN_MINUS)){
    decrementeVitesse();
  }

  runMotor();
  delay(100);
}
