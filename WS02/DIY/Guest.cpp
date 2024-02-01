/***********************************************************************
// OOP244 Workshop #02 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date: September 25, 2023
// Author: Yosef Ashibani, Fardad Soleimanloo
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
#include <iostream>
#include <cstring>
#include "Guest.h"
using namespace std;

namespace seneca {

	// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
	void set(Guest& guest, const char* first, const char* last, int age) {
		//m_adult set to false by default
		guest.m_adult = false;

		//Check firstName and lastName value before allocate memory
		if (guest.m_firstName != nullptr || guest.m_lastName != nullptr) {
			vacate(guest);
		}

		if (first != nullptr && last != nullptr && first[0] != '\0' && last[0] != '\0') {
			//allocate memory to firstname and lastname
			guest.m_firstName = new char[strlen(first) + 1];
			guest.m_lastName = new char[strlen(last) + 1];

			//set guest
			strcpy(guest.m_firstName, first);
			strcpy(guest.m_lastName, last);
			guest.m_adult = age >= 18;
		}

	}

	// Prints the guest name:
	// "Name Surname(child)"
	// The child flag is printed if the guest is not an adult
	// and if the names are not set, "Vacated!" is printed.
	void print(const Guest& guest) {
		
		if (guest.m_firstName == nullptr && guest.m_lastName == nullptr) { //Print vacate message if there is no guest
			cout << "Vacated!" << endl;
		}
		else {  //Print guest detail if there is guest
			cout << guest.m_firstName << " " << guest.m_lastName;
			if (!guest.m_adult) {
				cout << "(Child)";
			}
			cout << endl;
		}
	}

	// books the guest information from the console:
	// Name: Jake<ENTER>
	// Lastname: Doe<ENTER>
	// Age: 10<ENTER>
	void book(Guest& guest) {
		char first[MAX_STRING_LEN]{}, last[MAX_STRING_LEN]{};
		int age{};

		//Get guest input
		cout << "Name: ";
		cin >> first;
		cin.ignore(500,'\n');
		cout << "Lastname: ";
		cin >> last;
		cin.ignore(500, '\n');
		cout << "Age: ";
		cin >> age;
		cin.ignore(500, '\n');

		//Set struct
		set(guest, first, last, age);
	}

	// vacates the guest by dallocating its memory.
	void vacate(Guest& guest) {
		delete[] guest.m_firstName;
		delete[] guest.m_lastName;
		guest.m_firstName = nullptr;
		guest.m_lastName = nullptr;
	}
}