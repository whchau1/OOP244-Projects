/*Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Utils.h"
using namespace std;

namespace seneca {

	int PreTriage::getWaitTime(const Patient& patients) const {
		Time time{};
		int m_numOfPatient{};
		if (patients == 'C') {
			time = m_contaigenWaitTime;
			for (int i = 0; i < m_numLineup; i++) {
				if (*m_lineupPatients[i] == 'C') {
					m_numOfPatient++;
				}
			}
		}
		else if (patients == 'T') {
			time = m_triageWaitTime;
			for (int i = 0; i < m_numLineup; i++) {
				if (*m_lineupPatients[i] == 'T') {
					m_numOfPatient++;
				}
			}
		}
		time *= (m_numOfPatient);
		return time;
	}

	PreTriage::PreTriage(const char* filename, size_t CWaitTime, size_t TWaitTime) :m_contaigenWaitTime(CWaitTime), m_triageWaitTime(TWaitTime){
		if (filename) {
			m_filename = new char[strlen(filename) + 1];
			strcpy(m_filename, filename);
			load();
		}
	}

	PreTriage::PreTriage(const PreTriage& src) {
		operator=(src);
	}

	PreTriage& PreTriage::operator=(const PreTriage& src) {
		m_contaigenWaitTime = src.m_contaigenWaitTime;
		m_triageWaitTime = src.m_triageWaitTime;
		for (int i = 0; i < m_numLineup; i++) {
			m_lineupPatients[i] = src.m_lineupPatients[i];
		}
		if (src.m_filename) {
			m_filename = new char[strlen(src.m_filename) + 1];
			strcpy(m_filename, src.m_filename);
		}

		return *this;
	}

	PreTriage::~PreTriage() {
		save();
		delete[] m_filename;
		m_filename = nullptr;
		for (int i = 0; i < m_numLineup; i++) {
			delete m_lineupPatients[i];
			m_lineupPatients[i] = nullptr;
		}
	}

	PreTriage& PreTriage::load() {
		ifstream file(m_filename);
		Patient* newPatient{};
		char patientType{};

		cout << "Loading data..." << endl;
		if (file.is_open()) {
			m_contaigenWaitTime.read(file);
			file.ignore();  //ignore ','
			m_triageWaitTime.read(file);
			file.ignore();  //ignore '\n'
			while (file >> patientType && m_numLineup < MAX_LINEUP) {
				file.ignore();  //ignore ','
				if (patientType == 'C') {
					newPatient = new TestPatient;
				}
				else if (patientType == 'T') {
					newPatient = new TriagePatient;
				}
				if (newPatient) {
					newPatient->read(file);
					m_lineupPatients[m_numLineup++] = newPatient;
				}
				file.ignore();  //ignore '\n'
			}
		}
		if (file.peek() != EOF) {
			cout << "Warning: number of records exceeded " << m_numLineup << endl;
		}
		if (m_numLineup) {
			cout << m_numLineup << " Records imported..." << endl;
		}
		else {
			cout << "No data or bad data file!" << endl;
		}
		cout << endl;

		return *this;
	}

	void PreTriage::save() const {
		ofstream file(m_filename);
		int CPatient{}, TPatient{};
		cout << "Saving lineup..." << endl;
		file << m_contaigenWaitTime << ',' << m_triageWaitTime << endl;
		for (int i = 0; i < m_numLineup; i++) {
			m_lineupPatients[i]->write(file);
			file << endl;
			if (m_lineupPatients[i]->type() == 'C') {
				CPatient++;
			}
			else if (m_lineupPatients[i]->type() == 'T') {
				TPatient++;
			}
		}
		cout << CPatient << " Contagion Tests and " << TPatient << " Triage records were saved!" << endl;
	}

	void PreTriage::lineup() const {
		int selection{};
		Menu submenu("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
		switch (submenu >> selection) {
		case 1:
			findCustomerByType(clog, 'C');
			break;
		case 2:
			findCustomerByType(clog, 'T');
			break;
		}
		
	}

	void PreTriage::admit() {
		int selection{}, index{};
		Menu submenu("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
		switch (submenu >> selection) {
		case 1:
			index = indexOfFirstInLine('C');
			break;
		case 2:
			index = indexOfFirstInLine('T');
			break;
		}
		if (index == EOF) {
			cout << "Lineup is empty!\n" << endl;
		}
		else {
			cout << endl;
			printHeaderLine(42, '*', 0) << endl;
			cout << "Call time: [";
			Time().reset().write(cout) << "]" << endl
				<< "Calling at for ";
			m_lineupPatients[index]->write(cout);
			printHeaderLine(42, '*', 0) << endl;
			setAverageWaitTime(*m_lineupPatients[index]);
			U.removeDynamicElement(m_lineupPatients, index, m_numLineup);
		}

	}

	int PreTriage::indexOfFirstInLine(const char type) const {
		int index{ EOF };
		for (int i = 0; i < m_numLineup && index == EOF; i++) {
			index = m_lineupPatients[i]->operator==(type) ? i : index;
		}

		return index;
	}

	Time PreTriage::setAverageWaitTime(Patient& patient) {
		Time CT{}, PTT{}, AWT{};
		if (patient == 'C') {
			AWT = m_contaigenWaitTime;
		}
		else if(patient == 'T' ) {
			AWT = m_triageWaitTime;
		}
		int PTN = patient.number();
		CT.reset();
		PTT = patient.time();
		AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
		if (patient == 'C') {
			m_contaigenWaitTime = AWT;
		}
		else if (patient == 'T' ) {
			m_triageWaitTime = AWT;
		}

		return AWT;
	}

	PreTriage& PreTriage::registerPatient() {
		int selection{};
		/*Patient* newPatient{};*/
		Menu submenu("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
		if (m_numLineup == MAX_LINEUP) {
			cout << "Line up full!" << endl;
		}
		else {
			switch (submenu >> selection) {
			case 1:
				m_lineupPatients[m_numLineup] = new TestPatient;
				break;
			case 2:
				m_lineupPatients[m_numLineup] = new TriagePatient;
				break;
			}
			m_lineupPatients[m_numLineup]->setArrivalTime();
			cout << "Please enter patient information: " << endl;
			m_lineupPatients[m_numLineup]->read(cin);
			cout << endl;
			printHeaderLine(42, '*', 0) << endl;
			m_lineupPatients[m_numLineup]->write(cout);
			cout << "Estimated Wait Time: ";
			Time(getWaitTime(*m_lineupPatients[m_numLineup])).write(cout) << endl;
			printHeaderLine(42, '*', 0) << endl << endl;
			m_numLineup++;
		}

		return *this;
	}

	ostream& PreTriage::printHeaderLine(int qty, char symbol, int header) const {
		if (header) {
			cout << "Row - Patient name                                          OHIP     Tk #  Time" << endl;
		}
		for (int i = 0; i < qty; i++) {
			cout << symbol;
		}
		return cout;
	}

	ostream& PreTriage::findCustomerByType(ostream& out, const char type) const {
		int j{};
		printHeaderLine(79, '-', 1) << endl;
		for (int i = 0; i < m_numLineup; i++) {
			if (*m_lineupPatients[i] == type) {
				out.width(3);
				out.setf(ios::left);
				out << ++j << " - ";
				m_lineupPatients[i]->write(out) << endl;
			}
		}
		printHeaderLine(79, '-', 0) << endl;

		return out;
	}

	PreTriage& PreTriage::run(){
		int selection{};

		Menu menu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
		do {
			switch (menu >> selection) {
			case 1:
				registerPatient();
				break;
			case 2:
				admit();
				break;
			case 3:
				lineup();
				break;
			}
		} while (selection != 0);

		return *this;
	}

}
