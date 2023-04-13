#include "dht.h"
const int pin_DHT = A2;     

#include <LiquidCrystal_I2C.h>

const int pin_Gas = A0;
const int pin_Flame = A1;
const int pin_Servo = 11;
const int pin_Buzzer = 4;

const int pin_Pump_ENA = 5; // L298N enable pin
const int pin_Pump_IN1 = 6; // L298N IN1 pin
const int pin_Pump_IN2 = 7; // L298N IN2 pin

const int pin_Fan_ENB = 8; // L298N enable pin
const int pin_Fan_IN3 = 9; // L298N IN1 pin
const int pin_Fan_IN4 = 10; // L298N IN2 pin

dht DHT;
LiquidCrystal_I2C lcd(0X27, 16, 2);

int angle = 0;
bool clockwise = true;

unsigned long previousMillis = 0;
const long interval = 5000;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(pin_Servo, OUTPUT);
  pinMode(pin_Flame, INPUT_PULLUP);
  pinMode(pin_Buzzer, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    DHT.read11(pin_DHT);
    lcd.setCursor(0, 0);
    lcd.print("Tempe:");
    lcd.print(int(DHT.temperature));
    lcd.setCursor(0, 1);
    lcd.print("Humi:");
    lcd.print(int(DHT.humidity));
  }

  if (digitalRead(pin_Flame) == LOW) {
    tone(pin_Buzzer, 1000); // phát ra tần số 1000Hz
    
    digitalWrite(pin_Pump_ENA, HIGH); // enable L298N
    digitalWrite(pin_Pump_IN1, HIGH); // turn on motor
    digitalWrite(pin_Pump_IN2, LOW);
    delay(2000); // phát ra âm thanh trong 3 giây
    noTone(pin_Buzzer); // tắt âm thanh

  } else {
    digitalWrite(pin_Pump_ENA, LOW); // disable L298N
    digitalWrite(pin_Pump_IN1, LOW); // turn off motor
    digitalWrite(pin_Pump_IN2, LOW);
  }
  
  if (digitalRead(pin_Gas) == HIGH) {
    tone(pin_Buzzer, 1000); // phát ra tần số 1000Hz
    
    digitalWrite(pin_Fan_ENB, HIGH); // enable L298N
    digitalWrite(pin_Fan_IN3, HIGH); // turn on motor
    digitalWrite(pin_Fan_IN4, LOW);
    delay(2000); // phát ra âm thanh trong 3 giây
    noTone(pin_Buzzer); // tắt âm thanh

  } else {
    digitalWrite(pin_Fan_ENB, LOW); // enable L298N
    digitalWrite(pin_Fan_IN3, LOW); // turn on motor
    digitalWrite(pin_Fan_IN4, LOW);
  }
  

  digitalWrite(pin_Servo, HIGH);
  delayMicroseconds(angle);
  digitalWrite(pin_Servo, LOW);
  delayMicroseconds(20000 - angle);

  if (angle >= 2300) {
    clockwise = false;
  }
  if (angle <= 600) {
    clockwise = true;
  }

  angle += clockwise ? 1 : -1;
}
