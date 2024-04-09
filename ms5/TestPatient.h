/*Final Project Milestone 5
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
	public:
		/// <summary>
		/// Constructor initializes the base class Patient with the m_nextTestTicket
		/// </summary>
		TestPatient();

		/// <summary>
		/// Get the type of patient
		/// </summary>
		/// <returns>Type charater 'C'</returns>
		virtual char type() const;

		/// <summary>
		/// Insert the information of the current object to ostream reference with different format. The format is based on the given ostream object.
		/// </summary>
		/// <param name="out">ostream object</param>
		/// <returns>A reference of ostream object</returns>
		ostream& write(ostream& out) const;

		/// <summary>
		/// Extract patient information from the istream. The extract format is based on the given istream object.
		/// If the istream object is cin, m_nextTestTicket will equal the patient ticket number plus 1.
		/// </summary>
		/// <param name="in">istream object</param>
		/// <returns>A reference of istream object</returns>
		istream& read(istream& in);

		/// <summary>
		/// Default destructor
		/// </summary>
		virtual ~TestPatient() = default;
	};

}

#endif // !TESTPATIENT_H
