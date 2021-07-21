#include "Date.h"

using namespace std;

bool Date::setDate(int d, int m, int y)
{
	bool test = true;
	// Check day and let users know what they were wrong
	if ((d > 0) && (d < 32))
	{
		day = d;
	}
	else
	{
		cout << "Day should not be negative and larger than 31!" << endl;
		test = false;
	}

	// Check month and let users know what they were wrong
	if ((m > 0) && (m < 13))
	{
		month = m;
	}
	else
	{
		cout << "Month should not be negative and larger than 12!" << endl;
		test = false;
	}

	// Check year and let users know what they were wrong
	if (y > 0)
	{
		year = y;
	}
	else
	{
		cout << "Year should not be negative!" << endl;
		test = false;
	}

	return test;
	
}
void Date::getDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
void Date::printDate()
{
	cout << day << "/" << month << "/" << year << endl;
}