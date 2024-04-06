/*Final Project Milestone 5
Module: Patient
Filename: Patient.h
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
using namespace std;

namespace seneca {

	const int MAX_PATIENT_NAME = 50;
	const int MIN_OHIPNUMBER = 100000000;
	const int MAX_OHIPNUMBER = 999999999;

	class Patient : public IOAble{
		char* m_name{};
		int m_OHIP{};
		Ticket m_ticket;
		Patient& allocateCopyName(const char* buffer);
	public:
		Patient(int ticketNum);
		Patient(const Patient& src);
		Patient& operator=(const Patient& src);
		virtual ~Patient();
		virtual char type() const = 0;
		bool operator==(const char ch) const;
		bool operator==(const Patient& p2) const;
		void setArrivalTime();
		Time time() const;
		int number() const;
		operator bool() const;
		operator char* () const;
		ostream& write(ostream& os) const;
		istream& read(istream& is);
	};

}

#endif // !PATIENT_H
