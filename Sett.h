/*
  Settings Module
  Major features of this module includes changing the default view and text color
*/

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
	    void ShowSettingsMenu();    //Display view menu
	    void SettingsMenu();        //Main View menu selection
        void changeDefaultView();   //change the default view
        void changeTextColor();     //changes text color
        void changeMonth();         //change the month
        void whatChange();          //does the change
        void displayCurrent();      //display the current settings


    protected:

    private:
        int defaultView; // signals default view
        int textColor; //type still unknown
        int currentMonthDisplayed; // current month
};

#endif // SETTINGS_H
//
