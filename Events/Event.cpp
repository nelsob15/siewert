#include <iostream>
#include "Event.h"
#include <map>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

Event::Event()
{

}

void Event::EventFill(string name_new, int month_new, int day_new, int start_hour_new, int start_minute_new,
                    int m_start_new, int year_new, int end_hour_new, int end_minute_new, int m_end_new, string new_notes)
{
    name = name_new;
    date.year = year_new;
    date.month = month_new;
    date.day = day_new;
    time.start_hour = start_hour_new;
    time.start_minute = start_minute_new;
    m_start = m_start_new;
    time.end_hour = end_hour_new;
    time.end_minute = end_minute_new;
    m_end = m_end_new;
    notes = new_notes;
}

Event::~Event()
{
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
	temp->EventFill(eventName,month,day,start_hour,start_minute, meridiem_start, year,end_hour,end_minute, meridiem_end, eventNotes);

	temp2 = *head;
	temp3 = head;

	while(eventSort(temp, temp2) != 0)
	{
        temp3 = &temp2->next;
        temp2 = temp2->next;
	}
    *temp3 = temp;
    temp->next = temp2;
}

int Event::eventSort(Event * temp, Event * temp2)
{
    if(temp2 != NULL && (temp2->date.year * 10000000000 + temp2->date.month*1000000 + temp2->date.day*10000 + temp2->get_start_meridian()
          *1000 + temp2->time.start_hour*100 + temp2->time.start_minute) < (temp->date.year * 10000000000 + temp->date.month*1000000 +
          temp->date.day*10000 + temp->get_start_meridian()*1000 + temp->time.start_hour*100 + temp->time.start_minute))
        return 1;
    else
        return 0;
}

void Event::modifyEvent(Event ** head)
{
    Event * traverse;
    traverse = *head;

    string eventName;
    char date_seperator = '/', time_seperator = ':';
    int day, month, year;
    int start_minute, start_hour, end_minute, end_hour;
    string smeridiem;
    int meridiem_start, meridiem_end;
    string eventNotes;

    bool found = false;
    string modify;
    cout << "Enter name of the event you wish to modify: " << endl;
    getline(cin, modify);

    cout << endl;
    while (traverse != NULL)
	{
	    if(traverse->getName() == modify)
        {
            found = true;
            traverse->showEventDetails();

            cout << "name   -- event name" << endl;
            cout << "date   -- event date" << endl;
            cout << "start  -- event start time" << endl;
            cout << "end    -- event end time" << endl;
            cout << "notes  -- event notes" << endl;
            cout << "cancel -- go back to menu" << endl;
            cout << "What would you like to change: " << endl;
            getline(cin, modify);

            if(modify == "name")
            {
                cout << "Enter Events Name (string): ";
                getline(cin,eventName);
                traverse->name = eventName;
            }
            else if (modify == "date")
            {
                while (cout << "Enter date as day/month/year (ex 1/1/2017): " &&
                       !(cin >> month >> date_seperator >> day >> date_seperator >> year))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input; please re-enter.\n";
                }
                traverse->date.year = year;
                traverse->date.month = month;
                traverse->date.day = day;
                cin.ignore();
            }
            else if (modify == "start")
            {
                while (cout << "Enter start time in hour:time (am/pm) (ex 11:59 am): " &&
                           !(cin >> start_hour >> time_seperator >> start_minute >> smeridiem ))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input; please re-enter.\n";
                }
                if (smeridiem == "am" || smeridiem == "AM")
                {
                    traverse->m_start = 0;
                }
                else if ((smeridiem == "pm" || smeridiem == "PM"))
                {
                     traverse->m_start = 1;
                }
                traverse->time.start_hour = start_hour;
                traverse->time.start_minute = start_minute;
                cin.ignore();
            }
            else if (modify == "end")
            {
                while (cout << "Enter end time in hour:time (am/pm) (ex 11:59 am): " &&
                       !(cin >> end_hour >> time_seperator >> end_minute >> smeridiem ))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input; please re-enter.\n";
                }
                if (smeridiem == "am" || smeridiem == "AM")
                {
                   traverse->m_end = 0;
                }
                else if ((smeridiem == "pm" || smeridiem == "PM"))
                {
                   traverse->m_end = 1;
                }
                traverse->time.end_hour = end_hour;
                traverse->time.end_minute = end_minute;
                cin.ignore();
            }
            else if (modify == "notes")
            {
                cout << "Enter event notes (string): ";
                cin.ignore();
                getline(cin,eventNotes);
                traverse->notes = eventNotes;
            }

            cout << endl;
            break;
            cin.ignore();
        }
		traverse = traverse->next;
	}
	if (!found)
    {
        cout << "Event does not exit!" << endl;
    }
    cout << endl << "Event Modified!" << endl;
}

void Event::removeEvent(Event **head)
{
    Event *current;
    current = *head;

    string eventName;

    cout << "Select the name of the event you wish to delete: " << endl;
    getline(cin, eventName);

    if (current == NULL) {
        cout << "There are no more events! " << endl << endl;
        return;
    }

    if (current->name == eventName)
    {
        cout << "Deleting event: " << eventName << endl << endl;
        *head = (*head)->next;
        return;
    }

    while (current->next != NULL)
    {
        if (current->next->name == eventName)
        {
            cout << "Deleting event: " << eventName << endl << endl;
            current->next = current->next->next;
            return;
        }

        current = current->next;
    }

    cout << "Not found\n" << endl;
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
    cout << notes <<endl << endl;
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
    cout << "create - create an event" << endl;
    cout << "modify - modify an event" << endl;
    cout << "remove - remove an event" << endl;
    cout << "list   - display events of list" << endl;
    cout << "search - search for event" << endl;
    cout << "exit   - exit" << endl << endl;
}

void Event::main_event_menu()
{
    Event *head;
    head = NULL;

    string user;

    show_event_menu();
    getline(cin,user);
    cout << endl;

    while(user != "exit")
    {
        if(user == "create")
        {
            push(&head);
            cout << endl;
        }
        else if(user == "modify")
        {
            modifyEvent(&head);
            cout << endl;
        }
        else if(user == "remove")
        {
            removeEvent(&head);
        }
        else if(user == "list")
        {
            traverse(&head);
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



