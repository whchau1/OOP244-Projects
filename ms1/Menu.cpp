/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author   John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2024/3/10 Start attempt 1
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "Utils.h"

namespace seneca{

	void Menu::printIndent(){
		for (int i = 0; i < m_noOfTab * 3; i++) {
			cout << ' ';
		}
	}

	int Menu::getSelection(){
		char buffer[10]{};
		int noAlpha{}, noSpace{}, noInt{};
		int selection = -1;
		do {
			noAlpha = noSpace = noInt = 0;
			cin.getline(buffer, 10);
			if (strlen(buffer) < 10) {
				cin.putback('\n');
			}
			cin.clear();
			cin.ignore(10000, '\n');
			for (int i = 0; buffer[i] != '\0'; i++) {
				if (isspace(buffer[i])) {
					noSpace++;
				}
				else if (isalpha(buffer[i])) {
					noAlpha++;
				}
				else if (isdigit(buffer[i])) {
					noInt++;
				}
			}
			if (noAlpha) {
				cout << "Bad integer value, try again: ";
			}
			else if ((noSpace && noInt) || noSpace) {
				cout << "Only enter an integer, try again: ";
			}
			else if (noInt) {
				selection = 0;
				for (int i = 0; buffer[i] != '\0'; i++) {
					selection = selection * 10 + (buffer[i] - '0');
				}
				if (!(selection >= 0 && selection <= m_noOfOpt)) {
					cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfOpt << "]: ";
				}
			}
		} while (selection < 0 || selection > m_noOfOpt);

		return selection;
	}

	Menu::Menu(const char* menuContent, int numberOfTabs){
		if (menuContent) {
			m_text = new char[strlen(menuContent) + 1];
			strcpy(m_text, menuContent);
			for (int i = 0; menuContent[i] != '\0'; i++)
				if (menuContent[i] == '\n')
					m_noOfOpt++;
			m_noOfTab = numberOfTabs;
		}
	}

	Menu::~Menu(){
		delete[] m_text;
	}

	ostream& Menu::display(){
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

	int& Menu::operator>>(int& Selection){
		display();
		Selection = getSelection();

		return Selection;
	}
}