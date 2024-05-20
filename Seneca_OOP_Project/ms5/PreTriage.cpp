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

	int PreTriage::getWaitTime(const Patient& patient) const {
		Time time{};
		int m_numOfPatient{};
		if (patient == 'C') {
			time = m_contaigenWaitTime;
		}
		else if (patient == 'T') {
			time = m_triageWaitTime;
		}
		for (int i = 0; i < m_numLineup; i++) {
			if (*m_lineupPatients[i] == patient) {
				m_numOfPatient++;
			}
		}

		return time *= (m_numOfPatient);
	}

	PreTriage& PreTriage::setAverageWaitTime(Patient& patient) {
		Time CT{}, PTT = patient.time(), AWT{};
		int PTN = patient.number();
		CT.reset();
		if (patient == 'C') {
			AWT = m_contaigenWaitTime;
			m_contaigenWaitTime = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
		}
		else if (patient == 'T') {
			AWT = m_triageWaitTime;
			m_triageWaitTime = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
		}

		return *this;
	}

	int PreTriage::indexOfFirstInLine(const char type) const {
		int index{ EOF };
		for (int i = 0; i < m_numLineup && index == EOF; i++) {
			index = *m_lineupPatients[i] == type ? i : index;
		}

		return index;
	}

	PreTriage& PreTriage::load() {
		ifstream file(m_filename);
		Patient* newPatient{};
		char patientType{};

		cout << "Loading data..." << endl;
		if (file.is_open()) {
			m_contaigenWaitTime.read(file);  //Read Wait time of contaigen test patient from file
			file.ignore();  //ignore ','
			m_triageWaitTime.read(file);  //Read Wait time of triage patient from file
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

		if (file.peek() != EOF) { //Check if there are any record more
			cout << "Warning: number of records exceeded " << m_numLineup << endl;
		}

		if (m_numLineup) { //Print the number of record read
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
		if (file.is_open()) {
			file << m_contaigenWaitTime << ',' << m_triageWaitTime << endl;  //Write Wait Time to file
			for (int i = 0; i < m_numLineup; i++) {
				m_lineupPatients[i]->write(file) << endl; //Write patient lineup records
				if (*m_lineupPatients[i] == 'C') { //Calculate the number of two type patients respectively
					CPatient++;
				}
				else if (*m_lineupPatients[i] == 'T') {
					TPatient++;
				}
			}
		}
		cout << CPatient << " Contagion Tests and " << TPatient << " Triage records were saved!" << endl;  //Print the respective type of patient record read
	}

	PreTriage& PreTriage::registerPatient() {
		int selection{};
		if (m_numLineup == MAX_LINEUP) {  //Check if the line is full
			cout << "Line up full!" << endl;
		}
		else { //If the line is not full
			Menu submenu("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
			switch (submenu >> selection) {
			case 1:
				m_lineupPatients[m_numLineup] = new TestPatient;
				setPatient(); //Read patient information
				break;
			case 2:
				m_lineupPatients[m_numLineup] = new TriagePatient;
				setPatient(); //Read patient information
				break;
			}
		}

		return *this;
	}

	PreTriage& PreTriage::setPatient() {
		m_lineupPatients[m_numLineup]->setArrivalTime();  //Set patient's arrival time
		cout << "Please enter patient information: " << endl;
		m_lineupPatients[m_numLineup]->read(cin);  //Ask for patient detail by input
		cout << endl;
		printHeaderLine(42, '*', 0) << endl;  //Print issued ticket information
		m_lineupPatients[m_numLineup]->write(cout)
			<< "Estimated Wait Time: ";
		Time(getWaitTime(*m_lineupPatients[m_numLineup])).write(cout) << endl;
		printHeaderLine(42, '*', 0) << endl << endl;
		m_numLineup++; //Increase the number of patient in line

		return *this;
	}

	PreTriage& PreTriage::admit() {
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
		else if (selection != 0) {
			cout << endl;
			printHeaderLine(42, '*', 0) << endl;
			cout << "Call time: [" << Time().reset() << "]" << endl  //Print current Time as call time
				<< "Calling at for ";
			m_lineupPatients[index]->write(cout); //Print admitted patient information
			printHeaderLine(42, '*', 0) << endl << endl;
			setAverageWaitTime(*m_lineupPatients[index]); //Set the wait time based on the patient type
			U.removeDynamicElement(m_lineupPatients, index, m_numLineup);  //Remove the patient in the line
		}

		return *this;
	}

	ostream& PreTriage::lineup() const {
		int selection{}, listNum{};
		char type{};
		Menu submenu("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
		switch (submenu >> selection) {
		case 1:
			type = 'C';
			/*findCustomerByType(clog, 'C');*/
			break;
		case 2:
			type = 'T';
			/*findCustomerByType(clog, 'T');*/
			break;
		}
		if (selection != 0) {
			printHeaderLine(79, '-', 1) << endl;
			for (int i = 0; i < m_numLineup; i++) {
				if (*m_lineupPatients[i] == type) {
					clog.width(3);
					clog.setf(ios::left);
					clog << ++listNum << " - ";
					m_lineupPatients[i]->write(clog) << endl;
				}
			}
			printHeaderLine(79, '-', 0) << endl;
		}

		return cout;
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

	PreTriage::PreTriage(const char* filename, size_t CWaitTime, size_t TWaitTime) :m_contaigenWaitTime(CWaitTime), m_triageWaitTime(TWaitTime){
		if (filename) {
			delete[] m_filename;
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
		for (int i = 0; i < m_numLineup; i++) { //Deep copy Patient object
			*m_lineupPatients[i] = *src.m_lineupPatients[i];
		}
		if (src.m_filename) { //Deep copy filename
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
