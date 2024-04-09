/*Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
Version 1.0
Author   Wing Ho Chau
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Patient.h"

namespace seneca {

	Patient& Patient::allocateCopyName(const char* buffer) {
		if (buffer) {
			delete[] m_name;
			m_name = new char[strlen(buffer) + 1];
			strcpy(m_name, buffer);
		}

		return *this;
	}

	Patient::Patient(const int ticketNum) :m_ticket(ticketNum) {}

	Patient::Patient(const Patient& src) :m_ticket(0) {
		operator=(src);
	}

	Patient& Patient::operator=(const Patient& src) {
		allocateCopyName(src.m_name);
		m_OHIP = src.m_OHIP;
		m_ticket = src.m_ticket;

		return *this;
	}
	
	Patient::~Patient() {
		delete[] m_name;
		m_name = nullptr;
	}

	bool Patient::operator==(const char ch) const {
		return type() == ch;
	}

	bool Patient::operator==(const Patient& p2) const {
		return type() == p2.type();
	}

	Patient& Patient::setArrivalTime() {
		m_ticket.resetTime();

		return *this;
	}

	Time Patient::time() const {
		return m_ticket.time();
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	Patient::operator bool() const{
		return m_name && m_OHIP;
	}

	Patient::operator char* () const {
		return m_name;
	}

	ostream& Patient::write(ostream& os) const {
		if (&os == &clog) {
			if (bool(*this)) {
				os.width(53);
				os.setf(ios::left);
				os.fill('.');
				os << m_name;
				os.fill(' ');
				os << m_OHIP;
				os.width(5);
				os.setf(ios::right);
				os << m_ticket.number() << ' ' << m_ticket.time();
				os.unsetf(ios::right);
			}
			else {
				os << "Invalid Patient Record";
			}
		}
		else if (&os == &cout) {
			if (bool(*this)) {
				os << m_ticket << endl << m_name << ", OHIP: " << m_OHIP << endl;
			}
			else {
				os << "Invalid Patient Record" << endl;
			}
		}
		else {
			if (bool(*this)) {
				os << type() << ',' << m_name << ',' << m_OHIP << ',' << m_ticket;
			}
			else {
				os << "Invalid Patient Record" << endl;
			}
			
		}
		return os;
	}

	istream& Patient::read(istream& is) {
		char buffer[MAX_PATIENT_NAME + 1]{};

		if (&is == &cin) {
			cout << "Name: ";
			is.getline(buffer, MAX_PATIENT_NAME + 1, '\n');
			allocateCopyName(buffer);

			cout << "OHIP: ";
			do {
				is >> m_OHIP;
				if (is.fail()) {
					cout << "Bad integer value, try again: ";
					is.clear();
				}
				else if (is.peek() != '\n') {
					cout << "Only enter an integer, try again: ";
				}
				else if (m_OHIP < MIN_OHIPNUMBER || m_OHIP > MAX_OHIPNUMBER) {
					cout << "Invalid value enterd, retry[" << MIN_OHIPNUMBER << " <= value <= " << MAX_OHIPNUMBER << "]: ";
				}
				is.ignore(10000, '\n');
			} while (m_OHIP < MIN_OHIPNUMBER || m_OHIP > MAX_OHIPNUMBER);
		}
		else {
			is.getline(buffer, MAX_PATIENT_NAME + 1, ',');
			allocateCopyName(buffer);
			is >> m_OHIP;
			is.ignore();  //ignore ','
			m_ticket.read(is);
		}
		
		return is;
	}
}