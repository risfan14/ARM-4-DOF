#include <Servo.h>

const int VRX1 = A0;  
const int VRY1 = A1;  
const int SW1 = 2;  
const int VRX2 = A2;
const int VRY2 = A3;
const int SW2 = 4;

Servo servo1;      
Servo servo2;  
Servo servo3;      
Servo servo4;


int pServo1 = 90;  
int pServo2 = 90;  
int pServo3 = 90;  

const int AMBANG_BATAS = 25;
const int LANGKAH = 1;          
const int DELAY_SERVO = 10;

void setup() {
  Serial.begin(9600);
  servo1.attach(5);  
  servo2.attach(6);  
  servo3.attach(9);  
  servo4.attach(10);  
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void loop() {
  
  int xV1 = analogRead(VRX1);  
  int yV1 = analogRead(VRY1); 
  int button1 = digitalRead(SW1); 
  
  int xV2 = analogRead(VRX2);  
  int yV2 = analogRead(VRY2); 
  int button2 = digitalRead(SW2); 

 if (abs(yV1 - 512) > AMBANG_BATAS) {
        int targetServo1 = map(yV1, 0, 1023, 0, 180);
        if (targetServo1 > pServo1) pServo1 += LANGKAH;
        if (targetServo1 < pServo1) pServo1 -= LANGKAH;
    }
    if (abs(xV1 - 512) > AMBANG_BATAS) {
        int targetServo2 = map(xV1, 0, 1023, 0, 180);
        if (targetServo2 > pServo2) pServo2 += LANGKAH;
        if (targetServo2 < pServo2) pServo2 -= LANGKAH;
    }
    if (abs(xV2 - 512) > AMBANG_BATAS) {
        int targetServo3 = map(xV2, 0, 1023, 0, 180);
        if (targetServo3 > pServo3) pServo3 += LANGKAH;
        if (targetServo3 < pServo3) pServo3 -= LANGKAH;
    }

    servo1.write(pServo1);
    servo2.write(pServo2);
    servo3.write(pServo3);
    servo4.write(Cakar);
    
//  int s1 = map(yV1, 0, 1023, 0, 180);
//  servo1.write(s1);
////  delay(10);
//
//  int s2 = map(xV1, 0, 1023, 0, 180);
//  servo2.write(s2);
////  Serial.println(s2);
////  delay(10);
//
//  int s3 = map(xV2, 0, 1023, 0, 180);
//  servo3.write(s3);
////  Serial.println(s1);
////  delay(10);


 if (button1 == LOW) {
        servo4.write(30);  
    }
    if (button2 == LOW) {
        servo4.write(0);
    }
    Serial.print("puter: "); Serial.print(pServo1);
    Serial.print(" | siku1: "); Serial.print(pServo2);
    Serial.print(" | siku2: "); Serial.print(pServo3);
    Serial.print(" | Cakar: "); Serial.println("kkkk");


    delay(DELAY_SERVO);
//    delay(10);

}
