#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Event
{
	public:
		int day, month;
		string name;
};

int main(void)
{
  int i;
  Event a, b, c;
  string searchName;

  ofstream myFile;
  myFile.open("events.csv");
  
  myFile <<"name,day,month\n";

  cout<<"Event creation:"<<endl;

  cout<<"day:";
  cin>>a.day;
  cout<<"month";
  cin>>a.month;
  cout<<"name:";
  cin>>a.name;

  myFile <<a.name<<","<<a.day<<","<<a.month<<"\n";

  cout<<"day:";
  cin>>b.day;
  cout<<"month";
  cin>>b.month;
  cout<<"name:";
  cin>>b.name;

  myFile <<b.name<<","<<b.day<<","<<b.month<<"\n";

  cout<<"day:";
  cin>>c.day;
  cout<<"month";
  cin>>c.month;
  cout<<"name:";
  cin>>c.name;

  myFile <<c.name<<","<<c.day<<","<<c.month<<"\n";

  myFile.close();

  ifstream readFile;
  readFile.open("events.csv");
  int isFound = 0;

  cout<<"search for an event name:";
  cin>>searchName; 
  string temp = "";

  getline(readFile,temp);

  while(!readFile.eof() && !isFound)
  {
    getline(readFile, temp, ',');
   
    cout<<temp<<endl;
   
    for(i = 0; i < searchName.size(); i++)
    {
      if(temp[i] == searchName[i])
	isFound = 1;
      else
      {
        isFound = 0;
        break;
      }
    }

    if(isFound)
    {
      Event found;

      found.name = temp;
      getline(readFile, temp, ',');
      found.day = stoi(temp);
      getline(readFile, temp, ',');
      found.month = stoi(temp);
      cout<<"Name: "<<found.name<<" Day: "<<found.day<<" Month: "<<found.month<<endl;
    }
  }

  readFile.close();

}
