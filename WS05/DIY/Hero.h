/***********************************************************************
// OOP244 Workshop #5 p2: tester program
//
// File	Hero.h
// Version 1.0
// Author Mohammad Shamas
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Wing Ho Chau
// Seneca Email: whchau1@myseneca.ca
// Seneca ID: 150924231
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef HERO_H
#define HERO_H
#include <iostream>
#include "Power.h"
using namespace std;

namespace seneca {
	class Hero {
		char m_name[MAX_NAME_LENGTH]{};
		Power* m_power{};
		int m_numPower{};
		int m_powerLevel{};

		void powerLevelCount();
	public:
		Hero();
		Hero(const char* name,const Power powerList[], const int nPower);
		~Hero();
		
		Hero& operator+=(const Power& power);
		Hero& operator-=(const Power& power);
		Hero& operator-=(const int num);
		Hero& operator<<(const Power& power);
		bool operator>(Hero& rhs);
		bool operator<(Hero& rhs);

		ostream& display()const;
	};

	void operator>>(const Power& lhs, Hero& rhs);


}

#endif // !HERO_H
