#include "dht.h"
#include<SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

SoftwareSerial mySerial(2,3); //TX - RX

const int pin_Gas = A0; // Analog pin for gas sensor
const int pin_Flame = A1; // Analog pin for flame sensor
const int pin_DHT = A2; // Analog pin for DHT sensor     
const int pin_Servo = 11; // Digital pin for servo motor
const int pin_Buzzer = 4; // Digital pin for buzzer

const int pin_Pump_ENA = 5; // L298N enable pin for pump motor
const int pin_Pump_IN1 = 6; // L298N IN1 pin for pump motor
const int pin_Pump_IN2 = 7; // L298N IN2 pin for pump motor

const int pin_Fan_ENB = 8; // L298N enable pin for fan motor
const int pin_Fan_IN3 = 9; // L298N IN1 pin for fan motor
const int pin_Fan_IN4 = 10; // L298N IN2 pin for fan motor

dht DHT; // an instance of the DHT sensor library
LiquidCrystal_I2C lcd(0X27, 16, 2); //an instance of the LiquidCrystal_I2C library, specifying the I2C address and dimensions of the LCD

int angle = 0; // Initialize the angle of the servo motor to 0 and 
bool clockwise = true; //set the initial direction to clockwise

unsigned long previousMillis = 0; // a variable to store the previous time in milliseconds
const long interval = 5000; //a constant to specify the interval for taking sensor readings

void setup() {
 
Serial.begin(9600); // Initialize serial communication
mySerial.begin(9600); // Initialize serial communication for sending data to a module
lcd.init(); // Initialize LCD display
lcd.backlight();
pinMode(pin_Servo, OUTPUT); // Set servo pin as output
pinMode(pin_Flame, INPUT_PULLUP); // Set flame pin as input with internal pull-up resistor enabled
pinMode(pin_Buzzer, OUTPUT); // Set buzzer pin as output
}

void loop() {
// Read temperature and humidity data from DHT11 sensor and display on LCD every specified interval
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
  previousMillis = currentMillis;

  DHT.read11(pin_DHT); // Read temperature and humidity data11
  lcd.setCursor(0, 0);  // Display temperature on LCD screen
  lcd.print("Tempe:");
  lcd.print(int(DHT.temperature));

  // Send temperature data to connected device via serial communication
  mySerial.print("TEMP:");
  mySerial.println(DHT.temperature);

  // Display humidity on LCD screen
  lcd.setCursor(0, 1);
  lcd.print("Humi:");
  lcd.print(int(DHT.humidity));

  // Send humidity data to connected device via serial communication
  Serial.print(DHT.humidity);
  mySerial.print("HUMI:");
  mySerial.println(DHT.humidity);
  }

  if (digitalRead(pin_Flame) == LOW) {
    mySerial.print("FLAME:");
    mySerial.println(1);
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

    mySerial.print("FLAME:");
    mySerial.println(0);
  }
  
  if (digitalRead(pin_Gas) == HIGH) {
    mySerial.print("GAS:");
    mySerial.println(1);
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

    mySerial.print("GAS:");
    mySerial.println(0);
  }
  

  digitalWrite(pin_Servo, HIGH);
  delayMicroseconds(angle);
  digitalWrite(pin_Servo, LOW);
  delayMicroseconds(20000 - angle);

  if (angle >= 2300) { //Change the direction of rotation when the angle reaches 2300
    clockwise = false;
  }
  if (angle <= 600) { //Change the direction of rotation when the angle reaches 600
    clockwise = true;   
  }

  angle += clockwise ? 1 : -1; //angle variable is increased by 1 if clockwise is true, or decreased by 1 if clockwise is false
  }
