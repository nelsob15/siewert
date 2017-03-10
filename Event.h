#ifndef EVENT_H
#define EVENT_H

#include<iostream>
#include<cstring>

class Event
{
    public:

        Event *next;

        //enum Meridiem {am,pm};

        struct Time
        {
            int start_hour;
            int start_minute;
            int end_hour;
            int end_minute;
        };
        struct Date
        {
            int day;
            int month;
            int year;
        };
        Time time;
        Date date;

        Event();
        EventCreate(std::string name_new, int month_new, int day_new, int start_hour_new, int start_minute_new,
                    int m_start_new, int year_new,int end_hour_new, int end_minute_new, int m_end_new); //creates the event object
        ~Event();
        void modifyEvent(std::string name_mod, int month_mod, int day_mod, int start_hour_mod, int start_minute_mod, int m_start_mod, int year_mod,
                         int end_hour_mod, int end_minute_mod, int m_end_mod); //modifies the event
        void showEvent();  //displays the event
        void showEventList();
        void eventDeleted(); //removes the event
        void display_meridiem(int m);

        std::string getName();
        int m_start;
        int m_end;

    protected:

    private:
        std::string name;
        std::string location;
        bool notifications;
        std::string notes;
        bool allDay;
};

#endif // EVENT_H
