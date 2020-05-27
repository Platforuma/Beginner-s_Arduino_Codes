#include<LiquidCrystal.h>
LiquidCrystal lcd(10,9,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("I/P Serial Data");  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Enter something: ");
  while(Serial.available()==0){}
  String a = Serial.readString();
  Serial.println(a);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You Entered: ");
  lcd.setCursor(0,1);
  lcd.print(a);
}
