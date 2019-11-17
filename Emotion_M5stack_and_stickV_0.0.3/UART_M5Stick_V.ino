

void read_m5stic_v() {

  while (Serial.available()) {
    data = Serial.read();
    if (data == '\r' || xPos > 311) {
      xPos = 0;
      //yDraw = scroll_line();
    }
    if (data > 31 && data < 128) {
      //xPos += M5.Lcd.drawChar(data, xPos, yDraw, 2);
      //client.publish("esp/desk_robot",  String(data));
      emotion += String(data);
    }
  }

  if (emotion.equals(" sad")) {
    move_ears(0, 180);
    M5.Lcd.fillScreen( WHITE );
    Avatar_Face(1);
    client.publish("esp/desk_robot", "Hola, te sucede algo, es que el robot de escritorio te ve triste. puedo hacer algo para ayudarte?...");
    emotion = "";
  } else if (emotion.equals(" angry")) {
    move_ears(180, 0);
    M5.Lcd.fillScreen( WHITE );
    Avatar_Face(1);
    client.publish("esp/desk_robot", "Hola, te sucede algo, es que el robot de escritorio te ve enfadado. puedo hacer algo para ayudarte?. Recuerda que estar enfadado puede afectar tu salud.");
    emotion = "";
  } else if (emotion.equals(" neutral")) {
    //M5.Lcd.fillScreen( WHITE );
    Avatar_Face(1);
  } else {
    move_ears(90, 90);
    //M5.Lcd.fillScreen( WHITE );
    Avatar_Face(1);
  }


  //client.publish("esp/desk_robot", emotion);
}


// ##############################################################################################
// Call this function to scroll the display one text line
// ##############################################################################################
int scroll_line() {
  int yTemp = yStart; // Store the old yStart, this is where we draw the next line
  // Use the record of line lengths to optimise the rectangle size we need to erase the top line
  // M5.Lcd.fillRect(0,yStart,blank[(yStart-TOP_FIXED_AREA)/TEXT_HEIGHT],TEXT_HEIGHT, TFT_BLACK);
  M5.Lcd.fillRect(0, yStart, 320, TEXT_HEIGHT, TFT_WHITE);

  // Change the top of the scroll area
  yStart += TEXT_HEIGHT;
  // The value must wrap around as the screen memory is a circular buffer
  // if (yStart >= YMAX - BOT_FIXED_AREA) yStart = TOP_FIXED_AREA + (yStart - YMAX + BOT_FIXED_AREA);
  if (yStart >= YMAX) yStart = 0;
  // Now we can scroll the display
  scrollAddress(yStart);
  return  yTemp;
}

// ##############################################################################################
// Setup a portion of the screen for vertical scrolling
// ##############################################################################################
// We are using a hardware feature of the display, so we can only scroll in portrait orientation
void setupScrollArea(uint16_t tfa, uint16_t bfa) {
  M5.Lcd.writecommand(ILI9341_VSCRDEF); // Vertical scroll definition
  M5.Lcd.writedata(tfa >> 8);           // Top Fixed Area line count
  M5.Lcd.writedata(tfa);
  M5.Lcd.writedata((YMAX - tfa - bfa) >> 8); // Vertical Scrolling Area line count
  M5.Lcd.writedata(YMAX - tfa - bfa);
  M5.Lcd.writedata(bfa >> 8);           // Bottom Fixed Area line count
  M5.Lcd.writedata(bfa);
}

// ##############################################################################################
// Setup the vertical scrolling start address pointer
// ##############################################################################################
void scrollAddress(uint16_t vsp) {
  M5.Lcd.writecommand(ILI9341_VSCRSADD); // Vertical scrolling pointer
  M5.Lcd.writedata(vsp >> 8);
  M5.Lcd.writedata(vsp);
}
