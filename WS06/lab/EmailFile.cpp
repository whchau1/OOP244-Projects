/***********************************************************************
// OOP244 Workshop # 6
//
// File: EmailFile.cpp
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Wing Ho Chau
// Seneca Email: whchau1@myseneca.ca
// Seneca ID: 150924231
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{

	Email& Email::operator=(const Email& rhs) {

		if (this != &rhs && rhs.m_email && rhs.m_name) {
			delete[] m_email;
			m_email = nullptr;
			m_email = new char[strlen(rhs.m_email) + 1];
			strcpy(m_email, rhs.m_email);
			delete[] m_name;
			m_name = nullptr;
			m_name = new char[strlen(rhs.m_name) + 1];
			strcpy(m_name, rhs.m_name);
			strcpy(m_year, rhs.m_year);
		}

		return *this;
	}

	bool Email::load(std::ifstream& in) {

		char buffer[BUFFER_SIZE];
		bool result = false;

		if (in.getline(buffer, BUFFER_SIZE, ',')) {
			delete[] m_email;
			m_email = new char[strlen(buffer) + 1];
			strcpy(m_email, buffer);

			if (in.getline(buffer, BUFFER_SIZE, ',')) {
				delete[] m_name;
				m_name = new char[strlen(buffer) + 1];
				strcpy(m_name, buffer);

				if (in.getline(buffer, BUFFER_SIZE, '\n')) {
					strcpy(m_year, buffer);
					result = true;
				}
			}
		}

		return result;
	}

	Email::~Email() {
		delete[] m_name;
		delete[] m_email;
	}

	void EmailFile::setFilename(const char* filename)
	{
		delete[] m_filename;
		m_filename = nullptr;
		if (filename)
		{
			m_filename = new char[strlen(filename) + 1];
			m_filename[0] = '\0';
			strcpy(m_filename, filename);
		}
	}

	void EmailFile::setEmpty()
	{
		delete[] m_emailLines;
		delete[] m_filename;
		m_emailLines = nullptr;
		m_filename = nullptr;
		m_noOfEmails = 0;
	}

	bool EmailFile::setNoOfEmails() {

		bool isValid = false;
		ifstream file(m_filename);

		if (!file.is_open()) {
			cout << "Failed to open file: " << m_filename << endl;
		}
		else
		{
			m_noOfEmails = 0;
			while (file) {
				m_noOfEmails += (file.get() == '\n');
			}
			file.close();

			if (m_noOfEmails == 0)
			{
				delete[] m_filename;
				m_filename = nullptr;
			}
			else {
				m_noOfEmails++;
				isValid = true;
			}
		}
		return isValid;
	}

	void EmailFile::loadEmails() {
		if (m_filename && setNoOfEmails()) {
			ifstream file(m_filename);
			if (file.is_open()) {
				delete[] m_emailLines;
				m_emailLines = nullptr;
				m_emailLines = new Email[--m_noOfEmails];
				for (int i = 0; i < m_noOfEmails; i++) {
					m_emailLines[i].load(file);
				}
			}
		}
	}

	EmailFile::operator bool() const {
		return m_emailLines != nullptr && m_noOfEmails > 0;
	}

	std::ostream& EmailFile::view(std::ostream& ostr) const
	{
		if (m_filename) {
			ostr << m_filename << endl;
			ostr.width(strlen(m_filename));
			ostr.fill('=');
			ostr << "=" << endl;
			ostr.fill(' ');
			for (int i = 0; i < m_noOfEmails; i++) {
				ostr.width(35);
				ostr.setf(ios::left);
				ostr << m_emailLines[i].m_email;
				ostr.width(25);
				ostr << m_emailLines[i].m_name;
				ostr << "Year = " << m_emailLines[i].m_year << endl;
			}
		}

		return ostr;
	}

	EmailFile::EmailFile(const char* filename) {
		if (filename) {
			setFilename(filename);
			loadEmails();
		}
		else {
			setEmpty();
		}
	}

	EmailFile::EmailFile(const EmailFile& rhs) {
		operator=(rhs);
	}

	EmailFile::~EmailFile() {
		delete[] m_emailLines;
		delete[] m_filename;
	}

	EmailFile& EmailFile::operator=(const EmailFile& rhs) {
		if (rhs) {
			setFilename(rhs.m_filename);
			m_noOfEmails = rhs.m_noOfEmails;
			delete[] m_emailLines;
			m_emailLines = new Email[rhs.m_noOfEmails];
			for (int i = 0; i < rhs.m_noOfEmails; i++) {
				m_emailLines[i] = rhs.m_emailLines[i];
			}
		}

		return *this;
	}

	bool EmailFile::saveToFile(const char* filename) const {
		bool result{};
		ofstream outputFile(filename);
		if (outputFile.is_open()) {
			for (int i = 0; i < m_noOfEmails; i++) {
				outputFile << m_emailLines[i].m_email << ',' << m_emailLines[i].m_name << ',' << m_emailLines[i].m_year << endl;
			}
			result = 1;
		}
		else {
			result = 0;
		}
		outputFile.close();

		return result;
	}

	void EmailFile::fileCat(const EmailFile& obj, const char* name) {
		if (*this && obj) {
			int totalEmails = m_noOfEmails + obj.m_noOfEmails;
			Email* temp = new Email[totalEmails];
			for (int i = 0; i < m_noOfEmails; i++) {
				temp[i] = m_emailLines[i];
			}
			for (int i = 0; i < obj.m_noOfEmails; i++) {
				temp[i + m_noOfEmails] = obj.m_emailLines[i];
			}
			m_noOfEmails = totalEmails;
			delete[] m_emailLines;
			m_emailLines = new Email[m_noOfEmails];
			for (int i = 0; i < m_noOfEmails; i++) {
				m_emailLines[i] = temp[i];
			}
			if (name) {
				setFilename(name);
			}
			saveToFile(m_filename);
			delete[] temp;
		}
	}

	std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
	{
		return text.view(ostr);
	}

}