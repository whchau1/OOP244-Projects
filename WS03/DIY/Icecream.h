/***********************************************************************
// OOP244 Workshop #03 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date: September 28, 2023
// Author: Yosef Ashibani
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
#ifndef ICECREAM_H
#define ICECREAM_H

#define MAX_FLAVOUR 5
#define MIN_SCOOP 1
#define MAX_SCOOP 3
#define PRICE_PER_SCOOP 5.00
#define CHOC_FLAVOUR 1.00
#define WAFER_PRICE 5.00

namespace seneca {
	class IceCream {
		int m_flavour{};
		int m_nOfScoop{};
		char m_needWaferCone{};
		double m_totalOrderPrice{};

		//Print flavour menu
		void printFlavourtMenu();

		//Set a number to variable and validate the number between a range before set
		void getInt(int& destination, const int minRange, const int maxRange);

		//Calculate total for single order
		double calcTotal(const double iceCream, const double isChoc, const double wafer);

	public:
		//Get ice cream order
		void getOrder();

		//Print single order
		void printOrder();

		//Print a line
		void line(const int qty);

		//Getter for retrieving the single order total price
		double getTotal();

		//Print order with format
		void printOrderFormat(const char* title, const double price);
		void printOrderFormat(const char* header1, const char* header2);
	};
}

#endif // !ICECREAM_H
