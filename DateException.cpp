// File:    DateException.cpp
// Author:  Nathan Heidt

// This file contains the implimentation code 
// for the DateException class

#include "DateException.h"

namespace DateNameSpace
{

DateException::DateException(const string& m)
{
    message = m;
}

string DateException::what()
{
    return message;
}

}