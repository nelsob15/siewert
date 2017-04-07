#include <iostream>
#include "Event.h"
#include "Views.h"
#include <map>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

Event::Event()
{

}

void Event::EventCreate(string name_new, int month_new, int day_new, int start_hour_new, int start_minute_new,
                    int m_start_new, int year_new, int end_hour_new, int end_minute_new, int m_end_new, string new_notes)
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
    notes = new_notes;
}

Event::~Event()
{
}

void Event::modifyEvent(string name_mod, int month_mod, int day_mod, int start_hour_mod, int start_minute_mod, int m_start_mod, int year_mod,
                         int end_hour_mod, int end_minute_mod, int m_end_mod, string notes_mod)
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
    notes = notes_mod;

    cout << "Event Modified!" << endl;
}

void Event::eventDeleted() //deletes the event
{
    cout << "Event Deleted!" << endl;
}

void Event::display_meridiem(int meridian)
{
   switch(meridian)
    {
        case 0 : cout << "am";   break;
        case 1  : cout << "pm"; break;
    }
}

string Event::getName()
{
    return name;
}
int Event::getDay()
{
    return date.day;
}
int Event::getMonth()
{
    return date.month;
}
int Event::getYear()
{
    return date.year;
}
int Event::get_start_meridian()
{
    return m_start;
}

int Event::get_end_meridian()
{
    return m_end;
}

void Event::push(Event **head)
{
    //enum Meridiem {am,pm};
    //Meridiem meridiem_start, meridiem_end;
    //map<string,Meridiem> meri;
    //meri["am"] = am;
    //meri["AM"] = am;
    //meri["pm"] = pm;
    //meri["PM"] = pm;
    string smeridiem;
    int meridiem_start, meridiem_end;
    int month, day, start_hour, start_minute, end_hour, end_minute, year;
    char date_seperator = '/';
    char time_seperator = ':';
    string eventName;
    string eventNotes;

    cout << "Enter Events Name (string): ";
    getline(cin,eventName);

    while (cout << "Enter date as day/month/year (ex 1/1/2017): " &&
           !(cin >> month >> date_seperator >> day >> date_seperator >> year))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input; please re-enter.\n";
    }

    while (cout << "Enter start time in hour:time (am/pm) (ex 11:59 am): " &&
           !(cin >> start_hour >> time_seperator >> start_minute >> smeridiem ))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input; please re-enter.\n";
    }
   if (smeridiem == "am" || smeridiem == "AM")
   {
       meridiem_start = 0;
   }
   else if ((smeridiem == "pm" || smeridiem == "PM"))
   {
       meridiem_start = 1;
   }
   else
   {
       cout << "Error!" << endl;
   }

    while (cout << "Enter end time in hour:time (am/pm) (ex 11:59 am): " &&
           !(cin >> end_hour >> time_seperator >> end_minute >> smeridiem ))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input; please re-enter.\n";
    }
    if (smeridiem == "am" || smeridiem == "AM")
    {
       meridiem_end = 0;
    }
    else if ((smeridiem == "pm" || smeridiem == "PM"))
    {
       meridiem_end = 1;
    }
    else
    {
       cout << "Error!" << endl;
    }

    cout << "Enter event notes (string): ";
    cin.ignore();
    getline(cin,eventNotes);

    //cout << endl << endl;

	Event *temp, *temp2, **temp3;
	temp = new Event;
	temp->EventCreate(eventName,month,day,start_hour,start_minute, meridiem_start, year,end_hour,end_minute, meridiem_end, eventNotes);

	temp2 = *head;
	temp3 = head;

	while(temp2 != NULL && (temp2->date.year * 10000000000 + temp2->date.month*1000000 + temp2->date.day*10000 + temp2->get_start_meridian()
          *1000 + temp2->time.start_hour*100 + temp2->time.start_minute) < (temp->date.year * 10000000000 + temp->date.month*1000000 +
          temp->date.day*10000 + temp->get_start_meridian()*1000 + temp->time.start_hour*100 + temp->time.start_minute))
	{
        temp3 = &temp2->next;
        temp2 = temp2->next;
	}
    *temp3 = temp;
    temp->next = temp2;
}

