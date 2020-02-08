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
    enum orderFormat {LittleEndian, MiddleEndian, BigEndian};
    enum delimiterFormat {Slash, Dash, Space};
    enum monthFormat {Text, Numeric};
    enum dayOfWeekFormat {Weekday, NoWeekday};
    enum arithmeticFormat {Day, Month, Year};

    class Date
    {
        public:
            Date();                 // Default Constructor
            Date(int, int, int);    // Constructor that takes Month, Day, Year parameters
            void getMonth() const;  // Method to retrieve the Month attribute
            void getDay() const;    // Method to retrieve the Day attribue
            void getYear() const;   // Method to retrieve the Year attribute
            void setDate(int, int, int);        // Method to set day, month, and year attributes
            static void outputFormat(orderFormat);     // Mehtod to determine output format
            static void outputFormat(delimiterFormat);
            static void outputFormat(monthFormat);
            static void outputFormat(dayOfWeekFormat);
            static void Arithmetic(arithmeticFormat);      // Mehtod to set arithmetic calculations on Day, Month, or Year

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
            static orderFormat order; 
            static delimiterFormat delimiter;
            static monthFormat month;
            static dayOfWeekFormat dayOfWeek;       // Static attribute to determine output format
            static arithmeticFormat arithmetic;     // Static attribute to determine arithmetic calculations

    };
    istream& operator>>(istream&, Date&);   // Input Overload
}
#endif