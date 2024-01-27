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
			status = fscanf(fptr, "%d", &value);
		}

		return status;
	}

	//Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(double& value, FILE* fptr) {
		bool status{};

		if (fptr != NULL) {
			status = fscanf(fptr, "%lf", &value);
		}

		return status;
	}

	//Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, cstr and returns true if it was successful, otherwise, it will return false
	bool read(char* cstr, FILE* fptr) {
		bool status{};

		if (fptr != NULL) {
			status = fscanf(fptr, ",%60[^\n]\n", cstr);
		}

		return status;
	}

	bool read(Assessment& assess, FILE* fptr) {
		double tempMark{};
		char tempTitle[61]{};
		bool status{};

		if (fptr != NULL) {
			if (read(tempMark, fptr) == 1 && read(tempTitle, fptr) == 1) {

				assess.m_mark = new double;
				assess.m_title = new char[strlen(tempTitle) + 1];

				*assess.m_mark = tempMark;
				strcpy(assess.m_title, tempTitle);
				status = true;
			}
		}

		return status;
	}

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
			for (; i < nOfRecord && readStatus; i++) {
				readStatus = read(aptr[i], fptr);
				//printf("%.2lf, %s\n", *aptr[i].m_mark, aptr[i].m_title);
			}
			if (nOfRecord != i) {
				freeMem(aptr, nOfRecord);
				i = 0;
			}
		}

		return i;
	}
}