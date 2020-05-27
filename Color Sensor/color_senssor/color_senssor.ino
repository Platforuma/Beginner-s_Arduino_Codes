int S0=4;
int S1=5;
int S2=6;
int S3=7;
int sensorOut=8;

int r = 9;
int g = 10;
int b = 11;

float pulsewidth;
float rfrequency;
float gfrequency;
float bfrequency;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  rfrequency = pulseIn(sensorOut, LOW);
  Serial.print("R= ");//printing name
  Serial.print(rfrequency);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  gfrequency = pulseIn(sensorOut, LOW);
  Serial.print("G= ");//printing name
  Serial.print(gfrequency);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  bfrequency = pulseIn(sensorOut, LOW);
  Serial.print("B= ");//printing name
  Serial.print(bfrequency);//printing RED color frequency
  Serial.println("  ");
  delay(100);


  if(gfrequency > rfrequency && gfrequency > bfrequency){
    analogWrite(r,255);
    analogWrite(g,0);
    analogWrite(b,0);
  }

  else if(rfrequency > gfrequency && rfrequency > bfrequency){
    analogWrite(r,0);
    analogWrite(g,0);
    analogWrite(b,255);
  }
  
  else{
    analogWrite(r,0);
    analogWrite(g,255);
    analogWrite(b,0);
  }
}
