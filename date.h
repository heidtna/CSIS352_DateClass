// File:    date.h
// Author:  Nathan Heidt

// This file contains the header file for the Date Class

#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <stdexcept>
using namespace std;

namespace DateNameSpace
{

enum OrderFormat {LittleEndian, MiddleEndian, BigEndian};
enum DelimiterFormat {Slash, Dash, Space};
enum MonthFormat {Text, Numeric};
enum DayOfWeekFormat {Weekday, NoWeekday};
enum ArithmeticFormat {Days, Months, Years};

class Date
{
    public:
        Date();                         // Default Constructor
        Date(int, int, int);            // Constructor that takes Month, Day, Year parameters
        static Date Today();            // Method to return Date object set to current date
        int getMonth() const;           // Method to retrieve the Month attribute
        int getDay() const;             // Method to retrieve the Day attribue
        int getYear() const;            // Method to retrieve the Year attribute
        void setToday();                // Method to reset Date members to current date values
        void setDate(int, int, int);    // Method to set day, month, and year attributes
        //void setDaysInMonth(int);       // Method to set the number of days in the set month
        string convertMonth(int) const; // Method to return the name of the set integer month
        string getDayOfWeek() const;    // Method to return the day of the week for the set date
        static void outputFormat(OrderFormat);      // Method to set the order of the output
        static void outputFormat(DelimiterFormat);  // Method to set the delimiter of the output
        static void outputFormat(MonthFormat);      // Method to set the output format of the month member
        static void outputFormat(DayOfWeekFormat);  // Method to set whether the day of the week is output
        static void Arithmetic(ArithmeticFormat);   // Mehtod to set arithmetic calculations on Day, Month, or Year

        const Date& operator+=(const Date&);    // Compound assignment operator += overload
        const Date& operator-=(const Date&);    // Compound assignment operator -= overload
        bool operator>(const Date&) const;      // Relational Operator == overload
        bool operator<(const Date&) const;      // Relational Operator != overload
        bool operator>=(const Date&) const;     // Relational Operator >= overload
        bool operator<=(const Date&) const;     // Relational Operator <= overload
        bool operator==(const Date&) const;     // Relational Operator > overload
        bool operator!=(const Date&) const;     // Relational Operator < overload

        friend ostream& operator<<(ostream&, const Date&);  // Output Overload
    
    private:
        int day;
        int month;
        int year;
        static OrderFormat orderFormat; 
        static DelimiterFormat delimiterFormat;
        static MonthFormat monthFormat;
        static DayOfWeekFormat dayOfWeekFormat;       // Static attribute to determine output format
        static ArithmeticFormat arithmeticFormat;     // Static attribute to determine arithmetic calculations

};
bool isValidDate(int, int, int);// Method to check if date values result in valid date
bool isLeapYear(int);           // Method to determine if the set year is a leap year
int daysInMonth(int, int);

istream& operator>>(istream&, Date&);   // Input Overload

class DateException
{
    public:
        DateException(const string& m = "");
        string what();
    
    private:
        string message;
};


}

#endif