#pragma once
#include <iostream>

using namespace std;
class Date
{
	int day;
	int month;
	int year;

public:
	//Set Up Date
	bool setDate(int, int, int);

	//Get Date Values
	void getDate(int, int, int);
	int getDay() const { return day; }
	int getMonth() const {return month;}
	int getYear() const { return year; }

	//Output Date (Day/Month/Year)
	void printDate();
};

