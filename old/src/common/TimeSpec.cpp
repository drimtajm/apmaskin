/*
 * TimeSpec.cpp
 *
 *  Created on: 2009-apr-26
 *      Author: bege
 */

#include <time.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "TimeSpec.h"

using std::ostream;
using std::setfill;
using std::setw;
using std::stringstream;

ostream & operator <<(ostream & out, const TimeSpec & p)
{
	stringstream str;
	str << p.time.tv_sec << "." << setfill('0') << setw(9) << p.time.tv_nsec;
	return out << str.str();
}









