int ir = 9;
int led = 10;

int state;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ir,INPUT);
pinMode(led,OUTPUT);
state =0;
}

void loop() {
  // put your main code here, to run repeatedly:
state = digitalRead(ir);
if(state == HIGH){
  Serial.println("Clear");
  digitalWrite(led,LOW);
}
else{
  Serial.println("Block");
  digitalWrite(led,HIGH);
}
}
