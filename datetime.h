//Scott Corcoran
//4/29/16
//Software construction
//This program predicts what day of the week a date will be
//There are some predetermined holidays for users as well

//This is the header containing everything you 
//actually need to run the program



#ifndef DATETIME
#define DATETIME

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

//This is the class containing everything, 
//including offsets and data hardcoded in
class date
{
private:
	string dayName;
	int lengthOfYear = 365;
	int numberOfYears;
	int leapyear;
	int numberOfYearsCalc(int days, int month ,int years);
	int offSetOfDayforYearStart = 6; //for 2000 this is saturday
	//Set this differently if you choose to adjust the start year
	int monthCalc(int month);
	

public:
	int RecieveDate(int UserMonth, int UserDate, int UserYear);
	void getFindWeekDay();
	void findWeekDay(int datenum);
	//these use the findWeekday and the get version to output the 
	//Dates but have been seperated as a delogation of jobs
	void getChristmas(int year);  
	void getHalloween(int year);
	void getValentines(int year);
	void getLabor(int year);
	void getPirate(int year);
	void getPatrick(int year);
	void getThanksgiving(int year);
	void getMothers(int year);
	void getFathers(int year);

};

//FIND SPECIFIC DATE FUNCTION
////////////////////////////////////////////////////////////////////////////

//Input: A year
//Output: No return however output to screen happens
//These will fail if findWeekDate or getFindDateWWeek fail
//Modify the dayname variable using findWeekDay
//Then print it using get version


//Christmas
void date::getChristmas(int year)
{
		cout << "Christmas is on the ";
		findWeekDay(RecieveDate(12, 25, year));
		getFindWeekDay();
}

//Valentines day
void date::getValentines(int year)
{
		cout << "Valentines day is on the ";
		findWeekDay(RecieveDate(2, 14, year));
		getFindWeekDay();
}


//Talk like a pirate day
void date::getPirate(int year)
{
		cout << "Talk like a pirate day is on the ";
		findWeekDay(RecieveDate(9, 19, year));
		getFindWeekDay();
}


//Labor day
void date::getLabor(int year)
{
		cout << "Labor day is on the ";
		findWeekDay(RecieveDate(9, 5, year));
		getFindWeekDay();
}

//Halloween
void date::getHalloween(int year)
{
		cout << "Halloween is on the ";
		findWeekDay(RecieveDate(10, 31, year));
		getFindWeekDay();
}

//St Patrick's
void date::getPatrick(int year)
{
		cout << "Saint Patrick's day is on the ";
		findWeekDay(RecieveDate(3, 17, year));
		getFindWeekDay();
}


//Thanksgiving
void date::getThanksgiving(int year)
{
		cout << "Thanksgiving is on the ";
		findWeekDay(RecieveDate(11, 24, year));
		getFindWeekDay();
}

//Mother's Day
void date::getMothers(int year)
{
		cout << "Mother's day is on the ";
		findWeekDay(RecieveDate(5, 8, year));
		getFindWeekDay();
}

//Father's Day
void date::getFathers(int year)
{
		cout << "Father's day is on the ";
		findWeekDay(RecieveDate(6, 19, year));
		getFindWeekDay();
}


//START OF SUPPORT FUNCTIONS
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//Input number to be turned into day of wekk
//Output: none
//MOdifies variable for later output.
void date::findWeekDay(int datenum)
{
	datenum += offSetOfDayforYearStart;
	if (datenum > 6)
	{
		datenum = datenum % 7;
	}
	switch (datenum)
	{
		case 0: dayName = "Sunday"; break;
		case 1: dayName = "Monday"; break;
		case 2: dayName = "Tuesday"; break;
		case 3: dayName = "Wednesday"; break;
		case 4: dayName = "Thursday"; break;
		case 5: dayName = "Friday"; break;
		case 6: dayName = "Saturday"; break;
		defualt: cout << "error in guessing week day" << endl;
	}
}

void date::getFindWeekDay()
{
	cout << dayName << endl;
}


////////////////////////////////////////////////////////////////////////////

//Take user number
int date::RecieveDate(int UserMonth,int UserDate, int UserYear)
{
	leapyear = 0; //reset it before its used for numberOfYearsCalc
	int finalDate = UserDate + numberOfYearsCalc(UserDate,UserMonth,UserYear);
	finalDate += monthCalc(UserMonth);
	finalDate += leapyear;

	return finalDate;
}


////////////////////////////////////////////////////////////////////////////
int date::monthCalc(int month)
{
	int returnDate = 0;
	switch (month)
	{
		case 1: returnDate = 0; break;
		case 2: returnDate = 31; break;
		case 3: returnDate = 59; break;
		case 4: returnDate = 90; break;
		case 5: returnDate = 120; break;
		case 6: returnDate = 151; break;
		case 7: returnDate = 181; break;
		case 8: returnDate = 212; break;
		case 9: returnDate = 243; break;
		case 10: returnDate = 273; break;
		case 11: returnDate = 304; break;
		case 12: returnDate = 334; break;
		defualt: cout << "error in guessing week day" << endl;
	}

	return returnDate;
}
//*/


int date::numberOfYearsCalc(int days, int month ,int years)
{
	years -= 2000;
	int numOfDays = years * lengthOfYear;
	if (60>=(numOfDays + monthCalc(month) + days) % 365)
	{
		leapyear -= 1;
	}
	if (years >= 4)
	{
		for (int i = 0; i <= int(years / 4)-1 ;i++)
		{
			leapyear += 1;
		}
	}
	return numOfDays;
}

////////////////////////////////////////////////////////////////////////////
#endif 


