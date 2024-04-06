/*Final Project Milestone 5
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
#include "IOAble.h"

namespace seneca {

	ostream& operator<<(ostream& os, const IOAble& io) {
		return io.write(os);
	}

	istream& operator>>(istream& is, IOAble& io) {
		return io.read(is);
	}

}
