#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>

using namespace std;

/**
This program is a conversion program that will convert units of time and
temperature. For time it is to convert seconds into hours, minutes, and 
seconds. For temperature it is to convert from Fahrenheit to Celsius and
vice versa
*/

/**
 For this function time, it is to convert seconds to hours, minutes, and 
 seconds. Basically this function would run after the user picks 1 for 
 converting time. In this function it will ask the user to input seconds
 and it must be a positive or else it will give a prompt saying to 
 insert a positive number. After the user inputs a positive number in 
 seconds, it will divide the seconds into minutes and then take the 
 remainder of it into seconds. Then takes the minutes and divides 
 it into hours and then takes the remainder of it for the minutes.
 */

void time(){
	int seconds;
	
	cout << "Input seconds (positive integer)\n";
	cin >> seconds;
	
	while(seconds < 0)
	{
		cout << "Please enter a positive number: ";
		cin >> seconds;
	}
	
	while(seconds >= 0)
	{
		int minutes = seconds / 60;
		int seconds_remainder = seconds % 60;
		int hours = minutes / 60;
		 minutes = minutes % 60;
		cout << seconds << " seconds is " << hours << " hours " << 
		minutes << " minutes " << seconds_remainder << " seconds\n\n";
		break;
	}
/**
 For both converting from Fahrenheit to Celsius, and from Celsius to 
 Fahrenheit, the program will ask the user to enter values of 
 temperature for both cases. If the user doesn't enter a number, it will 
 give a prompt saying you must enter a number and gives you the option 
 again. Using the cin.fail(), cin.clear(), and cin.ignore(), 
 it can detect data types. 
 */
		
}
void fahrenheit(){
	double f;
	
	cout << "Enter a Fahrenheit value: \n";
	cin >> f;
	
	
	while(1)
	{
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Enter a valid number\n";
			cin >> f;
		}
		if(!cin.fail())
		break;
	}
	
	double c = ((f-32)*5)/9;
	cout << f << " in celsius is " << c;
	
}
void celsius(){
	double c;
	
	cout << "Enter a Celsius value: \n";
	cin >> c;
	
	if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Enter a valid number\n";
			cin >> f;
		}
		if(!cin.fail())
		break;
	
	double f = (c*9.0)/5.0 + 32;
	cout << c << " in fahrenheit is " << f;
}

/**
 * Here is the menu for the program. 
 */
void menu(){
	cout << "\n\t\tChoose a selection below: \n\n"
		 << "1. Seconds to hours, minutes, and seconds\n"
		 << "2. Fahrenheit to Celsius\n"
		 << "3. Celsius to Fahrenheit\n"
		 << "4. Quit\n\n"
		 << "Please Select ONE: ";
}


void printMeFirst(string name, string courseInfo)
{
	cout << " Program written by: " << name << endl; 
	cout << " Course Info: " << courseInfo << endl;
	time_t now = time(0); 
	char* dt = ctime(&now);
	cout << " Date: " << dt << endl;
}

/**
 For my main functin I used a do-while loop to implement the menu. 
 The menu will pop up and as long as the user doesn't quit, it will 
 keep going back to the menu after running the conversions. 
 */

int main()
{	
	int select; //Select which number on menu
	
	const int time_select = 1,
			  quit_select = 4;
	printMeFirst("Justin Sanchez", "CS116");
	do
	{
		menu();
		cin >> select;
		while (select < time_select || select > quit_select)
		{
			cout << "Please enter valid choice: ";
			cin >> select;
		}
		if(select != quit_select)
		{
			switch(select)
			{
				case 1:
				time();
				break;
				
				case 2:
				fahrenheit();
				break;
				
				case 3:
				celsius();
				break;
				
			}
		}
		else
		{
			cout << "Thank you! Please come again\n\n";
		}
	}while(select != quit_select);
	
	
};
