/***********************************************************************
// OOP244 Workshop #7 Lab (part 1)
//
// File  SavingsAccount.h
// -----------------------------------------------------------
// Name:			Wing Ho Chau
// Seneca Email:	whchau1@myseneca.ca
// Seneca ID:		150924231
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
#include "DepositUtility.h"

namespace seneca {

	class SavingsAccount : public BankAccount {
		double m_interest{};
		Date m_interestDate{};
		void writeInterest(ostream& out) const;
	public:
		SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
		virtual ~SavingsAccount() = default;

		void applyInterest(Date& dt);
		ostream& write(ostream& out) const;
		istream& read(istream& in);
	};
	istream& operator>>(std::istream& in, SavingsAccount& acct);
	ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
}

#endif // !SAVINGSACCOUNT_H

