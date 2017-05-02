
#include "menu.h"

using namespace std;

std::string intString(int i)
{

  std::stringstream ss;

  ss << i;

  return ss.str();

}

void Menu::getInput() //retrieves user input
{
    string menuInput;
    std::string default_console = "\033[" + intString(0) + "m";
    displaySettings();

}


void Menu::displaySettings() ////displays settings
{
    string settingsInput;
    Settings settingsTest;

     do
    {
    cout << "(cdf)  -- change default view" << endl;
    cout << "(cml)  -- change menu location" << endl;
    cout << "(ctc)  -- change text color" << endl;
    cout << "(exit) -- done with settings" << endl;

    cin >> settingsInput;

        if(settingsInput == "cdf")
        {
            settingsTest.changeDefaultView();
        }

        else if(settingsInput=="cml")
        {
            settingsTest.changeMenuLoc();
        }
        else if(settingsInput=="ctc")
        {
            settingsTest.changeTextColor();
        }
        else if(settingsInput=="exit")
        {
            settingsInput = "exit";
        }        
        else
        {
            cout << "Invalid Input" << endl;
        }

        //cin >> settingsInput;

    }while(settingsInput!="exit");
}
