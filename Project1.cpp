//Tyler Yamashiro
//Project1.cpp

//Purpose: Driver file for the program interacts with the user in order to
//Schedule, cancel, check for, and reschedule appointments, as well as
//add, delete, and list users and retrieve the purpose of an appointment

//Input:Chars to select what option in the welcome screen to choose, Ints for
//the hours, minutes, and strings for AM or PM, usernames, and the date.

//Processing: Takes the input of the user and creates objects based on the
//specified parameters. Converts the date string into 3 ints for year, month
//and day interacts with the vector of type user to organize and find users

//Output: OutPuts welcome screen and prompts of what information the user
//should supply.  Outputs information to the user about whether or not
//Appointments exist and if users exists as well as provides error messages
//when necassary

#include "User.h"
#include <stdlib.h>

void addUser(string userName, vector<User>& userList);
//Precondition:A vector of type user exists a string for a username
//PostCondition:Takes the vector the string to create a User object with the
//userName of the parmaeter and inserts it into the vector of type user.
void deleteUser(string userName, vector<User>& userList);
//Precondition:A vector of type user exists a string for a username
//PostCondition:finds the user based on userName and if a match is found
//it deletes the user from the vector
void printUserList(vector<User> userList);
//Prints the vector given in the parameter
void createAppointment(string userName, vector<User>& userList);
//Precondition:A vector of type user exists a string for a username
//PostCondition: The Create appointment function for the specifed user is
//created, the function asks for dates and times from the user  
void deleteAppointment(string userName, vector<User>& userList);
//Precondition:A vector of type user exists a string for a username
//PostCondition:The delete Appointment fucntion for the appropriate User is
//called.
void checkAppointment(string userName, vector<User>& userList);
//Precondition:A vector of type user exists a string for a username
//PostCondition:The function asks for date and times in order to check if
//an appointment exists that matches the specified information from thse user
void retrievePurpose(string userName, vector<User>& userList);
//Precondition:A vector of type user exists a string for a username
//PostCondition:Function asks for date and time in order to check if an
//appointment exists if yes then it calls functions to print the purpose
void reAppointment(string userName, vector<User>& userList);
//Precondition:A vector of type user exists a string for a username
//PostCondition:Function asks for date and time in order to check if an
//Appointment exists.  If it does it asks for more dates and times from the
//user as well as a purpose and replaces the existing appointment with a new
//one

int main()
{
  vector<User> userList;
  bool mainMenu = true;
  string userID;
  char input;
  while(mainMenu){
	cout << endl << endl;
	cout << //prints the menu
	  "Welcome to Appointment Management System! What would you like to do??"
		 << endl << endl;
	cout << "[a] Add new user" << endl;
	cout << "[d] Delete an existing user" << endl;
	cout << "[l] List existing users" << endl;
	cout << "[s] Schedule an appointment" << endl;
	cout << "[c] Cancel an appointment" << endl;
	cout << "[f] Check for appointment on certain date and time" << endl;
	cout << "[p] Retrieve purpose of an appointment" << endl;
	cout << "[r] Reschedule an existing appointment" << endl;
	cout << "[x] Exit the system" << endl;
	cout << endl;
	cin >> input;
	
	if(tolower(input) == 'a'){ //all the commands for menu inputs
	  cout << "Please input a Username: ";
	  cin >> userID;
	  addUser(userID, userList);
	}
	else if(tolower(input) == 'd'){
	  cout << "Please input a Username to delete: ";
	  cin >> userID;
	  deleteUser(userID, userList);
	}
	else if(tolower(input) == 'l'){
	  cout << "Now printing all existing users...";
	  cout << endl;
	  printUserList(userList);
	}
	else if(tolower(input) == 's'){
	  cout << "What user would you like to make an appointment for?: ";
	  cin >> userID;
	  createAppointment(userID, userList);
	}
	else if(tolower(input) == 'c'){
	  cout << "What user would you like to cancel an appointment for?: ";
	  cin >> userID;
	  deleteAppointment(userID, userList);
	}
	else if(tolower(input) == 'f'){
	  cout << "What user would you like to find an appoinment for?: ";
	  cin >> userID;
	  checkAppointment(userID, userList);
	}
	else if(tolower(input) == 'p'){
	  cout << "What user would you like to access?: ";
	  cin >> userID;
	  retrievePurpose(userID, userList);
	}
	else if(tolower(input) == 'r'){
	  cout << "What user would you like to reschedule an appointment for? :";
	  cin >> userID;
	  reAppointment(userID, userList);
	}
	else if(tolower(input) == 'x'){
	  cout << "Goodbye thank you for useing the program.";
	  cout << endl;
	  mainMenu = false;
	}
	else{
	  cout<< "Sorry that was an invalid command.";
	}
  }
}





