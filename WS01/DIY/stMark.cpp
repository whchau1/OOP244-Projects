#include <iostream>
#include "StMark.h"
#include "file.h"
#include "io.h"
#include "graph.h"
using namespace std;

namespace seneca {

	bool printReport(const char* filename) {
		StMark m[MAX_NO_RECS];
		int recordsRead{}, marksGroup[MAX_MARK_GROUP]{};
		bool fileStatus{};

		if (fileStatus = openFile(filename)) {
			recordsRead = readMarks(m);

			countMark(m, recordsRead, marksGroup);
			printGraph(marksGroup, MAX_MARK_GROUP, "Students' mark distribution");

			sortMark(m, recordsRead);

			for (int i = 0; i < recordsRead; i++) {
				printInt(i + 1, 3);
				cout << ": [";
				printInt(m[i].mark, 3);
				cout << "]" << m[i].name << " " << m[i].surname << endl;
			}
			line(40);
		}

		closeFile();

		return fileStatus;
	}

	//Count all the mark into 10 groups
	void countMark(const StMark stMark[], const int noOfRecord, int* group) {
		int result{};

		for (int i = 0; i < noOfRecord; i++) {
			result = 10 - (stMark[i].mark - 1) / 10 - 1;  //(mark - 1 / 10) determine which group a mark belongs to, 10 - () reverse the group number
			group[result]++;
			
		}
	}

	//Sort the marks in descending order
	void sortMark(StMark* m, int noOfRecord) {
		StMark swap{};
		for (int i = 0; i < noOfRecord; i++) {
			for (int j = 0; j < noOfRecord - i - 1; j++) {
				if (m[j].mark < m[j + 1].mark) {
					swap = m[j];
					m[j] = m[j + 1];
					m[j + 1] = swap;
				}
			}
		}
	}

}