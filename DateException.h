// File:    DateException.h
// Author:  Nathan Heidt

// This file contains the header code for the
// DateException class

#ifndef _DATE_EXCEPTION_
#define _DATE_EXCEPTION_

#include <iostream>
using namespace std;

namespace DateNameSpace
{
    class DateException
    {
        public:
            string what()
            {
                return "Exception";
            }
    };
}

#endif