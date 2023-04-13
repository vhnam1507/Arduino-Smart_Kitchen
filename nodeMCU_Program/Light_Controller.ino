#define pin_DS D1
#define pin_SHCP D2 // 
#define pin_STCP D3

#define pin_Sw1 D5
#define pin_Sw2 D6
#define pin_Sw3 D7

byte leds_Pos = 0B00000000;

int status_Led1 = 0;
int status_Led2 = 0;
int status_Led3 = 0;

int previous_Status_Sw1 = 0;
int previous_Status_Sw2 = 0;
int previous_Status_Sw3 = 0;

void updateShiftRegister(byte led) {
    digitalWrite(pin_STCP, LOW);
    shiftOut(pin_DS, pin_SHCP, MSBFIRST, led);
    digitalWrite(pin_STCP, HIGH);
}

void setup() {
    pinMode(pin_Sw1, INPUT_PULLUP);
    pinMode(pin_Sw2, INPUT_PULLUP);
    pinMode(pin_Sw3, INPUT_PULLUP);
    pinMode(pin_STCP, OUTPUT);
    pinMode(pin_SHCP, OUTPUT);
    pinMode(pin_DS, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    //Thao tác nút nhấn 1 - led 1
    int status_Sw1 = digitalRead(pin_Sw1);

    if (status_Sw1 != previous_Status_Sw1) { // Nếu trạng thái nút bấm đã thay đổi
        delay(50); // Chờ đợi thời gian debounce
        if (status_Sw1 == 1) { // Nếu nút bấm được nhấn
            status_Led1 = !status_Led1; // Chuyển đổi trạng thái đèn LED
            if (status_Led1 == 1)
                leds_Pos = leds_Pos + 0B00000001; // Cập nhật giá trị độ sáng
            else
                leds_Pos = leds_Pos - 0B00000001;
            updateShiftRegister(leds_Pos); // Cập nhật đầu ra trên IC 74HC595
        }
    }
    previous_Status_Sw1 = status_Sw1; // Lưu trạng thái nút bấm để sử dụng trong vòng lặp tiếp theo

    //Thao tác nút nhấn 2 - led 2
    int status_Sw2 = digitalRead(pin_Sw2);

    if (status_Sw2 != previous_Status_Sw2) { // Nếu trạng thái nút bấm đã thay đổi
            delay(50); // Chờ đợi thời gian debounce
            if (status_Sw2 == 1) { // Nếu nút bấm được nhấn
                status_Led2 = !status_Led2; // Chuyển đổi trạng thái đèn LED
                if (status_Led2 == 1)
                    leds_Pos = leds_Pos + 0B00000010; // Cập nhật giá trị độ sáng
                else
                    leds_Pos = leds_Pos - 0B00000010;
                updateShiftRegister(leds_Pos); // Cập nhật đầu ra trên IC 74HC595
                }
        }
    previous_Status_Sw2 = status_Sw2; // Lưu trạng thái nút bấm để sử dụng trong vòng lặp tiếp theo

    //Thao tác nút nhấn 3 - led 3
    int status_Sw3 = digitalRead(pin_Sw3);

    if (status_Sw3 != previous_Status_Sw3) { // Nếu trạng thái nút bấm đã thay đổi
            delay(50); // Chờ đợi thời gian debounce
            if (status_Sw3 == 1) { // Nếu nút bấm được nhấn
            status_Led3 =!status_Led3; // Chuyển đổi trạng thái đèn LED
                if (status_Led3 == 1)
                    leds_Pos = leds_Pos + 0B00000100; // Cập nhật giá trị độ sáng
                else
                    leds_Pos = leds_Pos - 0B00000100;
                updateShiftRegister(leds_Pos); // Cập nhật đầu ra trên IC 74HC595
                }
        }
    previous_Status_Sw3 = status_Sw3; // Lưu trạng thái nút bấm để sử dụng trong vòng lặp tiếp theo

    Serial.print("Sw1: ");
    Serial.println(leds_Pos);
}
