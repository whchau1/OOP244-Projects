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
#include <iostream>
#include "Vendor.h"
#include "Icecream.h"
using namespace std;

namespace seneca {

	void Vendor::setEmpty(){
		m_order = nullptr;
	}

	void Vendor::takeOrders(){
		cout << "Seneca Icecream shop" << endl;
		printIceCream();
		cout << "How many Icecreams?\n" << "> ";
		cin >> m_nOfOrder;

		m_order = new IceCream[m_nOfOrder];
		for (int i = 0; i < m_nOfOrder; i++) {
			cout << "Order number " << i + 1 << ":" << endl;
			m_order[i].getOrder();
		}
		cout << endl;
	}

	void Vendor::displayOrders(){
		double total{};
		cout << "********** Order Summary **********" << endl;
		for (int i = 0; i < m_nOfOrder; i++) {
			cout << "Order No: " << i + 1 << ":" << endl;
			m_order[i].printOrder();
			if (i < m_nOfOrder - 1) {
				cout << endl;
			}
		}
		m_order->line(35);
		for (int i = 0; i < m_nOfOrder; i++) {
			total += m_order[i].getTotal();
		}

		m_order->printOrderFormat("Price:", total);
		m_order->printOrderFormat("Tax:", total * TAX_RATE);
		m_order->printOrderFormat("Total Price ($):", total * (1 + TAX_RATE));

	}

	void Vendor::clearData() {
		if (m_order != nullptr) {
			delete[] m_order;
		}
		m_order = nullptr;
	}

	//Print ice cream pattern
	void Vendor::printIceCream(){
		cout.width(12);
		cout << "@\n";
		cout.width(14);
		cout << "(' .)\n";
		cout.width(15);
		cout << "(*.`. )\n";
		cout.width(14);
		cout << "\\###/\n";
		cout.width(13);
		cout << "\\#/\n";
		cout.width(11);
		cout << "V" << endl;
	}
	
}