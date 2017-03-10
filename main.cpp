#include <iostream>
#include "Event.h"
#include <map>
#include <sstream>

using namespace std;

enum Meridiem {am,pm};

void push(Event **head)
{
    string eventName;
    int month;
    int day;
    int start_hour;
    int start_minute;
    int end_hour;
    int end_minute;
    int year;

    Meridiem meridiem_start, meridiem_end;
    std::map<std::string,Meridiem> meri;
    meri["am"] = am;
    meri["pm"] = pm;
    std::string smeridiem;

    cout << "Event Events Name (string): ";
    getline(cin,eventName);
    cout << "Enter month (int): ";
    cin >> month;
    cout << "Enter days (int): ";
    cin >> day;
    cout << "Enter year (int): ";
    cin >> year;
    cout << "Enter start time in hours (int): ";
    cin >> start_hour;
    cout << "Enter start time in minutes (int): ";
    cin >> start_minute;
    cout << "Enter start AM/PM (enum: am/pm): ";
    cin >> smeridiem;
    meridiem_start = meri[smeridiem];
    cout << "Enter end time in hours (int): ";
    cin >> end_hour;
    cout << "Enter end time in minutes (int): ";
    cin >> end_minute;
    cout << "Enter end AM/PM (enum: am/pm): ";
    cin >> smeridiem;
    meridiem_end = meri[smeridiem];
    cout << endl;

	Event *temp, *temp2, **temp3;
	temp = new Event;
	temp->EventCreate(eventName,month,day,start_hour,start_minute, meridiem_start, year,end_hour,end_minute, meridiem_end);

	temp2 = *head;
	temp3 = head;

	while(temp2 != NULL && (temp2->date.year * 10000000000 + temp2->date.month*1000000 + temp2->date.day*10000 + temp2->m_start*1000 +
          temp2->time.start_hour*100 + temp2->time.start_minute) < (temp->date.year * 10000000000 + temp->date.month*1000000 +
          temp->date.day*10000 + temp->m_start*1000 + temp->time.start_hour*100 + temp->time.start_minute))
	{
        temp3 = &temp2->next;
        temp2 = temp2->next;
	}
    *temp3 = temp;
    temp->next = temp2;
}
//(temp2->time.start_hour*1000 + temp2->time.start_minute) < (temp->time.start_hour*1000 + temp->time.start_minute)

void traverse(Event **head)
{
    Event * traverse;

    traverse = *head;

	cout << "List View" << endl << endl;

	while (traverse != NULL)
	{
	    //if(traverse->next != NULL && traverse->date.month == traverse->next->date.month && traverse->date.day == traverse->next->date.day)
        //    traverse->showEventList();
        //else
        //{
            //cout << traverse->date.month << "/" << traverse->date.day << endl;
            traverse->showEventList();
        //}
		cout << endl;
		traverse = traverse->next;
	}
	cout << endl;
}

void display_event(Event **head)
{
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
            traverse->showEvent();
            cout << endl;
        }
		traverse = traverse->next;
	}
	cout << endl;
}


void menu()
{
    cout << "Select an action:" << endl;
    cout << "create - create an event" << endl;
    cout << "list   - display events of list" << endl;
    cout << "search - search for event" << endl;
    cout << "exit   - exit" << endl << endl;
}

int main()
{
    Event *head;
    head = NULL;

    string user;

    menu();
    getline(cin,user);
    cout << endl << endl;

    while(user != "exit")
    {
        if(user == "create")
        {
            push(&head);

            cin.ignore();
            menu();
        }
        else if(user == "list")
        {
            traverse(&head);
            menu();
        }
        else if(user == "search")
        {
            display_event(&head);
            cin.ignore();
            menu();
        }
        else
            cout << "Invalid input, try again!" << endl;

        getline(cin,user);
        cout << endl;
    }

    return 0;
}
