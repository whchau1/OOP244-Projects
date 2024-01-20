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

		if (openFile(filename)) {
			recordsRead = readMarks(m);

			countMark(m, recordsRead, marksGroup);
			printGraph(marksGroup, MAX_MARK_GROUP, "Students' mark distribution");
			
		}
		return openFile(filename);
	}

	//Count all the mark into 10 groups
	void countMark(const StMark stMark[], const int noOfRecord, int* group) {
		int result{};

		for (int i = 0; i < noOfRecord; i++) {
			result = 10 - (stMark[i].mark - 1) / 10 - 1;
			group[result]++;
			
		}
	}
}