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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "Assessment.h"

namespace seneca {

	//Reads one integer from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(int& value, FILE* fptr) {
		bool status{};

		if (fptr != NULL) {
			status = fscanf(fptr, "%d\n", &value) == 1;
		}

		return status;
	}

	//Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(double& value, FILE* fptr) {
		bool status{};

		if (fptr != NULL) {
			status = fscanf(fptr, "%lf", &value) == 1;
		}

		return status;
	}

	//Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, cstr and returns true if it was successful, otherwise, it will return false
	bool read(char* cstr, FILE* fptr) {
		bool status{};

		if (fptr != NULL) {
			status = fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
		}

		return status;
	}

	//Read a double value for the mark and a string for the title into a temporary local double variable and a 60-character lone cString (+1 for null).
	bool read(Assessment& assess, FILE* fptr) {
		double tempMark{};
		char tempTitle[61]{};
		bool status{};

		if (fptr != NULL) {
			if (read(tempMark, fptr) == 1 && read(tempTitle, fptr) == 1) {

				//Allcate memory
				assess.m_mark = new double;
				assess.m_title = new char[strlen(tempTitle) + 1];

				//Copy the value to struct
				*assess.m_mark = tempMark;
				strcpy(assess.m_title, tempTitle);
				status = true;
			}
		}

		return status;
	}

	//Release memory
	void freeMem(Assessment*& aptr, int size) {
		for (int i = 0; i < size; i++) {
			delete aptr[i].m_mark;
			delete[] aptr[i].m_title;
		}
		delete[] aptr;
	}

	int read(Assessment*& aptr, FILE* fptr) {
		int nOfRecord{}, readStatus = 1, i{};
		
		//Read the first integer to define how many record is going to read
		if (read(nOfRecord, fptr)) {

			aptr = new Assessment[nOfRecord]; //Allocate memory
			for (; i < nOfRecord && read(aptr[i], fptr); i++) {}
			if (nOfRecord != i) {
				freeMem(aptr, i);
				i = 0;
			}
		}

		return i;
	}
}