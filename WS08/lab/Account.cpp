/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file implements the Account class
// -----------------------------------------------------------
// Name            Date            Reason
// 
***********************************************************************/
#include "Account.h"

namespace seneca {

	double Account::balance() const {
		return m_balance;
	}

	Account::Account(double balance) {
		if (balance > 0.0) {
			m_balance = balance;
		}
	}

	bool Account::credit(const double amount) {
		bool status{};
		if (amount > 0.0) {
			m_balance += amount;
			status = 1;
		}

		return status;
	}

	bool Account::debit(double amount) {
		bool status{};
		if (amount > 0.0) {
			m_balance -= amount;
			status = 1;
		}

		return status;
	}


}