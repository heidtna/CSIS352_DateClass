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

string Date::getWeekday(const Date& date) const
{
    Date today;
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
