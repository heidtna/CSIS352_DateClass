// File:    date.cpp
// Author:  Nathan Heidt

// This file contains the implementation file for 
// the Date Class

#include <iostream>
#include <sstream>
#include <ctime>
#include "date.h"
using namespace std;

namespace DateNameSpace
{

// Description: Default constructor
// Precondition: None
// Postcondition: Date members are set to reflect current date
Date::Date()
{
    tm *current;
    time_t lt;
    lt = time(0);
    current = localtime(&lt);

    day = current->tm_mday;
    month = current->tm_mon+1;
    year = current->tm_year+1900;
}

// Description:
// Precondition:
// Postcondition:
Date::Date(int m, int d, int y)
{
    if (isValidDate(m, d, y))
    {
        year = y;
        month = m;
        day = d;
    }
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
    if (isValidDate(newMonth, newDay, newYear))
    {
        year = newYear;
        month = newMonth;
        day = newDay;
    }
}

// Description:
// Precondition:
// Postcondition:
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

string Date::getDayOfWeek() const
{
    int centuries;
    int months;
    int dayOfWeek;

    centuries = (3 - year / 100 % 4) * 2;

    switch (month)
    {
        case 1: if (isLeapYear(year))
                {
                    months = 6;
                }
                else
                {
                    months = 0;
                }
                break;
        case 2: if (isLeapYear(year))
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
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";      
    }        
    return 0;    
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
        dateString += date.getDayOfWeek();
        dateString += ", ";
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

// Description:
// Precondition:
// Postcondition:
bool isValidDate(int chkMonth, int chkDay, int chkYear)
{
    if (chkMonth < 1 || chkMonth > 12)
    {
        throw DateException("Date Exception: Month is out of range");
        return 0;
    }
    
    else if (chkDay > daysInMonth(chkMonth, chkYear))
    {
        throw DateException("Date Exception: Day is out of range");
        return 0;
    }
    return 1;
}

// Description:
// Precondition:
// Postcondition:
bool isLeapYear(int Year)
{
    return Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0;
}

// Description:
// Precondition:
// Postcondition:
int daysInMonth(int monthToCheck, int inYear)
{
    switch (monthToCheck)
    {
        case 1  :   return 31;
        case 2  :   if (isLeapYear(inYear))
                    {
                        return 29;
                    }
                    else
                    {
                        return 28;
                    }
        case 3  :   return 31;
        case 4  :   return 30;
        case 5  :   return 31;
        case 6  :   return 30;
        case 7  :   return 31;
        case 8  :   return 31;
        case 9  :   return 30;
        case 10 :   return 31;
        case 11 :   return 30;
        case 12 :   return 31;
        default :   return -1;
    }
    return 0;
}

DateException::DateException(const string& m)
{
    message = m;
}

string DateException::what()
{
    return message;
}

}

/*
*/
