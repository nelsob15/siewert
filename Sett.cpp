/*
  Settings Module
  Major features of this module includes changing the default view and text color
*/

#include "Sett.h"
#include<iostream>
using namespace std;

Settings::Settings()
{
	
}

Settings::~Settings()
{
	
}

std::string intToString(int i)
{

  std::stringstream ss;

  ss << i;

  return ss.str();

} //change text color

void Settings::changeDefaultView() //change the default view
{
    string choiceView;
    
    //Gets User Input for Default View
    do{
    
    cout<<"What view would you like?"<<endl;
    cout<<"(c)    --Calendar View"<<endl;
    cout<<"(list) --List View"<<endl;
    cin>>choiceView;
    }while((choiceView!="c") && (choiceView!="list"));
    
    //Checks user input. If invaild will display comment on the failure.
    if(choiceView == "c")
    {
    cout<<"Calendar View Displayed"<<endl;
    cout<<"View changed successfully"<<endl;
    }
    else if(choiceView == "list")
    {
    cout<<"List View Displayed"<<endl;
    cout<<"View changed successfully"<<endl;
    }
    else
    {
    cout<<"View change failed"<<endl;
    }
    
}

void Settings::changeTextColor() //changes text color
{
	int colorChoice;
      std::string default_console = "\033[" + intToString(0) + "m";
//Gets User Input for change of color
do{
      cout<<"What Color do you want?"<<endl;
      cout<<"(30)  --Black"<<endl;
      cout<<"(31)  --Red"<<endl;
	  cout<<"(32)  --Green"<<endl;
	  cout<<"(33)  --Yellow"<<endl;
	  cout<<"(34)  --Purple"<<endl;
	  cout<<"(35)  --Pink"<<endl;
	  cout<<"(36)  --Blue"<<endl;
      cout<<"(37)  --White"<<endl;
      cout<<"(38)  --Default"<<endl;
      cout<<"(39)  --Exit"<<endl;


      }while((29 > colorChoice) && (colorChoice > 40));

			cin>> colorChoice; 
      cin.ignore();
      
  /*Color code based off of source code from http://www.dreamincode.net/forums/topic/335483-outputting-colors-in-c-putty-using-linux/ */
    //Checks user input. If invaild will display comment on the failure.
    if((29 < colorChoice) && (colorChoice < 38))
    {
    std::string color = "\033[0;" + intToString(colorChoice) + "m";
    std::cout << color << "Color has been changed " << std::endl;  
    }
    else if(colorChoice == 38)
    {
        std::cout << default_console << std::endl;
        cout << "Color has been changed " <<endl;  
    }
    else if(colorChoice == 39)
    {
    cout << "Do Nothing" <<endl;
    }
    else
    {
    cout<<"Color Change Failed"<<endl;
    }

}

void Settings::ShowSettingsMenu()   //Display settings menu
{
	cout << endl;
    cout << "Select an action:" << endl;
    cout << "T - Show Text Color" << endl;
	cout << "V - Change the default view" << endl;
    cout << "X - Return to main menu" << endl << endl;	
}

void Settings::SettingsMenu()   //Main seetings menu selection
{
	string setting_menu_input;
	char setting_menu_char;
	
	cout << "------------------------------------------------" << endl;
    ShowSettingsMenu();
	cout << "Settings Menu Selection: ";
    getline(cin, setting_menu_input);
    istringstream in_string(setting_menu_input);
    in_string >> setting_menu_char;
	cout << endl;

    while(toupper(setting_menu_char) != 'X' )
    {
		switch(toupper(setting_menu_char))
		{
			case 'T':{
				changeTextColor(); // changes text color of events in the calendar view
				break;
			}
			case 'V':{
				
				break;
			}
			case 'X':{
				break;
			}
			default:{
			    cout << "Invalid Output, Try again!" << endl;
				break;
			}
		}
		
		cout << "------------------------------------------------" << endl;
		ShowSettingsMenu();
		cout << "Settings Menu Selection: ";
        getline(cin, setting_menu_input);
        istringstream in_string(setting_menu_input);
        in_string >> setting_menu_char;
		cout << endl;
	}
}

