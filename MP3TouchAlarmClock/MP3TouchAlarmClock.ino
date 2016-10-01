#include "MP3TAC_RTC.h"  // Including RTC DS1307 (Real Time Clock) functions.
#include "MP3TAC_TTFT.h" // Including Touth TFT functions.


#define esp8266 Serial3 // Connect to Internet with an ESP8266 E12 board.


void setup()
{
// Initial setup

  Serial.begin(115200);
  Serial3.begin(115200);
  
  
  myGLCD.InitLCD();
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 255);
  //drawButtons();  
  drawBorder();
  rtctime=getTime();
  Serial.print("rtctime.Hour: ");
  Serial.print(rtctime.Hour);
  drawTime();
}




void loop()
{


// Reading from esp8266 and printing on Serial
if(esp8266.available()){
   Serial.print(char(Serial3.read()));
   //myGLCD.setFont(SmallFont);
   //myGLCD.setColor(255, 0, 0);
   //myGLCD.print(char(Serial3.read()), LEFT, 192);  
}



// Printing on Screen the touching position.

    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      
     // updateStr(getButtonNumber());
       myGLCD.setFont(SmallFont);
      myGLCD.print(String("x:") + x + String("y:") + y, CENTER, 192);
       
     Serial.println(String("x:") + x + String("y:") + y);     
     
    }
  
}




