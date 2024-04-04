/***********************************************************************
// Workshop # 9, Derived Class with a Resource
//
// File: Book.h
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file implements the Book class
// -----------------------------------------------------------
// Name            Date            Reason
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef BOOK_H
#define BOOK_H
#include "LibraryItem.h"

namespace seneca {

	class Book :public LibraryItem {
		char* m_author{};
	public:
		Book(const char* title, const int year, const char* author);
		Book(const Book& src);
		Book& operator=(const Book& src);
		virtual ~Book();
		ostream& display(ostream& ostr = cout) const;
		bool operator>(const Book& other)const;
	};

}

#endif // !BOOK_H

