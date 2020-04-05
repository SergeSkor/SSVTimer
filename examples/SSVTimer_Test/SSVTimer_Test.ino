#include <SSVTimer.h>

void repeatMe1();

SSVTimer timer1(100, repeatMe1);
SSVTimer timer2;

void setup() 
{
  Serial.begin(115200);
  //
  timer1.SetRepeatCount(30);
  //
  timer2.SetInterval(1000);
  timer2.SetOnTimer(repeatMe2);
}

void loop() 
{
  timer1.RefreshIt();
  timer2.RefreshIt();

  if (millis() >=  10000) {timer1.SetInterval(2000); }
  if ( (millis() >=  20000) && (millis() <  50000) ) {timer1.SetEnabled(false); timer1.SetRepeatCount(0); }
  if (millis() >=  50000) {timer1.SetEnabled(true); }

}

void repeatMe1() 
{
Serial.print("timer#1: "); Serial.print(timer1.GetCounter() ); Serial.print(" "); Serial.print(timer1.GetRepeatCount() ); Serial.print(" "); Serial.println(millis() );
}

void repeatMe2() 
{
Serial.print("              timer#2: "); Serial.print(timer2.GetCounter() ); Serial.print(" "); Serial.println(millis() );
}

