#include "sett.h"

using namespace std;

std::string intToString(int i)
{

  std::stringstream ss;

  ss << i;

  return ss.str();

} //change text color

void Settings::changeDefaultView() //change the default view
{
    string choiceView;
    
    //Gets User Input for Default View
    do{
    
    cout<<"What view would you like?"<<endl;
    cout<<"(c)    --Calendar View"<<endl;
    cout<<"(list) --List View"<<endl;
    cin>>choiceView;
    }while((choiceView!="c") && (choiceView!="list"));
    
    //Checks user input. If invaild will display comment on the failure.
    if(choiceView == "c")
    {
    cout<<"Calendar View Displayed"<<endl;
    cout<<"View changed successfully"<<endl;
    }
    else if(choiceView == "list")
    {
    cout<<"List View Displayed"<<endl;
    cout<<"View changed successfully"<<endl;
    }
    else
    {
    cout<<"View change failed"<<endl;
    }
    
}

void Settings::changeMenuLoc() //changes menu location
{
int viewChoice;
//Gets User Input for change menu location
do{
    cout << "Change Menu Location" << endl;
    cout<<"(1)    --view/menu"<<endl;
    cout<<"(2)    --menu/view"<<endl;

    }while((1 == viewChoice) && (2 == viewChoice));
    
    cin>>viewChoice;
    
//Checks user input. If invaild will display comment on the failure.
    if(1 == viewChoice)
    {
    cout<<"view/menu"<<endl;
    cout<<"View Order changed successfully"<<endl;
    }
    else if(1 == viewChoice)
    {
    cout<<"menu/view"<<endl;
    cout<<"View Order changed successfully"<<endl;
    }
    else
    {
    cout<<"View change failed"<<endl;
    }
}
void Settings::changeTextColor() //changes text color
{
	int colorChoice;
      std::string default_console = "\033[" + intToString(0) + "m";
//Gets User Input for change of color
do{
      cout<<"What Color do you want?"<<endl;
      cout<<"(30)  --Black"<<endl;
      cout<<"(31)  --Red"<<endl;
			cout<<"(32)  --Green"<<endl;
			cout<<"(33)  --Yellow"<<endl;
			cout<<"(34)  --Purple"<<endl;
			cout<<"(35)  --Pink"<<endl;
			cout<<"(36)  --Blue"<<endl;
      cout<<"(37)  --White"<<endl;
      cout<<"(38)  --Default"<<endl;
      cout<<"(39)  --Exit"<<endl;


      }while((29 > colorChoice) && (colorChoice > 40));

			cin>> colorChoice; 
      cin.ignore();
      
  /*Color code based off of source code from http://www.dreamincode.net/forums/topic/335483-outputting-colors-in-c-putty-using-linux/ */
    //Checks user input. If invaild will display comment on the failure.
    if((29 < colorChoice) && (colorChoice < 38))
    {
    std::string color = "\033[0;" + intToString(colorChoice) + "m";
    std::cout << color << "Color has been changed " << std::endl;  
    }
    else if(colorChoice == 38)
    {
        std::cout << default_console << std::endl;
        cout << "Color has been changed " <<endl;  
    }
    else if(colorChoice == 39)
    {
    cout << "Do Nothing" <<endl;
    }
    else
    {
    cout<<"Color Change Failed"<<endl;
    }

}

