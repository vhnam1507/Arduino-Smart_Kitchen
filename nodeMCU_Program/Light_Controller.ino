// #include <ESP8266WiFi.h>

// const byte PIN_DS = D1;
// const byte PIN_SHCP = D2;
// const byte PIN_STCP = D3;

// const byte PIN_SW[] = {D5, D6, D7};
// const byte PIN_LED[] = {0B00000001, 0B00000010, 0B00000100};

// byte leds_Pos = 0B00000000;
// byte status_Led[3] = {0, 0, 0};
// byte previous_Status_Sw[3] = {HIGH, HIGH, HIGH};

// void updateShiftRegister(byte led) {
//     digitalWrite(PIN_STCP, LOW);
//     shiftOut(PIN_DS, PIN_SHCP, MSBFIRST, led);
//     digitalWrite(PIN_STCP, HIGH);
// }

// void setup() {
//     pinMode(PIN_SW[0], INPUT_PULLUP);
//     pinMode(PIN_SW[1], INPUT_PULLUP);
//     pinMode(PIN_SW[2], INPUT_PULLUP);
//     pinMode(PIN_STCP, OUTPUT);
//     pinMode(PIN_SHCP, OUTPUT);
//     pinMode(PIN_DS, OUTPUT);
//     Serial.begin(9600);
// }

// void loop() {
//     for (byte i = 0; i < 3; i++) {
//         byte status_Sw = digitalRead(PIN_SW[i]);

//         if (status_Sw != previous_Status_Sw[i]) {
//             delay(50);
//             if (status_Sw == LOW) {
//                 status_Led[i] = !status_Led[i];
//                 bitWrite(leds_Pos, i, status_Led[i]);
//                 updateShiftRegister(leds_Pos);
//             }
//         }
//         previous_Status_Sw[i] = status_Sw;
//     }

//     Serial.print("Led status: ");
//     Serial.println(leds_Pos, BIN);
// }
