//Tyler Yamashiro
//Date.cpp
//implementation of Date.h

#include "Date.h"
#include <string>

Date::Date()
{
  year = 2017;
  month = 4;
  day = 3;
}

Date::Date(int yr, int mon, int d)
{
  year = yr;
  month = mon;
  day = d;
}

bool Date::setDate(int yr, int mon, int d)
{
  if( yr < 0 || mon <= 0 || mon > 12 || d <= 0 || d > 31){//Check if date is
	return false;                                         //valid
  }
  else{
  year = yr;
  month = mon;
  day = d;
  return true;
  }
}

string Date::findSeason()//finds the season
{
  int monthConv = month * 100;
  int sea = monthConv + day;

  if(sea >= 321 && sea < 621)
	return "Spring";
  else if( sea >= 621 && sea < 923)
	return "Summer";
  else if(sea >= 923 && sea < 1222)
	return "Fall";
  else{
	return "Winter";
  }
}
 
string Date::convertMonth()//converts the month int to a month string 
{
  string monthStr;
  if(month == 1)
	monthStr = "01";
  if(month == 2)
	monthStr = "02";
  if(month == 3)
	monthStr = "03";
  if(month == 4)
	monthStr = "04";
  if(month == 5)
	monthStr = "05";
  if(month == 6)
	monthStr = "06";
  if(month == 7)
	monthStr = "07";
  if(month == 8)
	monthStr = "08";
  if(month == 9)
	monthStr = "09";
  if(month == 10)
	monthStr ="10";
  if(month == 11)
	monthStr = "11";
  if(month == 12)
	monthStr = "12";
  return monthStr;
}

void Date::displayDate() const //prints date to the screen
{
  cout << convertMonth() << '/' << day << '/' << year << endl;
}

bool Date::checkDate(string date)//Checks if the date matches with the inputted
{                                //date
  string y;
  stringstream convert;//converts date to string
  convert << year;
  y = convert.str();
  string d;
  convert.str("");
  convert << day;
  d = convert.str();
  if(day < 10)
	dateComp = y + '-' + convertMonth()  + '-' + '0'+ d;
  else{
	dateComp = y + '-' + convertMonth() + '-' + d;
  }
  return(dateComp == date);
}

string Date::returnDate()//returns the date in YYYY-MM-DD time.
{
  string y;
  stringstream convert;//Proccess to convert int to string
  convert << year;
  y = convert.str();
  string d;
  convert.str("");
  convert << day;
  d = convert.str();
  if(day < 10)
	dateComp = y + '-' + convertMonth()  + '-' + '0'+ d;
  else{
	dateComp = y + '-' + convertMonth() + '-' + d;
  }
  return dateComp;
}
