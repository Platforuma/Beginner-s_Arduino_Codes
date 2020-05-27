int relay1 = 8;
int relay2 = 9;
int relay3 = 10;
int relay4 = 11;
int i;
int d = 64.5;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 1; i <= 10000; i++) {
    Serial.println(i);
    digitalWrite(relay1, HIGH);
    digitalWrite(led1,HIGH);
    delay(d);
    digitalWrite(relay1, LOW);
    digitalWrite(led1,LOW);
    delay(d);
    digitalWrite(relay2, HIGH);
    digitalWrite(led2,HIGH);
    delay(d);
    digitalWrite(relay2, LOW);
    digitalWrite(led2,LOW);
    delay(d);
    digitalWrite(relay3, HIGH);
    digitalWrite(led3,HIGH);
    delay(d);
    digitalWrite(relay3, LOW);
    digitalWrite(led3,LOW);
    delay(d);
    digitalWrite(relay4, HIGH);
    digitalWrite(led4,HIGH);
    delay(d);
    digitalWrite(relay4, LOW);
    digitalWrite(led4,LOW);
    delay(d);
  }
}
