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
            Date();                 // Default Constructor
            Date(int, int, int);    // Constructor that takes Month, Day, Year parameters
            int getMonth() const;  // Method to retrieve the Month attribute
            int getDay() const;    // Method to retrieve the Day attribue
            int getYear() const;   // Method to retrieve the Year attribute
            void setDate(int, int, int);        // Method to set day, month, and year attributes
            void isLeapYear(int);
            static void outputFormat(OrderFormat);     // Mehtod to determine output format
            static void outputFormat(DelimiterFormat);
            static void outputFormat(MonthFormat);
            static void outputFormat(DayOfWeekFormat);
            static void Arithmetic(ArithmeticFormat);      // Mehtod to set arithmetic calculations on Day, Month, or Year

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
            bool leapYear;
            static OrderFormat orderFormat; 
            static DelimiterFormat delimiterFormat;
            static MonthFormat monthFormat;
            static DayOfWeekFormat dayOfWeekFormat;       // Static attribute to determine output format
            static ArithmeticFormat arithmeticFormat;     // Static attribute to determine arithmetic calculations

    };
    istream& operator>>(istream&, Date&);   // Input Overload
}
#endif