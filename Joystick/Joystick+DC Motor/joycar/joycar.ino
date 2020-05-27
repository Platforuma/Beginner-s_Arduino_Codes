int xjoy = A0;
int yjoy = A1;
int xval;
int yval;
int m1p1 = 8;
int m1p2 = 9;
int m2p1 = 10;
int m2p2 = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xjoy, INPUT);
  pinMode(yjoy, INPUT);
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  xval = analogRead(xjoy);
  xval = map(xval, 0,684,0,100);  
  yval = analogRead(yjoy);
  yval = map(yval, 0,684,0,100);
  Serial.print(xval);
  Serial.print("  ");
  Serial.println(yval);
  if(xval>70 && 30<yval<70){
    digitalWrite(m1p1,HIGH);
    digitalWrite(m1p2,LOW);
    digitalWrite(m2p1,HIGH);
    digitalWrite(m2p2,LOW);  
  }
  else if(xval<40 && 30<yval<70){
    digitalWrite(m1p1,LOW);
    digitalWrite(m1p2,HIGH);
    digitalWrite(m2p1,LOW);
    digitalWrite(m2p2,HIGH);
  }
  else if(yval>70 && 30<xval<70){
    digitalWrite(m1p1,HIGH);
    digitalWrite(m1p2,LOW);
    digitalWrite(m2p1,LOW);
    digitalWrite(m2p2,HIGH);

  }
  else if(yval<40 && 30<xval<70){
    digitalWrite(m1p1,LOW);
    digitalWrite(m1p2,HIGH);
    digitalWrite(m2p1,HIGH);
    digitalWrite(m2p2,LOW);  
  }
  else{
    digitalWrite(m1p1,LOW);
    digitalWrite(m1p2,LOW);
    digitalWrite(m2p1,LOW);
    digitalWrite(m2p2,LOW);  
  }}
/*  val = analogRead(yjoy);
  val = map(val, 0,684,0,100);
  delay(100);
}*/
     
