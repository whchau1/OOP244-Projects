/*Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "Utils.h"

namespace seneca{

	void Menu::printIndent() const{
		for (int i = 0; i < m_noOfTab * 3; i++) {
			cout << ' ';
		}
	}

	int Menu::getSelection() const{
		int selection{}, valid{};
		char newLine{};
		do {
			cin >> selection;
			cin.get(newLine);
			if (cin.fail()) {
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (newLine != '\n') {
				cout << "Only enter an integer, try again: ";
			}
			else if (!(selection >= 0 && selection <= m_noOfOpt)) {
				cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfOpt << "]: ";
			}
			else {
				valid = 1;
			}
		} while (!valid);

		return selection;
	}

	Menu::Menu(const char* menuContent, int numberOfTabs){
		if (menuContent) {
			m_text = new char[strlen(menuContent) + 1];
			strcpy(m_text, menuContent);
			for (int i = 0; menuContent[i] != '\0'; i++) {
				if (menuContent[i] == '\n') {
					m_noOfOpt++;
				}
			}
			m_noOfTab = numberOfTabs;
		}
	}

	Menu::~Menu(){
		delete[] m_text;
	}

	ostream& Menu::display() const{
		printIndent();
		for (int i = 0; m_text[i] != '\0'; i++) {
			cout << m_text[i];
			if (m_text[i] == '\n') {
				printIndent();
			}
		}
		cout << endl;
		printIndent();
		cout << "0- Exit\n";
		printIndent();
		cout << "> ";

		return cout;
	}

	int& Menu::operator>>(int& Selection) const{
		display();

		return Selection = getSelection();
	}
}