/***********************************************************************
// Workshop # 9, Derived Class with a Resource
//
// File: Book.cpp
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file implements the Book class
// -----------------------------------------------------------
// Name            Date            Reason
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

namespace seneca{

	Book::Book(const char* title, const int year, const char* author) :LibraryItem(title, year){
		if (author) {
			delete[] m_author;
			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
		}
	}

	Book::Book(const Book& src) {
		operator=(src);
	}

	Book& Book::operator=(const Book& src) {
		if (src.m_author) {
			delete[] m_author;
			m_author = new char[strlen(src.m_author) + 1];
			strcpy(m_author, src.m_author);
		}
		LibraryItem::operator=(src);

		return *this;
	}

	Book::~Book() {
		delete[] m_author;
		m_author = nullptr;
	}

	ostream& Book::display(ostream& ostr) const {
		LibraryItem::display(ostr);
		return ostr << endl << "Author: " << m_author;
	}

	bool Book::operator>(const Book& other) const {
		return strcmp(m_author, other.m_author) > 0;
	}

}