#include<Servo.h>
Servo arm;
Servo arm2;

int xjoy = A0;
int yjoy = A1;
int val;

void setup() {
  // put your setup code here, to run once:
arm.attach(9);
arm2.attach(10);
pinMode(xjoy,INPUT);
pinMode(yjoy,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(xjoy);
val = map(val,0,1023,0,180);
arm.write(val);
delay(25);

val = analogRead(yjoy);
val = map(val,0,1023,0,180);
arm2.write(val);
delay(25);

}
