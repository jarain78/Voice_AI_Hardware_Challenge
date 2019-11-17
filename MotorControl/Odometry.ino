

void get_velocity_from_message(float speed_req, float angular_speed_req) {
  speed_req_left = speed_req - angular_speed_req * (wheelbase / 2); //Calculate the required speed for the left motor to comply with commanded linear and angular speeds
  speed_req_right = speed_req + angular_speed_req * (wheelbase / 2); //Calculate the required speed for the right motor to comply with commanded linear and angular speeds


  speed_cmd_right = constrain(speed_cmd_right, -max_speed, max_speed);
  PID_rightMotor.Compute();                                                 // compute PWM value for right motor
  PWM_rightMotor = constrain(((speed_req_right + sgn(speed_req_right) ) / 0.1) + (speed_cmd_right / 0.00235), -20, 20); //

  speed_cmd_left = constrain(speed_cmd_left, -max_speed, max_speed);
  PID_leftMotor.Compute();                                                 // compute PWM value for left motor
  PWM_leftMotor = constrain(((speed_req_left + sgn(speed_req_left) ) / 0.1) + (speed_cmd_left / 0.00235), -20, 20); //

}

void get_motor_speed() {

  if (abs(pos_left) < 5) {                                                  //Avoid taking in account small disturbances
    speed_act_left = 0;
  }
  else {
    speed_act_left = ((pos_left / 990) * 2 * PI) * (1000 / LOOPTIME) * radius; // calculate speed of left wheel
  }

  if (abs(pos_right) < 5) {                                                 //Avoid taking in account small disturbances
    speed_act_right = 0;
  }
  else {
    speed_act_right = ((pos_right / 990) * 2 * PI) * (1000 / LOOPTIME) * radius; // calculate speed of right wheel
  }
}


template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
