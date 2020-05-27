#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Address,EN,RW , RS, D4,D5,D6,D7,BackLight,BL_Polarity
LiquidCrystal_I2C lcd2(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd2.begin(16, 2);
}

void loop() {
  for (int i = 1; i <= 10; i++) {
    lcd2.clear();
    lcd2.setCursor(0, 0);
    lcd2.print("   Platforuma");
    lcd2.setCursor(0, 1);
    lcd2.print("Counter: ");
    lcd2.print(i);
    delay(500);
  }
}

