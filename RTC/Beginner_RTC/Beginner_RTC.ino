// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
//#include <LiquidCrystal.h>
#include "RTClib.h"

RTC_DS1307 rtc;
//LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (rs, e, d4, d5, d6, d7)

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int buzz = 11;
int led = 10;

void setup (){
  Serial.begin(9600);
  //lcd.begin(16, 2);
  pinMode(buzz,OUTPUT);
  pinMode(led,OUTPUT);
  
  if (! rtc.begin())
  {
    Serial.print("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning())
  {
    Serial.print("RTC is NOT running!");
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
  //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));// to set the time manualy

}

void loop ()
{
  DateTime now = rtc.now();

  //lcd.setCursor(0, 1);
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second());
  Serial.print("   ");

  //lcd.setCursor(0, 0);
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(" ,");
  Serial.print(now.day());
  Serial.print('/');
  Serial.print(now.month());
  Serial.print('/');
  Serial.print(now.year());
  Serial.println("");

  rtc.setAlarm(18,0,0);
  if(rtc.isAlarmTime()){
    digitalWrite(buzz,HIGH);
    digitalWrite(led,HIGH);
    delay(5000);
    digitalWrite(buzz,LOW);
    digitalWrite(led,LOW);
    }
}
