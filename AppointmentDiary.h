//Tyler Yamashiro
//AppointmentDiary.h
//.h file for the AppointmentDiary class

#include "Appointment.h"
#include <vector>

#ifndef APPOINTMENTDIARY_H
#define APPOINTMENTDIARY_H

class AppointmentDiary
{
 public:
  AppointmentDiary();
  //constructor
  void insertAppointment(Appointment a1);
  //Parameter is an appointment object
  //Precondition:An appointment Diary object exists and an appointment object
  //PostCondition:Appointment gets pushed into the vector in the private
  //section
  void deleteAppointment(string date, int hour24Start, int hour24End);
  //Parameters are a string for the date and a start and end time in 24 hour
  //format
  //Precondition: Appointment diary exists
  //Postcondition:The Appointment that matches the parameters is deleted. 
  void clearDiary();
  //Precondition: a vector exists
  //PostCondition:removes all objects in the vector
  bool checkForMatch(Appointment a1);
  //Precondition: Appointments exists in the vector
  //PostCondition: If an appointment matches the parameter it returns true
  bool validAppointment(Appointment a1);
  //PreCondition: A vector exists of type appointment there is an Appointment
  //object that is taken in as a parameter
  //PostCondition:Checks the times and the dates against each other to make
  //sure appointments dont overlap if there are conflicts it returns false else
  //it returns true
  bool checkForMatchNO(string date, int hour24Start, int hour24End);
  //Precondition: Checks if there exists an object with the giver parameters
  //of string date, and int startTime and int endTime in 24 hour format
  //PostCondition: returns true if a match is found in the vector and false
  //if nothing is found
  void retrievePurpose(string date, int hour24Start, int hour24End);
  //PreCondition: Retrieves the purpose of an appointment based on the
  //parameters
  //PostCondition: Finds the object and calls the getPurpose function of
  //the object
  void deleteOldAppointment(string date, int hour24Start, int hour24End);
  //PreCondition: Deletes an appointment that matches the parameters given
  //PostCondition: Deletes the object in the vector that matches the parameters
 private:
  vector<Appointment> diary;//a vector that holds the Appointment type objects
  
};

#endif
