#ifndef MENU_H
#define MENU_H

#include<iostream>
#include <sstream>
#include <string>
#include "sett.h"

class Menu
{
    public:
        void getInput();                  //retrieves user input
        void displaySettings();           //displays settings
        void displayMenu();

    protected:

    private:

        bool toggleMenu;     //toggle the menu scene
        bool toggleView;     //toggle the view scene
        bool toggleSettings; //toggle the settings scene

};

#endif // MENU_H
