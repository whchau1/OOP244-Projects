/***********************************************************************
// Workshop # 9, Derived Class with a Resource
//
// File: LibraryItem.cpp
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file implements the LibraryItem class
// -----------------------------------------------------------
// Name            Date            Reason
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LibraryItem.h"
using namespace std;

namespace seneca {

	LibraryItem::LibraryItem(const char* title, const int year) :m_year(year){
		if (title) {
			delete[] m_title;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}

	LibraryItem::LibraryItem(const LibraryItem& src) {
		operator=(src);
	}

	LibraryItem& LibraryItem::operator=(const LibraryItem& src) {
		if (src.m_title) {
			delete[] m_title;
			m_title = new char[strlen(src.m_title) + 1];
			strcpy(m_title, src.m_title);
		}
		m_year = src.m_year;

		return *this;
	}

	LibraryItem::~LibraryItem() {
		delete[] m_title;
		m_title = nullptr;
	}

	ostream& LibraryItem::display(ostream& ostr) const {
		return ostr << "Title: " << m_title << " (" << m_year << ")";
	}

}