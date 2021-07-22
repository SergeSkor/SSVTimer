#include <SSVTimer.h>
SSVTimer Tmr1; 

#define onboard_led 2 //onboard LED

void setup() 
{
  Serial.begin(115200);
  pinMode(onboard_led, OUTPUT);

  Tmr1.SetEnabled(true); //enable timer
  Tmr1.SetInterval(1000); //every xxx mS
  Tmr1.SetOnTimer(Tmr1Function); //assign timer function
}

void loop() 
{
  Tmr1.RefreshIt();  //run timer's internal logic
}

void Tmr1Function()
{
  Serial.print(millis()); Serial.println("mS -> Tmr1 Event");
  digitalWrite( onboard_led, !digitalRead(onboard_led) ); //invert onboard LED
}
