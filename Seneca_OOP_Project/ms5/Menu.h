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
		char* m_text{};  //Content of the menu. Store the content dynamically.
		int m_noOfOpt{};  //Number of options in the menu
		int m_noOfTab{};  //Number of indentation tabs

		/// <summary>
		/// Print space based on the number of indentations
		/// </summary>
		/// <returns>A reference of ostream</returns>
		ostream& printIndent() const;

		/// <summary>
		/// Get the user input and validate it until the input passes. If user input is invalid, print the appropriate message
		/// </summary>
		/// <returns></returns>
		/// 
		int getSelection() const;

	public:
		/// <summary>
		/// Constructor initializes the menu content and number of indentation tabs. Number of indentation is 0 by default.
		/// Calculate the number of options by the menu content
		/// </summary>
		/// <param name="menuContent">The menu content</param>
		/// <param name="numberOfTabs">Number of indentation tabs. Default is 0.</param>
		Menu(const char* menuContent, int numberOfTabs = 0);

		/// <summary>
		/// Copy constructor prohibited
		/// </summary>
		/// <param name="menu">The Menu to copy</param>
		Menu(const Menu& menu) = delete;

		/// <summary>
		/// Virtual destructor to deallocate resources for m_text
		/// </summary>
		virtual ~Menu();
		
		/// <summary>
		/// Copy assignment prohibited
		/// </summary>
		/// <param name="menu"></param>
		/// <returns></returns>
		Menu& operator=(const Menu& menu) = delete;

		/// <summary>
		/// Display the menu content and display with indentation if any.
		/// </summary>
		/// <returns>ostream object</returns>
		ostream& display() const;

		/// <summary>
		/// It first calls the display function and then receives the user's selection as an integer value.
		/// </summary>
		/// <param name="Selection">- The right operand to store the user's selection</param>
		/// <returns>A reference of the selection</returns>
		int& operator>>(int& Selection) const;

		
	};
}

#endif // !MENU_H
