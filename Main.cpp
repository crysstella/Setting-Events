#include "Date.h"
#include "Event.h"
#include "Func.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector <Event> eventVect;
	string userInput;
	do
	{
		int SIZE = eventVect.size();
	
		cout << "(a)dd an event, (c)ancel an event, (v)iew all events, or (q)uit: " << endl;
		getline(cin, userInput);

		if (userInput == "a")
		{
			addEvent(eventVect);
		}
		else if (userInput == "c")
		{
			cancelEvent(eventVect, SIZE);
		}
		else if (userInput == "v")
		{
			viewEvents(eventVect, SIZE);
		}

		cout << endl;
	} while (userInput != "q");
	return 0;
}

