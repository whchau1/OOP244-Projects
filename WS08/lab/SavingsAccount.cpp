/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file implements the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "SavingsAccount.h"
using namespace std;

namespace seneca {

	SavingsAccount::SavingsAccount(double balance, double rate) :Account(balance) {
		if (rate > 0.0) {
			m_interestRate = rate;
		}
	}

	void SavingsAccount::monthEnd() {
		double currentBalance = balance();
		credit(currentBalance *= m_interestRate);
	}

	void SavingsAccount::display(std::ostream& out) const {
		out << "Account type: Savings" << endl 
			<< "Balance: $";
		out.setf(ios::fixed);
		out.precision(2);
		out << balance() << endl 
			<< "Interest Rate (%): " << m_interestRate * 100 << endl;
	}
}