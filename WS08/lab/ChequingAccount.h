/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.h
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H
#include "Account.h"

namespace seneca {

	class ChequingAccount :public Account {
		double m_transFee{};
		double m_monthlyFee{};
	public:
		ChequingAccount(const double balance, const double transFee, const double monthlyFee);
		bool credit(const double amount);
		bool debit(const double amount);
		void monthEnd();
		void display(std::ostream& out) const;
		virtual ~ChequingAccount() = default;
	};
}

#endif // !CHEQUINGACCOUNT_H