void addUser(string userName, vector<User>& userList)
{
  string userID = userName;  //creates a new user
  bool valid = true;
  User user1(userID);
  for(int i = 0; i < userList.size(); i++){
	if(user1.returnUsername() == userList[i].returnUsername()){
	  valid = false; //see if user already exists
	}
  }
  if( valid ){
	userList.push_back(user1);
	cout << "User created!...returning to welcome screen" << endl;
  }
  else{
	cout << "An error has occured...returning to welcome screen.";
	cout<< endl;
	  }	
}

void deleteUser(string userName, vector<User>& userList)
{
  string userID = userName;  //find the user and if exists then deletes it
  bool valid = true;;
  for(unsigned i = 0; i < userList.size(); i++){
	if( userID == userList[i].returnUsername()){
	  userList[i].clearDiary();
	  userList.erase(userList.begin()+i);
	  valid = false;
	  cout << "User successfully deleted" << endl;
	}
  }
  if(valid)
	cout << "User could not be found." << endl;
}

void printUserList(vector<User> userList)
{
  for(int i = 0; i < userList.size(); i++){
	cout << userList[i].returnUsername() << endl;
  }
}
	
void createAppointment(string userName, vector<User>& userList)
{
  bool userFound = false;
  int hourStart, minuteStart, hourEnd, minuteEnd, year, month, day;
  string AMorPMStart, AMorPMEnd, date, convert, temp, purpose;
  string userID = userName;
  
  for(int i = 0; i < userList.size(); i++){
	if( userID == userList[i].returnUsername()){ //finds the specified user
	  userFound = true;

	  cout << "Please input a date in format YYYY-MM-DD: "; //date input
	  cin >> date;
	  cout << endl;
	  temp = convert.assign(date,0, 4);
	  year = atoi(temp.c_str());				
	  temp = convert.assign(date,5,2);
	  month = atoi(temp.c_str());
	  temp = convert.assign(date,8,2);
	  day = atoi(temp.c_str());
	  
	  cout << "When would you like your appointment to start?"<< endl;
	  cout << "Please input the hour: ";
	  cin >> hourStart;
	  cout <<"Please input the minutes: ";
	  cin >> minuteStart;
	  cout << "AM or PM?: ";
	  cin >> AMorPMStart;
	  cout << endl;
	  
	  cout << "When would you like your appointment to end?"<< endl;
	  cout << "Please input the hour: ";
	  cin >> hourEnd;
	  cout <<"Please input the minutes: ";
	  cin >> minuteEnd;
	  cout << "AM or PM?: ";
	  cin >> AMorPMEnd;
	  cout << endl;
	  
	  cout << "Please input a purpose for your appointment: ";
	  cin >> purpose;
	  cout << endl;
	  
	  userList[i].createAppointment(hourStart, minuteStart, AMorPMStart,
									hourEnd, minuteEnd, AMorPMEnd, year, month,
									day, purpose);
	  
	}
  }
  if(!userFound){
	cout << "User not found returning to welcome screen...";
	cout << endl;
  }
}

