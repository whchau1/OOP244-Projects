/***********************************************************************
// OOP244 Workshop #7 Lab (part 1)
//
// File  BankAccount.h
// -----------------------------------------------------------
// Name:			Wing Ho Chau
// Seneca Email:	whchau1@myseneca.ca
// Seneca ID:		150924231
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include "DepositUtility.h"
using namespace std;

namespace seneca{
	const int MAX_BUFFER = 50;

	class BankAccount {
		char m_name[MAX_BUFFER + 1]{};
		Date m_openDate{};
		DepositInfo m_depInfo{};
		double m_balance{};
	protected:
		double getbalance() const;
		void setBalance(double balance);
		void writeCurrency(ostream& out, double amount) const;
	public:
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
		virtual ~BankAccount() = default;

		ostream& write(ostream& out) const;
		istream& read(istream& in);
	};
	istream& operator>>(istream& in, BankAccount& acct);
	ostream& operator<<(ostream& out, const BankAccount& acct);
}


#endif // !BANKACCOUNT_H




