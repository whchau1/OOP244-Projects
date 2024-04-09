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

	const int MAX_PATIENT_NAME = 50;  //Maximum length of patient name 
	const int MIN_OHIPNUMBER = 100000000;  //Minumum number of OHIP number
	const int MAX_OHIPNUMBER = 999999999;  //Maximum number of OHIP number

	class Patient : public IOAble{
		char* m_name{};  //Store patient name dynamically.
		int m_OHIP{};  //OHIP number
		Ticket m_ticket; //Ticket number and issue time

		/// <summary>
		/// Allocate memory to data member m_name and get a copy from the provide string
		/// </summary>
		/// <param name="buffer">- String to copy</param>
		/// <returns>A reference of current object</returns>
		Patient& allocateCopyName(const char* buffer);

	public:
		/// <summary>
		/// Instantiate a Patient object by providing a ticket number (an integer)
		/// </summary>
		/// <param name="ticketNum">- Ticket number</param>
		Patient(const int ticketNum);

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="src">- Right operand to copy(Patient object)</param>
		Patient(const Patient& src);

		/// <summary>
		/// Copy assignment operator
		/// </summary>
		/// <param name="src">- Right operands to copy(Patient object)</param>
		/// <returns>A reference of current object</returns>
		Patient& operator=(const Patient& src);

		/// <summary>
		/// Virtual destructor to deallocate resources for m_name.
		/// </summary>
		virtual ~Patient();

		/// <summary>
		/// Pure virtual function. Get the type of patient.
		/// </summary>
		/// <returns>Type of patient</returns>
		virtual char type() const = 0;

		/// <summary>
		/// Compare the current object with a single character (the right operand). Return true if the values returned by the type function of this patient and the provided single character are identical
		/// </summary>
		/// <param name="ch">- Charater to compare</param>
		/// <returns>True if the type of patient equal to the given type character, false if not</returns>
		bool operator==(const char ch) const;

		/// <summary>
		/// Compare the current object to another patient. Return true if the type of the current patient is the same as the type of the other patient; otherwise, return false.
		/// </summary>
		/// <param name="p2">- Right operand to compare(Patient object)</param>
		/// <returns>True if left Patient object and right Patient object are same type, false if not</returns>
		bool operator==(const Patient& p2) const;

		/// <summary>
		/// Sets the time of the patient's ticket to the current time
		/// </summary>
		/// <returns>A reference of current object</returns>
		Patient& setArrivalTime();

		/// <summary>
		/// Retrieve the time of the patient's ticket
		/// </summary>
		/// <returns>The time of the patient's ticket</returns>
		Time time() const;

		/// <summary>
		/// Retrieve the ticket number of the patient's ticket
		/// </summary>
		/// <returns>Ticket number</returns>
		int number() const;

		/// <summary>
		/// Check if the Patient object is in a valid state. Return true if it is in valid state, false if it is not.
		/// </summary>
		operator bool() const;

		/// <summary>
		/// Cast current object to a constant character pointer. Return the address of the patient's name.
		/// </summary>
		operator char* () const;

		/// <summary>
		/// Insert the information of the current object to ostream reference with different format. The format is based on the given ostream object.
		/// </summary>
		/// <param name="os">- The type of ostream object</param>
		/// <returns>A reference of ostream object</returns>
		ostream& write(ostream& os) const;

		/// <summary>
		/// Extract patient information from the istream. The extract format is based on the given istream object.
		/// </summary>
		/// <param name="is">- istream object</param>
		/// <returns>A reference of istream object</returns>
		istream& read(istream& is);
	};

}

#endif // !PATIENT_H
