#include "timerClass.h"

#define CLK_TCK 1000
     ///////////////////////////////////////////////////////////////////////
    //   timerClass.cpp   //				David Foricher  -  03/05/04  //
   ///////////////////////////////////////////////////////////////////////
  //   The Timer class provides you an way to determine the exectution //
 // time of a program or one of its functions. (precision : 10ms)	  //
///////////////////////////////////////////////////////////////////////


Timer::Timer():startClockPeriodsM(0),endClockPeriodsM(0),startedM(false){}


Timer::Timer(const Timer &t):startClockPeriodsM(t.startClockPeriods()), endClockPeriodsM(t.endClockPeriods()), startedM(false){}


Timer::~Timer(){}


void Timer::start()
{
	// Record the number of clock ticks since the beginning of the execution
	startClockPeriodsM=clock();
	startedM=true;
}


void Timer::stop()
{
	endClockPeriodsM=clock();
	startedM=false;
}


void Timer::resume()
{
	if(startClockPeriodsM==0) start();
	else startedM=true;
}


bool Timer::started() const{ return startedM; }


clock_t Timer::startClockPeriods() const{ return startClockPeriodsM; }


clock_t Timer::endClockPeriods() const{ return endClockPeriodsM; }



double Timer::getTime(){
	// CLK_TCK is a constant that is equal to the number of clock ticks per second.
	// To have the result in ms, it is just divided by 1000
	if(started()) return (clock()/((long) CLK_TCK/1000)-startClockPeriods()/((long) CLK_TCK/1000));
	else return (endClockPeriods()/((long) CLK_TCK/1000)-startClockPeriods()/((long) CLK_TCK/1000));

}


bool Timer::operator == (Timer& t) {
	return (getTime()==t.getTime());
}

bool Timer::operator != (Timer& t) { return !((*this)==t); }

bool Timer::operator <= (Timer& t) { return getTime()<=t.getTime(); }

bool Timer::operator >= (Timer& t) { return getTime()>=t.getTime(); }

bool Timer::operator < (Timer & t) { return !((*this)>=t); }

bool Timer::operator > (Timer& t) { return !((*this)<=t); }

Timer& Timer::operator = (const Timer& t)
{
	startClockPeriodsM=t.startClockPeriods();
	endClockPeriodsM=t.endClockPeriods();
	return (*this);
}
