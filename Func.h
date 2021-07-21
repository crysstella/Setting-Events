#pragma once
#include <iostream>
#include "Event.h"
#include <vector>
#include <algorithm>

void addEvent(vector <Event>&);
bool eventsOverlaps(vector <Event>&, Event, Date, int);
void cancelEvent(vector <Event>&, int);
void viewEvents(vector <Event>&, int);
