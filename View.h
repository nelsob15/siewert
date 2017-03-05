#ifndef VIEW_H
#define VIEW_H

#include<iostream>
#include "calendar.h"

class View
{
    public:
        View();
        ~View();
        void currentView();     //displays current view
        void displayList();     //displays list view
        void displayCalendar(); //display calendar view
        void changeView();      //change view
    protected:

    private:
        int default_view; //enum
        int current;      //enum
};

#endif // VIEW_H
