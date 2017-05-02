/*
The MyCalendar application prototype
  The event module below is in change of Event interaction wether from an external file or from the user. The 3 main features present in this module is 
  event creation, event modification, and event deletion. This includes some error handling features for user input as well as detecting objects
  that are currently in the list or not in the list at all. The code is not 100% as not covering full path coverage nor is error handling robust to
  handle all errors
*/

#include <iostream>
#include "Event.h"
#include "Views.h"
#include <map>
#include <sstream>
#include <iomanip>
#include <limits>

#define YEAR_MULTIPLIER 10000000000
#define MONTH_MULTIPLIER 1000000
#define DAY_MULTIPLIER 10000
#define MERIDIAN_MULTIPLIER 1000
#define HOUR_MULTIPLIER 100

using namespace std;

Event::Event() 
{

}

// Fills the new event instance with event attributes
void Event::EventFill(string name_new, string location_new,int month_new, int day_new, int year_new, int start_hour_new, int start_minute_new,
                    int meridian_start_new, int end_hour_new, int end_minute_new, int meridian_end_new, string new_notes)
{
    name = name_new;
	location = location_new;
    date.year = year_new;
    date.month = month_new;
    date.day = day_new;
    time.start_hour = start_hour_new;
    time.start_minute = start_minute_new;
    time.meridian_start = meridian_start_new;
    time.end_hour = end_hour_new;
    time.end_minute = end_minute_new;
    time.meridian_end = meridian_end_new;
    notes = new_notes;
}

Event::~Event()
{
}

void Event::DisplayMeridian(int meridian) // displays either am or pm
{
   switch(meridian){
        case 0 : cout << "am"; break;
        case 1 : cout << "pm"; break;
    }
}

string Event::GetName() // gets the event name
{
    return name;
}

string Event::GetLocation()// gets event location
{
    return location;
}

int Event::GetDay() // gets event day
{
    return date.day;
}

int Event::GetMonth() // gets event month
{
    return date.month;
}

int Event::GetYear() // gets event year
{
    return date.year;
}

int Event::GetStartHour() // gets event start hour
{
    return time.start_hour;	
}

int Event::GetStartMinute() // gets event start minutes
{
    return time.start_minute;	
}

string Event::GetStartMeridian()// get events start meridian
{
    if(ReadStartMeridian())
        return "PM";
    else
        return "AM";		
}

int Event::GetEndHour() // gets events end hour
{
    return time.end_hour;	
}

int Event::GetEndMinute() // gets event end minute
{
    return time.end_minute;	
}

string Event::GetEndMeridian() // gets event end meridian
{
    if(ReadEndMeridian())
        return "PM";
    else
        return "AM";		
}
string Event::GetNotes() // gets notes
{
    return notes;	
}

void Event::CreateEvent(Event **event_list) // start event creation process
{
    int meridian_start, meridian_end;
    int month, day, year, start_hour, start_minute, end_hour, end_minute;
	string all_day;
	char all_day_char;
    string event_name, event_location, event_notes, smeridian;

    cout << "Enter event name (string): "; // new event name
    getline(cin,event_name);

	cout << "Enter event location (string): "; // new event location
    getline(cin,event_location);

    GetDate(&month, &day, &year); //gets the event date data

	cout << "Is the event all day? (Y - Yes / N - No): ";
	cin >> all_day_char;

	if(toupper(all_day_char) == 'Y'){ // handling all day event
		start_hour = 12;
		start_minute = 0;
		meridian_start = 0;
		end_hour = 11;
		end_minute = 59;
		meridian_end = 1;
	}
	else{
		do{
			GetStartTime(&start_hour, &start_minute, &meridian_start); // new start time
			GetEndTime(&end_hour, &end_minute, &meridian_end); // new end time
		}while(!EndVsStartTime(start_hour, start_minute, meridian_start, meridian_end, end_hour, end_minute)); // end time before start time
	}
	cin.ignore();

    cout << "Enter event notes (string): "; // gets notes
    getline(cin,event_notes);

	// creates the new completed event
	Event *temp, *temp2, **temp3;
	temp = new Event;
	temp->EventFill(event_name,event_location,month,day,year, start_hour,start_minute, meridian_start, end_hour,end_minute, meridian_end, event_notes);

	temp2 = *event_list;
	temp3 = event_list;

	// sorts the event list by start time to the minute precision
	while(EventSort(temp, temp2) != 0){
        temp3 = &temp2->next;
        temp2 = temp2->next;
	}
    *temp3 = temp;
    temp->next = temp2;
	
	cout << endl << "Event successfully created!" << endl << endl;
}

