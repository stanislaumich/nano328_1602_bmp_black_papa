#include <Arduino.h>


//#define sm 7
#define pinbeep 2
//--------------------BEEP---------------------------
void beep(int t1,int t2){
  #ifdef pinbeep
   unsigned long h;
   h=millis();
   while (millis()-h<(unsigned int)(t1)){
    digitalWrite(pinbeep,HIGH);
    delayMicroseconds(t2);
    digitalWrite(pinbeep,LOW);
    delayMicroseconds(t2);
   }
   digitalWrite(pinbeep,LOW);
  #endif
 }
void shortbeep(void){
  beep(125,150);
 }
void longbeep(void){
  beep(250,250);
 }
void dshortbeep(void){
  shortbeep();
  delay(50);
  shortbeep(); 
 } 
 void initBeep(void)
 {
  //pinMode(sm,OUTPUT);
  pinMode(pinbeep,OUTPUT);
  //digitalWrite(sm,LOW); 
  digitalWrite(pinbeep,LOW);
 }
//-----------------------------------------------------------