void Event::traverse(Event **head)
{
    Event * traverse;
    traverse = *head;

	cout << "List View" << endl << endl;

	while (traverse != NULL)
	{
    traverse->showEventList();
		cout << endl;
		traverse = traverse->next;
	}
	cout << endl;
}

void Event::display_event(Event **head)
{
    bool found = false;
    string user;
    Event * traverse;
    traverse = *head;

    cout << "Enter event name to display event details: " << endl;
    cin >> user;

    cout << endl;
    while (traverse != NULL)
	{
	    if(traverse->getName() == user)
        {
            found = true;
            traverse->showEventDetails();
            cout << endl;
        }
		traverse = traverse->next;
	}
	if (!found)
    {
        cout << "Event does not exit!" << endl;
    }
	cout << endl;
}

void Event::showEventDetails() //displays the event
{
    cout << name << endl;
    cout << date.month << "/" << date.day << "/" << date.year << endl;

    if (time.start_minute < 10)
        cout << time.start_hour << ":" << "0" << time.start_minute << " ";
    else
        cout << time.start_hour << ":" << time.start_minute << " ";
    display_meridiem(m_start);

    if (time.end_minute < 10)
        cout << " - " << time.end_hour << ":" << "0" << time.end_minute << " ";
    else
       cout << " - " << time.end_hour << ":" << time.end_minute << " ";
    display_meridiem(m_end);

    cout << endl << "Notes:" << endl;
    cout << notes <<endl;
    cout << endl;

}

void Event::showEventList() //displays the event
{
    cout << name << endl;
    cout << date.month << "/" << date.day << "/" << date.year << endl;

    if (time.start_minute < 10)
        cout << time.start_hour << ":" << "0" << time.start_minute << " ";
    else
        cout << time.start_hour << ":" << time.start_minute << " ";
    display_meridiem(m_start);

    if (time.end_minute < 10)
        cout << " - " << time.end_hour << ":" << "0" << time.end_minute << " ";
    else
       cout << " - " << time.end_hour << ":" << time.end_minute << " ";
    display_meridiem(m_end);
    cout << endl;
}

void Event::show_event_menu()
{
    cout << "Select an action:" << endl;
    cout << "create   - create an event" << endl;
    cout << "list     - display events of list" << endl;
    cout << "monthly  - display events of the month" << endl;
    cout << "daily    - display events of the day" << endl;
    cout << "calendar - show full month calendar" << endl;
    cout << "search   - search for event" << endl;
    cout << "exit     - exit" << endl << endl;
}

void Event::main_event_menu()
{
    Event *head;
    head = NULL;
    View testView; // Create a View object to display events

    string user;

    show_event_menu();
    getline(cin,user);
    cout << endl << endl;

    while(user != "exit")
    {
        if(user == "create")
        {
            push(&head);

            cout << endl;
        }
        else if(user == "list")
        {
            // all events
            cout << "Full list: " << endl;
            traverse(&head);            
        }
        else if(user == "monthly")
        {
            // all events for a month
            cout << "Monthly list: " << endl;
            testView.showMonthly(&head);
            cin.ignore();        
        }
        else if(user == "daily")
        {
            // all events for a day
            cout << "Daily list: " << endl;
            testView.showDaily(&head);
            cin.ignore();      
        }
        else if(user == "calendar")
        {
            // show the calendar grid
            testView.showCalendar(&head);
            cin.ignore();
        }
        else if(user == "search")
        {
            display_event(&head);
            cin.ignore();
        }
        else
            cout << "Invalid input, try again!" << endl;

        show_event_menu();
        getline(cin,user);
        cout << endl;
    }
}



