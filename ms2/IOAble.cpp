#include "IOAble.h"
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
#include "IOAble.h"

namespace seneca {

	ostream& seneca::operator<<(ostream& os, IOAble io) {
		return io.write(os);
	}

	istream& operator>>(istream& is, IOAble io){
		return io.read(is);
	}

}
