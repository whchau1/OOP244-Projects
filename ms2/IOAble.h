/*Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef IOABLE_H
#define IOABLE_h
#include <iostream>
using namespace std;

namespace seneca {

	class IOAble {
	public:
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& is) = 0;
		virtual ~IOAble() = 0;
	};
	ostream& operator<<(ostream& os, IOAble io);
	istream& operator>>(istream& is, IOAble io);
}

#endif // !IOABLE_H
