/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author   John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2024/3/10 Start attempt 1
2024/3/13 Add const key words in Menu.cpp and default constructor
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
		size_t hour{}, min{};
		hour = m_mins / 60;
		min = m_mins % 60;
		os.width(2);
		os.fill('0');
		os << hour << ":";
		os.width(2);
		os << min;

		return os;
	}

	istream& Time::read(istream& is){
		size_t hour{}, min{};
		char colon{};
		is >> hour;
		is.get(colon);
		if (colon == ':') {
			is >> min;
		}
		else {
			is.unget();
			is.setstate(ios::failbit);
		}
		m_mins = hour * 60 + min;

		return is;
	}

	Time::operator unsigned int() const{
		return m_mins;
	}

	Time& Time::operator*=(int val) {
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
		result -= T.m_mins;

		return Time(result);
	}

	ostream& operator<<(ostream& os, const Time& time){
		return time.write(os);
	}

	istream& operator>>(istream& is, Time& time){
		time.read(is);

		return is;
	}

}

