////Tyler Yamashiro
//Appointment.cpp
//Purpose: Implementation file of the Appointment class
//Input:Parameters int for hours int for minutes and string for AM or PM
#include "Appointment.h"

Appointment::Appointment()
{
  timeStart;
  timeEnd;
  appDate;
}


bool Appointment::setStartTime(int hourStart, int minuteStart,
							   string AMoPMStart)
{
  bool valid = true;             //Sets time and returns true if successful
                                 //and false if not successful
  valid = timeStart.setTime(hourStart, minuteStart, AMoPMStart);
  if(valid){
	return true;
  }
  else{
	return false;
  }
}


bool Appointment::setEndTime(int hourEnd, int minuteEnd, string AMorPMEnd)
{
  bool valid = true; //Sets time and returns true if successful and false if 
                     //if not successful
  valid = timeEnd.setTime(hourEnd, minuteEnd, AMorPMEnd);
  if(valid){
	return true;
  }
  else{
	return false;
  }
}

void Appointment::setPurpose(string purp)
{
  purpose = purp;
}

void Appointment::getPurpose()const
{
  cout <<"The purpose of the appointment is: " <<  purpose << endl;
}

bool Appointment::setDate(int year,int month,int day)//Sets date and 
{                                                    //returns bool based on
  return(appDate.setDate(year, month, day));        //success
}

string Appointment::returnDate()//calls return date function for Date object
{
 return  appDate.returnDate();
}

int Appointment::returnStartTime()//calls return time function for Time object
{
  return timeStart.returnTime();
}

int Appointment::returnEndTime()//calls return time function for Time object
{
  return timeEnd.returnTime();
}

