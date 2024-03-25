/*Final Project Milestone 3
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef IOABLE_H
#define IOABLE_H
#include <iostream>
using namespace std;

namespace seneca {

	class IOAble {
	public:
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& is) = 0;
		virtual ~IOAble() = default;
	};
	ostream& operator<<(ostream& os, const IOAble& io);
	istream& operator>>(istream& is, IOAble& io);

}

#endif // !IOABLE_H
