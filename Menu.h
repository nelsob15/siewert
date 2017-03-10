#ifndef MENU_H
#define MENU_H

#include<iostream>
#include <sstream>
#include <string>
#include "calendar.h"
#include "Event.h"
#include "Synch.h"
#include "View.h"
#include "Settings.h"

class Menu
{
    public:
        Menu();
        ~Menu();
        void displayMenu();               //displays menu for user input
        void swapView();                  //switches the view from calendar to schedule or vice verse
        void displayEvents(Event *test);  //displays the contents of the current event objects
        void displayView();               //displays the current view
        void displaySettings();           //displays settings
        void sync();                      //starts synchronization of a file
        void getInput();                  //retrieves user input

    protected:

    private:
        bool toggleEvents;   //toggles the event scene
        bool toggleMenu;     //toggle the menu scene
        bool toggleView;     //toggle the view scene
        bool toggleSettings; //toggle the settings scene
        bool toggleSync;     //toggle the sync scene
};

#endif // MENU_H
