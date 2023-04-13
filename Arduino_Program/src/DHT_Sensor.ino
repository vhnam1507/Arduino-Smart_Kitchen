// #include "dht.h"
// #define dht_apin A0

// #include <Wire.h> 
// #include <LiquidCrystal_I2C.h>

// dht DHT;
// LiquidCrystal_I2C lcd(0X27,16,2); //SCL A5 SDA A4

// // void setup()
// {
//     Serial.begin(9600);
//     lcd.init();                    
//     lcd.backlight(); 
// }

// void loop()
// {
//     DHT.read11(dht_apin);

//     Serial.print("Humidity: ");
//     Serial.println(int(DHT.humidity));
//     Serial.print("Temperature: ");
//     Serial.println(int(DHT.temperature));

//     lcd.setCursor(0,0);
//     lcd.print("Tempe:");
//     lcd.setCursor(6,0);
//     lcd.print(int(DHT.temperature));
//     lcd.setCursor(0,1);
//     lcd.print("Humi:");
//     lcd.setCursor(5,1);
//     lcd.print(int(DHT.humidity));

//     delay (10000);
//   }