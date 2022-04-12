#ifndef TIMER_CLASS
#define TIMER_CLASS

     ///////////////////////////////////////////////////////////////////////
    //   timerClass.h   //					David Foricher  -  03/05/04  //
   ///////////////////////////////////////////////////////////////////////
  //   The Timer class provides you an way to determine the exectution //
 // time of a program or one of its functions. (precision : 10ms)	  //
///////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <time.h>

class Timer{

public:
	Timer();
	Timer(const Timer &t);
	~Timer();

	void start();
	void stop();
	void resume();
	bool started() const;
	double getTime();
	clock_t startClockPeriods() const;
	clock_t endClockPeriods() const;
	
	bool operator == (Timer& t);
	bool operator != (Timer& t);
	bool operator < (Timer& t);
	bool operator > (Timer& t);
	bool operator <= (Timer& t);
	bool operator >= (Timer& t);
	Timer& operator = (const Timer& t);

private:
	clock_t startClockPeriodsM;
	clock_t endClockPeriodsM;
	bool startedM;
	
};


#endif


/*============================================================*\

start
-----
- Start the timer.
- If there was one, the last beginning time is overwritten.


stop
----
- Stop the timer.


resume
------
- Resume the timing after a stop().
- If the timer has never been started, it acts like start().


started
-------
- Return true if the timer is on.


getTime
-------
- Return the time elapsed between the start() and the stop().
- If the timer isn't stoped, return the time elapsed between the
  start() and the getTime().

\*============================================================*/