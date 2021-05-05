#include <Arduino.h>
//-------БИБЛИОТЕКИ---------
//#include "LowPower.h"
//#include "EEPROMex.h"
#include "LCD_1602_RUS.h"
#include <GyverUART.h>
//-------БИБЛИОТЕКИ---------

LCD_1602_RUS lcd(0x27, 16, 2);            // создать дисплей
// если дисплей не работает, замени 0x27 на 0x3f

uint32_t ms_button = 0;
bool     button_state = false;
bool     button_long_state = false;

void setup() {
  uart.begin(9600); 
   lcd.init();
  lcd.backlight();
  lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(L"Привет, ромашки");
}

void loop(){

 uint32_t ms    = millis();
 if(uart.available()){
  String s=uart.readStringUntil(10);
  lcd.setCursor(0, 1);
  lcd.print(s);
 }

 
 int i=analogRead(A3);
   if( i<1022 && !button_state && ( ms - ms_button ) > 50 ){
      button_state      = true;
      button_long_state = false;  
      ms_button         = ms;
      lcd.setCursor(0, 1);
      lcd.print("    ");
   }
// Фиксируем длинное нажатие кнопки   
   if( i<1022 && !button_long_state && ( ms - ms_button ) > 2000 ){
      button_long_state = true;
      Serial.println("Long press key");
      lcd.setCursor(0, 1);
      lcd.print("LONG");    
   }
// Фиксируем отпускание кнопки   
   if( i>1022 && button_state && ( ms - ms_button ) > 50  ){
      button_state      = false;   
      ms_button         = ms;
      if( !button_long_state ){
        lcd.setCursor(0, 1);
        lcd.print("SHOR");   
      }
   }

}
