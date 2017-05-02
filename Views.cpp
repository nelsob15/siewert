/*
  Views - Module
  Handles the output display of how events are viewed. Currently handles a calendar view with day and month list views. 
*/



#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <limits>
#include "Views.h"
#include "calendar.h"
#include "Event.h"

using namespace std;

View::View()
{
}

void View::showCalendar(Event **event_list) //displays the events in a calendar view
{
  int monthToView;
  int yearToView;
   char dateSeparator = '/';
	
  while (cout<<"Enter month and year to show (ex. 1/2000): " && !((cin >> monthToView >> dateSeparator >> yearToView) &&  (monthToView > 0) && (monthToView < 13)))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input; please re-enter.\n";
  }

  // Call a new Calendar grid to view the events there.
  Calendar c(monthToView, yearToView);
  c.setFirstDay();
  c.print(event_list);
  cin.ignore();
}

void View::showMonthly(Event **event_list) // display events ina month view
{
  int monthToSearch;
  int yearToSearch;
  char dateSeparator = '/';

  // Make a new node to traverse.
  Event * traverse;
  traverse = *event_list;

  // Search and display events with the same month entered.
  while (cout<<"Enter month and year to show (ex. 1/2000): " && !((cin >> monthToSearch >> dateSeparator >> yearToSearch) &&  (monthToSearch > 0) && (monthToSearch < 13)))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input; please re-enter.\n";
  }

  cout << endl << "Events for: " << monthToSearch << dateSeparator << yearToSearch<< endl;
  while (traverse != NULL)
  {
    if (monthToSearch == traverse->GetMonth() && yearToSearch == traverse->GetYear())
    {
      traverse->ShowEventListDetails();
      cout << endl;
    }
    traverse = traverse->next;
  }
  cout << endl;
  cin.ignore();
}

void View::showDaily(Event **event_list) // display events in a daily view
{
  int monthToSearch, dayToSearch, yearToSearch;
  char dateSeparator = '/';

  // Make a new node to traverse.
  Event * traverse;
  traverse = *event_list;

  while (cout<<"Enter date to show: " &&
                 !((cin >> monthToSearch >> dateSeparator >> dayToSearch >> dateSeparator >> yearToSearch) &&
                 (monthToSearch > 0) && (monthToSearch < 13)))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input; please re-enter.\n";
  }

  // Search and display events with the entered date.
  cout<<"Events for: " << monthToSearch << "/" << dayToSearch << "/" << yearToSearch << endl;
  while (traverse != NULL)
  {
    if ((monthToSearch == traverse->GetMonth()) && (dayToSearch == traverse->GetDay()) && (yearToSearch == traverse->GetYear()))
    {
      traverse->ShowEventListDetails();
      cout << endl;
    }
    traverse = traverse->next;
  }
  cout << endl;
  cin.ignore();
}

void View::DefaultView(Event **event_list) // view default view
{
	Calendar c(5, 2017);
    c.setFirstDay();
    c.print(event_list);	
}

void View::ShowViewMenu() // display view menu options
{
	cout << endl;
    cout << "Select an action:" << endl;
    cout << "V - Show full month calendar" << endl;
    cout << "N - show events for the month" << endl;
	cout << "D - Show events for the day" << endl;
    cout << "X - Return to main menu" << endl << endl;
}

void View::ViewMenu(Event **event_list) // displays view menu
{
	string view_menu_input;
	char view_menu_char;
	
	cout << "------------------------------------------------" << endl;
    ShowViewMenu();
	cout << "Event Menu Selection: ";
    getline(cin, view_menu_input);
    istringstream in_string(view_menu_input);
    in_string >> view_menu_char;
	cout << endl;

	while(toupper(view_menu_char) != 'X' ) // loops until exit
    {
		switch(toupper(view_menu_char)){
			case 'V':{ // show calendar view
				showCalendar(event_list);
				break;
			}
			case 'N':{ // show month view
				showMonthly(event_list);	
				break;
			}
			case 'D':{ // show daily view
				showDaily(event_list);
				break;
			}
			case 'X': // exit back to main menu
				break;
			default:{ // invalid input
				cout << "Invalid input, try again!" << endl;
				break;
			}
		}
		cout << "------------------------------------------------" << endl;
		ShowViewMenu();
		cout << "Event Menu Selection: ";
		getline(cin, view_menu_input);
		istringstream in_string(view_menu_input);
		in_string >> view_menu_char;
		cout << endl;
	}
}
