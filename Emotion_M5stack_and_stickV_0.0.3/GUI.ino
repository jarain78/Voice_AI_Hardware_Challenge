

void print_text(String text_to_show, int cursor_x, int cursor_y, int text_size) {
  M5.Lcd.setCursor(cursor_x, cursor_y);
  M5.Lcd.setTextColor(BLUE);
  M5.Lcd.setTextSize(text_size);
  M5.Lcd.println(text_to_show);
}

int print_char(char text_to_show, int cursor_x, int cursor_y, int text_size, int text_color) {
  M5.Lcd.setCursor(cursor_x, cursor_y);
  M5.Lcd.setTextColor(text_color);
  M5.Lcd.setTextSize(text_size);
  //M5.Lcd.println("analog input MIC");
  M5.Lcd.println(text_to_show);
  return cursor_x;
}


void clean_lcd() {
  M5.Lcd.fillScreen( WHITE );
}


void avatar_face_animation() {
  float rad = 0.0;

  for (int deg = 0; deg < 180; deg++) {
    Serial.print(deg);
    //rad = (deg * 180)/PI;
    //Serial.println(sin(rad));
  }
  Serial.println("-----------------");
}

void Avatar_Face(int avatar_faces) {

  // SAD
  if (avatar_faces == 0) {
    // Sad
    M5.Lcd.fillCircle(80, 100, 14, TFT_BLACK);
    M5.Lcd.fillCircle(230, 100, 14, TFT_BLACK);
    delay(5);

    M5.Lcd.drawLine(160, 170, 200, 190, TFT_BLACK);
    delay(5);

    M5.Lcd.drawLine(160, 170, 120, 190, TFT_BLACK);
    delay(5);


  } else if (avatar_faces == 1) {
    // Happy
    M5.Lcd.fillCircle(80, 100, 14, TFT_BLACK);
    M5.Lcd.fillCircle(230, 100, 14, TFT_BLACK);
    delay(5);

    M5.Lcd.drawLine(160, 170, 200, 120, TFT_BLACK);
    delay(5);

    M5.Lcd.drawLine(160, 170, 120, 120, TFT_BLACK);
    delay(5);
  }else if (avatar_faces == 2) {
    // MM
    M5.Lcd.fillCircle(80, 100, 14, TFT_BLACK);
    M5.Lcd.fillCircle(230, 100, 14, TFT_BLACK);
    delay(5);

    M5.Lcd.drawLine(160, 170, 200, 150, TFT_BLACK);
    delay(5);

    }

    
  /*else if (avatar_faces == 1) {
    M5.Lcd.drawCircle(80, 110, 14, TFT_BLACK);
    M5.Lcd.drawCircle(230, 110, 14, TFT_BLACK);

    delay(5);
    M5.Lcd.fillCircle(80, 110, 13, TFT_BLACK);
    delay(5);
    M5.Lcd.fillCircle(230, 110, 13, TFT_BLACK);
    delay(5);

    } else if (avatar_faces == 2) {

    M5.Lcd.fillCircle(80, 100, 14, TFT_BLACK);
    M5.Lcd.fillCircle(230, 100, 14, TFT_BLACK);

    M5.Lcd.drawLine(80, 100, 160, 100, TFT_BLACK);
    delay(5);
    M5.Lcd.drawLine(230, 100, 160, 100, TFT_BLACK);
    delay(5);

    }*/
}

void Avatar_Emotion(int avatar_emotions) {

  if (avatar_emotions == 0) {

    M5.Lcd.drawLine(280, 30, 280, 40, TFT_BLACK);
    M5.Lcd.drawLine(290, 30, 290, 40, TFT_BLACK);

    M5.Lcd.drawLine(280, 50, 280, 60, TFT_BLACK);
    M5.Lcd.drawLine(290, 50, 290, 60, TFT_BLACK);

    M5.Lcd.drawLine(270, 40, 280, 40, TFT_BLACK);
    M5.Lcd.drawLine(270, 50, 280, 50, TFT_BLACK);

    M5.Lcd.drawLine(290, 40, 300, 40, TFT_BLACK);
    M5.Lcd.drawLine(290, 50, 300, 50, TFT_BLACK);

  }



}

//M5.Lcd.fillRect(200, 0, 119, 40, BLUE);
