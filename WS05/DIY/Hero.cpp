/***********************************************************************
// OOP244 Workshop #5 p2: tester program
//
// File	Hero.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Hero.h"

namespace seneca {

	void Hero::powerLevelCount(){
		m_powerLevel = 0;
		for (int i = 0; i < m_numPower; i++) {
			m_powerLevel += m_power[i].checkRarity();
		}
		m_powerLevel *= m_numPower;
	}

	Hero::Hero() {};

	Hero::Hero(const char* name, const Power powerList[], const int nPower) {
		strcpy(m_name, name);
		m_numPower = nPower;
		m_power = new Power[m_numPower];
		for (int i = 0; i < m_numPower; i++) {
			m_power[i] = powerList[i];
		}
		powerLevelCount();
	}

	Hero::~Hero(){
		if (m_power != nullptr) {
			delete[] m_power;
		}
		m_power = nullptr;
	}

	Hero& Hero::operator+=(const Power& power){
		Power* temp{};
		if (m_power != nullptr) {
			int i{};
			temp = new Power[m_numPower];
			for (i = 0; i < m_numPower; i++) {
				temp[i] = m_power[i];
			}
			delete[] m_power;
			m_numPower++;
			m_power = new Power[m_numPower];
			for (i = 0; i < m_numPower - 1; i++) {
				m_power[i] = temp[i];
			}
			m_power[m_numPower - 1] = power;
		}
		powerLevelCount();
		delete[] temp;
		temp = nullptr;
		return *this;
	}

	Hero& Hero::operator-=(const Power& power){

		return *this;
	}

	Hero& Hero::operator-=(const int num){
		m_powerLevel -= 10;
		return *this;
	}

	Hero& Hero::operator<<(const Power& power){
		operator+=(power);
		return *this;
	}

	bool Hero::operator>(Hero& rhs){
		return m_powerLevel > rhs.m_powerLevel;
	}

	bool Hero::operator<(Hero& rhs){
		return m_powerLevel < rhs.m_powerLevel;
	}

	ostream& Hero::display() const{
		cout << "Name: " << m_name << endl;
		cout << "List of available powers: \n";
		for (int i = 0; i < m_numPower; i++) {
			cout.width(8);
			cout << "Name: " << m_power[i].checkName() << ", Rarity: " << m_power[i].checkRarity() << endl;
		}
		cout << "Power Level: " << m_powerLevel;

		return cout;
	}

	void operator>>(const Power& lhs, Hero& rhs){
		rhs += lhs;
	}

}
