#include "Settings.h"

using namespace std;

Settings::Settings()
{
    //ctor
}

Settings::~Settings()
{
    //dtor
}

std::string intToString(int i)
{

  std::stringstream ss;

  ss << i;

  return ss.str();

} //change text color

void Settings::changeDefaultView() //change the default view
{
    cout << "Changing Default View" << endl;
}
void Settings::changeRemTimeLength() //changes time
{
    cout << "Changing Remaining Time Length" << endl;
}
void Settings::changeMenuLoc() //changes menu location
{
    cout << "Change Menu Location" << endl;
}
void Settings::changeTextColor() //changes text color
{
	int colorChoice;
      std::string default_console = "\033[" + intToString(0) + "m";

	
  			cout<<"What Color do you want?"<<endl;
      cout<<"(31)  --Red"<<endl;
			cout<<"(32)  --Green"<<endl;
			cout<<"(33)  --Yellow"<<endl;
			cout<<"(34)  --Purple"<<endl;
			cout<<"(35)  --Pink"<<endl;
			cout<<"(36)  --Blue"<<endl;
			cout<<"(37)  --White"<<endl;

			cin>> colorChoice; 
	
  /*Color code based off of source code from http://www.dreamincode.net/forums/topic/335483-outputting-colors-in-c-putty-using-linux/ */

    std::string color = "\033[0;" + intToString(colorChoice) + "m";

    std::cout << color << "Color has been changed " /*<< colorChoice*/ << std::endl;

}
void Settings::changeMonth() //change the month
{
    cout << "Change Month" << endl;
}
void Settings::whatChange() //does the change
{
    cout << "What change" << endl;
}
void Settings::displayCurrent() //display the current settings
{
    cout << "Display Current" << endl;
}
