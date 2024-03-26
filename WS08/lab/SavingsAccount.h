/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingAccount.h
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file defines the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
// 
***********************************************************************/
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_G
#include "Account.h"

namespace seneca {
	
	class SavingsAccount : public Account{
		double m_interestRate{};
	public:
		SavingsAccount(double balance, double rate);
		void monthEnd();
		void display(std::ostream& out) const;
		virtual ~SavingsAccount() = default;
	};

}

#endif // !SAVINGSACCOUNT_H
