/***********************************************************************
// OOP244 Workshop #03 p1: tester program
//
// File	main.cpp
// Version 1.0
// Date: September 28, 2023
// Author: Yosef Ashibani, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Wing Ho Chau
// Seneca Email: whchau1@myseneca.ca
// ID: 150924231
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Car.h"

namespace seneca {
	class Customer {
		int m_id;
		char* m_name;
		const Car* m_car;
	public:
		//Checks if the object is in a safe empty state. A customer is considered empty if the name pointer is null or empty cString or the car pointer is null.
		bool isEmpty() const;

		//Sets the customer to a safe empty state by setting the pointers to null and the id to 0
		void setEmpty();

		//Deallocates the dynamically allocated memory for the m_name member variable
		void deallocateMemory();

		//Set the Customer name, ID and Car.
		void set(int customerId, const char* name, const Car* car);

		//Displays the Customer in specific format
		void display() const;

		//Returns the car object pointed to by m_car pointer by dereferencing it
		const Car& car()const;
	};
}

#endif // !CUSTOMER_H
