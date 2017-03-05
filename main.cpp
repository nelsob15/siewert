//
// SE310 HW3 Domain Model
//
// -- prototype for interactive calendar with events
//
// This is a domain model for an event calendar. This is the first rough draft displaying functionality between methods and attributes.
//

#include<iostream>
#include<cstring>
//#include<conio.h>
#include<iomanip>
#include "calendar.h"
#include "Menu.h"

using namespace std;

int main()                    //This was to just be able to run your class...
{
    Menu menu;                // creates menu object which handles user input and interaction

    menu.displayView();       // displays default view - calendar view for this test
    menu.displayMenu();       // display option menu for user input
    menu.getInput();          // retrieves input from user

	return 0;
}
