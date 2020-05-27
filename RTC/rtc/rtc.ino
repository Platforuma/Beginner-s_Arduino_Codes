#include "Wire.h"
//#include <LiquidCrystal.h>
#define DS1307_ADDRESS 0x68
//LiquidCrystal lcd(8,9,4,5,6,7);

int button_pin = 2;
int buttonState = 0;

byte set_second = 0;
byte set_minute = 16;
byte set_hour = 7;
byte set_day = 7;
byte set_date = 20;
byte set_month = 05;
byte set_year = 18;

byte read_second;
byte read_minute;
byte read_hour;
byte read_day;
byte read_date;
byte read_month;
byte read_year;

byte bcd_to_Dec(byte val)
{
  return( (val/16*10) + (val%16) );
}

byte dec_to_bcd(byte val)
{
  return( (val/10*16) + (val%10) );
}

void setup() {
  Wire.begin();
  pinMode(button_pin, INPUT);
  buttonState = digitalRead(button_pin);

  if (buttonState == HIGH) {
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(0);
  Wire.write(dec_to_bcd(set_second));
  Wire.write(dec_to_bcd(set_minute));
  Wire.write(dec_to_bcd(set_hour));
  Wire.write(dec_to_bcd(set_day));
  Wire.write(dec_to_bcd(set_date));
  Wire.write(dec_to_bcd(set_month));
  Wire.write(dec_to_bcd(set_year));
  Wire.endTransmission();
  } else {}

  //lcd.begin(16,2);
  //lcd.clear();
  Serial.begin(9600);
}

void loop() {
   Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  read_second = bcd_to_Dec(Wire.read());
  read_minute = bcd_to_Dec(Wire.read());
  read_hour = bcd_to_Dec(Wire.read());
  read_day = bcd_to_Dec(Wire.read());
  read_date = bcd_to_Dec(Wire.read());
  read_month = bcd_to_Dec(Wire.read());
  read_year = bcd_to_Dec(Wire.read());
  
  //lcd.clear();
  //lcd.setCursor(0,0);
   if (read_hour<10)
  {
    Serial.print("0”");
  }
  Serial.print(read_hour);
  Serial.print(":");
  if (read_minute<10)
  {
    Serial.print("0");
  }
  Serial.print(read_minute);
  Serial.print(":");
  if (read_second<10)
  {
    Serial.print("0");
  }
  Serial.println(read_second);
  //lcd.setCursor(0,1);
  Serial.print(read_date);
  Serial.print("/");
  Serial.print(read_month);
  Serial.print("/");
  Serial.print(read_year);
   
  delay(1000);
}
