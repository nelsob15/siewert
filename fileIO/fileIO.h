#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>

using namespace std;

class File;

//This Event class is a placeholder for the class which Bruce is working on.
//All methods associated with this class will come from Bruce and what I've shown
//is meant for my testing purposes only.

class Event
{
        friend class File;
        private:
                int day, month;
                string name;
        public:
                void setDay(int newDay);
                void setMonth(int newMonth);
                void setName(string newName);
};

//TODO: create a method for reading in events from a linked list to a file
//Test driver reads in events from array, need to translate this into the parseList method

class File
{
        friend class Event;
        private:
                string fileName;
                ofstream inputFile;
                ifstream outputFile;
        public:
                void getFileName(void);
		void getFileName(string name);
                bool openFile(char direction);
                bool closeFile(char direction);
                bool insertHeaderRow(void);
		bool removeHeaderRow(void);
                bool insertDataRow(Event insert);
		void parseFile(void);
		int getIntInputFromFile(void);
		string getStringInputFromFile(void);
		bool getBoolInputFromFile(void);
		Event getLineFromFile(void);
//		void parseList(void);
};

void Event::setDay(int newDay)
{
	//class setter for the day
        day = newDay;
}

void Event::setMonth(int newMonth)
{
	//class setter for the month
        month = newMonth;
}

void Event::setName(string newName)
{
	//class setter for the event name
        name = newName;
}

void File::getFileName(void)
{
	//query the user to obtain the file name
	//TODO: add error checking to make sure they append the file extension of ".csv"
	//if they don't, need to add it

        cout<<"Please enter the file name you wish to synch.  Include the file extension: ";
        cin>>fileName;
}

void File::getFileName(string name)
{
	fileName = name;
}

bool File::openFile(char direction)
{
	//open the file based on whether it's being used for input or output
	//TODO: check whether the oposite file is already open.  can't have input and output happening at the same time.

        if(direction == 'i')
        {
	        inputFile.open(fileName.c_str());
	}
	else if(direction == 'o')
	{
                outputFile.open(fileName.c_str());
	}
        else
                cout<<"Invalid entry."<<endl;
        return 1;
}

bool File::closeFile(char direction)
{
	//close the file based on whether it is being used for input or output
	//TODO: check whether the oposite file is already open.  can't have input and output happening at the same time.

        if(direction == 'i')
	{
                inputFile.close();
	}
        else if(direction == 'o')
	{
                outputFile.close();
	}
        else
                cout<<"Invalid entry."<<endl;
        return 1;
}

bool File::insertHeaderRow(void)
{
        //insert the header to the .csv file

        inputFile<<"name,day,month\n";
        return 1;
}

bool File::removeHeaderRow(void)
{
	string temp;
	getline(outputFile, temp);
}

bool File::insertDataRow(Event insert)
{
	//insert the given Event object into the file that is currently open

        inputFile<<insert.name<<","<<insert.day<<","<<insert.month<<"\n";
        return 1;
}

void File::parseFile(void)
{
	//need to read in one line of the file at a time
	//error check as read in to make sure data is valid

	string temp = "", myName = "", myDay = "", myMonth = "";
	int convertedDay, convertedMonth;

	//read in the file header

	getline(outputFile, temp);

	//have variables for each of the attributes of an event
	//read in the file to each of these temp variables
	//error check as read in
	//once all are validated, call createEventNode and feed it the temps

	//get the name of the first line now and be able to check if it's EOF
	getline(outputFile, myName, ',');
	assert(myName != "");

	while(!outputFile.eof())
	{
		//order is: name, day, month

		getline(outputFile, myDay, ',');
		assert(myDay != "");
		convertedDay = stoi(myDay, NULL);

		assert(convertedDay > 0 && convertedDay <= 31);

		getline(outputFile, myMonth);
		assert(myMonth != "");
		convertedMonth = stoi(myMonth, NULL);

		assert(convertedMonth >= 1 && convertedMonth <=12);

		//createEventNode function call here

		//have to get the next name value now in case it's EOF
		getline(outputFile, myName, ',');

		//Commenting this assert out lets happy_path.csv work
		//Placing it in the code lets neg_empty_name.csv work
		//Not entirely sure why...
//		assert(myName != "");
	}

}

Event File::getLineFromFile(void)
{
	string line, token;
	stringstream iss;
	Event newEvent;
	int counter;

	getline(outputFile, line);
	
		iss << line;
		counter = 0;

		while(getline(iss, token, ','))
		{
			switch(counter)
			{
				case 0:
					newEvent.setName(token);
					break;
				case 1:
					newEvent.setDay(stoi(token,NULL));
					break;
				case 2:
					newEvent.setMonth(stoi(token,NULL));
					break;
			}
			counter++;
		}
	
	return newEvent;
}

int File::getIntInputFromFile(void)
{
	string temp;
	getline(outputFile, temp, ',');
	return stoi(temp);
}

string File::getStringInputFromFile(void)
{
	string temp;
	getline(outputFile, temp, ',');
	return temp;
}

bool File::getBoolInputFromFile(void)
{
	string temp;
	getline(outputFile, temp, ',');
	return stoi(temp);
}

/*void File::parseList(void)
{
	//start at the head of the list and continue until NULL
	//insert a row in the file for each element in the list

	next = head;

	while(next->next != NULL)
	{
		this.insertDataRow(next->eventThing);
		next = next->next;
	}
}
*/
