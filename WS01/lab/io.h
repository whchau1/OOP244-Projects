/***********************************************************************
Workshop 1: Compiling modular source code
File	w1p2.cpp
Version 1.0
Author	Fardad Soleimanloo  2241
Description:
   This provides some source code in a single file to break
   into modules and compile together

Revision History
-----------------------------------------------------------
Name            Date            Reason
Wing Ho Chau    1/17/2024
Senece Email: whchau1@myseneca.ca
Student ID  : 150924231
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef IO_H
#define IO_H

namespace io {

	// prints the int value in width of fieldWidth
	void printInt(int value, int fieldWidth);
	// erturns number of digits in an integer
	int intDigits(int value);
	// Performs a fool-proof integer entry assuming the user will only enter numeric values.
	// if the user enters non digit values, the function will hang in an endless loop.
	int getInt(int min, int max);
	// moves the cursor backwards
	void goBack(int n);
	// displays the user interface menu
	int menu(int noOfSamples);
	// Draws a line and adds a label
	void labelLine(int n, const char* label);
	// Draws a line
	void line(int n);
}

#endif