#include "Synch.h"

using namespace std;

Synch::Synch(std::string fname) //passes in the file
{
    filename = fname;
    cout << "Syncing " << filename << endl;
}

Synch::~Synch()
{
    //dtor
}

void Synch::parseCSV() //parses the csv file
{
    cout << "Starting Parse" << endl;
    syncEvents();
}

void Synch::syncEvents() //syncs events
{
    cout << "Starting Sync of events" << endl;
}
