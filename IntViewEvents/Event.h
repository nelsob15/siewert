#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include "Event.h"
#include <map>
#include <sstream>
#include <iomanip>
#include <limits>

class Event
{
    public:
        Event *next;  // points to next node in list

        struct Time  // keeps track of times
        {
            int start_hour;    // events start hour
            int start_minute;  // events start minute
            int end_hour;      // events end hour
            int end_minute;    // events end minute
			int meridian_start;  // start meridian
            int meridian_end;    // end meridian
        };
        struct Date  // date of event
        {
            int day;   // events day
            int month; // events month
            int year;  // events year
        };

        Event();
		~Event();

		void CreateEvent(Event **event_head);  // creating a new event
        void ModifyEvent(Event **event_head);
        void RemoveEvent(Event **event_head);

		void EventFill(std::string name_new, std::string location_new,int month_new, int day_new, int start_hour_new, int start_minute_new,
                       int meridian_start_new, int year_new,int end_hour_new, int end_minute_new, int meridian_end_new, std::string new_notes);

		int EventSort(Event * temp, Event * temp2);
		void ReOrderEvents(Event **event_head);

		void GetDate(int * month, int * day, int * year);
		void GetStartTime(int * hour, int * minute, int * meridian_start);
		void GetEndTime(int * end_hour, int * end_minute, int * meridian_end);

        bool ValidDate(int month, int day, int year);
        bool ValidTime(int hour, int minute, std::string meridian);
        bool EndVsStartTime(int start_hour, int start_minute, int meridian_start, int meridian_end, int end_hour, int end_minute);

        int GetStartMeridian(); // gets start meridian
        int GetEndMeridian();   // gets end meridian
        std::string GetName();    // gets name of event
        int getDay();
        int getMonth();
        int getYear();

		void Traverse(Event **event_head); // iterating through event
		void ClearList(Event ** event_head);
		void ShowEventMenu();   // displays menu options for events
        void ShowEventFullDetails();  // displays all of the event details
        void ShowEventListDetails();     // displays event in a list format
		void DisplayEventFull(Event **event_head); //display event
        void DisplayMeridian(int meridian);  // displays set meridian


    protected:

    private:
        Time time;
        Date date;

        bool notifications;  // sets notifications
        bool allDay;         // sets if event is all day
        std::string name;    // event name
        std::string location;// event location
        std::string notes;   // event notes
};

#endif // EVENT_H
