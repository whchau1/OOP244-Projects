/***********************************************************************
// Workshop # 9, Derived Class with a Resource
//
// File: LibraryItem.h
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file implements the LibraryItem class
// -----------------------------------------------------------
// Name            Date            Reason
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <iostream>
using namespace std;

namespace seneca {

	class LibraryItem {
		char* m_title{};
		int m_year{};
	public:
		LibraryItem() {};
		LibraryItem(const char* title, const int year);
		LibraryItem(const LibraryItem& src);
		LibraryItem& operator=(const LibraryItem& src);
		virtual ~LibraryItem();
		virtual ostream& display(ostream& ostr = cout) const;
	};

}

#endif // !LIBRARYITEM_H

