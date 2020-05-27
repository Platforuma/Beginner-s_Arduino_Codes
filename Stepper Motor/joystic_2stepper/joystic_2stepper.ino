int a[] = {5,4,3,2};
int b[] = {8,9,10,11};
int x = A0;
int y = A1;
int i;
float d = 5;
float s = 5;
int xval;
int yval;

void setup() {
  // put your setup code here, to run once:
for(i=0;i<4;i++){
  pinMode(a[i],OUTPUT);
  pinMode(b[i],OUTPUT);
}
pinMode(x,INPUT);
pinMode(y,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int xval = analogRead(x);
int yval = analogRead(y);

xval = map(xval, 0,1023,1,100);
yval = map(yval, 0,1023,1,100);
Serial.print("xval: ");
Serial.print(xval);
Serial.print("    ");
Serial.print("yval: ");
Serial.println(yval);

if (xval>=40 && xval <= 70 && yval>=40 && yval<=70){
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],HIGH);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],HIGH);
}

else if(xval>=1 && xval <= 35 && yval>=42 && yval<=62){
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],LOW);  digitalWrite(a[2],LOW);  digitalWrite(a[3],LOW);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],HIGH);
  delay(d);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],LOW);  digitalWrite(a[3],LOW);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],HIGH);
  delay(d);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],LOW);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],LOW);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],HIGH);
  delay(d);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],LOW);  digitalWrite(a[2],LOW);  digitalWrite(a[3],HIGH);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],HIGH);
  delay(d);
}

else if(xval>=75 && xval <= 100 && yval>=42 && yval<=62){
  digitalWrite(a[0],LOW);  digitalWrite(a[1],LOW);  digitalWrite(a[2],LOW);  digitalWrite(a[3],HIGH);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],HIGH);
  delay(s);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],LOW);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],LOW);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],HIGH);
  delay(s);
  digitalWrite(a[0],LOW);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],LOW);  digitalWrite(a[3],LOW);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],HIGH);
  delay(s);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],LOW);  digitalWrite(a[2],LOW);  digitalWrite(a[3],LOW);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],HIGH);
  delay(s);
}

else if(xval>=40 && xval <= 70 && yval>=1 && yval<=35){
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],LOW);  digitalWrite(b[2],LOW);  digitalWrite(b[3],LOW);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],HIGH);
  delay(d);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],HIGH);
  digitalWrite(b[0],LOW);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],LOW);  digitalWrite(b[3],LOW);
  delay(d);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],HIGH);
  digitalWrite(b[0],LOW);  digitalWrite(b[1],LOW);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],LOW);
  delay(d);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],HIGH);
  digitalWrite(b[0],LOW);  digitalWrite(b[1],LOW);  digitalWrite(b[2],LOW);  digitalWrite(b[3],HIGH);
  delay(d);
}

else if(xval>=1 && xval <= 35 && yval>=70 && yval<=100){
  digitalWrite(b[0],LOW);  digitalWrite(b[1],LOW);  digitalWrite(b[2],LOW);  digitalWrite(b[3],HIGH);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],HIGH);
  delay(s);
  digitalWrite(b[0],LOW);  digitalWrite(b[1],LOW);  digitalWrite(b[2],HIGH);  digitalWrite(b[3],LOW);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],HIGH);
  delay(s);
  digitalWrite(b[0],LOW);  digitalWrite(b[1],HIGH);  digitalWrite(b[2],LOW);  digitalWrite(b[3],LOW);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],HIGH);
  delay(s);
  digitalWrite(b[0],HIGH);  digitalWrite(b[1],LOW);  digitalWrite(b[2],LOW);  digitalWrite(b[3],LOW);
  digitalWrite(a[0],HIGH);  digitalWrite(a[1],HIGH);  digitalWrite(a[2],HIGH);  digitalWrite(a[3],HIGH);
  delay(s);
}

else{
  Serial.println("Error"); 
}
  }
