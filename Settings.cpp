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
    cout << "Change Text Color" << endl;
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
