/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.h
Version 1.0
Author   John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2024/3/10 Start attempt 1
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

namespace seneca{
	class Time {
		size_t m_mins{};
	public:
		Time(unsigned int min = 0u);

		Time& reset();
		ostream& write(ostream& os) const;
		istream& read(istream& is);
		operator unsigned int()const;
		Time& operator*= (int val);
		Time& operator-= (const Time& D);
		Time operator-(const Time& T)const;
	};
	ostream& operator<<(ostream& os, const Time& time);
	istream& operator>>(istream& is, Time& time);
}

#endif // !TIME_H
