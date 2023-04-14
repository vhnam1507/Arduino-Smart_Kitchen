const int ledpin=13; 
const int flamepin=A2;
const int buzpin=11;
const int threshold=200;
int flamesensvalue=0; 

void setup() {
    Serial.begin(9600);
    pinMode(ledpin,OUTPUT);
    pinMode(flamepin,INPUT);
    pinMode(buzpin,OUTPUT);
}
void loop() {
    flamesensvalue=analogRead(flamepin); 
    if (flamesensvalue<=threshold) { 
        digitalWrite(ledpin,HIGH); 
        tone(buzpin,100);
        delay(1000); 
    }
    else{
    digitalWrite(ledpin,LOW); 
    noTone(buzpin);
    }
}
