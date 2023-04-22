
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

String S="Xin Chao Cac Ban"; //the string to print on the LCD

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 
}

void loop() {
  lcd.setCursor(0,1);
  hienthichuoi(0,0,S);

 }

void hienthichuoi(int cot, int dong, String chuoi)
{
  lcd.setCursor(cot,dong);
  for(int j=0;j<chuoi.length();j++)
    {
      lcd.print(chuoi[j]);
    } 
}
