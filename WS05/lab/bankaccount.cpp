/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Wing Ho Chau
// Seneca Email: whchau1@myseneca.ca
// Seneca ID: 150924231
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char* name, bool checking)
	{
		m_userName[0] = '\0';		// Empty string implies is account is not open 
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char* name, bool checking)
	{
		if (isOpen())
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods
	bankAccount::operator bool() const {
		return isOpen();
	}

	bankAccount::operator double() const {
		return m_funds;
	}

	bankAccount& bankAccount::operator++() {
		if (isOpen() && m_funds > 0) {
			if (m_checking)
				m_funds *= 1 + CHECKING_INTREST;
			else
				m_funds *= 1 + SAVINGS_INTREST;
		}
		return *this;
	}

	bankAccount& bankAccount::operator--() {
		if (m_checking)
			m_funds -= m_monthlyTransactions * CHECKING_TRANSACTION_FEE;
		else
			m_funds -= m_monthlyTransactions * SAVINGS_TRANSACTION_FEE;
		return *this;
	}

	bool bankAccount::operator+=(double funds) {
		int oldTrans = m_monthlyTransactions;
		if (isOpen()) {
			m_funds += funds;
			m_monthlyTransactions++;
			print(funds);
		}

		return m_monthlyTransactions != oldTrans;
	}

	bool bankAccount::operator-=(double funds) {
		funds *= -1;
		return operator+=(funds);
	}

	bool bankAccount::operator==(const bankAccount& rhs) const {
		return (!strcmp(m_userName, rhs.m_userName) && m_funds == rhs.m_funds && m_checking == rhs.m_checking) ? 1 : 0;
	}

	bool bankAccount::operator>(double rhs) const {
		bool result{};
		if (isOpen())
			result = m_funds > rhs;
		return result;
	}

	bool bankAccount::operator<=(double rhs) const {
		bool result{};
		if (isOpen())
			result = m_funds <= rhs;
		return result;
	}

	bool bankAccount::operator<<(bankAccount& from) {
		int oldTrans = m_monthlyTransactions;
		int oldFrom = from.m_monthlyTransactions;
		if (this->isOpen() && from.isOpen() && from.m_funds >= 0) {
			cout << "Transfer $";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << from.m_funds << " from " << from.m_userName << " to " << this->m_userName << endl;
			*this += from;
			from -= from;
		}
		return m_monthlyTransactions != oldTrans && from.m_monthlyTransactions != oldFrom;
	}

	void bankAccount::display(void) const {
		cout << "Display Account -> User:";
		cout.width(16);
		if (isOpen()) {
			cout.fill('-');
			cout << m_userName << " |";
			cout.fill(' ');
			cout.width(9);
			if (m_checking) {
				cout << "Checking";
			}
			else {
				cout << "Savings";
			}
			cout << " | Balance: $";
			cout.width(8);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_funds << " | Transactions:";
			cout.unsetf(ios::fixed);
			cout.fill('0');
			cout.width(3);
			cout << m_monthlyTransactions;
			cout.fill(' ');
			cout << endl;
		}
		else {
			cout.fill('-');
			cout << " NOT OPEN";
			cout.fill(' ');
			cout << endl;
		}
	}

	void bankAccount::print(double funds) {
		if (funds >= 0) {
			cout << "Deposit $";
		}
		else {
			cout << "Withdraw $";
		}
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << abs(funds) << " for " << m_userName << endl;
	}

	// ADD: Global Helper Functions

	bool operator>(double lhs, const bankAccount& rhs) {
		bool result{};
		if (bool(rhs))
			result = lhs > double(rhs);
		return result;
	}

	bool operator<=(double lhs, const bankAccount& rhs) {
		bool result{};
		if (bool(rhs))
			result = lhs <= double(rhs);
		return result;
	}

}
