int redpin = 11;
int greenpin = 10;
int bluepin = 6;
//s0 GND
//s1 5V
int s2 = 7;
int s3 = 8;
int outpin = 4;

int rcolorStrength;
int gcolorStrength;
int bcolorStrength;

unsigned int pulseWidth;

void setup() {
  Serial.begin(9600);

  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outpin, INPUT);

  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
}

void loop() {

  //to measure red

  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  pulseWidth = pulseIn(outpin, LOW);

  rcolorStrength = pulseWidth / 400. - 1;
  rcolorStrength = (255 - rcolorStrength);


  //to measure green

  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  pulseWidth = pulseIn(outpin, LOW);

  gcolorStrength = pulseWidth / 400. - 1;
  gcolorStrength = (255 - gcolorStrength);



  //to measure blue

  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  pulseWidth = pulseIn(outpin, LOW);

  bcolorStrength = pulseWidth / 400. - 1;
  bcolorStrength = (255 - bcolorStrength);

  //largest reading goes 255
  //smallest reading goes 0
  // middle goes half

  if (rcolorStrength > gcolorStrength && gcolorStrength > bcolorStrength) {
    rcolorStrength = 255;
    gcolorStrength = gcolorStrength / 2.;
    bcolorStrength = 0;
  }


  if (rcolorStrength > bcolorStrength && bcolorStrength > gcolorStrength) {
    rcolorStrength = 255;
    bcolorStrength = bcolorStrength / 2.;
    gcolorStrength = 0;
  }


  if (bcolorStrength > gcolorStrength && gcolorStrength > rcolorStrength) {
    bcolorStrength = 255;
    gcolorStrength = gcolorStrength / 2.;
    rcolorStrength = 0;
  }


  if (bcolorStrength > rcolorStrength && rcolorStrength > gcolorStrength) {
    bcolorStrength = 255;
    rcolorStrength = rcolorStrength / 2.;
    gcolorStrength = 0;
  }


  if (gcolorStrength > rcolorStrength && rcolorStrength > bcolorStrength) {
    gcolorStrength = 255;
    rcolorStrength = rcolorStrength / 2.;
    bcolorStrength = 0;
  }


  if (gcolorStrength > bcolorStrength && bcolorStrength > rcolorStrength) {
    gcolorStrength = 255;
    bcolorStrength = bcolorStrength / 2.;
    rcolorStrength = 0;
  }

  Serial.print(rcolorStrength);
  Serial.print(" , ");

  Serial.print(gcolorStrength);
  Serial.print(" , ");

  Serial.print(bcolorStrength);
  Serial.print(" , ");
  Serial.println("  ");
  

  digitalWrite(redpin, rcolorStrength);
  digitalWrite(greenpin, gcolorStrength);
  digitalWrite(bluepin, bcolorStrength);
  delay (250);

}


