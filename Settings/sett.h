#ifndef SETT_H
#define SETT_H

#include<iostream>
#include<cstring>
#include <sstream>
#include <string>

class Settings
{
    public:
        Settings();
        ~Settings();
        void changeDefaultView();   //change the default view
        void changeRemTimeLength(); //changes time
        void changeMenuLoc();       //changes menu location
        void changeTextColor();     //changes text color
        void changeMonth();         //change the month
        void whatChange();          //does the change
        void displayCurrent();      //display the current settings


    protected:

    private:
        int defaultView; //change to enum
        int reminderTimeLength;
        bool menuLocation;
        int textColor; //type still unknown
        int currentMonthDisplayed;
};

#endif // SETTINGS_H
