
#include <LiquidCrystal.h>
#include<Wire.h>

#include "RTClib.h"

RTC_DS1307 RTC;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(20, 4);
  lcd.print("---Simple  Clock----");



  Wire.begin();

  RTC.begin();

  if (! RTC.isrunning())

  {
    RTC.adjust(DateTime(__DATE__, __TIME__));

  }




}

void loop() {

  DateTime now = RTC.now();
  lcd.setCursor(0, 1);
  lcd.print("     ");
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);
  lcd.setCursor(0, 2);
  lcd.print("      ");
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);
  delay(1000);
}
