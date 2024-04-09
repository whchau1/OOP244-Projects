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

	ostream& Menu::printIndent() const{
		for (int i = 0; i < m_noOfTab; i++) {
			cout << "   ";
		}
		return cout;
	}

	int Menu::getSelection() const{
		int selection{}, valid{};  //selection to store the user's selection. valid is 1 if the input is valid, 0 if the input is invalid
		char newLine{};  //Store newline character
		do {
			cin >> selection;  //Get selection number
			cin.get(newLine);  //Get newline character
			if (cin.fail()) {  //if selection doesn't get an integer
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (newLine != '\n') {  //if selection is an integer but has something more
				cout << "Only enter an integer, try again: ";
			}
			else if (!(selection >= 0 && selection <= m_noOfOpt)) { //check if the selection is between a range
				cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfOpt << "]: ";
			}
			else {  //set the flag to exit the loop if the input is valid
				valid = 1;
			}
		} while (!valid);

		return selection;
	}

	Menu::Menu(const char* menuContent, int numberOfTabs){
		if (menuContent) {
			m_text = new char[strlen(menuContent) + 1];
			strcpy(m_text, menuContent);
			for (int i = 0; menuContent[i] != '\0'; i++) { //Check the menu content charater by charater.
				if (menuContent[i] == '\n') {  //Each newline character in the content means 1 option.
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
		printIndent();  //Print indentation for first line
		for (int i = 0; m_text[i] != '\0'; i++) { //Check the menu content charater by charater.
			cout << m_text[i];  //Print out the menu content by each character
			if (m_text[i] == '\n') {  //Print the indentation when find a newline character
				printIndent();
			}
		}
		cout << endl;
		printIndent() << "0- Exit\n";
		printIndent() << "> ";

		return cout;
	}

	int& Menu::operator>>(int& Selection) const{
		display();

		return Selection = getSelection();
	}
}