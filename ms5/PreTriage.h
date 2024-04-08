/*Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.h
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef PRETRIAGE_H
#define PRETRIAGE_H
#include "Time.h"
#include "Patient.h"
#include "Menu.h"

namespace seneca {

	const int MAX_LINEUP = 100;

	class PreTriage {
		Time m_contaigenWaitTime{};
		Time m_triageWaitTime{};
		Patient* m_lineupPatients[MAX_LINEUP]{};
		char* m_filename{};
		int m_numLineup{};

		int getWaitTime(const Patient& patients) const;
		PreTriage& load();
		void save() const;
		void lineup() const;
		void admit();
		int indexOfFirstInLine(const char type) const;
		Time setAverageWaitTime(Patient& patient);
		PreTriage& registerPatient();
		ostream& printHeaderLine(int qty, char symbol, int header) const;
		ostream& findCustomerByType(ostream& out, const char type) const;
	public:
		PreTriage(const char* filename, size_t CWaitTime = 15, size_t TWaitTime = 5);
		PreTriage(const PreTriage& src);
		PreTriage& operator=(const PreTriage& src);
		virtual ~PreTriage();
		PreTriage& run();
	};

}

#endif // !PRETRIAGE_H