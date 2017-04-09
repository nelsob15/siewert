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
    void showCalendar(Event **); // Display calendar view.
    void showDaily(Event **); // List events of selected day.
    void showMonthly(Event **); // List events of selected month.
};

#endif // VIEWS_H
