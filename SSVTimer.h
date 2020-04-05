#ifndef SSVTimer_h
#define SSVTimer_h

//
// Simple class to simulate timer functionality
// By Serge Skorodinsky, 2017
//


//there are some mess with defines
//#ifndef __AVR__     //#ifndef ESP8266
//typedef std::function<void(void)> timer_callback;  //for arduino, nano and similar
//#else
//typedef void (*timer_callback)();  //for ESP8266
//#endif // __AVR__

typedef void (*timer_callback)();  //seems like good for both

class SSVTimer
{
  public:
    //constructors
    SSVTimer();
    SSVTimer(unsigned long Interval, timer_callback OnTimerFunc);
	// Interval
	void SetInterval(unsigned long Value);
	unsigned long GetInterval();
	// Enabled
	void SetEnabled(bool Value);
	bool GetEnabled();
	//
	void SetOnTimer(timer_callback Value);
	void RefreshIt();
	//
	unsigned long GetCounter();
	void SetRepeatCount(unsigned long Value);
	unsigned long GetRepeatCount();
	void ResetCounter();
  
  protected:
    unsigned long _interval;
	bool _enabled;
    unsigned long _laststart; //when was started last time
    timer_callback _ontimer;
	//
	unsigned long _counter;   // how many times was started since timer was enabled - R/O
	unsigned long _repeatcount; //how many times the timer will be repeated, 0-infinite
};

#endif
// END OF FILE