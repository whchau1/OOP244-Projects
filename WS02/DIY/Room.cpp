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
#include "Room.h"
using namespace std;

namespace seneca {

	// sets the Room by allocating a dynamic array of guests and setting the room number 
	// (no validation is done for room number)
	void set(Room& room, int numberOfGuests, const char* roomNumber) {

		//Set number of guest and room number
		room.m_noOfGuests = numberOfGuests;
		strcpy(room.m_roomNumber, roomNumber);

		//Check struct m_guests value before allocate memory
		if (room.m_guests != nullptr) {
			vacate(*room.m_guests);
		}

		//Allocate memory
		room.m_guests = new Guest[numberOfGuests];

	}

	// Prints the room number and names of the guests in the following lines with four 
	// spaces of indentaion 
	// See correct_output.txt for the exact format
	void print(const Room& room) {

		if (strlen(room.m_roomNumber) != 0) {  //Print room number if the room number is not empty
			cout << "Room Number: " << room.m_roomNumber << endl;
		}
		else {  //If room number is empty print empty message
			cout << "Empty Room!" << endl;
		}

		//Print guest detail
		for (int i = 0; i < room.m_noOfGuests; i++) {
			cout << "    ";
			print(room.m_guests[i]);
		}
	}

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room& room) {
		char roomNum[6]{};
		int ppl{};

		//Get booking details
		cout << "Room number: ";
		cin >> roomNum;
		cin.ignore(500, '\n');

		cout << "Number of guests: ";
		cin >> ppl;
		cin.ignore(500, '\n');

		//Set struct
		set(room, ppl, roomNum);
		for (int i = 0; i < room.m_noOfGuests; i++) {
			cout << i + 1 << ":" << endl;
			book(room.m_guests[i]);
		}
	}

	// vacates the room by dallocating all the memory used.
	void vacate(Room& room) {
		for (int i = 0; i < room.m_noOfGuests; i++) {
			delete[] room.m_guests[i].m_firstName;
			delete[] room.m_guests[i].m_lastName;
			room.m_guests[i].m_firstName = nullptr;
			room.m_guests[i].m_lastName = nullptr;
		}
		delete[] room.m_guests;
		room.m_guests = nullptr;
		room.m_noOfGuests = 0;
		*room.m_roomNumber = {'\0'};
	}
}