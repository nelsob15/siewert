#include "View.h"

using namespace std;

View::View()
{
    //ctor
}

View::~View()
{
    //dtor
}

void View::currentView()  //displays the current view
{
    cout << "Displays Current View" << endl;
}
void View::displayList()  //displays list view
{
    cout << "List View" << endl;
}
void View::displayCalendar() //displays calendar view
{
    Calendar c;
	c.setFirstDay();
	c.print();
}
void View::changeView() //changes views
{
    cout << "change view" << endl;
    //current = new view
}
