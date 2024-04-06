/*Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef TRIAGEPATIENT_H
#define TRIAGEPATIENT_H
#include "Patient.h"

namespace seneca {

	const int MAX_SYMPTOMS_LEN = 511;

	class TriagePatient :public Patient {
		static int m_nextTriageTicket;
		char* m_symptoms{};
		TriagePatient& allocateCopyName(const char* buffer);
	public:
		TriagePatient();
		TriagePatient(const TriagePatient& src);
		TriagePatient& operator=(const TriagePatient& src);
		virtual char type() const;
		ostream& write(ostream& out) const;
		istream& read(istream& in);
		virtual ~TriagePatient();
	};

}

#endif // !TRIAGEPATIENT_H
