/*Final Project Milestone 5
Module: TestPatient
Filename: TestPatient.cpp
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "TestPatient.h"

namespace seneca {

	static int m_nextTestTicket{ 1 };

	TestPatient::TestPatient() :Patient(m_nextTestTicket++) {}

	char TestPatient::type() const {
		return 'C';
	}

	ostream& TestPatient::write(ostream& out) const {
		if (&out == &cout) {
			out << "Contagion TEST" << endl;
		}
		Patient::write(out);

		return out;
	}

	istream& TestPatient::read(istream& in) {
		Patient::read(in);
		if (&in != &cin) {
			m_nextTestTicket = Patient::number() + 1;
		}

		return in;
	};

}