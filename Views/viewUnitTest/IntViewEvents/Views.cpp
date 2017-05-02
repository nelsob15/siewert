#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <limits>
#include "Views.h"
#include "calendar.h"
#include "Event.h"

#define TESTMODE (1)
#define MONTH (4)
#define YEAR (2017)
#define DAY (14)
using namespace std;

View::View()
{
}

void View::showCalendar(Event **head)
{
  int monthToView = MONTH;
  int yearToView = YEAR;
  
  if(TESTMODE == 0)
  {
    while (cout<<"Enter month to view: " && !((cin >> monthToView) && (monthToView > 0) && (monthToView < 13)))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input; please re-enter.\n";
    }
    while (cout<<"Enter year to view: " && !((cin >> yearToView) && (yearToView > 1968)))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input; please re-enter.\n";
    }
  } 
  // Call a new Calendar grid to view the events there.
  Calendar c(monthToView, yearToView);
  c.setFirstDay();
  c.print(head);
  //cin.ignore();
}

void View::showDaily(Event **head)
{
  int monthToSearch = MONTH, dayToSearch = DAY, yearToSearch = YEAR;
  char dateSeparator = '/';

  // Make a new node to traverse.
  Event * traverse;
  traverse = *head;
  if (TESTMODE == 0)
  {
    while (cout<<"Enter date to show: " &&
                 !((cin >> monthToSearch >> dateSeparator >> dayToSearch >> dateSeparator >> yearToSearch) &&
                 (monthToSearch > 0) && (monthToSearch < 13)))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input; please re-enter.\n";
    }
  }

  // Search and display events with the entered date.
  cout<<"Events for: " << monthToSearch << "/" << dayToSearch << "/" << yearToSearch << endl;
  while (traverse != NULL)
  {
    if ((monthToSearch == traverse->getMonth()) && (dayToSearch == traverse->getDay()) && (yearToSearch == traverse->getYear()))
    {
      traverse->ShowEventListDetails();
      cout << endl;
    }
    traverse = traverse->next;
  }
  cout << endl;
  //cin.ignore();
}

void View::showMonthly(Event **head)
{
  int monthToSearch = MONTH;
  int yearToSearch = YEAR;
  char dateSeparator = '/';

  // Make a new node to traverse.
  Event * traverse;
  traverse = *head;

  // Search and display events with the same month entered.
  if(TESTMODE == 0)
  {
    while (cout<<"Enter month to show: " && !((cin >> monthToSearch >> dateSeparator >> yearToSearch) &&  (monthToSearch > 0) && (monthToSearch < 13)))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input; please re-enter.\n";
    }
  }
  cout << "Events for: " << monthToSearch << dateSeparator << yearToSearch<< endl;
  while (traverse != NULL)
  {
    if (monthToSearch == traverse->getMonth() && yearToSearch == traverse->getYear())
    {
      traverse->ShowEventListDetails();
      cout << endl;
    }
    traverse = traverse->next;
  }
  cout << endl;
  //cin.ignore();
}
