#include "Icecream.h"
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
#include "Icecream.h"
using namespace std;

namespace seneca {

	//Get ice cream order
	void seneca::IceCream::getOrder() {
		char newline{};
		bool isYN;
		printFlavourtMenu();

		//Get flavour
		getInt(m_flavour, 1, MAX_FLAVOUR);

		//Get how many scoops
		cout << "Number of Scoops (max 3)" << endl;
		getInt(m_nOfScoop, MIN_SCOOP, MAX_SCOOP);

		//Get wafer cone
		cout << "Vanilla wafer cone?" << endl;
		cout << "(Y)es/(N)o > ";
		do {
			m_needWaferCone = cin.get();
			newline = cin.get();
			isYN = m_needWaferCone == 'Y' || m_needWaferCone == 'y' || m_needWaferCone == 'N' || m_needWaferCone == 'n';
			if (!isYN || newline != '\n') {
				if (newline != '\n') {
					cin.ignore(500, '\n');
				}
				cout << "Only Y or N are acceptable:" << endl;
				cout << "> ";
			}
		} while (!isYN || newline != '\n');
	}

	//Get a number and validate the number is between the range
	void IceCream::getInt(int& number, const int minRange, const int maxRange) {
		do {
			cout << "> ";
			cin >> number;
			if (cin.fail()) {
				cout << "Invalid entry, retry" << endl;
			}
			else if (number < minRange || number > maxRange) {
				cout << "Invlid value(1<=val<=" << maxRange << ")" << endl;
			}
			cin.clear();
			cin.ignore(500, '\n');
		} while (cin.fail() || number < minRange || number > maxRange);
	}

	//Print flavour menu
	void IceCream::printFlavourtMenu(){
		cout << "Select flavour:\n";
		line(16);
		cout << "1: Chocolate\n"
			<< "2: Strawberry\n"
			<< "3: Mango\n"
			<< "4: Tutti fruit\n"
			<< "5: Almond crunch" << endl;
		line(16);
	}


	//Print a line
	void IceCream::line(const int qty){
		for (int i = 0; i < qty; i++) {
			cout << "-";
		}
		cout << endl;
	}

	//Getter for retrieving the single order total price
	double IceCream::getTotal()
	{
		return m_totalOrderPrice;
	}

	//Calculate total for single order
	double IceCream::calcTotal(const double iceCream, const double isChoc, const double wafer){
		return iceCream + isChoc + wafer;
	}

	//Print single order
	void IceCream::printOrder(){
		double iceCreamPrice{}, isChocPrice{}, waferPrice{};

		//Header
		printOrderFormat("Order details:", "Price");

		line(35);

		//Ice cream price
		iceCreamPrice = m_nOfScoop * PRICE_PER_SCOOP;
		cout.setf(ios::left);
		cout << "Number of scoops, " << m_nOfScoop << " total:";
		cout.unsetf(ios::left);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.width(9);
		cout << iceCreamPrice << endl;

		//Print selected flavour, extra $1 for each scoop if it is chocolate flavour
		cout.setf(ios::left);
		switch (m_flavour) {
		case 1:
			isChocPrice = m_nOfScoop * CHOC_FLAVOUR;
			printOrderFormat("Chocolate flavour:", isChocPrice);
			break;
		case 2:
			cout << "Strawberry flavour" << endl;
			break;
		case 3:
			cout << "Mango flavour" << endl;
			break;
		case 4:
			cout << "Tutti fruit flavour" << endl;
			break;
		case 5:
			cout << "Almond crunch flavour" << endl;
			break;
		}

		//Wafer Price
		waferPrice = m_needWaferCone == 'y' || m_needWaferCone == 'Y' ? WAFER_PRICE : 0.00;
		printOrderFormat("Vanilla Wafer:", waferPrice);

		//Total price for single order
		m_totalOrderPrice = calcTotal(iceCreamPrice, isChocPrice, waferPrice);
		printOrderFormat("Price:", m_totalOrderPrice);
	}

	//Format the order
	void IceCream::printOrderFormat(const char* title, const double price) {
		cout.width(26);
		cout.setf(ios::left);
		cout << title;	
		cout.unsetf(ios::left);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.width(9);
		cout << price << endl;
	}

	//Format the order
	void IceCream::printOrderFormat(const char* header1, const char* header2) {
		cout.width(26);
		cout.setf(ios::left);
		cout << header1;
		cout.unsetf(ios::left);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.width(9);
		cout << header2 << endl;
	}
}