//Tyler Yamashiro
//User.cpp
//User.h implementation file

#include "User.h"

User::User(string userID)
{
  userName = userID;
}

string User::returnUsername()//returns Username
{
  return userName;
}


bool User::createAppointment(int hourStart, int minuteStart,
							 string AMorPMStart, int hourEnd , int minuteEnd,
							 string AMorPMEnd, int year, int month, int day,
							 string purpose)
{
  bool valid = true;
  Appointment a1; //returns false if any of the checks fail
  if( valid != a1.setStartTime(hourStart, minuteStart, AMorPMStart)){
	cout << "Time start invalid returning to welcome screen." << endl;
	return false;
  }
  	
  else if(valid !=  a1.setEndTime(hourEnd, minuteEnd, AMorPMEnd)){
	cout <<"Time end invalid returning to welcome screen." << endl;
	return false;
  }
  
  else if( valid !=  a1.setDate(year, month, day)){
	cout << "Date invalid returning to welcome screen." << endl;
	return false;
  }
  
  a1.setPurpose(purpose);

  if(diary.validAppointment(a1)){  //checks the appointment agains the others
	diary.insertAppointment(a1);   //in the diary
	//diary.test();
	cout << "Success! Returning to welcome screen.";
  }
  else{
	cout << "Not a valid appointment...Returning to welcome screen" << endl;
  }
 
}


						 
void User::clearDiary()//calls clearDiary
{
  diary.clearDiary();
} 


void User::deleteAppointment(string date,int hour24Start,int hour24End)
{
  diary.deleteAppointment(date,hour24Start, hour24End); //calls 
}                                                     //deleteAppointment

bool User::checkForMatch(string date, int hour24Start, int hour24End)
{ //checks for a match based on parameters returns result
  return( diary.checkForMatchNO(date, hour24Start, hour24End));
}

void User::retrievePurpose(string date, int hour24Start, int hour24End)
{//passes parameters to print the purpose
  diary.retrievePurpose(date, hour24Start, hour24End);
}


bool User::replaceAppointment(int hourStart, int minuteStart,
							 string AMorPMStart, int hourEnd , int minuteEnd,
							 string AMorPMEnd, int year, int month, int day,
							 string purpose)
{            //Checks for valid parmaeters returns false if it fails any
  bool  valid = true;
  Appointment a1;
  if(valid !=  a1.setStartTime(hourStart, minuteStart, AMorPMStart)){
	cout << "Time invalid returning to welcome screen." << endl;
	return false;
  }
  else if(valid != a1.setEndTime(hourEnd, minuteEnd, AMorPMEnd)){
	cout << "Time invalid returning to welcome screen." << endl;
	return false;
  }
  else if(valid !=  a1.setDate(year, month, day)){
	cout << "Date invalid returning to welcome screen." << endl;
	return false;
  }
  a1.setPurpose(purpose);
  diary.insertAppointment(a1); //inserts the appointment into the diary
  cout << "Appointment has been rescheduled." ;
 
}

void User::deleteOldAppointment(string date, int hour24Start, int hour24End)
{  //deletes teh diary specified
  diary.deleteOldAppointment(date, hour24Start, hour24End);
}