void Event::GetDate(int * month, int * day, int * year) // processess a new date with error handling
{
	char date_seperator1 = '/';
    char date_seperator2 = '/';

	while ((cout << "Enter date as day/month/year (ex 1/1/2017): " && !(cin >> *month >> date_seperator1 >> *day >> date_seperator2 >> *year))
       || date_seperator1 != '/' || date_seperator2 != '/' || (*month <= 0 || *month >= 13 ) || (*year <= 1969 || *year >= 3000)
	   || (*day <= 0 || *day >= 32 || (*day == 31 && (*month == 4 || *month == 6 || *month == 9 || *month == 11))
	   || ((*day >= 29 && *month == 2) && (*year%4 != 0) )))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Date! Please re-enter in gregorian date format with forward slashes in between month, day, and year. " << endl;
    }
}

bool Event::ValidDate(int month, int day, int year) // verifies teh date is correct by itself within expected parameters
{
    if (month <= 0 || month >= 13 )
        return 0;
    if (year <= 1969 || year >= 3000)
        return 0;
    if (day <= 0 || day >= 32 || (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) || ((day >= 29 && month == 2) && (year%4 != 0 && year%100 != 0) ))
        return 0;
    return 1;
}

void Event::GetStartTime(int * start_hour, int * start_minute, int * meridian_start) // verifiies a valid start time
{
	string smeridian;
	char time_seperator = ':';

	while ((cout << "Enter start time in hour:time (am/pm) (ex 11:59 am): " && !(cin >> *start_hour >> time_seperator >> *start_minute >> smeridian ))
        || time_seperator != ':' || (*start_hour <= 0 || *start_hour >= 13) || (*start_minute < 0 || *start_minute >= 60)
	    || (smeridian != "am" && smeridian != "AM" && smeridian != "pm" && smeridian != "PM"))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Start Time! Please re-enter in a civilian date format with meridian." << endl;
    }
    if (smeridian == "am" || smeridian == "AM")
        *meridian_start = 0;
    else
        *meridian_start = 1;
}

void Event::GetEndTime(int * end_hour, int * end_minute, int * meridian_end) // verifies a valid end time
{
	string smeridian;
	char time_seperator = ':';

	while ((cout << "Enter end time in hour:time (am/pm) (ex 11:59 am): " && !(cin >> *end_hour >> time_seperator >> *end_minute >> smeridian ))
        || time_seperator != ':' || (*end_hour <= 0 || *end_hour >= 13) || (*end_minute < 0 || *end_minute >= 60)
	    || (smeridian != "am" && smeridian != "AM" && smeridian != "pm" && smeridian != "PM"))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Start Time! Please re-enter in a civilian date format with meridian." << endl;
    }
   if (smeridian == "am" || smeridian == "AM")
       *meridian_end = 0;
   else
       *meridian_end = 1;
}

int Event::ReadStartMeridian() // returns start meridian
{
    return time.meridian_start;
}

int Event::ReadEndMeridian() // returns end meridian
{
    return time.meridian_end;
}

bool Event::ValidTime(int hour, int minute, string meridian) // flag for valid time
{
    if (hour <= 0 || hour >= 13)
        return 0;
    if (minute < 0 || minute >= 60)
        return 0;
    if(meridian != "am" && meridian != "AM" && meridian != "pm" && meridian != "PM")
        return 0;
    return 1;
}

bool Event::EndVsStartTime(int start_hour, int start_minute, int meridian_start, int meridian_end, int end_hour, int end_minute) // verifies start time before end time
{
	if (start_hour == 12)
		start_hour = 0;
    if (end_hour == 12)
		end_hour = 0;
    if (meridian_start * MERIDIAN_MULTIPLIER + start_hour * HOUR_MULTIPLIER + start_minute >=
        meridian_end * MERIDIAN_MULTIPLIER + end_hour * HOUR_MULTIPLIER + end_minute)
	{
		cout << "Start time must come before end time, try again!" << endl;
        return 0;
	}

    return 1;
}

