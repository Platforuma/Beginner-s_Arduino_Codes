//THIS IS MASTER
#include<SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);

int xjoy = A0;
int yjoy = A1;
int xval;
int yval;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(38400);
  pinMode(xjoy,INPUT);
  pinMode(yjoy,INPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  xval = analogRead(xjoy);
  xval = map(xval,0,1023,0,100);
  yval = analogRead(yjoy);
  yval = map(yval,0,1023,0,100);
  BTSerial.write(xval);  
  BTSerial.write(yval);
  }
