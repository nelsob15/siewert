#include "calendar.h"
#include "Textcolor.h" // Use textcolor functions to edit terminal output appearance.

using namespace std;

Calendar :: Calendar (int _month, int _year){

	month = _month;
	year = _year;
}

void Calendar :: setFirstDay(){
  // This part determines which day will be the first day of that year.
  // Sun - 0, Mon - 1, Tues - 2, Wed - 3, Thurs - 4, Fri - 5, Sat - 6.
	int day=1;
	int y = year - (14-month)/12;
	int m = month +12 * ((14-month) / 12) -2;
	firstday= (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;
}

void Calendar :: print(Event **head){

	int NumberOfDaysInMonth;
	int FirstDayOfMonth;
	int DayOfWeekCounter = 0;
	int DateCounter = 1;
 
  // Initialize traverse for input arg Event list.
  Event * traverse;
  traverse = *head;

  // Determine appropriate days of the given month.
	switch (month)
	{
	  case 1:
      cout<<setw(21)<<"January "<<year;
      NumberOfDaysInMonth = 31;
	  break;
	  case 2:
      cout<<setw(21)<<"February "<<year;
      if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        NumberOfDaysInMonth = 29;
      else
       NumberOfDaysInMonth = 28;
	  break;
	  case 3:
      cout<<setw(21)<<"March "<<year;
      NumberOfDaysInMonth = 31;
	  break;
	  case 4:
      cout<<setw(21)<<"April "<<year;
      NumberOfDaysInMonth = 30;
	  break;
	  case 5:
      cout<<setw(21)<<"May "<<year;
      NumberOfDaysInMonth = 31;
	  break;
	  case 6:
      cout<<setw(21)<<"June "<<year;
      NumberOfDaysInMonth = 30;
	  break;
	  case 7:
      cout<<setw(21)<<"July "<<year;
      NumberOfDaysInMonth = 31;
	  break;
	  case 8:
      cout<<setw(21)<<"August "<<year;
      NumberOfDaysInMonth = 31;
	  break;
	  case 9:
      cout<<setw(21)<<"September "<<year;
      NumberOfDaysInMonth = 30;
	  break;
	  case 10:
      cout<<setw(21)<<"October "<<year;
      NumberOfDaysInMonth = 31;
	  break;
	  case 11:
      cout<<setw(21)<<"November "<<year;
      NumberOfDaysInMonth = 30;
	  break;
	  case 12:
      cout<<setw(21)<<"December "<<year;
      NumberOfDaysInMonth = 31;
	  break;
	}

  // Display the days at the top of each month.
	cout<<"\nSun   Mon   Tue   Wed   Thu   Fri   Sat";
	cout<<"\n\n"<<setw(2);
  // Determine where the first day begins.
  if (firstday > 0)
  {
    if (firstday == 1)
      cout<<setw(8);
    if (firstday == 2)
      cout<<setw(14);
    if (firstday == 3)
      cout<<setw(20);
    if (firstday == 4)
      cout<<setw(26);
    if (firstday == 5)
      cout<<setw(32);
    if (firstday == 6)
      cout<<setw(38);
  }
	int tempfirstday=firstday;
	DateCounter = 1;
	DayOfWeekCounter = tempfirstday;
  // This loop represents the date display and will continue to run until
  // the number of days in that month have been reached.

	  for (DateCounter; DateCounter <= NumberOfDaysInMonth; ++DateCounter)
	  {

      if ( *head != NULL ) // Make sure we aren't using an empty list.
      {
        // If the day is found when we compare, change the color of that particular date.
        if ((traverse != NULL) && (DateCounter == traverse->GetDay())) // Make sure traversal is traversable.
        {
          textcolor(BRIGHT, RED, BLACK);
          traverse = traverse->next;
          // Skip through the list until we get to the next date;
          // we have to keep the dateCounter and the traversal consistent
          while ( (traverse != NULL ) && (traverse->GetDay() == DateCounter))
            traverse = traverse->next;
        }
        
      }
      // Print out day.
		  cout<<DateCounter<<setw(6);
        
      // Reset color to terminal.
      textcolor(RESET, WHITE, BLACK);
      
      // Move on to the next day of the week        
		  ++DayOfWeekCounter;
        
      // When we hit the end of the week (sat), adjust to next week (line).
		  if (DayOfWeekCounter > 6)
		  {
		  	cout<<"\n\n"<<setw(2);
		  	DayOfWeekCounter = 0;
		  }

	  }
	  cout << " \n" ;

	  tempfirstday = DayOfWeekCounter + 1;
}
