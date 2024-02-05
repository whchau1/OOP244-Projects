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
#include "Car.h"
using namespace std;

namespace seneca{

	//Check if the object is in a safe recognizable empty state. Considered empty if the either "make and model" or "service description" is either null or an empty cstring.
	bool seneca::Car::isEmpty() const
	{
		return m_makeModel == nullptr || m_serviceDesc == nullptr || m_makeModel[0] == '\0' || m_serviceDesc[0] == '\0';
	}

	//Sets the object a safe recognizable empty state.
	void Car::setEmpty()
	{
		for (int i = 0; i < 9; i++) {
			m_licencePlate[i] = '\0';
		}
		m_cost = 0.00;
		m_makeModel = nullptr;
		m_serviceDesc = nullptr;
	}

	//Deallocate dynamically allocated memory for "make and model" and "service description" member variables
	void Car::deallocateMemory()
	{
		if (m_makeModel != nullptr || m_serviceDesc != nullptr) {
			delete[] m_makeModel;
			delete[] m_serviceDesc;

			m_makeModel = nullptr;
			m_serviceDesc = nullptr;
		}
	}

	//Set car information and service details
	void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost)
	{
		deallocateMemory();
		if (carMakeModel != nullptr && serviceDesc != nullptr && carMakeModel[0] != '\0' && serviceDesc[0] != '\0') {
			m_makeModel = new char[strlen(carMakeModel) + 1];
			m_serviceDesc = new char[strlen(serviceDesc) + 1];
			
			strcpy(m_licencePlate, plateNo);
			strcpy(m_makeModel, carMakeModel);
			strcpy(m_serviceDesc, serviceDesc);
			m_cost = serviceCost;
		}
	}

	//Displays the car in specific format
	void Car::display() const
	{
		if (m_licencePlate != nullptr && !isEmpty()) {

			cout.unsetf(ios::right);
			cout.width(15);
			cout.setf(ios::left);
			cout << "License Plate:";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_licencePlate << endl;

			cout.unsetf(ios::right);
			cout.width(15);
			cout.setf(ios::left);
			cout << "Model:";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_makeModel << endl;
			
			cout.unsetf(ios::right);
			cout.width(15);
			cout.setf(ios::left);
			cout << "Service Name:";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_serviceDesc << endl;
			
			cout.unsetf(ios::right);
			cout.width(15);
			cout.setf(ios::left);
			cout << "Service Cost:";
			cout.width(20);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_cost << endl;

		}

	}


}
