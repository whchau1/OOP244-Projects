/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
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
#include <iostream>
#include "Fridge.h"
using namespace std;

namespace seneca {

	Food::Food() {}

	Food::Food(const char* nm, int wei) {
		strncpy(m_name, nm, NAME_LEN);
		m_weight = wei;
	}
	
	const char* Food::name() const {
		return m_name;
	}

	int Food::weight() const {
		return m_weight;
	}


	//Constructor
	Fridge::Fridge() :m_numFoods{}, m_model{ nullptr } {}

	Fridge::Fridge(Food farr[], int nf, const char* mod) :m_numFoods{}, m_model{ new char[strlen(mod) + 1] } {
		if (nf > 0 && mod != nullptr && mod[0] != '\0') {
			m_numFoods = nf;
			strcpy(m_model, mod);
			for (int i = 0; i < nf; i++) {
				m_foods[i] = farr[i];
			}
		}
	}

	//Destructor
	Fridge::~Fridge() {
		if (m_model) delete[] m_model;
		m_model = nullptr;
	}

	//Member functions
	bool Fridge::addFood(const Food& f){
		bool result{};
		int emptyIndex{};
		if (m_numFoods < FRIDGE_CAP) {
			for (; emptyIndex < m_numFoods && m_foods[emptyIndex].name(); emptyIndex++) {}
			m_foods[emptyIndex] = f;
			if (m_foods[emptyIndex].name()[0] != '\0') {
				m_numFoods++;
				result = 1;
			}
		}
		else {
			result = 0;
		}

		return result;
	}

	void Fridge::changeModel(const char* m){
		if (m && m[0] != '\0') {
			m_model = new char[strlen(m) + 1];
			strcpy(m_model, m);
		}
	}

	bool Fridge::fullFridge() const{
		return m_numFoods == FRIDGE_CAP;
	}

	bool Fridge::findFood(const char* f) const{
		bool result = 1;
		for (int i = 0; i<m_numFoods && result; i++) {
			result = strcmp(m_foods[i].name(), f) == 0 ? 0 : 1;
		}
		return !result;
	}
	std::ostream& Fridge::display(std::ostream& os) const
	{
		if (m_model) {
			os << "Fridge Model: " << m_model << '\n';
			os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << '\n';
			os << "List of Foods" << endl;
			if (m_numFoods > 0) {
				for (int i = 0; i < m_numFoods; i++) {
					os.width(NAME_LEN);
					os << m_foods[i].name() << " | " << m_foods[i].weight() << endl;
				}
			}
		}
		return os;
	}
}
