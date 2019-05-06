//Tyler Yamashiro
//Time.cpp
//Purpose: The implementation file for the Time class/
//Input: Takes in integers for hours and minutes and a string for AM or PM
//Processing: Converts time to 24 hour time format.
//Output: Returns the time in a 24 hour format and can also display the time.
#include "Time.h"

Time::Time()
{
  hours = 12;
  minutes = 0;
  aopm = "AM";
}

Time::Time(int hour, int minute, string apm)
{
  hours = hour;
  minutes = minute;
  aopm = apm;
  for(unsigned i = 0 ; i < aopm.length() ; i++)
	aopm[i] = toupper(aopm[i]);
}

bool Time::setTime(int hour, int minute, string apm)
{
  for(unsigned i = 0 ; i < apm.length() ; i++)//converts apm string into upper
	apm[i] = toupper(apm[i]);                //case.

  if(hour < 1 || hour > 12 || minute < 0 || minute > 59){
	return false;
  }
  else if(apm != "AM" && apm !=  "PM"){
	return false;
  }  
  else{
	hours = hour;
	minutes = minute;
	aopm = apm;
	return true;
  }
}

void Time::displayTime() const
{
  if(minutes < 10){
	cout << hours << ":" << "0" << minutes << ' ' << aopm << endl;
  }
  else{
	cout << hours << ":" << minutes << ' ' << aopm << endl; 
  }
}

bool Time::checkTime(int hour, int minute, string apm)
{											   
   for(unsigned i = 0 ; i < apm.length() ; i++)
	apm[i] = toupper(apm[i]);
  return( hours == hour && minutes == minute && aopm == apm);
}
  
int Time::returnTime()//returns time in 24 hour times.
{
  int hour24;
  int returnTime;
  for(unsigned i = 0 ; i < aopm.length() ; i++)
	aopm[i] = toupper(aopm[i]);
  if(aopm == "PM" || aopm == "AM"){
	hour24 = hours + 12;
  }

  hour24 = hour24 * 100;

  returnTime = hour24 + minutes;
  return returnTime;
	
	
}
