#ifndef SYNCH_H
#define SYNCH_H

#include<iostream>
#include<cstring>


class Synch
{
    public:
        Synch(std::string fname); //passes in the file
        ~Synch();
        void parseCSV();   //parses the csv file
        void syncEvents(); //sync the events to the calendar

    protected:

    private:
        std::string filename;
        int eventsParsed[50][7];

};

#endif // SYNCH_H
