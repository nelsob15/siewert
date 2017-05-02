/*
  File Synchronization Module
  Major features of this module includes file load to load files from the event log to the file upon program start up. File Save that saves events in the system
  for reuse in the next session. Lastly file synch that synchs an external file events to the system.
*/


#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>
#include "Event.h"

class File
{
	friend class Event;
	
	public:
	    File();
		void FileSave(Event **event_head); // saves events to event log file
		void FileLoad(Event **event_head); // loads events from event log file
		void FileSynch(Event **event_head); // synchs an external file add events to the system
	    std::string file_name;
		std::ofstream inputFile;
		std::ifstream outputFile;
};

#endif
