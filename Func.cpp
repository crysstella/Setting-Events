#include "Func.h"

void addEvent(vector <Event>& eventVect)
{
	int size = eventVect.size();
	int d, m, y, startH, endH;
	string name;
	Date eDate;
	bool testDate, test_Start_Hour, test_End_Hour, check_One_Day, check_Overlaps;

	do
	{
		cout << "Enter an event's name, the date info (day, month, year), and start and end time: " << endl;
		getline(cin, name);
		cin >> d >> m >> y >> startH >> endH;
		cin.ignore();

		testDate = eDate.setDate(d, m, y);
		Event eventInfo(name, startH, endH, eDate);
		eventInfo.setDate(eDate);

		test_Start_Hour = eventInfo.setStartHour(startH);
		test_End_Hour = eventInfo.setEndHour(endH);
		check_One_Day = eventInfo.checkOneDay(startH, endH);
		check_Overlaps = eventsOverlaps(eventVect, eventInfo, eDate, size);

		if ((testDate == true) && (test_Start_Hour == true) && (test_End_Hour == true) && (check_One_Day == true) && (check_Overlaps == true))
		{
			eventVect.push_back(eventInfo);
		}

		
	} while ((testDate == false) || (test_Start_Hour == false) || (test_End_Hour == false) || (check_One_Day == false) || (check_Overlaps == false));

	cout << "Your data was added!" << endl;
}

bool eventsOverlaps(vector <Event>& eventVect, Event eventInfo, Date eDate, int size)
{
	bool test = true;
	for (int i = 0; i < size; i++)
	{
		//Overlaps time hour
		int startHour = eventVect[i].getStartHour();
		int endHour = eventVect[i].getEndHour();

		int distance1 = max(eventInfo.getEndHour(), endHour) - min(startHour, eventInfo.getStartHour());
		int distance2 = (endHour - startHour) + (eventInfo.getEndHour() - eventInfo.getStartHour());
		if (eventVect[i].compare(eDate) == true) 
		{
			if (distance1 < distance2)
			{
				cout << "Your event overlaps another one or already exists! Please enter another one!" << endl;
				return false;
			}
		}
	}
	return true;
}

void cancelEvent(vector <Event>& eventVect, int size)
{
	string name;
	int day, month, year, startH, endH;
	int count = 0;
	//Event* eventClass;
	do
	{
		cout << "Please enter an event (name, day, month, year, start and end time) that you want to cancel: " << endl;
		getline(cin, name);
		cin >> day >> month >> year >> startH >> endH;
		cin.ignore();
		Date eDate;
		eDate.getDate(day, month, year);

		for (int i = 0; i < eventVect.size(); i++)
		{
			if ((eventVect[i].compare(eDate) == true) && (eventVect[i].getEventName() == name) && (eventVect[i].getStartHour() == startH) && (eventVect[i].getEndHour() == endH))
			{
				count++;
				eventVect.erase(eventVect.begin() + i);
			}

		}
		cout << endl;
	} while( count == 0);
}

void viewEvents(vector <Event>& eventVect, int size)
{
	for (int i = 0; i < size; i++)
	{
		eventVect[i].printEvent();
	}
}
