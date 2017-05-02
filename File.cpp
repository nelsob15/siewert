/*
  File Synchronization Module
  Major features of this module includes file load to load files from the event log to the file upon program start up. File Save that saves events in the system
  for reuse in the next session. Lastly file synch that synchs an external file events to the system.
*/

#include "File.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>
#include "Event.h"

using namespace std;

File::File()
{
	
}

void File::FileSave(Event **event_head) // parses file from the system to the event log file
{
	ofstream myfile;
	Event * traverse;
	traverse = *event_head;
	
	myfile.open("eventlog.csv");  //, std::ios_base::app
	
	myfile << "Name , " << "Location , " << "Month , " << "Day , " << "Year , " << "Start Hour , " << "Start Minute , "
	       << "Start Meridian , " << "End Hour , " << "End Minute , " << "End Meridian , " << "Notes \n";
	
	while (traverse != NULL){
		myfile << traverse->GetName() << "," << traverse->GetLocation() << "," << traverse->GetMonth() << "," << traverse->GetDay()
		<< "," << traverse->GetYear() << "," << traverse->GetStartHour() << "," << traverse->GetStartMinute() << "," 
		<< traverse->GetStartMeridian() << "," << traverse->GetEndHour() << "," << traverse->GetEndMinute() << "," <<
		traverse->GetEndMeridian() << "," << traverse->GetNotes() << "\n";
		
		traverse=traverse->next;
	}
	myfile.close();
}

void File::FileLoad(Event **event_head) // loads files from the event log into the system
{
	ifstream myfile;
    int meridian_start, meridian_end;
	string meridian_start_str, meridian_end_str;
    int month, day, year, start_hour, start_minute, end_hour, end_minute;
	string month_str, day_str, year_str, start_hour_str, start_minute_str, end_hour_str, end_minute_str;
    string event_name, event_location, event_notes, smeridian;
	string lineIn;
	
	myfile.open("eventlog.csv", std::ios_base::app);  

    getline(myfile, lineIn);	
	while(getline(myfile, lineIn)) {
	    stringstream linestr(lineIn);
		if (getline(linestr, event_name, ',') &&
        getline(linestr, event_location, ',') &&
        getline(linestr, month_str, ',') &&
        getline(linestr, day_str, ',') &&
        getline(linestr, year_str, ',') &&
        getline(linestr, start_hour_str, ',') &&        
        getline(linestr, start_minute_str, ',') &&
        getline(linestr, meridian_start_str, ',') &&
		getline(linestr, end_hour_str, ',') &&        
        getline(linestr, end_minute_str, ',') &&
        getline(linestr, meridian_end_str, ',') &&
		getline(linestr, event_notes, ','))
		{
	        istringstream ( month_str ) >> month;
	        istringstream ( day_str ) >> day;
	        istringstream ( year_str ) >> year;
	        istringstream ( start_hour_str ) >> start_hour;
	        istringstream ( start_minute_str ) >> start_minute;
			if(meridian_start_str == "AM" || meridian_start_str == "am")
				meridian_start = 0;
			else 
				meridian_start = 1;
	        istringstream ( end_hour_str ) >> end_hour;
	        istringstream ( end_minute_str ) >> end_minute;
			if(meridian_end_str == "AM" || meridian_end_str == "am")
				meridian_end = 0;
			else 
				meridian_end = 1;
		
			Event *temp, *temp2, **temp3;
			temp = new Event;
			temp->EventFill(event_name,event_location,month,day, year,start_hour,start_minute, meridian_start,end_hour,end_minute, meridian_end, event_notes);

			temp2 = *event_head;
			temp3 = event_head;

			while(temp->EventSort(temp, temp2) != 0){
				temp3 = &temp2->next;
				temp2 = temp2->next;
			}
			*temp3 = temp;
			temp->next = temp2;	
		}
	}
}

void File::FileSynch(Event **event_head) // synches an outside file and parses events to the system
{	
	ifstream myfile;
    int meridian_start, meridian_end;
	string meridian_start_str, meridian_end_str;
    int month, day, year, start_hour, start_minute, end_hour, end_minute;
	string month_str, day_str, year_str, start_hour_str, start_minute_str, end_hour_str, end_minute_str;
    string event_name, event_location, event_notes, smeridian;
	string lineIn;
	string file_name;
	
	cout << endl << "Enter the name of the file (with extension) to synch: ";
	getline(cin, file_name);
	myfile.open(file_name.c_str(), ios::in | ios::binary);  

    //getline(myfile, lineIn);	//Used to skip lines
	while(getline(myfile, lineIn)) {
	    stringstream linestr(lineIn);
		if (getline(linestr, event_name, ',') &&
        getline(linestr, event_location, ',') &&
        getline(linestr, month_str, ',') &&
        getline(linestr, day_str, ',') &&
        getline(linestr, year_str, ',') &&
        getline(linestr, start_hour_str, ',') &&        
        getline(linestr, start_minute_str, ',') &&
        getline(linestr, meridian_start_str, ',') &&
		getline(linestr, end_hour_str, ',') &&        
        getline(linestr, end_minute_str, ',') &&
        getline(linestr, meridian_end_str, ',') &&
		getline(linestr, event_notes, ','))
		{
	        istringstream ( month_str ) >> month;
	        istringstream ( day_str ) >> day;
	        istringstream ( year_str ) >> year;
	        istringstream ( start_hour_str ) >> start_hour;
	        istringstream ( start_minute_str ) >> start_minute;
			if(meridian_start_str == "AM" || meridian_start_str == "am")
				meridian_start = 0;
			else 
				meridian_start = 1;
	        istringstream ( end_hour_str ) >> end_hour;
	        istringstream ( end_minute_str ) >> end_minute;
			if(meridian_end_str == "AM" || meridian_end_str == "am")
				meridian_end = 0;
			else 
				meridian_end = 1;
		
			Event *temp, *temp2, **temp3;
			temp = new Event;
			temp->EventFill(event_name,event_location,month,day, year,start_hour,start_minute, meridian_start,end_hour,end_minute, meridian_end, event_notes);

			temp2 = *event_head;
			temp3 = event_head;

			while(temp->EventSort(temp, temp2) != 0){
				temp3 = &temp2->next;
				temp2 = temp2->next;
			}
			*temp3 = temp;
			temp->next = temp2;	
		}
	}
	cout << endl << "File Synching of " << file_name << " is complete!" << endl;
}