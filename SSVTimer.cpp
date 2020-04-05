//
// Simple class to simulate timer functionality
// By Serge Skorodinsky, 2017
//

#include "SSVTimer.h"
#include <Arduino.h> 

SSVTimer::SSVTimer()
{
  _interval = 1000;
  _enabled = true;
  _laststart = millis();
  _ontimer=NULL;
  _counter = 0;   
  _repeatcount = 0;
}

SSVTimer::SSVTimer(unsigned long Interval, timer_callback OnTimerFunc)
{
  _interval = Interval;
  _enabled = true;
  _laststart = millis();
  _ontimer=OnTimerFunc;  
  _counter = 0;   
  _repeatcount = 0;
}

void SSVTimer::SetInterval(unsigned long Value)
{
  if (_interval != Value)
    {
    _interval = Value;
	_laststart = millis();
	_counter = 0;
	}	
}

unsigned long SSVTimer::GetInterval()
{
	return _interval;
}

void SSVTimer::SetEnabled(bool Value)
{
  if (_enabled != Value)
    {
    _enabled = Value;
	if (Value)
	  {
      _counter = 0;
      _laststart = millis();
	  }
    }
}

bool SSVTimer::GetEnabled()
{
	return _enabled;
}

void SSVTimer::SetOnTimer(timer_callback Value)
{
  _ontimer=Value;
}

void SSVTimer::RefreshIt()
{
unsigned long NowIs, EstimTime;
if ( (_enabled) && (_ontimer != NULL) )
  {
  NowIs = millis();	
  EstimTime = _laststart + _interval;
  if (NowIs >= EstimTime)
    {
	_laststart = NowIs; 
    _counter++;	
	_ontimer(); //run callback, may take long
	if ( (_repeatcount > 0) && (_counter >= _repeatcount) ) {SetEnabled(false);}
    }
  }
}
  
unsigned long SSVTimer::GetCounter()
{
	return _counter;
}

void SSVTimer::ResetCounter()
{
	_counter = 0;
}

void SSVTimer::SetRepeatCount(unsigned long Value)
{
if (_repeatcount != Value)
  {
  _repeatcount = Value;
  if ( (_repeatcount > 0) && (_counter >= _repeatcount) ) {SetEnabled(false);}
  }
}

unsigned long SSVTimer::GetRepeatCount()
{
	return _repeatcount;
}


// END OF FILE   `