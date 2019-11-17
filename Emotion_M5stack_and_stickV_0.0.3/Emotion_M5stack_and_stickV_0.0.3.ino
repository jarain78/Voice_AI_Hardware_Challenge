

#include <Wire.h>
#include <M5Stack.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

#include <WiFi.h>
#include <MQTT.h>

#define YMAX 240
#define TEXT_HEIGHT 16
#define BOT_FIXED_AREA 0
#define TOP_FIXED_AREA 14



const char ssid[] = "SOL_JARA";
const char pass[] = "PhD_Jaimico_Solete@1978";

char data = 0;
uint16_t xPos = 0;
uint16_t yDraw = 0;
uint16_t yStart = 0;
boolean selected = 1;
boolean change_colour = 1;
unsigned long lastMillis = 0;
uint16_t yArea = YMAX - TOP_FIXED_AREA - BOT_FIXED_AREA;

int blank[19];
int my_emotion[19];

String emotion = "";
String old_emotion = "";

unsigned int pos0 = 172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180 = 565; // ancho de pulso en cuentas para la pocicion 180°


WiFiClient net;
MQTTClient client;
//HardwareSerial m5stack_uart(0);

void connect() {
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    M5.Lcd.print(".");
    delay(1000);
  }
  M5.Lcd.println();

  M5.Lcd.print("Connecting...");
  while (!client.connect("arduino", "try", "try")) {
    M5.Lcd.print(".");
    delay(1000);
  }

  M5.Lcd.println();
  M5.Lcd.println("connected!");
  client.subscribe("esp/desk_robot");

}

void messageReceived(String &topic, String &payload) {
  //M5.Lcd.println("incoming: " + topic + " - " + payload);

}

void setup() {

  M5.begin(true, true, true, true);

  Serial.begin(9600);
  //m5stack_uart.begin(9600, SERIAL_8N1, 3, 1); // RX-TX
  setupScrollArea(0, 120);
  M5.Lcd.fillScreen( WHITE );
  for (byte i = 0; i < 18; i++) blank[i] = 0;
  for (byte i = 0; i < 18; i++) my_emotion[i] = 0;

  WiFi.begin(ssid, pass);

  client.begin("192.168.0.106", net);
  client.onMessage(messageReceived);

  connect();
  delay(2000);
  M5.Lcd.fillScreen( WHITE );
  Avatar_Face(1);
  init_servo();
  
}

void loop(void) {

  emotion = " ";
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    //client.publish("esp/desk_robot", emotion);
  }
  read_m5stic_v();
  //old_emotion = emotion;

}
