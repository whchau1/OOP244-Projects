/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.h
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
// 
***********************************************************************/
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "iAccount.h"

namespace seneca {

	class Account : public iAccount{
		double m_balance{};
	protected:
		double balance() const;
	public:
		Account(double balance);
		virtual ~Account() = default;
		bool credit(double amount);
		bool debit(double amount);
	};

}

#endif // !ACCOUNT_H
