//Tyler Yamashiro
//AppointmentDiary.cpp
//Purpose: The implemnation file for the AppointmentDiary class
//Input: Integer for time, a string for the date, an object of type Appointment
//Processing: Checks for matches, inserts, and deletes object inside the
//vector of type Appointment
//Output: bools for wherther or not a match was found
#include "AppointmentDiary.h"

AppointmentDiary::AppointmentDiary()
{
}

void AppointmentDiary::clearDiary()//clear all vector entries
{
  diary.clear();
}

void AppointmentDiary::insertAppointment(Appointment a1)//isnerts object at
{                                                         //end of list
  diary.push_back(a1);
}

bool AppointmentDiary::checkForMatch(Appointment a1)//checks for match 
{                                                   //of two objects
  bool match = true;
  
  for(unsigned i = 0; i < diary.size(); i++){
	if(diary[i].returnDate() == a1.returnDate() &&
	   diary[i].returnStartTime() == a1.returnStartTime() &&
	   diary[i].returnEndTime() == a1.returnStartTime())
	  return true;
	else{
	  match = false;
	}
  }
  
  return match;
}

bool AppointmentDiary::validAppointment(Appointment a1)//Sees if an 
{                                                  //Appointment object is 
  bool valid = true;                                 //valid
  for( int i = 0; i < diary.size(); i++){
	if(valid){
	  if(diary[i].returnDate()== a1.returnDate()){
		if(diary[i].returnStartTime() <=  a1.returnStartTime() &&
		   diary[i].returnEndTime() >= a1.returnStartTime()){
		  return false;
		}
		else if(diary[i].returnStartTime() <= a1.returnEndTime() &&
				diary[i].returnStartTime() >= a1.returnEndTime())
		  return false;
		else{
		  valid= true;
		}
	  }
	}
  }
  return valid;
}


void AppointmentDiary::deleteAppointment(string date,
										 int hour24Start, int hour24End)
{
  for(int i = 0; i < diary.size(); i++){          //Deletes an object
	if(diary[i].returnDate() ==  date &&         //that matches parameters
	   diary[i].returnStartTime() == hour24Start &&
	   diary[i].returnEndTime() == hour24End){
	  
	  diary.erase(diary.begin()+i);
	  cout <<  "Appointment has been deleted." << endl;
	}
	else{
		cout << "Could not find Appointment returning to Welcome screen.";
		cout << endl;
	}
  }
}


bool AppointmentDiary::checkForMatchNO(string date, int hour24Start,
									   int hour24End)
{
  //checks for parameter matches with Appointment objects
  bool match = false;
  for(int i = 0; i < diary.size(); i++){
	if(diary[i].returnDate() ==  date &&
	   diary[i].returnStartTime() == hour24Start &&
	   diary[i].returnEndTime() == hour24End){ 
	  match = true;
	}
  }
  return match;
}

void AppointmentDiary::retrievePurpose(string date, int hour24Start,
										 int hour24End)
{   //finds the object who has the matching data members and calls getPurpose
  bool found = false;    //for it
  for(int i = 0; i < diary.size(); i++){
	if(diary[i].returnDate() ==  date &&
	   diary[i].returnStartTime() == hour24Start &&
	   diary[i].returnEndTime() == hour24End){
	  
	  diary[i].getPurpose();
	  found = true;
	}

  }
  if(!found){
	cout << "Sorry appointment not found.";
  }
}


void AppointmentDiary::deleteOldAppointment(string date,
										 int hour24Start, int hour24End)
{                                         //Deletes and object based on 
  for(int i = 0; i < diary.size(); i++){  //parameters
	if(diary[i].returnDate() ==  date &&
	   diary[i].returnStartTime() == hour24Start &&
	   diary[i].returnEndTime() == hour24End){
	  
	  diary.erase(diary.begin()+i);
	}
  }
}