void deleteAppointment(string userName, vector<User>& userList)
{
  string date, AMorPMStart, AMorPMEnd;
  int hourStart, minuteStart, hourEnd, minuteEnd, hour24Start, hour24End;
  bool userFound = false;
  string userID = userName;
  for(int i = 0; i < userList.size(); i++){
	if( userID == userList[i].returnUsername()){
	  userFound = true;
	  cout << endl;
	  cout <<
		"Please enter the date of the appointment in YYYY-MM-DD fomrat: ";
	  cin >> date;
	  cout << endl;
	  cout << "Please enter the hour of your appointment start time: ";
	  cin >> hourStart;
	  cout << "Please enter the minutes of you appointment start time: ";
	  cin >> minuteStart;
	  cout << "Please enter AM or PM: ";
	  cin >> AMorPMStart;
	  cout << endl;
  
	  cout << "Please enter the hour of your appointment end time: ";
	  cin >> hourEnd;
	  cout << "Please enter the minutes of you appointment end time: ";
	  cin >> minuteEnd;
	  cout << "Please enter AM or PM: ";
	  cin >> AMorPMEnd;
	  cout << endl;
	  
	  for(unsigned j = 0; j <AMorPMStart.length(); j++) //turns AM PM into 
		AMorPMStart[j] = toupper(AMorPMStart[j]);     //uppercase
	  if(AMorPMStart == "PM" || AMorPMStart == "AM"){
		hour24Start = hourStart + 12;
	  }
	  hour24Start = hour24Start * 100;
	  hour24Start = hour24Start + minuteStart;
	  
	  for(unsigned j = 0; j <AMorPMEnd.length(); j++)//turns AMorPM into 
		AMorPMEnd[j] = toupper(AMorPMEnd[j]);        // uppercase
	  if(AMorPMEnd == "PM" || AMorPMEnd == "AM"){
		hour24End = hourEnd + 12;
	  }
	  hour24End = hour24End * 100;
	  hour24End = hour24End + minuteEnd;
	  
	  userList[i].deleteAppointment(date, hour24Start, hour24End);
	}
  }
  if(!userFound){
	cout << "User could not be found returning to welcome screen...";
	cout << endl;
  }
}


void checkAppointment(string userName, vector<User>& userList)
{
  string date, AMorPMStart, AMorPMEnd;
  int hourStart, minuteStart, hourEnd, minuteEnd, hour24Start, hour24End;
  bool userFound = false;
  string userID = userName;
  for(int i = 0; i < userList.size(); i++){
	if( userID == userList[i].returnUsername()){
	  userFound = true;                //asks for relevant information
	  cout << endl;
	  cout <<
		"Please enter the date of the appointment in YYYY-MM-DD fomrat: ";
	  cin >> date;
	  cout << endl;
	  cout << "Please enter the hour of your appointment start time: ";
	  cin >> hourStart;
	  cout << "Please enter the minutes of you appointment start time: ";
	  cin >> minuteStart;
	  cout << "Please enter AM or PM: ";
	  cin >> AMorPMStart;
	  cout << endl;
	  
	  cout << "Please enter the hour of your appointment end time: ";
	  cin >> hourEnd;
	  cout << "Please enter the minutes of you appointment end time: ";
	  cin >> minuteEnd;
	  cout << "Please enter AM or PM: ";
	  cin >> AMorPMEnd;
	  cout << endl;
	  
	  for(unsigned j = 0; j <AMorPMStart.length(); j++)//turn string into
		AMorPMStart[j] = toupper(AMorPMStart[j]);      // uppercase
	  if(AMorPMStart == "PM" || AMorPMStart == "AM"){
		hour24Start = hourStart + 12;
	  }
	  hour24Start = hour24Start * 100;
	  hour24Start = hour24Start + minuteStart;
	  
	  for(unsigned j = 0; j <AMorPMEnd.length(); j++)
		AMorPMEnd[j] = toupper(AMorPMEnd[j]);
	  if(AMorPMEnd == "PM" || AMorPMEnd == "AM"){
		hour24End = hourEnd + 12;
	  }
	  hour24End = hour24End * 100;
	  hour24End = hour24End + minuteEnd;
	  
	  if(userList[i].checkForMatch(date, hour24Start, hour24End)){
		cout << "There is an appointment at the date and time specified";
		cout << endl;
	  }
	  else{
		cout << "No appointment was found";
		cout << endl;
	  }	  
	}
  }
  if(!userFound){
	cout << "User could not be found exiting to welcome screen...";
	cout << endl;
  }
}
 

