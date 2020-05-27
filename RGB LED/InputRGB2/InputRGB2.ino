int r = 3;
int g = 5;
int b = 6;
int ri, gi, bi;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  Serial.print("Red Intensity: ");
  while (Serial.available() == 0) {}
  ri = Serial.parseInt();
  Serial.println(ri);
  
  Serial.print("Green Intensity: ");
  while (Serial.available() == 0) {}
  gi = Serial.parseInt();
  Serial.println(gi);
 
  Serial.print("Blue Intensity: ");
  while (Serial.available() == 0) {}
  bi = Serial.parseInt();
  Serial.println(bi);

  analogWrite(r,ri);
  analogWrite(g,gi);
  analogWrite(b,bi);  

  Serial.println("");
  }

