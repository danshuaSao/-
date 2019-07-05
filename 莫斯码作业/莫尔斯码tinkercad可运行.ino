#include "Arduino.h"
#ifndef _MORSE_H
#define _MORSE_H
#define do  morse.dot();
#define da  morse.dash();

class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};
#endif /*_MORSE_H*/


Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(250);
	digitalWrite(_pin,LOW);
	delay(250);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(1000);
	digitalWrite(_pin,LOW);
	delay(250);
}




Morse morse(13);
 
void setup()
{
   Serial.begin(9600);
}

char ch=' ';
String out=" ";
 
void loop(){
    if(Serial.available()>0){
      ch = Serial.read(); 
      }else{
        Serial.print(out);
        
        } 
      switch(ch){
        case 'a':out += "*-"; do;da;break; 
        case 'b':out += "-***";da;do;do;do;break;
        case 'c':out += "-*-*";da;do;da;do;break;
        case 'd':out += "-**";da;do;do;break;
        case 'e':out += "*";do;break;
        case 'f':out += "**-*";do;do;da;do;break;
        case 'g':out += "--*";da;da;do;break;
        case 'h':out += "****";do;do;do;do;break;
        case 'i':out += "**";do;do;break;
        case 'j':out += "*---";do;da;da;da;break;
        case 'k':out += "-*-";da;do;da;break;
        case 'l':out += "*-**";do;da;do;do;break;
        case 'm':out += "--";da;da;break;
        case 'n':out += "-*";da;do;break;
        case 'o':out += "---";da;da;da;break;
        case 'p':out += "*--*";do;da;da;do;break;
        case 'q':out += "--*-";da;da;do;da;break;
        case 'r':out += "*-*";do;da;do;break;
        case 's':out += "***";do;do;do;break;
        case 't':out += "-";da;break;
        case 'u':out += "**-";do;do;da;break;
        case 'w':out += "*--";do;da;da;break;
        case 'x':out += "-**-";da;do;do;da;break;
        case 'y':out += "-*--";da;do;da;da;break;
        case 'z':out += "--**";da;da;do;do;break;
        case ' ':out += "/";break;
        case '\n':out+= "/";break;
      } 

  delay(3000);
}
