//Tyler Yamashiro
//User.h
//.h file for the User class

#include "AppointmentDiary.h"

#ifndef USER_H
#define USER_H

class User
{
 public:
  User(string userID);
  //constructor accepts a string as for userName private data member
  string returnUsername();
  //PreConditoin: UserName data member has a string
  //PostCondition: Returns the Username 
  bool createAppointment(int hourStart, int minuteStart,string AMorPMStart,
						 int hourEnd, int minuteEnd, string AMorPMEnd,
						 int year, int month, int day, string purpose);
  //Parameters are the ints for hour and minute and string  for AM or Pm
  //for both the start and end times of the appointment also takes the
  //ints for the year and the string for the purpose of the appointment
  //PreCondition:Recieves all the parameters and a AppointmentDiary object
  //exists
  //PostConditio: Sets the start and end times for the appointment, as well
  //as date and purpose.  Creates an Appointment type object and validates the
  //times.  Sees if there are conficts with the other objects in the
  //AppointmentDiary object and prints error message if there are any problems
  //If no problems calls diary.insertAppointment to insert the created
  //appointment
  void deleteAppointment(string date,int hour24Start,int hour24End);
  //Precondition:Parameters are given and a object exists in the diary
  //PostCondition:Calls the diary.deleteAppointment function and passes the
  //parameters into it
  void clearDiary();
  //Preconditon: An Appointment Diary object exists
  //Postcondition: calls the diary.clearDiary function
  bool checkForMatch(string date, int hour24Start, int hour24End);
  //Precondition:An AppointmentDiary object exists
  //PostCondtion: Calls an checkForMatchNO function for the AppointmentDiary
  //object
  void retrievePurpose(string date, int hour24Start, int hour24End);
  //Precondtion:An AppointemntDiary object exists
  //PostCondition: Calls the retrievePurpose function for the AppointmentDiary
  //object
  
  bool replaceAppointment(int hourStart, int minuteStart,string AMorPMStart,
						 int hourEnd, int minuteEnd, string AMorPMEnd,
						  int year, int month, int day, string purpose);
  //Parameters are the ints for hour and minute and string  for AM or Pm
  //for both the start and end times of the appointment also takes the
  //ints for the year and the string for the purpose of the appointment
  //PreCondition:Recieves all the parameters and a AppointmentDiary object
  //exists
  //PostConditio: Sets the start and end times for the appointment, as well
  //as date and purpose.  Creates an Appointment type object and validates the
  //times.
  //Calls diary.insertAppointment to insert the created
  //appointment
  void deleteOldAppointment(string date,int hour24Start,int hour24End);
  //Precondition:Parameters are given and a object exists in the diary
  //PostCondition:Calls the diary.deleteAppointment function and passes the
  //parameters into it
  
 private:
  AppointmentDiary diary;//The AppointmentDiary object
  string userName; //Users username
  
};

#endif