void retrievePurpose(string userName, vector<User>& userList)
{ string date, AMorPMStart, AMorPMEnd;
  int hourStart, minuteStart, hourEnd, minuteEnd, hour24Start, hour24End;
  bool userFound = false;
  string userID = userName;
  for(int i = 0; i < userList.size(); i++){
	if( userID == userList[i].returnUsername()){
	  userFound = true;
	  cout << endl;
	  cout <<
		"Please enter the date of the appointment in YYYY-MM-DD fomrat: ";
	  cin >> date;
	  cout << endl;
	  cout << "Please enter the hour of your appointment start time: ";
	  cin >> hourStart;
	  cout << "Please enter the minutes of you appointment start time: ";
	  cin >> minuteStart;
	  cout << "Please enter AM or PM: ";
	  cin >> AMorPMStart;
	  cout << endl;
	  
	  cout << "Please enter the hour of your appointment end time: ";
	  cin >> hourEnd;
	  cout << "Please enter the minutes of you appointment end time: ";
	  cin >> minuteEnd;
	  cout << "Please enter AM or PM: ";
	  cin >> AMorPMEnd;
	  cout << endl;
	  
	  for(unsigned j = 0; j <AMorPMStart.length(); j++)
		AMorPMStart[j] = toupper(AMorPMStart[j]);
	  if(AMorPMStart == "PM" || AMorPMStart == "AM"){
		hour24Start = hourStart + 12;
	  }
	  hour24Start = hour24Start * 100;
	  hour24Start = hour24Start + minuteStart;
	  
	  for(unsigned j = 0; j <AMorPMEnd.length(); j++)
		AMorPMEnd[j] = toupper(AMorPMEnd[j]);
	  if(AMorPMEnd == "PM" || AMorPMEnd == "AM"){
		hour24End = hourEnd + 12;
	  }
	  hour24End = hour24End * 100;
	  hour24End = hour24End + minuteEnd;
	  
	  userList[i].retrievePurpose(date, hour24Start, hour24End);
	}
  }
  if(!userFound){
	cout << "User could not be found exiting to welcome screen...";
	cout << endl;
  }
}

