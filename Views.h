/*
  Views - Module
  Handles the output display of how events are viewed. Currently handles a calendar view with day and month list views. 
*/


#ifndef VIEWS_H
#define VIEWS_H

#include<iostream>
#include<cstring>
#include "Event.h"

class View
{
  friend class Event; // For use of Events linked list.

  private:
  Event head;
  // View class does not contain its own private fields
  // since it only needs manipulate the Event class'
  // linked list. It is purely for displaying information.

  public:
    View();
	void ShowViewMenu();   //Display view menu
	void ViewMenu(Event **); //Main View menu selection
    void showCalendar(Event **); // Display calendar view.
    void showDaily(Event **); // List events of selected day.
    void showMonthly(Event **); // List events of selected month.
	void DefaultView(Event **); // Displays the default view
};

#endif // VIEWS_H
