//THIS IS SLAVE
#include<SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);

int xval;
int yval;
int m2p1 = 3;
int m2p2 = 4;
int m1p1 = 5;
int m1p2 = 6;

void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(38400);
  pinMode(m1p1,OUTPUT);
  pinMode(m1p2,OUTPUT);  
  pinMode(m2p1,OUTPUT);
  pinMode(m2p2,OUTPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
if (BTSerial.available()>0){
  xval = BTSerial.read();
}
if (BTSerial.available()>0){
  yval = BTSerial.read();
}
  
if (xval > 70 && 30<yval<70){
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,LOW);
  digitalWrite(m2p1,HIGH);
  digitalWrite(m2p2,LOW);
  }

else if(xval < 30 && 30<yval<70){
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,HIGH);
  digitalWrite(m2p1,LOW);
  digitalWrite(m2p2,HIGH);
  }

else if(yval > 70 && 30<xval<70){
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,HIGH);
  digitalWrite(m2p1,HIGH);
  digitalWrite(m2p2,LOW);
  }

else if(yval < 30 && 30<xval<70){
  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2,LOW);
  digitalWrite(m2p1,LOW);
  digitalWrite(m2p2,HIGH);
  }

else{
  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2,LOW);
  digitalWrite(m2p1,LOW);
  digitalWrite(m2p2,LOW);
}
}
