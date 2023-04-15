#define BLYNK_PRINT Serial
#define APP_DEBUG
#define BLYNK_TEMPLATE_ID "BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Kitchen"
#define BLYNK_AUTH_TOKEN "BLYNK_AUTH_TOKEN"

#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "ssid[]";
char pass[] = "wifi passwords";

const byte PIN_DS = D2;
const byte PIN_SHCP = D3;
const byte PIN_STCP = D4;

const byte PIN_SW[] = {D5, D6, D7};
const byte PIN_LED[] = {0B00000001, 0B00000010, 0B00000100};

byte leds_Pos = 0B00000000;
byte status_Led[3] = {0, 0, 0};
byte previous_Status_Sw[3] = {HIGH, HIGH, HIGH};

void updateShiftRegister(byte led) {
    digitalWrite(PIN_STCP, LOW);
    shiftOut(PIN_DS, PIN_SHCP, MSBFIRST, led);
    digitalWrite(PIN_STCP, HIGH);
}

BLYNK_WRITE(V0) {
  status_Led[0] = param.asInt();
  bitWrite(leds_Pos, 0, status_Led[0]);
  updateShiftRegister(leds_Pos);
}

BLYNK_WRITE(V1) {
  status_Led[1] = param.asInt();
  bitWrite(leds_Pos, 1, status_Led[1]);
  updateShiftRegister(leds_Pos);
}

BLYNK_WRITE(V2) {
  status_Led[2] = param.asInt();
  bitWrite(leds_Pos, 2, status_Led[2]);
  updateShiftRegister(leds_Pos);
}

void setup()
{
    Serial.begin(9600);
    pinMode(0,INPUT);
    pinMode(1,INPUT);
    WiFi.begin(ssid, pass);
    pinMode(PIN_SW[0], INPUT_PULLUP);
    pinMode(PIN_SW[1], INPUT_PULLUP);
    pinMode(PIN_SW[2], INPUT_PULLUP);
    pinMode(PIN_STCP, OUTPUT);
    pinMode(PIN_SHCP, OUTPUT);
    pinMode(PIN_DS, OUTPUT);
    
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
    delay(100);
    Blynk.syncAll();
}

void loop() {

  if (Serial.available() == 0 ) {
    Blynk.run();
    Blynk.syncAll();  
  }

  for (byte i = 0; i < 3; i++) {
      byte status_Sw = digitalRead(PIN_SW[i]);
      if (status_Sw != previous_Status_Sw[i]) {
          delay(50);
          if (status_Sw == LOW) {
              status_Led[i] = !status_Led[i];
              bitWrite(leds_Pos, i, status_Led[i]);
              updateShiftRegister(leds_Pos);

              Blynk.virtualWrite(i, status_Led[i]);
          }
      }
      previous_Status_Sw[i] = status_Sw;
  }

  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');

    if (data.startsWith("GAS:")) {
      float gas = data.substring(4).toFloat();
      Blynk.virtualWrite(V6, gas);
    }

    if (data.startsWith("FLAME:")) {
      float flame = data.substring(6).toFloat();
      Blynk.virtualWrite(V5, flame);
    }

    if (data.startsWith("TEMP:")) {
      float temperature = data.substring(5).toFloat();
      Blynk.virtualWrite(V3, temperature);
    }
    if (data.startsWith("HUMI:")) {
      float humi = data.substring(5).toFloat();
      Blynk.virtualWrite(V4, humi);
    }
  }
}