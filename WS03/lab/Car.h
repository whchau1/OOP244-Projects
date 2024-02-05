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
#ifndef CAR_H
#define CAR_H

namespace seneca {
	class Car {
		char m_licencePlate[9];
		char* m_makeModel;
		char* m_serviceDesc;
		double m_cost;
	public:
		
		//Check if the object is in a safe recognizable empty state. Considered empty if the either "make and model" or "service description" is either null or an empty cstring.
		bool isEmpty() const;

		//Sets the object a safe recognizable empty state.
		void setEmpty();

		//Deallocate dynamically allocated memory for "make and model" and "service description" member variables
		void deallocateMemory();

		//Set car information and service details
		void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);

		//Displays the car in specific format
		void display() const;
	};

}

#endif