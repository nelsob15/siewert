/*
The MyCalendar application prototype
  The event module below is in change of Event interaction wether from an external file or from the user. The 3 main features present in this module is 
  event creation, event modification, and event deletion. This includes some error handling features for user input as well as detecting objects
  that are currently in the list or not in the list at all. The code is not 100% as not covering full path coverage nor is error handling robust to
  handle all errors
*/


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

		void CreateEvent(Event **event_list);  // creating a new event
        void ModifyEvent(Event **event_list);  // modify existing event
        void RemoveEvent(Event **event_list);  // remove existing event

		void EventFill(std::string name_new, std::string location_new,int month_new, int day_new, int year_new, int start_hour_new, int start_minute_new,
                       int meridian_start_new, int end_hour_new, int end_minute_new, int meridian_end_new, std::string new_notes); // fills new instance

		int EventSort(Event * temp, Event * temp2); // sorts events by time
		void ReOrderEvents(Event **event_list); // reorders the list

		void GetDate(int * month, int * day, int * year); // gets the date month/day/year
		void GetStartTime(int * hour, int * minute, int * meridian_start); // gets the start time hour:minute meridian
		void GetEndTime(int * end_hour, int * end_minute, int * meridian_end); // gets the end time hour:minute meridian
		int ReadStartMeridian(); // gets start meridian
		int ReadEndMeridian();   // gets end meridian
		
        bool ValidDate(int month, int day, int year); // checks for valid date
        bool ValidTime(int hour, int minute, std::string meridian); // checks for valid time
        bool EndVsStartTime(int start_hour, int start_minute, int meridian_start, int meridian_end, int end_hour, int end_minute); // checks if start time comes before end time

        std::string GetName();    // gets name of event
		std::string GetLocation(); // gets location
        int GetDay();         // get start day
        int GetMonth();       // get start month
        int GetYear();        // get start year
		int GetStartHour();   // get start hour
		int GetStartMinute(); // get start minute
        std::string GetStartMeridian(); // get start meridian
		int GetEndHour();   // get end hour
		int GetEndMinute(); // get end minute
        std::string GetEndMeridian(); // get end meridian
		std::string GetNotes();  // get notes

		void Traverse(Event **event_list); // iterating through event
		void ClearList(Event ** event_list); // clears and frees the list
		void EventMenu(Event ** event_list); // processes the event menu
		void ShowEventMenu();   // displays menu options for events
        void ShowEventFullDetails();  // displays all of the event details
        void ShowEventListDetails();     // displays event in a list format
		void DisplayEventFull(Event **event_list); //display event
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
