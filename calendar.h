#ifndef CALENDAR_H
#define CALENDAR_H

#include<iostream>
#include<cstring>
//#include<conio.h>
#include<iomanip>

class Calendar
{
private:
	int month;
	int year;
	int firstday;
public:
	Calendar(int =2, int =2017);
	void setFirstDay();
	void print();
};

#endif // CALENDAR_H
