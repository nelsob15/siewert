//
// SE310 HW3 Domain Model
//
/* -- prototype for interactive calendar with events
  Below is a representation of our MyCalendar prototype that is an event calendar application. This file represents the menu file that acts as a directory
  to the other 4 modules of our program. It starts by loading previous saved events from the Event Log and parses them to the event list. After which the 
  user will be able to select the desired action and continue entering input until program exit, at which point saves the session's events for the next
  session.
*/


#include<iostream>
#include "Event.h" //Event selection
#include "Views.h" //View selection
#include "File.h"  //File selection
#include "Sett.h"  //Settings selection

void ShowMenu() //Displays Main Menu to screen for user selection
{
	std::cout << std::endl;
    std::cout << "Select an action:" << std::endl;
    std::cout << "E - Events" << std::endl;
    std::cout << "V - event_list" << std::endl;
    std::cout << "F - File Synch" << std::endl;
    std::cout << "S - Settings" << std::endl;
    std::cout << "X - Exit" << std::endl << std::endl;
}

int main()                    //This was to just be able to run your class...
{
    Event *event_list; // create event list
    event_list = NULL;
    View views;   // construct views instance
	File files;   // construct files instances
    Settings set; // construct settings instance

    std::string menu_input;
	char menu_char;
	
	std::cout << std::endl << "Loading events please wait ... " << std::endl;
	files.FileLoad(&event_list); // loads files from event log
	std::cout << "Events done loading, now starting application" << std::endl;
	
	views.DefaultView(&event_list); // displays default view for events
	
	std::cout << "------------------------------------------------" << std::endl;
    ShowMenu(); // display menu options
	std::cout << "Menu Selection: ";
    getline(std::cin, menu_input); // prompt for user input for menu options
    std::istringstream in_string(menu_input);
     in_string >> menu_char;
	std::cout << std::endl;
	
    while(toupper(menu_char) != 'X' ) { // program continues until program exit
	    switch(toupper(menu_char)){
			case 'E':{
			    event_list->EventMenu(&event_list); // switches to Event Menu
			    break;
			}
			case 'V':{
			    views.ViewMenu(&event_list);	// switches to view Menu
				break;
			}
			case 'F':{
				files.FileSynch(&event_list); // switches to Synchronization
				break;
			}
			case 'S':{
				set.SettingsMenu(); // switches to settings menu
				break;
			}
			case 'X':
			    break;  // do nothing and wait for exit
			default:{
				std::cout << "Invalid input, try again!" << std::endl; // prompt for valid input
				break;
			}
		}
		std::cout << "------------------------------------------------" << std::endl;
		views.DefaultView(&event_list); // default view for events
		ShowMenu(); // display menu options
		std::cout << "Menu Selection: ";
		getline(std::cin, menu_input);
		std::istringstream in_string(menu_input);
		in_string >> menu_char;
		std::cout << std::endl;

    }

	files.FileSave(&event_list); // saves event from current session


	
	event_list->ClearList(&event_list); // delete linked list and free the memory
	
	std::cout << std::endl << "Saving ... " << std::endl;
	std::cout << "Program has exited!" << std::endl;

    return 0;
}
