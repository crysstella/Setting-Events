#include "Event.h"

Event::Event(string name, int startH, int endH, Date eDate)
{
	eventName = name;
	startHour = startH;
	endHour = endH;
	eventDate = eDate;
}

void Event::setEventName(string name)
{
	eventName = name;
}

void Event::setDate(Date eDate)
{
	eventDate = eDate;
}
bool Event::setStartHour(int startH)
{
	bool test = true;

	if ((startH > -1) && (startH < 24))
	{
		startHour = startH;
	}
	else
	{
		cout << "Your start time is invalid!" << endl;
		test = false;
	}

	return test;
}

bool Event::setEndHour(int endH)
{
	bool test = true;

	if ((endH > -1) && (endH < 24))
	{
		endHour = endH;
	}
	else
	{
		cout << "Your end time is invalid!" << endl;
		test = false;
	}

	return test;
}

bool Event::checkOneDay(int startH, int endH)
{
	if (startH < endH)
	{
		return true;
	}
	cout << "Start hour should be less than end hour!" << endl;
	return false;
}

bool Event::compare(Date eDate)
{
	
	if ((eventDate.getDay() == eDate.getDay()) && (eventDate.getMonth() == eDate.getMonth()) && (eventDate.getYear() == eDate.getYear()))
	{
		return true;
	}
	return false;
}
void Event::printEvent()
{
	cout << eventName << ": starts from " << startHour << " to " << endHour << " on ";
	eventDate.printDate();
}