/*
 * TimeSpec.h
 *
 *  Created on: 2009-apr-26
 *      Author: bege
 */

#ifndef TIMESPEC_H_
#define TIMESPEC_H_

#include <ostream>
#include <cassert>
#include <stdexcept>

/**
 * Wrapper class for the Posix timespec struct. It holds seconds and nanoseconds
 * and has a few arithmetic operators.
 */
class TimeSpec {
    static const long int LONG_MSB = 0x80000000L;
public:
    TimeSpec() {
        time.tv_sec = 0;
        time.tv_nsec = 0;
    }

    TimeSpec(const time_t sec, const long  nanosec) {
        time.tv_sec = sec;
        time.tv_nsec = nanosec;
    }

    TimeSpec(timespec timespec) : time(timespec){ }

    /**
	 * Get the current time.
	 */
    void getTime() {
        clock_gettime(CLOCK_REALTIME, &time);
    }

    const TimeSpec operator -(const TimeSpec & rhs) const {
        TimeSpec tmp = *this;
        tmp -= rhs;
        return tmp;
    }

    const bool operator <(const TimeSpec & rhs) const {
        return time.tv_sec < rhs.time.tv_sec || time.tv_nsec < rhs.time.tv_nsec;
    }

    const bool operator >(const TimeSpec & rhs) const {
        return rhs < *this;
    }

	TimeSpec & operator -=(const TimeSpec & rhs) {
		bool nsecOverflow = false;
		long diff = time.tv_nsec - rhs.time.tv_nsec;
		if ((time.tv_nsec ^ diff) & (rhs.time.tv_nsec ^ diff) & LONG_MSB) { //underflow
			nsecOverflow = true;
			diff = NSEC_MAX + diff;
		}
		time.tv_nsec = diff;

		diff = time.tv_sec - rhs.time.tv_sec;
		if(nsecOverflow) {
			diff -= 1;
		}
		if ((time.tv_sec ^ diff) & (rhs.time.tv_sec ^ diff) & LONG_MSB) { //underflow
		        throw std::runtime_error("Can't handle negative time");
		}
		time.tv_sec = diff;
		return *this;
	}

    TimeSpec & operator =(const TimeSpec & rhs) {
		time = rhs.time;
		return *this;
	}

	/**
	 * Conversion operator to POSIX struct.
	 */
	operator const timespec() {
		return time;
	}

	virtual ~TimeSpec() { }

	friend std::ostream & operator <<(std::ostream & out, const TimeSpec & p);
private:
	static const signed long NSEC_MAX = 1e9;
	timespec time;
};

#endif /* TIMESPEC_H_ */
