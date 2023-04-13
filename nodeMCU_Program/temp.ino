#define BLYNK_PRINT Serial
#define APP_DEBUG

#define BLYNK_TEMPLATE_ID "TMPL6FbdCQEUR"
#define BLYNK_TEMPLATE_NAME "Smart Kitchen"
#define BLYNK_AUTH_TOKEN "1nvFLK6T22b_NzYQt0O1bnan2c_q3Y_z"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>
 
char ssid[] = "Gia Dinh";
char pass[] = "0966686879@@@";

const byte PIN_DS = D1;
const byte PIN_SHCP = D2;
const byte PIN_STCP = D3;

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
    pinMode(PIN_SW[0], INPUT_PULLUP);
    pinMode(PIN_SW[1], INPUT_PULLUP);
    pinMode(PIN_SW[2], INPUT_PULLUP);
    pinMode(PIN_STCP, OUTPUT);
    pinMode(PIN_SHCP, OUTPUT);
    pinMode(PIN_DS, OUTPUT);
    Serial.begin(115200);

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

    delay(100);
    Blynk.syncAll();
}

void loop() {

    Blynk.run();
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
    // Lấy giá trị nhiệt độ từ dữ liệu nhận được
    float gas = data.substring(4).toFloat();
    // Gửi giá trị nhiệt độ lên dashboard của Blynk
    Blynk.virtualWrite(V6, gas);
  }

  if (data.startsWith("FLAME:")) {
    // Lấy giá trị nhiệt độ từ dữ liệu nhận được
    float flame = data.substring(6).toFloat();
    // Gửi giá trị nhiệt độ lên dashboard của Blynk
    Blynk.virtualWrite(V5, flame);
  }

  if (data.startsWith("TEMP:")) {
    // Lấy giá trị nhiệt độ từ dữ liệu nhận được
    float temperature = data.substring(5).toFloat();
    // Gửi giá trị nhiệt độ lên dashboard của Blynk
    Blynk.virtualWrite(V3, temperature);
  }
  if (data.startsWith("HUMI:")) {
    // Lấy giá trị nhiệt độ từ dữ liệu nhận được
    float humi = data.substring(5).toFloat();
    // Gửi giá trị nhiệt độ lên dashboard của Blynk
    Blynk.virtualWrite(V4, humi);
  }
  }
}
