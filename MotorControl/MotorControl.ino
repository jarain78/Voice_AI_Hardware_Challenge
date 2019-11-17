#include "Config.h"


void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);

  //wheel 1 - Setup pin mode
  pinMode(ml_EL_Start_Stop, OUTPUT);//stop/start - EL
  pinMode(ml_Signal_hall, INPUT);   //plus       - Signal
  pinMode(ml_ZF_Direction, OUTPUT); //direction  - ZF

  pinMode(mr_EL_Start_Stop, OUTPUT);//stop/start - EL
  pinMode(mr_Signal_hall, INPUT);   //plus       - Signal
  pinMode(mr_ZF_Direction, OUTPUT); //direction  - ZF

  ml_wheel_stop(LOW);
  mr_wheel_stop(LOW);
  delay(2000);

  config_interruptions();
}


void loop() {

  if (Serial.available() > 0) {
    String command_input = Serial.readString();
    get_comman(command_input);
    get_motor_speed();
  }

  center_distance = distancia_center(5);
  left_distance = distancia_left(5);
  right_distance = distancia_right(5);

}
