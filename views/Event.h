#ifndef EVENT_H
#define EVENT_H

#include<iostream>
#include<cstring>

class Event
{
    friend class View;
    public:
        Event *next;  // points to next node in list

        struct Time  // keeps track of times
        {
            int start_hour;    // events start hour
            int start_minute;  // events start minute
            int end_hour;      // events end hour
            int end_minute;    // events end minute
        };
        struct Date  // date of event
        {
            int day;   // events day
            int month; // events month
            int year;  // events year
        };

        Event();
        void EventCreate(std::string name_new, int month_new, int day_new, int start_hour_new, int start_minute_new,
                    int m_start_new, int year_new,int end_hour_new, int end_minute_new, int m_end_new, std::string new_notes);
        //creates the event object
        ~Event();
        void modifyEvent(std::string name_mod, int month_mod, int day_mod, int start_hour_mod, int start_minute_mod, int m_start_mod, int year_mod,
                         int end_hour_mod, int end_minute_mod, int m_end_mod, std::string notes_mod);
        //modifies the event

        int get_start_meridian(); // gets start meridian
        int get_end_meridian();   // gets end meridian
        std::string getName();    // gets name of event
        int getDay(); // gets day
        int getMonth(); // gets month
        int getYear(); // gets year
        void showEventDetails();  // displays all of the event details
        void showEventList();     // displays event in a list format
        void eventDeleted();      // removes the event
        void display_meridiem(int meridian);  // displays set meridian
        void show_event_menu();   // displays menu options for events
        void main_event_menu();   // event menu
        void push(Event **head);  // creating a new event
        void traverse(Event **head); // iterating through event
        void display_event(Event **head); //display event

    protected:

    private:
        Time time;
        Date date;

        int m_start;  // start meridian
        int m_end;    // end meridian
        bool notifications;  // sets notifications
        bool allDay;         // sets if event is all day
        std::string name;    // event name
        std::string location;// event location
        std::string notes;   // event notes
};

#endif // EVENT_H
