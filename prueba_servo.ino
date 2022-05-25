#include <Servo.h>
Servo servo1, servo2, servo3, servo4;
int ang=0;
void setup() {
  servo2.attach(11);
  Serial.begin(9600);
  servo2.write(ang);
}

void loop() {
  // put your main code here, to run repeatedly:
servo2.write(90);
delay(2000);
servo2.write(180);
delay(2000);
}
