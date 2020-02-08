// File:    date.cpp
// Author:  Nathan Heidt

// This file contains the implementation file for 
// the Date Class

#include <iostream>
#include <sstream>
#include <ctime>
#include "date.h"
using namespace std;
//using namespace DateNameSpace;

// Description:
// Precondition:
// Postcondition:
Date::Date()
{
    tm *current;
    time_t lt;
    lt = time(0);
    current = localtime(&lt);

    day = current->tm_mday;
    month = current->tm_mon+1;
    year = current->tm_year+1900;
    isLeapYear(year);
}

// Description:
// Precondition:
// Postcondition:
Date::Date(int m, int d, int y)
{
    day = d;
    month = m;
    year = y;
}

// Description:
// Precondition:
// Postcondition:
int Date::getMonth() const
{
    return month;
}

// Description:
// Precondition:
// Postcondition:
int Date::getDay() const
{
    return day;
}

// Description:
// Precondition:
// Postcondition:
int Date::getYear() const
{
    return year;
}

// Description:
// Precondition:
// Postcondition:
void Date::setDate(int newMonth, int newDay, int newYear)
{
    day = newDay;
    month = newMonth;
    year = newYear;
    isLeapYear(year);
}
// Description:
// Precondition:
// Postcondition:
void Date::isLeapYear(int Year)
{
    leapYear = Year % 400 || Year % 4 && Year % 100 != 0;
}

string Date::convertMonth(int mon) const
{
    switch (mon)
    {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";        
        case 6: return "June";        
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";        
    }
    return 0;
}

void Date::getWeekday(const Date& date) const
{
    int centuries;
    int months;
    int dayOfWeek;

    centuries = (3 - date.year / 100 % 4) * 2;

    switch (date.month)
    {
        case 1: if (date.leapYear)
                {
                    months = 6;
                }
                else
                {
                    months = 0;
                }
                break;
        case 2: if (date.leapYear)
                {
                    months = 2;
                }
                else
                {
                    months = 3;
                }
                break;
        case 3: months = 3; break;
        case 4: months = 6; break;
        case 5: months = 1; break;
        case 6: months = 4; break;
        case 7: months = 6; break;
        case 8: months = 2; break;
        case 9: months = 5; break;
        case 10: months = 0; break;
        case 11: months = 3; break;
        case 12: months = 5; break;
    }

    dayOfWeek = (centuries + year%100 + year%100/4 + months+day)%7;

    switch (dayOfWeek)
    {
        case 0: cout << "Sunday"; break;
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;      
    }            
}

// Description:
// Precondition:
// Postcondition:
void Date::outputFormat(OrderFormat oFormat)
{
    orderFormat = oFormat;
}

// Description:
// Precondition:
// Postcondition:
void Date::outputFormat(DelimiterFormat delimFormat)
{
    delimiterFormat = delimFormat;
}

// Description:
// Precondition:
// Postcondition:
void Date::outputFormat(MonthFormat monFormat)
{
    monthFormat = monFormat;
}

// Description:
// Precondition:
// Postcondition:
void Date::outputFormat(DayOfWeekFormat dowFormat)
{
    dayOfWeekFormat = dowFormat;
}

// Description:
// Precondition:
// Postcondition:
void Date::Arithmetic(ArithmeticFormat arithFormat)
{
    arithmeticFormat = arithFormat;
}

OrderFormat Date::orderFormat = MiddleEndian;
DelimiterFormat Date::delimiterFormat = Slash;
MonthFormat Date::monthFormat = Numeric;
DayOfWeekFormat Date::dayOfWeekFormat = NoWeekday;
ArithmeticFormat Date::arithmeticFormat = Days;

ostream& operator<<(ostream& o, const Date& date)
{
    string firstDelim, secondDelim;
    string dateString = "", strDay, strMon, strYr;
    string weekDay = "Saturday"; 
    stringstream sd, sm, sy;

    sd << date.getDay(); 
    sm << date.getMonth();
    sy << date.getYear();  

    sd >> strDay;
    sm >> strMon;
    sy >> strYr;

    sd.clear(); sm.clear(); sy.clear();
    
    switch (date.delimiterFormat)
    {
        case Slash: firstDelim = '/'; secondDelim = '/'; break;
        case Dash: firstDelim = '-'; secondDelim = '-'; break;
        case Space: firstDelim = ' '; secondDelim = ' '; break;
    }

    if (date.monthFormat == Text)
    {
        strMon = date.convertMonth(date.getMonth());
        firstDelim = " ";
        secondDelim = ", ";
        if (date.orderFormat == BigEndian)
        {
            secondDelim = " ";
        }
    }

    if (date.dayOfWeekFormat == Weekday)
    {
        dateString = weekDay + ", ";
    }

    switch (date.orderFormat)
    {
        case LittleEndian: 
            dateString += strDay + firstDelim + strMon +
                        secondDelim + strYr;
            o << dateString;
            break;
        case MiddleEndian:
            dateString += strMon + firstDelim + strDay +
                        secondDelim + strYr;
            o << dateString;
            break;
        case BigEndian:
            dateString += strYr + firstDelim + strMon +
                        secondDelim + strDay;
            o << dateString;
    }

    

    return o;
}
// Description:
// Precondition:
// Postcondition:


// Description:
// Precondition:
// Postcondition:


// Description:
// Precondition:
// Postcondition:


// Description:
// Precondition:
// Postcondition:


// Description:
// Precondition:
// Postcondition:


// Description:
// Precondition:
// Postcondition:


// Description:
// Precondition:
// Postcondition:


// Description:
// Precondition:
// Postcondition:





/*
*/
