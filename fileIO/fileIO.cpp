#include<iostream>
#include<fstream>
#include<string>

#include "fileIO.h"

#define NUM_OF_EVENTS 5

using namespace std;

int main(int argc, char** argv)
{
  File myFile;
  Event myEventList[NUM_OF_EVENTS];
  int i;
  string temp;

  //Test parseFile()

  myFile.getFileName(argv[1]);
  myFile.openFile('o');
  myFile.parseFile();
  myFile.closeFile('o');

  //Simulate parseFile working with Bruces event creation
  //I use an array instead of a linked list, but the concept 
  //is the same

  myFile.openFile('o');
  myFile.removeHeaderRow();

  for(i = 0; i < NUM_OF_EVENTS; i++)
  {
    myEventList[i] = myFile.getLineFromFile();
  }
 
  myFile.closeFile('o');

  //Create the backup of the events that are currently
  //in the system by reading them into their own line

  myFile.getFileName("backup.csv");
  myFile.openFile('i');
  myFile.insertHeaderRow();

  for(i = 0; i < NUM_OF_EVENTS; i++)
  {
    myFile.insertDataRow(myEventList[i]);
  }

  myFile.closeFile('i');
}
