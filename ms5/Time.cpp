/*Final Project Milestone 5
Module: Time
Filename: Time.cpp
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Time.h"
#include "Utils.h"

namespace seneca {

	Time::Time(unsigned int min){
		m_mins = min;
	}

	Time& Time::reset(){		
		m_mins = U.getTime();

		return *this;
	}

	ostream& Time::write(ostream& os) const {
		size_t hour = m_mins / 60;
		size_t min = m_mins % 60;
		os.width(2);
		os.fill('0');
		os << hour << ":";
		os.width(2);
		os << min;
		os.fill(' ');

		return os;
	}

	istream& Time::read(istream& is){
		size_t hour{}, min{};

		is >> hour;
		if (is.peek() == ':') {
			is.ignore();  //Consume the ':'
			is >> min;
			m_mins = hour * 60 + min;
		}
		else {
			is.setstate(ios::failbit);
		}

		return is;
	}

	Time::operator unsigned int() const{
		return m_mins;
	}

	Time& Time::operator*=(const int val) {
		m_mins *= val;

		return *this;
	}

	Time& Time::operator-=(const Time& D){
		if (m_mins < D.m_mins) {
			m_mins += 24 * 60;
		}
		m_mins -= D.m_mins;

		return *this;
	}

	Time Time::operator-(const Time& T) const{
		size_t result = m_mins;
		
		if (result < T.m_mins) {
			result += 24 * 60;
		}

		return Time(result -= T.m_mins);
	}

	ostream& operator<<(ostream& os, const Time& time){
		return time.write(os);
	}

	istream& operator>>(istream& is, Time& time){
		return time.read(is);
	}

}

