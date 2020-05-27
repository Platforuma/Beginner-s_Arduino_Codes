#include<LiquidCrystal.h>
LiquidCrystal lcd(10,9,5,4,3,2);

byte first[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01111,
  B01000,
  B01000,
  B01000,
};

byte second[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11110,
  B00010,
  B00010,
  B00010,  
};

byte third[8] = {
  B01000,
  B01000,
  B01000,
  B01111,
  B00000,
  B00000,
  B00000,
  B00000,  
};

byte fourth[8] = {
  B00010,
  B00010,
  B00010,
  B11110,
  B00000,
  B00000,
  B00000,
  B00000,
};


byte horizontalup[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
};

byte horizontaldown[8] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte verticalleft[8] = {
  B00000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B00000,
};

byte verticalright[8] = {
  B00000,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00000,
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);

  lcd.createChar(0,first);
  lcd.createChar(1,second);
  lcd.createChar(2,third);
  lcd.createChar(3,fourth);
  lcd.createChar(4,horizontalup);
  lcd.createChar(5,verticalleft);
  lcd.createChar(6,verticalright);
  lcd.createChar(7,horizontaldown);
  
  lcd.setCursor(4,0);
  lcd.print(char(0));
  for(int i=5; i<=14; i++){
    lcd.setCursor(i,0);  
    lcd.print(char(4));
  }
  lcd.setCursor(15,0);
  lcd.print(char(1));

  lcd.setCursor(4,1);
  lcd.print(char(5));
  lcd.print("WELCOME TO");
  lcd.print(char(6));

  lcd.setCursor(4,2);
  lcd.print(char(5));
  lcd.print("PLATFORUMA");
  lcd.print(char(6));


  lcd.setCursor(4,4);
  lcd.print(char(2));
  for(int i=5; i<=14; i++){
    lcd.setCursor(i,i);  
    lcd.print(char(7));
  }
  lcd.setCursor(15,4);
  lcd.print(char(3));
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j=0;j<=3;j++){
    lcd.scrollDisplayLeft();
    delay(600);
  }
  for(int j=0;j<=7;j++){
    lcd.scrollDisplayRight();
    delay(600);
  }  
  for(int j=0;j<=3;j++){
    lcd.scrollDisplayLeft();
    delay(600);
  }
}
