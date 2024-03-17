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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "BankAccount.h"

namespace seneca {

	double BankAccount::getbalance() const {
		return m_balance;
	}

	void BankAccount::setBalance(double balance) {
		m_balance = balance;
	}

	void BankAccount::writeCurrency(ostream& out, double amount) const {
		out.setf(ios::fixed);
		out.precision(2);
		out << "$" << amount;
		out.unsetf(ios::fixed);
	}

	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance) :m_openDate(openDate), m_depInfo(depInfo), m_balance(balance) {
		strcpy(m_name, name);
	}

	ostream& BankAccount::write(ostream& out) const{
		out << ">> " << m_name << " | ";
		writeCurrency(out, m_balance);
		out << " | ";
		m_openDate.write(out);
		out << " | ";
		m_depInfo.write(cout);

		return out;
	}

	istream& BankAccount::read(istream& in) {
		cout << "Name: ";
		in.getline(m_name, MAX_BUFFER, '\n');
		cout << "Opening Balance: ";
		in >> m_balance;
		cout << "Date Opened ";
		m_openDate.read(in);
		m_depInfo.read(in);
		in.ignore(1000, '\n');

		return in;
	}

	istream& operator>>(istream& in, BankAccount& acct) {
		return acct.read(in);
	}

	ostream& operator<<(ostream& out, const BankAccount& acct) {
		return acct.write(out);
	}

}