/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File	main.cpp
// Version 1.0
//
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Wing Ho Chau
//Senece Email: whchau1@myseneca.ca
//Student ID  : 150924231
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef ASSESSMENT_H
#define ASSESSMENT_H

struct Assessment {
	double* m_mark;
	char* m_title;
};

namespace seneca {
	
	//Reads one integer from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(int& value, FILE* fptr);

	//Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(double& value, FILE* fptr);

	//Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, cstr and returns true if it was successful, otherwise, it will return false
	bool read(char* cstr, FILE* fptr);

	//Read a double value for the mark and a string for the title into a temporary local double variable and a 60-character lone cString (+1 for null).
	bool read(Assessment& assess, FILE* fptr);

	//Release memory
	void freeMem(Assessment*& aptr, int size);

	//	//Allocate memory to Assessment struct and read the data in file for the members
	int read(Assessment*& aptr, FILE* fptr);
}

#endif