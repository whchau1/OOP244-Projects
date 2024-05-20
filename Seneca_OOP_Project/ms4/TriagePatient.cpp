/*Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
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
#include "TriagePatient.h"

namespace seneca {

	int TriagePatient::m_nextTriageTicket{ 1 };

	TriagePatient& TriagePatient::allocateCopyName(const char* buffer) {
		if (buffer) {
			delete[] m_symptoms;
			m_symptoms = new char[strlen(buffer) + 1];
			strcpy(m_symptoms, buffer);
		}

		return *this;
	}

	TriagePatient::TriagePatient() :Patient(m_nextTriageTicket++) {}

	TriagePatient::TriagePatient(const TriagePatient& src) :Patient(src){
		allocateCopyName(src.m_symptoms);
	}

	TriagePatient& TriagePatient::operator=(const TriagePatient& src) {
		Patient::operator=(src);
		allocateCopyName(src.m_symptoms);

		return *this;
	}
	
	char TriagePatient::type() const {
		return 'T';
	}

	ostream& TriagePatient::write(ostream& out) const {
		if (&out == &cout) {
			out << "TRIAGE" << endl;
			Patient::write(out);
			out << "Symptoms: " << m_symptoms << endl;
		}
		else if (&out != &clog) {
			Patient::write(out);
			out << ',' << m_symptoms;
		}
		else {
			Patient::write(out);
		}

		return out;
	}

	istream& TriagePatient::read(istream& in) {
		char symptoms[MAX_SYMPTOMS_LEN]{};

		Patient::read(in);
		if (&in != &cin) {
			in.ignore(1000, ',');
			in.getline(symptoms, MAX_SYMPTOMS_LEN, '\n');
			allocateCopyName(symptoms);
			m_nextTriageTicket = Patient::number() + 1;
		}
		else {
			cout << "Symptoms: ";
			in.getline(symptoms, MAX_SYMPTOMS_LEN);
			allocateCopyName(symptoms);
		}
		if (in.fail()) {
			delete[] m_symptoms;
			m_symptoms = nullptr;
			in.clear();
		}

		return in;
	}

	TriagePatient::~TriagePatient() {
		delete[] m_symptoms;
		m_symptoms = nullptr;
	}

}