int Event::EventSort(Event * temp, Event * temp2) // sorts through event list by minute precision
{
    if(temp2 != NULL && (temp2->date.year * YEAR_MULTIPLIER + temp2->date.month * MONTH_MULTIPLIER + temp2->date.day * DAY_MULTIPLIER + temp2->ReadStartMeridian()
          * MERIDIAN_MULTIPLIER + (temp2->time.start_hour%12) * HOUR_MULTIPLIER + temp2->time.start_minute) < (temp->date.year * YEAR_MULTIPLIER + temp->date.month * MONTH_MULTIPLIER +
          temp->date.day * DAY_MULTIPLIER + temp->ReadStartMeridian() * MERIDIAN_MULTIPLIER + (temp->time.start_hour%12) * HOUR_MULTIPLIER + temp->time.start_minute))
        return 1;
    else
        return 0;
}

void Event::ModifyEvent(Event ** event_list) // modify event process
{
    Event * traverse;
    traverse = *event_list;

    string event_name, event_location;
    int day, month, year;
    int start_minute, start_hour, end_minute, end_hour;
    string smeridian;
    int meridian_start, meridian_end;
    string eventNotes;

    bool found = false;

    char eventModChar;
    string userInEventModify;

	// selects event to modify
    cout << "Enter name of the event you wish to modify: ";
    getline(cin, userInEventModify);

    istringstream in_string(userInEventModify);
    in_string >> eventModChar;
	cout << endl;


    cout << endl;
    while (traverse != NULL){
	    if(traverse->GetName() == userInEventModify){ // traverses until event is found and modify the selected attributes
            found = true;
            traverse->ShowEventFullDetails();
			cout << endl;

            cout << "N  -- event name" << endl;
			cout << "L  -- event location" << endl;
            cout << "D  -- event date" << endl;
			cout << "T  -- event start and end times" << endl;
            cout << "W  -- event notes" << endl;
            cout << "X  -- go back to menu" << endl;
            cout << "What would you like to change: " << endl;

			if(*event_list == NULL){
				cout << "There are no events no modify!" << endl;
			    return;
			}

            getline(cin, userInEventModify);
			istringstream in_string(userInEventModify);
            in_string >> eventModChar;

            switch(toupper(eventModChar)){
				case 'N':{
					cout << "Enter Events Name (string): ";
					getline(cin,event_name);
					traverse->name = event_name;
					break;
				}
				case 'L':{
					cout << "Enter event location (string): ";
					getline(cin,event_location);
					traverse->location = event_location;
				    break;
				}
				case 'D':{

					GetDate(&month, &day, &year); //gets the event date data
					traverse->date.year = year;
					traverse->date.month = month;
					traverse->date.day = day;
					cin.ignore();
					break;
				}
				case 'T':{
					do{
					GetStartTime(&start_hour, &start_minute, &meridian_start);
					GetEndTime(&end_hour, &end_minute, &meridian_end);
					}while(!EndVsStartTime(start_hour, start_minute, meridian_start, meridian_end, end_hour, end_minute));
					traverse->time.start_hour = start_hour;
					traverse->time.start_minute = start_minute;
					traverse->time.end_hour = end_hour;
					traverse->time.end_minute = end_minute;
					cin.ignore();
					break;
				}
				case 'W':{
					cout << "Enter event notes (string): ";
					//cin.ignore();
					getline(cin,eventNotes);
					traverse->notes = eventNotes;
					break;
				}
				case 'X':
				    break;
				default:{
				    cout << "Invalid Input!" << endl;
					break;
				}
			}

            cout << endl;
            break;
            cin.ignore();
        }
		traverse = traverse->next;
	}
	if (!found)
        cout << "Event does not exit!" << endl;

	ReOrderEvents(event_list);
    cout << endl << "Event successfully modified!" << endl << endl;
}

void Event::ReOrderEvents(Event **event_list) // reorders the event list
{
    Event *temp = *event_list;
    *event_list = NULL;

    while (temp)
    {
        Event **lhs = &temp;
        Event **rhs = &temp->next;
        bool swapped = false;


        while (*rhs){
            if (EventSort(*lhs, *rhs)){
                std::swap(*lhs, *rhs);
                std::swap((*lhs)->next, (*rhs)->next);
                lhs = &(*lhs)->next;
                swapped = true;
            }
            else{
                lhs = rhs;
                rhs = &(*rhs)->next;
            }
        }
        *rhs = *event_list;

        if (swapped){
            *event_list = *lhs;
            *lhs = NULL;
        }
        else{
            *event_list = temp;
            break;
        }
    }
}

void Event::RemoveEvent(Event **event_list) // removes the event from the list and frees the memory
{
    Event *current;
    current = *event_list;

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
        *event_list = (*event_list)->next;
        return;
    }

    while (current->next != NULL)
    {
        if (current->next->name == eventName)
        {
            cout << "Deleting event: " << eventName << endl << endl;
            current->next = current->next->next;
			delete current;
            return;
        }

        current = current->next;
    }

    cout << endl << "Event successfully modified!" << endl << endl;
}

