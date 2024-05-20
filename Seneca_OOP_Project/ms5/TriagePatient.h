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
		char* m_symptoms{}; //Store the symptoms dynamically

		/// <summary>
		/// Allocate memory to m_symptoms and copy the string from provided string
		/// </summary>
		/// <param name="src">Source to copy</param>
		/// <returns>A reference of current object</returns>
		TriagePatient& allocateCopySymptoms(const char* src);

	public:
		/// <summary>
		/// Constructor initialize the base class Patient with the m_nextTriageTicket
		/// </summary>
		TriagePatient();

		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="src">- Right operand to copy (TriagePatient object)</param>
		TriagePatient(const TriagePatient& src);

		/// <summary>
		/// Copy assignment operator
		/// </summary>
		/// <param name="src">- Right operand to copy (TriagePatient object)</param>
		/// <returns>A reference of current object</returns>
		TriagePatient& operator=(const TriagePatient& src);

		/// <summary>
		/// Get the type of patient
		/// </summary>
		/// <returns>Type charater 'T'</returns>
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
		/// Virtual destructor to deallocate resources for m_symptoms 
		/// </summary>
		virtual ~TriagePatient();
	};

}

#endif // !TRIAGEPATIENT_H
