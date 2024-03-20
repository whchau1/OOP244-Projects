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

	SavingsAccount::SavingsAccount(double balance, double rate):Account(balance) {
		if (rate > 0.0) {
			m_interestRate = rate;
		}
	}

	void SavingsAccount::monthEnd() {
		double currentBalance = balance();
		credit(currentBalance *= m_interestRate);
	}

	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << endl << "Balance: $";
		os.setf(ios::fixed);
		os.precision(2);
		os << balance() << endl << "Interest Rate (%): " << m_interestRate << endl;
	}
}