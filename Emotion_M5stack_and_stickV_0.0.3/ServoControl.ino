

void init_servo() {
  servos.begin();
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  init_movements();
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty = map(angulo, 0, 180, pos0, pos180);
  servos.setPWM(n_servo, 0, duty);
}

void move_neck(int angle) {
  setServo(0, angle);
}

void move_ears(int left_ear, int right_ear) {
  setServo(1, left_ear);
  setServo(2, right_ear);
}


void init_movements() {
  //setServo(0, 90);
  delay(200);
  setServo(0, 70);
  delay(200);
  setServo(0, 90);
  delay(200);
  setServo(0, 135);
  delay(200);
  setServo(1, 70);
  setServo(2, 70);
  delay(200);
  setServo(1, 0);
  setServo(2, 180);
  delay(200);
  setServo(1, 90);
  setServo(2, 90);

}

void erson_detected(){
  
}
