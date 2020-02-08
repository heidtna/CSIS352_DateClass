// File:    date.cpp
// Author:  Nathan Heidt

// This file contains the implementation file for 
// the Date Class

#include <iostream>
#include <ctime>
#include "date.h"
using namespace std;
using namespace DateNameSpace;

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
Date::Date(int d, int m, int y)
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
void Date::setDate(int newDay, int newMonth, int newYear)
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


ostream& operator<<(ostream& o, const Date& date)
{
    string dateString;

    switch (date.orderFormat)
    {
        case LittleEndian: break;
    }

    return o;
}



/*
*/
