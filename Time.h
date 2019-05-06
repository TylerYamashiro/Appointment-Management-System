//Tyler Yamashiro
//Time.h
//The .h file for the Time class
#ifndef TIME_H
#define TIME_H

#include <cctype>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class Time
{
 public:
  Time();
  //Constructor
  Time(int hour, int minute, string apm );
  //parameters are int hours, minutes and string apm
  //PreCondition: Object to be created parameters are passed in
  //PostCondition: Object is created with given parameters
  
  bool setTime(int hour, int minute, string apm);
  //parameters int hours, minutes, and string apm
  //PreConditions: The object is already created
  //PostConditions: Object private members get assigned the new values
  void displayTime() const;
  //PreConditions:Private members have values
  //PostCondition:Prints time to the screen
  bool checkTime(int hour, int minute, string apm);
  //parameters are int hours, minutes, and string apm
  //PreConditions:Object with values for each private member exists
  //PostConditions: returns a true if the inputted parameters match
  //the existing private members else returns false
  int returnTime();
  //Precondition:Object made with values for private data members
  //PostCondition:Returns the time in 24 hour time.

 private:
  int hours;
  int minutes;
  string aopm;//sting containg AM or PM
};
#endif
