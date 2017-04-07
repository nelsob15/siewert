#ifndef CALENDAR_H
#define CALENDAR_H

#include<iostream>
#include<cstring>
#include<iomanip>
#include "Event.h"

class Calendar
{
friend class Event; // Access the linked list to find events.
friend class View;  // View needs to instantiate a Calendar class and use methods.

private:
  Event head;
	int month;
	int year;
	int firstday;
public:
	Calendar(int =2, int =2017);
	void setFirstDay();
	void print(Event **);
};

#endif // CALENDAR_H
