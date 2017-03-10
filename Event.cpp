#include "Event.h"

using namespace std;

Event::Event()
{

}

Event::EventCreate(std::string name_new, int month_new, int day_new, int start_hour_new, int start_minute_new,
                    int m_start_new, int year_new, int end_hour_new, int end_minute_new, int m_end_new) //creates the event
{
    name = name_new;
    date.month = month_new;
    date.day = day_new;
    time.start_hour = start_hour_new;
    time.start_minute = start_minute_new;
    m_start = m_start_new;
    date.year = year_new;
    time.end_hour = end_hour_new;
    time.end_minute = end_minute_new;
    m_end = m_end_new;

    //cout << "Event Created!" << endl;
}

Event::~Event()
{
}

void Event::modifyEvent(std::string name_mod, int month_mod, int day_mod, int start_hour_mod, int start_minute_mod, int m_start_mod, int year_mod,
                         int end_hour_mod, int end_minute_mod, int m_end_mod) //modifies the event
{
    name = name_mod;
    date.month = month_mod;
    date.day = day_mod;
    time.start_hour = start_hour_mod;
    time.start_minute = start_minute_mod;
    m_start = m_start_mod;
    date.year = year_mod;
    time.end_hour = end_hour_mod;
    time.end_minute = end_minute_mod;
    m_end = m_end_mod;

    cout << "Event Modified!" << endl;
}

void Event::eventDeleted() //deletes the event
{
    cout << "Event Deleted!" << endl;
}

void Event::display_meridiem(int m)
{
   switch(m)
    {
        case 0 : std::cout << "am";   break;
        case 1  : std::cout << "pm"; break;
    }
}

void Event::showEvent() //displays the event
{
    cout << name << endl;
    cout << date.month << "/" << date.day << "/" << date.year << endl;
    cout << time.start_hour << ":" << time.start_minute << " ";
    display_meridiem(m_start);
    cout << " - " << time.end_hour << ":" << time.end_minute << " ";
    display_meridiem(m_end);
    cout << endl;
}

void Event::showEventList() //displays the event
{
    cout << name << endl;
    cout << date.month << "/" << date.day << "/" << date.year << endl;
    cout << time.start_hour << ":" << time.start_minute << " ";
    display_meridiem(m_start);
    cout << " - " << time.end_hour << ":" << time.end_minute << " ";
    display_meridiem(m_end);
    cout << endl;
}

std::string Event::getName()
{
    return name;
}

