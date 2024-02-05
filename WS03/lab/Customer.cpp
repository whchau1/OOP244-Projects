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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Customer.h"
#include "Car.h"
using namespace std;

namespace seneca {
	//checks if the object is in a safe empty state.A customer is considered empty if the name pointer is null or empty cString or the car pointer is null.
	bool Customer::isEmpty() const
	{
		return m_name == nullptr || m_car == nullptr || m_name[0] == '\0';
	}

	//Sets the customer to a safe empty state by setting the pointers to null and the id to 0
	void Customer::setEmpty()
	{
		m_id = 0;
		m_name = nullptr;
		m_car = nullptr;
	}

	//Deallocates the dynamically allocated memory for the m_name member variable
	void Customer::deallocateMemory()
	{
		if (m_name != nullptr) {
			delete[] m_name;
		}
		m_name = nullptr;
	}

	//Set the Customer name, ID and Car.
	void Customer::set(int customerId, const char* name, const Car* car)
	{
		deallocateMemory();
		if (name != nullptr && name[0] != '\0' && car != nullptr) {
			m_name = new char[strlen(name) + 1];

			m_id = customerId;
			strcpy(m_name, name);
			m_car = car;
		}
	}

	//Displays the Customer in specific format
	void Customer::display() const
	{
		if (m_name != nullptr && m_car != nullptr && m_name[0] != '\0') {

			cout.unsetf(ios::right);
			cout.width(15);
			cout.setf(ios::left);
			cout << "Customer ID:";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_id << endl;

			cout.unsetf(ios::right);
			cout.width(15);
			cout.setf(ios::left);
			cout << "First Name:";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_name << endl;


			m_car->display();
		}

	}

	//Returns the car object pointed to by m_car pointer by dereferencing it
	const Car& Customer::car() const
	{
		return *m_car;
	}
}