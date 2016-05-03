//Scott Corcoran
//4/29/16
//Software construction
//This program predicts what day of the week a date will be
//There are some predetermined holidays for users as well

//This is just the main file, it just shows the usge
//of the program dont need it to run program


#include <iostream>
#include <string>
#include "DATETIME.h"


using std::cout;
using std::endl;
using std::cin;

int main ()
{
	cout << "Please enter a month then enter, then repeat for day" << endl;
	cout << " (numeric example 9/18/2016 press enter between each value)" << endl;
	date userRequest;
	int month;
	int day;
	int year;
	cin >> month;
	cin >> day;
	cin >> year;
	
	userRequest.findWeekDay((userRequest.RecieveDate(month,day,year)));
	userRequest.getFindWeekDay();
	
	userRequest.getChristmas(2016); //Sunday
	userRequest.getHalloween(2016); //monday
	userRequest.getValentines(2016); // Sunday
	userRequest.getLabor(2016); //Monday
	userRequest.getPirate(2016); //Monday
	userRequest.getPatrick(2016); //Thursday
	userRequest.getThanksgiving(2016); //Thursday
	userRequest.getMothers(2016); //Sunday
	userRequest.getFathers(2016); //Sunday

	cin.get();
	cin.get();
	return 0;
}