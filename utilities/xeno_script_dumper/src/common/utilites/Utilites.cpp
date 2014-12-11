// $Id: Utilites.cpp 93 2006-11-12 13:49:02Z einherjar $

#include <string.h>
#include "Utilites.h"



int
power_of_two(int input)
{
    int value = 1;
    while ( value < input ) value <<= 1;
    return value;
}