void Event::Traverse(Event **event_list) // traverses from the linked list
{
    Event * traverse;
    traverse = *event_list;

	cout << "List View:" << endl << endl;
	cout << "---------------------" << endl;

	while (traverse != NULL)
	{
        traverse->ShowEventListDetails();
		cout << endl;
		traverse = traverse->next;
	}
}

void Event::ClearList(Event ** event_list) // deletes the whole list and frees up memory
{
	Event *current = *event_list;

    while (current != NULL) {
        *event_list = (*event_list)->next;
        delete current;
        current = *event_list;
    }
    *event_list = NULL;
}

void Event::DisplayEventFull(Event **event_list) // display all event details for selected event
{
    bool found = false;
    string user;
    Event * traverse;
    traverse = *event_list;

    cout << "Enter event name to display event details: ";
    cin >> user;

    cout << endl;
    while (traverse != NULL)
	{
	    if(traverse->GetName() == user)
        {
            found = true;
            traverse->ShowEventFullDetails();
            cout << endl;
        }
		traverse = traverse->next;
	}
	if (!found)
        cout << "Event does not exit!" << endl;

	cout << endl;
	cin.ignore();
}

void Event::ShowEventFullDetails() //displays the event
{
    cout << name << endl;
	cout << location << endl;
    cout << date.month << "/" << date.day << "/" << date.year << endl;

    if (time.start_minute < 10)
        cout << time.start_hour << ":" << "0" << time.start_minute << " ";
    else
        cout << time.start_hour << ":" << time.start_minute << " ";
    DisplayMeridian(time.meridian_start);

    if (time.end_minute < 10)
        cout << " - " << time.end_hour << ":" << "0" << time.end_minute << " ";
    else
       cout << " - " << time.end_hour << ":" << time.end_minute << " ";
    DisplayMeridian(time.meridian_end);

    cout << endl << "Notes:" << notes << endl ;
}

void Event::ShowEventListDetails() //displays the event
{
    cout << name << endl;
    cout << date.month << "/" << date.day << "/" << date.year << endl;

    if (time.start_minute < 10)
        cout << time.start_hour << ":" << "0" << time.start_minute << " ";
    else
        cout << time.start_hour << ":" << time.start_minute << " ";
    DisplayMeridian(time.meridian_start);

    if (time.end_minute < 10)
        cout << " - " << time.end_hour << ":" << "0" << time.end_minute << " ";
    else
       cout << " - " << time.end_hour << ":" << time.end_minute << " ";
    DisplayMeridian(time.meridian_end);
    cout << endl;
}

void Event::ShowEventMenu() // event menu options
{
	cout << endl;
    cout << "Select an action:" << endl;
    cout << "C - Create an event" << endl;
    cout << "M - Modify an event" << endl;
    cout << "R - Remove an event" << endl;
    cout << "L - Display events of list" << endl;
    cout << "S - Search for event" << endl;
    cout << "X - Return to main menu" << endl << endl;
}

void Event::EventMenu(Event ** event_list) // event menu
{
	string event_menu_input;
	char event_menu_char;
	
	cout << "------------------------------------------------" << endl;
    ShowEventMenu();
	cout << "Event Menu Selection: ";
    getline(cin, event_menu_input);
    istringstream in_string(event_menu_input);
    in_string >> event_menu_char;
	cout << endl;

    while(toupper(event_menu_char) != 'X' )
    {
		switch(toupper(event_menu_char))
		{
			case 'C':{ // create an event
				CreateEvent(event_list);
				break;
			}
			case 'M':{ // modify an event
				ModifyEvent(event_list);
				break;
			}
			case 'R':{ // remove an event
				RemoveEvent(event_list);
				break;
			}
			case 'L':{ // traverse an event
			    Traverse(event_list);
				break;
			}
			case 'S':{ // display event details
				DisplayEventFull(event_list);
				break;
			}
			case 'X':{ // exits
				break;
			}
			default:{ // invalid input
			    cout << "Invalid Output, Try again!" << endl;
				break;
			}
		}
		
		cout << "------------------------------------------------" << endl;
		ShowEventMenu();
		cout << "Event Menu Selection: ";
        getline(cin, event_menu_input);
        istringstream in_string(event_menu_input);
        in_string >> event_menu_char;
		cout << endl;
	}
}
