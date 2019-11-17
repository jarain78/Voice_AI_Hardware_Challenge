// LOW ==> Stop Motor
// ZF ==> HIGH ==> CW
// ZF ==> LOW ==> CCW

//----------------------------------------------------
// ML
//----------------------------------------------------

void ml_wheel_stop(int flag_start_stop) {
  digitalWrite(ml_EL_Start_Stop, flag_start_stop);
}

void ml_wheel_move(int flag_start_stop, int flag_direction, int speed_motor) {

  analogWrite(ml_VR_speed, speed1);
  digitalWrite(ml_EL_Start_Stop, flag_start_stop);
  digitalWrite(ml_ZF_Direction, flag_direction);
  Serial.print(motor_stop);
  Serial.print(" ");
  Serial.print(motor_direction_R);
  Serial.print(" ");
  Serial.print(motor_direction_L);
  Serial.print(" ");
  Serial.println(speed_motor);

}


//----------------------------------------------------
// MR
//----------------------------------------------------

void mr_wheel_stop(int flag_start_stop) {
  digitalWrite(mr_EL_Start_Stop, LOW);
}

void mr_wheel_move(int flag_start_stop,  int flag_direction, int speed_motor) {

  analogWrite(mr_VR_speed, speed1);
  digitalWrite(mr_EL_Start_Stop, flag_start_stop);
  digitalWrite(mr_ZF_Direction, flag_direction);

  Serial.print(motor_stop);
  Serial.print(" ");
  Serial.print(motor_direction_R);
  Serial.print(" ");
  Serial.print(motor_direction_L);
  Serial.print(" ");
  Serial.println(speed_motor);
}

void rotate_lef() {
  ml_wheel_move(HIGH, HIGH, 10);
  mr_wheel_move(HIGH, HIGH, 10);
}

void rotate_right() {
  mr_wheel_move(HIGH, LOW, 10);
  ml_wheel_move(HIGH, LOW, 10);
}
