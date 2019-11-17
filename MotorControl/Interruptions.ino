

void config_interruptions() {
  //Hall sensor detection - Count steps
  attachInterrupt(digitalPinToInterrupt(ml_Signal_hall), ml_plus, RISING);
  attachInterrupt(digitalPinToInterrupt(mr_Signal_hall), mr_plus, RISING);

}


void ml_plus() {
  pos_left++; //count steps
  Serial.print("Encoder Left: ");
  Serial.println(pos_left);
}


void mr_plus() {
  pos_right++; //count steps
  Serial.print("Encoder Right: ");
  Serial.println(pos_right);

}
