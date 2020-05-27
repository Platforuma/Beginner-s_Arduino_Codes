int r = 3;
int g = 5;
int b = 6;
int ri,gi,bi;
void setup() {
  // put your setup code here, to run once:
pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(b,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(ri=0;ri<=255;ri++){
analogWrite(r,ri);
analogWrite(g,255-ri);
analogWrite(b,ri/2);
delay(20);
}
for(gi=0;gi<=255;gi++){
analogWrite(r,gi/2);
analogWrite(g,gi);
analogWrite(b,255-gi);
delay(20);
}
for(bi=0;bi<=255;bi++){
analogWrite(r,255-bi);
analogWrite(g,bi/2);
analogWrite(b,bi);
delay(20);
}
}
