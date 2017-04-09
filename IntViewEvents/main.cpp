//
// SE310 HW3 Domain Model
//
// -- prototype for interactive calendar with events
//

#include<iostream>
#include "Event.h"
#include "Views.h"

using namespace std;

int main()                    //This was to just be able to run your class...
{
    Event *event_head;
    event_head = NULL;

    View testView;

    string menu_input;
	char menu_char;

	cout << "------------------------------------------------------------------------------------------" << endl;
    event_head->ShowEventMenu();
	cout << "Menu Selection: ";
    getline(cin, menu_input);
    istringstream in_string(menu_input);
    in_string >> menu_char;
	cout << endl;

    while(toupper(menu_char) != 'X' )
    {
		switch(toupper(menu_char))
		{
			case 'C':{
				event_head->CreateEvent(&event_head);
				break;
			}
			case 'M':{
				event_head->ModifyEvent(&event_head);
				break;
			}
			case 'R':{
				event_head->RemoveEvent(&event_head);
				break;
			}
			case 'L':{
			    event_head->Traverse(&event_head);
				break;
			}
			case 'S':{
				event_head->DisplayEventFull(&event_head);
				break;
			}
			case 'V':{
			    testView.showCalendar(&event_head);
			    break;
			}
			case 'N':{
			    testView.showMonthly(&event_head);	
				break;
			}
			case 'D':{
			    testView.showDaily(&event_head);
				break;
			}
			case 'X':
			    break;
			default:{
				cout << "Invalid input, try again!" << endl;
				break;
			}
		}
		cout << "------------------------------------------------------------------------------------------" << endl;
		event_head->ShowEventMenu();
		cout << "Menu Selection: ";
        getline(cin, menu_input);
        istringstream in_string(menu_input);
        in_string >> menu_char;
		cout << endl;
    }
	event_head->ClearList(&event_head);

    return 0;
}
