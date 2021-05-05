#include <Arduino.h>
//-------БИБЛИОТЕКИ---------
//#include "LowPower.h"
//#include "EEPROMex.h"
#include "LCD_1602_RUS.h"
//-------БИБЛИОТЕКИ---------

LCD_1602_RUS lcd(0x27, 16, 2);            // создать дисплей
// если дисплей не работает, замени 0x27 на 0x3f

void setup() {
  Serial.begin(9600); 
   lcd.init();
  lcd.backlight();
  lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(L"Привет, ромашки");


}
void loop(){
 int i=analogRead(A3);
 lcd.setCursor(0, 1);
 if (i>1022){
 lcd.print("OFF");
 }else{
  lcd.print("ON "); 
 }
 delay(10);
}

/*


*/