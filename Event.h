#ifndef EVENT_H
#define EVENT_H

#include<iostream>
#include<cstring>

class Event
{
    public:
        struct Time
        {
            int minutes;
            int hours;
        };
        struct Date
        {
            int day;
            int month;
        };
        Time time;
        Date date;

        Event(std::string n, int m, int h, int d, int mon, std::string l, bool notf, std::string note, bool ad); //creates the event object
        ~Event();
        void modifyEvent(std::string n, int m, int h, int d, int mon, std::string l, bool notf, std::string note, bool ad); //modifies the event
        void showEvent();  //displays the event
        void eventDeleted(); //removes the event



    protected:

    private:
        std::string name;

        std::string location;
        bool notifications;
        std::string notes;
        bool allDay;
};

#endif // EVENT_H
