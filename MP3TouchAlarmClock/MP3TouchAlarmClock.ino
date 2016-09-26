#include "MP3TAC_TTFT.h"


void setup()
{
// Initial setup

  Serial.begin(115200);
  
  myGLCD.InitLCD();
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 255); 
  //drawButtons();  
  drawBorder();
  drawTime();
}



void loop()
{

  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      
     // updateStr(getButtonNumber());
      myGLCD.setBackColor(255, 0, 0); // Red
      myGLCD.setFont(SmallFont);
      myGLCD.print(String("x:") + x + String("y:") + y, CENTER, 192);
       
     Serial.println(String("x:") + x + String("y:") + y);     
     
    }
  }
}

