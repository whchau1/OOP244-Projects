/*Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.h
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef TESTPATIENT_H
#define TESTPATIENT_H
#include "Patient.h"

namespace seneca {

	class TestPatient :public Patient {
		static int m_nextTestTicket;
	public:
		TestPatient();
		virtual char type() const;
		ostream& write(ostream& out) const;
		istream& read(istream& in);
		virtual ~TestPatient() = default;
	};

}

#endif // !TESTPATIENT_H
