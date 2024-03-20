/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: iAccount.h
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file defines the iAccount interface
// -----------------------------------------------------------
// Name            Date            Reason
// 
***********************************************************************/
#ifndef IACCOUNT_H
#define IACCOUNT_H
#include <iostream>

namespace seneca {
	
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() = default;
	};

}

#endif // !IACCOUNT_H