void reAppointment(string userName, vector<User>& userList)
{
 string date, AMorPMStart, AMorPMEnd;
 int hourStart, minuteStart, hourEnd, minuteEnd, hour24Start, hour24End;
 bool userFound = false;
 string dateNew, AMorPMStartNew, AMorPMEndNew, purposeNew ,temp, convert;
 int hourStartNew, minuteStartNew, hourEndNew,
   minuteEndNew, hour24StartNew, hour24EndNew, yearNew, monthNew, dayNew;
 string userID = userName;
 for(int i = 0; i < userList.size(); i++){
   if( userID == userList[i].returnUsername()){  //find user
	 userFound = true;
	 cout << endl;  //get needed data to find appointment
  	 cout <<
 	   "Please enter the date of the appointment in YYYY-MM-DD fomrat: ";
	 cin >> date;
	 cout << endl;
	 cout << "Please enter the hour of your appointment start time: ";
	 cin >> hourStart;
	 cout << "Please enter the minutes of you appointment start time: ";
	 cin >> minuteStart;
	 cout << "Please enter AM or PM: ";
	 cin >> AMorPMStart;
	 cout << endl;
	 
	 cout << "Please enter the hour of your appointment end time: ";
	 cin >> hourEnd;
	 cout << "Please enter the minutes of you appointment end time: ";
	 cin >> minuteEnd;
	 cout << "Please enter AM or PM: ";
	 cin >> AMorPMEnd;
	 cout << endl;
	 
	 for(unsigned j = 0; j <AMorPMStart.length(); j++) //turn strings into
	   AMorPMStart[j] = toupper(AMorPMStart[j]);      //uppercase
	 if(AMorPMStart == "PM" || AMorPMStart == "AM"){
	   hour24Start = hourStart + 12;
	 }
	 hour24Start = hour24Start * 100;
	 hour24Start = hour24Start + minuteStart;
	 
	 for(unsigned j = 0; j <AMorPMEnd.length(); j++)
	   AMorPMEnd[j] = toupper(AMorPMEnd[j]);
	 if(AMorPMEnd == "PM" || AMorPMEnd == "AM"){
	   hour24End = hourEnd + 12;
	 }
	 hour24End = hour24End * 100;
	 hour24End = hour24End + minuteEnd;
	 //if there is a match do the proccess of makeing an appointment
	 if(userList[i].checkForMatch(date, hour24Start, hour24End)){
	   cout << "There is an appointment at the date and time specified";
	   cout << endl;
	   cout <<
		 "Please enter the date of the new appointmentin YYYY-MM-DD fomrat: ";
	   cin >> dateNew;
	   cout << endl;
	   temp = convert.assign(dateNew,0, 4);
	   yearNew = atoi(temp.c_str());
	   temp = convert.assign(dateNew,5,2);
	   monthNew = atoi(temp.c_str());
	   temp = convert.assign(dateNew,8,2);
	   dayNew = atoi(temp.c_str());
	   cout <<
		 "Please enter the hour of your new appointmentstart time: ";
	   cin >> hourStartNew;
	   cout <<
		 "Please enter the minutes of your new appointment start time: ";
	   cin >> minuteStartNew;
	   cout << "Please enter AM or PM: ";
	   cin >> AMorPMStartNew;
	   cout << endl;
	   
	   cout << "Please enter the hour of your new appointment end time: ";
	   cin >> hourEndNew;
	   cout <<
		 "Please enter the minutes of your new  appointment end time: ";
	   cin >> minuteEndNew;
	   cout << "Please enter AM or PM: ";
	   cin >> AMorPMEndNew;
	   cout << endl;
	   
	   cout <<
		 "Please input the purpose of your new appointment: ";
	   cin >> purposeNew;
	   cout << endl;
	   
	   for(unsigned j = 0; j <AMorPMStartNew.length(); j++)
		 AMorPMStartNew[j] = toupper(AMorPMStartNew[j]);
	   if(AMorPMStartNew == "PM" || AMorPMStartNew == "AM"){
		 hour24StartNew = hourStartNew + 12;
	   }
	   hour24StartNew = hour24StartNew * 100;
	   hour24StartNew = hour24StartNew + minuteStartNew;
	   
	   for(unsigned j = 0; j <AMorPMEndNew.length(); j++)
		 AMorPMEndNew[j] = toupper(AMorPMEndNew[j]);
	   if(AMorPMEndNew == "PM" || AMorPMEndNew == "AM"){
		 hour24EndNew = hourEndNew + 12;
	   }
	   
	   
	   hour24EndNew = hour24EndNew * 100;
	   hour24EndNew = hour24EndNew + minuteEndNew;
	   //add appointment in and delete the old appointment
	   userList[i].replaceAppointment(hourStartNew, minuteStartNew,
									  AMorPMStartNew, hourEndNew,
									  minuteEndNew, AMorPMEndNew,
									  yearNew,monthNew,dayNew,
									  purposeNew);
	   
	   userList[i].deleteOldAppointment(date, hour24Start, hour24End);
	 }		   		
	 
	 else{
	   cout << "No appointment was found";
	   cout << endl;
	 }
   }
   if(!userFound){
	 cout << "User could not be found exiting to welcome screen...";
	 cout << endl;
   }
 }
}
