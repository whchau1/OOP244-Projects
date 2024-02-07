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
#ifndef VENDOR_H
#define VENDOR_H
#include "Icecream.h"

#define TAX_RATE 0.13

namespace seneca {
	class Vendor {
		IceCream* m_order{};
		int m_nOfOrder{};

		//Print ice cream pattern
		void printIceCream();
	public:

		void setEmpty();
		void takeOrders();
		void displayOrders();
		void clearData();
	};
}

#endif // !VENDOR_H
