int a[] = {9,10,11,12};

int i;

float d = 3;
float s = 3;

void setup() {
  // put your setup code here, to run once:
for(i=0;i<4;i++){
  pinMode(a[i],OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
for(i=0;i<=1000;i++){
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],LOW);  digitalWrite(a[2],LOW);  digitalWrite(a[3],LOW);
  delay(d);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],LOW);  digitalWrite(a[3],LOW);
  delay(d);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],LOW);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],LOW);
  delay(d);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],LOW);  digitalWrite(a[2],LOW);  digitalWrite(a[3],HIGH);
  delay(d);
  }
for(i=0;i<=1000;i++){
  digitalWrite(a[0],LOW);  digitalWrite(a[1],LOW);  digitalWrite(a[2],LOW);  digitalWrite(a[3],HIGH);
  delay(s);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],LOW);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],LOW);
  delay(s);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],LOW);  digitalWrite(a[3],LOW);
  delay(s);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],LOW);  digitalWrite(a[2],LOW);  digitalWrite(a[3],LOW);
  delay(s);
  }
}
