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
		Time m_contaigenWaitTime{};  //Wait time of contaigen test patient
		Time m_triageWaitTime{};  //Wait time of triage patient
		Patient* m_lineupPatients[MAX_LINEUP]{};  //The patients in the line
		char* m_filename{};  //Filename stored the line
		int m_numLineup{};  //The number of patient in the line

		/// <summary>
		/// Get the total estimated wait time based on the type of given patient
		/// </summary>
		/// <param name="patients">- patient information</param>
		/// <returns>time in min</returns>
		int getWaitTime(const Patient& patient) const;

		/// <summary>
		/// Receives the reference of the admitting patient and adjusts the average wait time of that type of patient based on the admittance time of the patient.
		/// </summary>
		/// <param name="patient">- admitted patient</param>
		/// <returns>A reference of current object</returns>
		PreTriage& setAverageWaitTime(Patient& patient);

		/// <summary>
		/// Receives a character representing the type of patient (C for Contaigen, T for Triage).
		/// Finds the index of the first patient in line that matches a specified type.
		/// </summary>
		/// <param name="type">Type of patient</param>
		/// <returns>Index of first patient of the given type in line</returns>
		int indexOfFirstInLine(const char type) const;

		/// <summary>
		/// Loads the average wait times and the patient records from the data file and stores them in the lineup array of pointers.
		/// </summary>
		/// <returns>A reference of current object</returns>
		PreTriage& load();

		/// <summary>
		/// Opens the data file for output.
		/// Inserts the average Contaigen Test and Triage wait times and patient lineup record, comma-separated into the data file. 
		/// </summary>
		void save() const;

		/// <summary>
		/// Registers a new patient
		/// </summary>
		/// <returns>A reference of current object</returns>
		PreTriage& registerPatient();

		/// <summary>
		/// Custom member function
		/// Get the user detail by input and print out the issued ticket information
		/// </summary>
		/// <returns>A reference of current object</returns>
		PreTriage& setPatient();

		/// <summary>
		/// Calls the next patient in line to be admitted to the contagion test centre or Triage centre.
		/// Remove called patient in line
		/// </summary>
		/// <returns>A reference of current object</returns>
		PreTriage& admit();

		/// <summary>
		/// 
		/// </summary>
		ostream& lineup() const;
		
		/// <summary>
		/// Print Line or Lineup header
		/// </summary>
		/// <param name="qty">- Number of symbols for a line</param>
		/// <param name="symbol">- Symbol</param>
		/// <param name="header">- 1 to enable lineup header, 0 to disable</param>
		/// <returns></returns>
		ostream& printHeaderLine(int qty, char symbol, int header) const;

	public:
		/// <summary>
		/// Constructor initializes the object using the data file name.
		/// Wait time of contaigen test patient is 15 by default.
		/// Wait time of triage patient is 5 by default.
		/// Call load() function after initialization
		/// </summary>
		/// <param name="filename">- Filename</param>
		/// <param name="CWaitTime">- Wait time of contaigen test patient</param>
		/// <param name="TWaitTime">- Wait time of triage patient</param>
		PreTriage(const char* filename, size_t CWaitTime = 15, size_t TWaitTime = 5);

		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="src">- Right operand to copy(PreTriage object)</param>
		PreTriage(const PreTriage& src);

		/// <summary>
		/// Copy assignment operator
		/// </summary>
		/// <param name="src">- Right operand to copy(PreTriage object)</param>
		/// <returns>A reference of current object</returns>
		PreTriage& operator=(const PreTriage& src);

		/// <summary>
		/// Virtual destructor
		/// Save the current lineup information to a file.
		/// Deallocate memory resources for m_filename and m_lineupPatients
		/// </summary>
		virtual ~PreTriage();

		/// <summary>
		/// Runs the PreTriage main application.
		/// </summary>
		/// <returns>A reference of current object</returns>
		PreTriage& run();
	};

}

#endif // !PRETRIAGE_H