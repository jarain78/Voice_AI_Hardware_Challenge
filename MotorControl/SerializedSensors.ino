
// "{"stop_robot":"True","direction":"True","lineal_speed":"0.2", "angular_speed":"0.0"}";

void get_comman(String command_input) {
  deserializeJson(doc, command_input);
  const char* stop_robot_0 = doc["stop_robot"];
  const char* motor_direction_0 = doc["direction"];
  char* lineal_speed = doc["lineal_speed"];
  char* angular_speed = doc["angular_speed"];

  String aa = String(lineal_speed);
  String bb = String(angular_speed);
  String cc = String(stop_robot_0);
  String dd = String(motor_direction_0);

  float lineal_speed_x  = aa.toFloat(); //.toFloat();
  float angular_speed_z = bb.toFloat();

  if (cc.equals("True")) {
    motor_stop = HIGH;
  } else {
    motor_stop = LOW;
  }

  if (dd.equals("True")) {
    motor_direction_L = HIGH;
    motor_direction_R = LOW;

  } else {
    motor_direction_L = LOW;
    motor_direction_R = HIGH;
  }

  get_velocity_from_message(lineal_speed_x,  angular_speed_z);

  ml_wheel_move(motor_stop, motor_direction_L, PWM_leftMotor);
  mr_wheel_move(motor_stop, motor_direction_R, PWM_rightMotor);

}

String send_data() {

  String data_sensors = String(5) + "," + String(10) + "," + String(15);

  String data_input =
    "{\"sensor\":\"us\",\"data\":[" + data_sensors + "]}";

  deserializeJson(doc, data_input);
  JsonObject obj = doc.as<JsonObject>();
  // You can get a String from a JsonObject or JsonArray:
  // No duplication is done, at least not in the JsonDocument.
  String sensor = obj["sensor"];

  // Unfortunately, the following doesn't work (issue #118):
  // sensor = obj["sensor"]; // <-  error "ambiguous overload for 'operator='"
  // As a workaround, you need to replace by:
  sensor = obj["sensor"].as<String>();

  // You can set a String to a JsonObject or JsonArray:
  // WARNING: the content of the String will be duplicated in the JsonDocument.
  obj["sensor"] = sensor;

  // It works with serialized() too:
  obj["sensor"] = serialized(sensor);

  // You can also concatenate strings
  // WARNING: the content of the String will be duplicated in the JsonDocument.
  //obj[String("sen") + "sor"] = String("gp") + "s";

  // You can compare the content of a JsonObject with a String
  //if (obj["sensor"] == sensor) {
  // ...
  //}

  // Lastly, you can print the resulting JSON to a String
  String output;
  serializeJson(doc, output);
  return output;

}
