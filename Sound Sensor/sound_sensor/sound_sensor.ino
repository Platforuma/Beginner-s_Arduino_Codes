int soundsensor = 2;
int led = 3;

void setup() {
  // put your setup code here, to run once:
pinMode(soundsensor,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int statusSensor = digitalRead(soundsensor);
if(statusSensor == 1){
  digitalWrite(led,HIGH);
}
else{
  digitalWrite(led,LOW);
}

}
