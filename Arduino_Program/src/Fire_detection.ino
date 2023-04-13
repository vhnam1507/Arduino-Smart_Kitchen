// #define pin_Servo 9

// int angle = 0, sum = 0; //Xác định độ rộng xung
// int clockwise = 1, clockwise_counter = 0;
// int pin_Flame = A0, pin_Gas = A1, pin_Buzzer = 13;


// void setup_Fire_dectection(){
//   pinMode(pin_Servo, OUTPUT);
//   pinMode(pin_Flame, INPUT_PULLUP);
//   pinMode(pin_Buzzer, OUTPUT);
// }

// void Fire_dectection(){
//   if (digitalRead(pin_Flame)==LOW){
//     digitalWrite(pin_Buzzer, HIGH);
//     delay(2000);
//   }

//   if (digitalRead(pin_Gas)==HIGH){
//     digitalWrite(pin_Buzzer, HIGH);
//     delay(2000);
//   }
//   digitalWrite(pin_Buzzer, LOW);
//   digitalWrite(pin_Servo, HIGH);
//   delayMicroseconds(angle);
//   digitalWrite(pin_Servo, LOW);
//   delayMicroseconds(sum);

//   if (angle >= 2300){
//     clockwise = 0;
//     clockwise_counter = 1;
//   }
//   if (angle <= 600){
//     clockwise = 1;
//     clockwise_counter = 0;
//   }

//   if (clockwise == 1)
//     angle++;
//   if (clockwise_counter == 1)
//     angle--;

//   sum = 20000 - angle;  
// }