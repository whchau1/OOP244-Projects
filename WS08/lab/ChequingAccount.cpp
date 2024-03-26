/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date:
// Author: Wing Ho Chau
// Description
// This file implements the ChequingAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "ChequingAccount.h"
using namespace std;

namespace seneca {

	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) :Account(balance) {
		if (transFee > 0.0) {
			m_transFee = transFee;
		}
		if (monthlyFee > 0.0) {
			m_monthlyFee = monthlyFee;
		}
	}

	bool ChequingAccount::credit(const double amount) {
		return Account::credit(amount) ? Account::debit(m_transFee) : 0;
	}

	bool ChequingAccount::debit(const double amount) {
		return Account::debit(amount) ? Account::debit(m_transFee) : 0;
	}

	void ChequingAccount::monthEnd() {
		Account::debit(m_monthlyFee);
	}

	void ChequingAccount::display(std::ostream& out) const {
		out << "Account type: Chequing" << endl 
			<< "Balance: $";
		out.setf(ios::fixed);
		out.precision(2);
		out << balance() << endl 
			<< "Per Transaction Fee: " << m_transFee << endl 
			<< "Monthly Fee: " << m_monthlyFee << endl;
	}

}