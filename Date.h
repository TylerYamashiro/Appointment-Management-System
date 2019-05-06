//Tyler Yamashiro
//Date.h

#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
 public:
  Date();
  //Constructor
  Date( int yr, int mon, int d);
  //Parameters are ints for year, month, and date
  //PreCondition: Object to be created with parameters
  //Postcondition: Object is created with the parameters passed in
  bool setDate(int yr, int mon, int d);
  //Parameters are int for year, month, and date
  //PreCondition: Object exists
  //PostCondition: Objects private members are replaced with parameter values
  void displayDate() const;
  //PreCondition:Private members have values
  //PostCondition: Date is printed to the screen
  string findSeason();
  //Returns the season based ont he date
  bool checkDate(string date);
  //Parameter is a string that is the date
  //PreCondition: There is a date to be tested against date of the object
  //PostCondition:Returns true if parameter matches date in object
  //else returns false
  string convertMonth();
  //PreCondition: Month value exists
  //PostCondition: Returns a string that represents the month
  string returnDate();
  //PreCondition:Private data members have values
  //PostCondition: Converts the date to YYYY-MM-DD format and returns it.

 private:
  int year;
  int month;
  int day;
  string dateComp;//string for the return date
  string season;
};
#endif
