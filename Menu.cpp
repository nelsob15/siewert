#include "Menu.h"

using namespace std;

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void Menu::displayView() //displays the current view
{
    Calendar c;
	c.setFirstDay();
	c.print();         //displays calendar view
}

void Menu::displayMenu() //displays menu for user input
{
    cout << "-- MAIN MENU --" << endl;
	cout << "\nSelect an action below! " << endl;
	cout << "(e)    -- EVENTS" << endl;
	cout << "(v)    -- VIEWS"  << endl;
	cout << "(s)    -- SYNCRHONIZE" << endl;
	cout << "(set)  -- SETTINGS" << endl;
	cout << "(p)    -- MENU" << endl;
	cout << "(exit) -- EXIT" << endl;
}

void Menu::getInput() //retrieves user input
{
    string menuInput;

    while(menuInput != "exit")
    {
        cin >> menuInput;

        if (menuInput == "e") //if users selects to access events
        {
            Event *eventTest;// = new Event;
            string eventInput;
            string name;
            struct Time
            {
                int minutes;
                int hours;
            };
            Time time;
            struct Date
            {
                int day;
                int month;
            };
            Date date;
            string location;
            bool notifications;
            string notes;
            bool allDay;

            cout << "EVENTS!" << endl;        //displays an events menu
            cout << "(c) -- create!" << endl;
            cout << "(m) -- modify!" << endl;
            cout << "(d) -- delete!" << endl;

            cin >> eventInput;

            if(eventInput == "c")  //creates an event
            {

                cout << "Enter new event" << endl;
                cout << "Event Name" << endl;
                cin.ignore();
                getline(cin,name);
                cout << "Event Time in minutes" << endl;
                cin >> time.minutes;
                cout << "Event Time in hours" << endl;
                cin >> time.hours;
                cout << "Event day" << endl;
                cin >> date.day;
                cout << "Event month" << endl;
                cin >> date.month;
                cout << "Location" << endl;
                cin.ignore();
                getline(cin,location);
                cout << "Allow notifications!" << endl;
                cin >> notifications;
                cout << "Write a note!" << endl;
                cin.ignore();
                getline(cin,notes);
                cout << "Is this all day!" << endl;
                cin >> allDay;

                eventTest = new Event(name, time.minutes, time.hours, date.day, date.month, location, notifications, notes, allDay);
                //name, time, date, location, notifications, notes, allDay
            }
            else if(eventInput == "m")  //modifies an event
            {
                string modifyInput;

                cout << "Which field would you like to modify!" << endl;
                cout << "name" << endl;
                cout << "time" << endl;
                cout << "date" << endl;
                cout << "location" << endl;
                cout << "notifications" << endl;
                cout << "notes" << endl;
                cout << "allDay" << endl;

                cin >> modifyInput;

                if(modifyInput == "name")
                {
                    cin.ignore();
                    cout << "Enter new name!" << endl;
                    getline(cin,name);
                }
                else if(modifyInput == "time")
                {
                    cout << "Enter new minutes!" << endl;
                    cin >> time.minutes;
                    cout << "Enter new hours!" << endl;
                    cin >> time.hours;
                }
                else if(modifyInput == "date")
                {
                    cout << "Enter new day!" << endl;
                    cin >> date.day;
                    cout << "Enter new month!" << endl;
                    cin >> date.month;
                }
                else if(modifyInput == "location")
                {
                    cin.ignore();
                    cout << "Enter new location!" << endl;
                    getline(cin,location);
                }
                else if(modifyInput == "notifications")
                {
                    cout << "Allow notifications!" << endl;
                    cin >> notifications;
                }
                else if(modifyInput == "notes")
                {
                    cin.ignore();
                    cout << "Write a new note!" << endl;
                    getline(cin,notes);
                }
                else if(modifyInput == "allDay")
                {
                    cout << "Allow for allDay?" << endl;
                    cin >> allDay;
                }
                else
                {
                    cout << "Invalid Input!" << endl;
                }

                eventTest->modifyEvent(name, time.minutes, time.hours, date.day, date.month, location, notifications, notes, allDay);
            }
            else if(eventInput == "d") //deletes an event
            {
                eventTest->eventDeleted();
            }
            else
            {
                cout << "Invalid Input!" << endl;
            }

            displayEvents(eventTest);

        }
        else if (menuInput == "v") //view selects
        {
            string viewInput;
            View testView;
            cout << "VIEWS!" << endl;
            cout << "(c)  -- Current View" << endl;
            cout << "(dl) -- Display List" << endl;
            cout << "(dc) -- Display Calendar" << endl;
            cout << "(cv) -- changeView()" << endl;

            cin.ignore();
            cin >> viewInput;

            if(viewInput == "c") //displays current view
            {
                testView.currentView();
            }
            else if(viewInput == "dl") //displays list view
            {
                testView.displayList();
            }
            else if(viewInput == "dc") //displays calendar view
            {
                testView.displayCalendar();
            }
            else if(viewInput == "cv") //changes the view
            {
                testView.changeView();
            }
            else
            {
                cout << "Invalid Input" << endl;
            }

        }
        else if (menuInput == "s") //synchronize the file
        {
            sync();
        }
        else if (menuInput == "set") //displays settings
        {
            cout << "SETTINGS!" << endl;
            displaySettings();
        }
        else if (menuInput == "p")
        {
            displayMenu(); //displays the menu
        }
        else if (menuInput == "exit")
        {
            cout << "EXIT!" << endl;
        }
        else
        {
            cout << "INVALID INPUT!" << endl;
        }

        displayMenu();
    }
}

void Menu::displayEvents(Event *test) ////displays the contents of the current event objects
{
    test->showEvent();
}

void Menu::sync() ////starts synchronization of a file
{
    string file_name;

    cout << "SYNCHRONIZE!" << endl;
    cout << "Enter name of file to sync" << endl;
    Synch synchTest(file_name);
    synchTest.parseCSV();
}

void Menu::displaySettings() ////displays settings
{
    string settingsInput;
    Settings settingsTest;

    settingsTest.displayCurrent();

    cout << "(cdf)  -- change default view" << endl;
    cout << "(crtl) -- change remainder time length" << endl;
    cout << "(cml)  -- change menu location" << endl;
    cout << "(ctc)  -- change text color" << endl;
    cout << "(cm)   -- change month" << endl;
    cout << "(wc)   -- what changes" << endl;
    cout << "(dc)   -- display current " << endl;

    cin >> settingsInput;

    while(settingsInput!="exit")
    {

        if(settingsInput == "cdf")
        {
            settingsTest.changeDefaultView();
        }
        else if(settingsInput=="crtl")
        {
            settingsTest.changeRemTimeLength();
        }
        else if(settingsInput=="cml")
        {
            settingsTest.changeMenuLoc();
        }
        else if(settingsInput=="ctc")
        {
            settingsTest.changeTextColor();
        }
        else if(settingsInput=="cm")
        {
            settingsTest.changeMonth();
        }
        else if(settingsInput=="wc")
        {
            settingsTest.whatChange();
        }
        else if(settingsInput=="dc")
        {
            settingsTest.displayCurrent();
        }
        else
        {
            cout << "Invalid Input" << endl;
        }

        cin >> settingsInput;

    }
}
