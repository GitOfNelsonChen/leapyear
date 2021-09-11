// Sample function setup source code that you may choose to include as part of your functional decomposition of the calendar program
#include <iostream>
#include <cstdlib>
#include <iomanip> //for setw
#include <string>

using namespace std;
//function prototypes
bool isLeapYear (/*in*/int); //a value-returning function returns a truth value
int startDayInputYear (/*in*/int );//a value-returning function returns an int
//other function prototypes
bool isNumber(/*in*/ string);

void getCalendarInput(/*inout*/ int&);

int numOfDaysInMonth(/*in*/ int,/*in*/ bool);

void CalendarMonthHeader(/*in*/ int);

void printMonth(/*in*/int,/*in*/ int&);

void whitespace(/*in*/int);
int main()
{
    int year, firstDayInCurrentMonth;
    int currentMonth = 1;
    int numDays;
    bool leap;
    //string str; //maybe needed for input validation
    char choice;

    //prompt for input
 //   cout << "What year do you want a calendar for? ";
	//cin
 //   cin >>year; // str?
	getCalendarInput(year);

    leap = isLeapYear( year ); //function call returns bool truth value
                             //needed to determine number of days in month for leap and non leap year

    firstDayInCurrentMonth = startDayInputYear( year ); // function call returns start day.
                                                        // Days of week numbered 0 through 9 for Sunday through Saturday.

    cout<< year << " " << leap << " " << firstDayInCurrentMonth <<endl; //remove statement - used to test key variable values

    //your code / function calls here

	while (currentMonth <= 12)
	{
		numDays = numOfDaysInMonth(currentMonth, leap);
		CalendarMonthHeader(currentMonth);
		printMonth(numDays, firstDayInCurrentMonth);

		currentMonth++;
	}

    return 0;
}


//function definitions with function related documentation

/*function IsLeapYear returns true if year is a leap year and
/ false otherwise.*/
bool isLeapYear (/*in*/int year)
//pre:value parameter has an assigned value
//post: //Is year not divisible by 4? If so, can't be a leap year
        //Is year not a multiple of 100? If so, is a leap year
        //Is year not a multiple of 400? If so, then is not a leap year
        //returns a truth value
{
    return   ((year%4==0) && (year%100 !=0))||(year%400==0)  ;
}

//function uses a value parameter in four calculated values
//to determine and return startday.
int  startDayInputYear(/*in*/int year)
//pre: value parameter has an assigned value
//post: returns a startday in the range of  0 to 6
{
	int startday;
	int num1, num2, num3;
	num1 = (year - 1) / 4;
	num2 = (year - 1) / 100;
	num3 = (year - 1) / 400;
	startday = (year + num1 - num2 + num3) % 7;
	return startday;
}
void getCalendarInput(int& year) 
{
	string str;
	while(1)
	{
		cout << "What year do you want a calendar for? ";
		cin >> str;
		if (isNumber(str))
		{
			year = atoi(str.c_str());
			break;
		}
		
		else 
		{
			cout << "non digit entered" << endl;
		}
	}
	

		//cin >> year; // str?
	
}


bool isNumber(/*in*/ string str)
{
	for (int strIndex = 0; strIndex < str.size(); strIndex++)
	{
		int charNum = str[strIndex];
		if (charNum >= 48 && charNum <= 57)
		{
			continue;
		}
		else
		{
			return false;
		}
		
	}
	return true;

}

int numOfDaysInMonth(/*in*/ int currentMonth,/*in*/ bool leap)
{
	switch (currentMonth) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (leap)return 29;
		else
		{
			return 28;
		}

	}
}

void CalendarMonthHeader(/*in*/ int currentMonth)
{
	switch (currentMonth)
	{
	case 1:
		cout << setw(15) << "January" << endl; break;
		
	case 2:
		cout << setw(16) << "February" << endl; break;
	case 3:
		cout << setw(13) << "March" << endl; break;
	case 4:
		cout << setw(13) << "April" << endl; break;
	case 5:
		cout << setw(11) << "May" << endl; break;
	case 6:
		cout << setw(12) << "June" << endl; break;
	case 7:
		cout << setw(12) << "July" << endl; break;
	case 8:
		cout << setw(14) << "August" << endl; break;
	case 9:
		cout << setw(17) << "September" << endl; break;
	case 10:
		cout << setw(15) << "October" << endl; break;
	case 11:
		cout << setw(16) << "November" << endl; break;
	case 12:
		cout << setw(16) << "December" << endl; break;
	}
	cout << setw(3) << "S" << setw(3) << "M" << setw(3) << "T" << setw(3) << "W" << setw(3) << "T" << setw(3) << "F" << setw(3) << "S" << endl;
	cout << endl;
	cout << "---------------------" << endl;
}


void printMonth(/*in*/int numDays,/*in*/ int& firstDayInCurrentMonth)
{
	int firstDayBefore;
	int lineMark;
	int day;
	lineMark = firstDayInCurrentMonth;
	whitespace(firstDayInCurrentMonth * 3);
	for (day = 1; day <= numDays; day++)
	{
		if (lineMark % 7 == 0) {
			lineMark = lineMark % 7;
			cout << endl;
		}
		cout << setw(3) << day;
		lineMark++;
	}
	firstDayInCurrentMonth = lineMark;
	cout << endl;
	
	

}




void whitespace(/*in*/int spaceAmount)
{
	int spaceNum;
	for (spaceNum = 1; spaceNum <= spaceAmount; spaceNum++)
	{
		cout << " ";
	}
	return;
}