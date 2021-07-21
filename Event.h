#pragma once
#include "Date.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Event
{
	Date eventDate;
	string eventName;
	int startHour;
	int endHour;

public:
	Event(string, int, int, Date);

	void setEventName(string);
	void setDate(Date);
	bool setStartHour(int);
	bool setEndHour(int);
	bool checkOneDay(int, int);

	bool compare(Date);
	void printEvent();
	Date getDate() const { return eventDate; }
	string getEventName() const { return eventName; }
	int getStartHour() const { return startHour; }
	int getEndHour() const { return endHour; }
	
}
;