/***********************************************************************
// OOP244 Workshop #7 Lab (part 1)
//
// File  BankAccount.cpp
// -----------------------------------------------------------
// Name:			Wing Ho Chau
// Seneca Email:	whchau1@myseneca.ca
// Seneca ID:		150924231
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "SavingsAccount.h"

namespace seneca {

	void SavingsAccount::writeInterest(ostream& out) const {
		out.setf(ios::fixed);
		out.precision(3);
		out << m_interest << "%";
		out.unsetf(ios::fixed);
	}

	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate)
		: BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}

	void SavingsAccount::applyInterest(Date& dt) {
		double oldBalance = getbalance();

		cout << "   ";
		cout.setf(ios::fixed);
		cout.precision(2);
		writeCurrency(cout, oldBalance);	//write current balance
		cout << " + ";
		writeCurrency(cout, oldBalance * m_interest);	//write interest amount
		cout << " (";
		writeInterest(cout);	//write interest rate
		setBalance(oldBalance *= 1 + m_interest);	
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << ") = " << getbalance() << " | ";	//write new balance with interest applied
		m_interestDate.write(cout);		//write last date interest was applied
		m_interestDate = dt;	//update interest date
		cout << " => ";
		m_interestDate.write(cout);		//write new date interest was applied
		cout << endl;
	}

	ostream& SavingsAccount::write(ostream& out) const {
		BankAccount::write(out);
		out << " | ";
		writeInterest(out);
		out << " | ";
		m_interestDate.write(out);

		return out;
	}

	istream& SavingsAccount::read(istream& in) {
		BankAccount::read(in);
		cout << "Interest Date ";
		m_interestDate.read(in);
		cout << "Interest Rate: ";
		cin >> m_interest;

		return in;
	}

	istream& operator>>(std::istream& in, SavingsAccount& acct) {
		return acct.read(in);
	}

	ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
		return acct.write(out);
	}

}