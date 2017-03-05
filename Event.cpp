#include "Event.h"

using namespace std;

Event::Event(std::string n, int m, int h, int d, int mon, std::string l, bool notf, std::string note, bool ad) //creates the event
{
    name = n;
    time.minutes = m;
    time.hours = h;
    date.day = d;
    date.month = mon;
    location = l;
    notifications = notf;
    notes = note;
    allDay = ad;

    cout << "Event Created!" << endl;
}

Event::~Event()
{
}

void Event::modifyEvent(std::string n, int m, int h, int d, int mon, std::string l, bool notf, std::string note, bool ad) //modifies the event
{
    name = n;
    time.minutes = m;
    time.hours = h;
    date.day = d;
    date.month = mon;
    location = l;
    notifications = notf;
    notes = note;
    allDay = ad;

    cout << "Event Modified!" << endl;
}

void Event::eventDeleted() //deletes the event
{
    cout << "Event Deleted!" << endl;
}

void Event::showEvent() //displays the event
{
    cout << "EVENT NAME: " <<name << endl;
    cout << "TIME: " << time.hours << ":" << time.minutes << endl;
    cout << "DATE: " <<date.day << "/" << date.month << endl;
    cout << "LOCATION: " << location << endl;
    cout << "ALLOW NOTIFICATIONS: " << notifications << endl;
    cout << "NOTES: " << notes << endl;
    cout << "ALLDAY?: " << allDay << endl;
}
