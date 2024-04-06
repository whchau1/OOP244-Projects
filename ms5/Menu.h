/*Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;

namespace seneca {

	class Menu {
		char* m_text{};
		int m_noOfOpt{};
		int m_noOfTab{};
		void printIndent() const;
		int getSelection() const;
	public:
		Menu(const char* menuContent, int numberOfTabs = 0);
		Menu(const Menu& menu) = delete;
		virtual ~Menu();
		
		Menu& operator=(const Menu& menu) = delete;
		ostream& display() const;
		int& operator>>(int& Selection) const;

		
	};
}

#endif // !MENU_H
