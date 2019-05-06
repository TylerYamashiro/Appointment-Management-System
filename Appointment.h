//Tyler Yamashiro
//Appointment.h
//The .h file for the Appointment class

#include <iostream>
#include "Date.h"
#include "Time.h"
using namespace std;

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

class Appointment
{
 public:
  Appointment();
  //constructor
  bool setStartTime(int hourStart, int minuteStart,string AMoPMStart);
  //Parameters ints for hour,time and a string for AM or PM
  //PreCondition:A Time object exists as a private member
  //PostCondition:The Private member of the Time objects values are set
  bool setEndTime(int hourStart, int minuteStart,string AMoPMEnd);
  //Parameters ints for hour,time and a string for AM or PM
  //PreCondition:A Time object exists as a private member
  //PostCondition:The Private member of the Time objects values are set
  void setPurpose(string purp);
  //Parameters a string for the purpose
  //Precondition: private member purpose exists
  //Postcondition: Assings the private member purpose a string
  bool setDate(int year, int month, int day);
  //Parameters ints for year, month, and day
  //PreConditoin: a Date object exists
  //PostCondition: Date object gets assigned values for members of its private
  //class returns true if successfull and false if not 
  void getPurpose() const;
  //PreCondition: Purpose exists
  //PostCondition:Prints Purpose to the screen
  int returnStartTime();
  //PreCondition:Time object has values
  //PostConditio:Returns the time values in 24 hour time
  int returnEndTime();
  //PreCondition:Time object has values
  //PostConditio:Returns the time values in 24 hour time
  string returnDate();
  //Returns the string that is the date
 private:
  string purpose;
  Time timeStart;//Time object that holds the start time
  Time timeEnd;//Time obhject that holds the end time
  Date appDate;//Date object that holds the date
};

#endif
