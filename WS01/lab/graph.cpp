/***********************************************************************
Workshop 1: Compiling modular source code
File	w1p2.cpp
Version 1.0
Author	Fardad Soleimanloo  2241
Description:
   This provides some source code in a single file to break
   into modules and compile together

Revision History
-----------------------------------------------------------
Name            Date            Reason
Wing Ho Chau    1/17/2024
Senece Email: whchau1@myseneca.ca
Student ID  : 150924231
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/

#include <iostream>
#include "graph.h"
#include "io.h"

using namespace std;

namespace graph {

    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples) {
        int i;
        for (i = 0; i < noOfSamples; i++) {
            io::line(28);
            cout << "\\ " << (i + 1) << "/";
            io::printInt(noOfSamples, 2);
            cout << ":                    /";
            io::goBack(20);
            samples[i] = io::getInt(1, 1000000);
        }
    }

    // finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
    // otherwise it will return GRAPH_WIDTH. 
    int findMax(int samples[], int noOfSamples) {
        int max = samples[0];
        int i;
        for (i = 1; i < noOfSamples; i++) {
            if (max < samples[i]) max = samples[i];
        }
        return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
    }

    // prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max) {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        cout << "| ";
        for (i = 0; i < barlength; i++) {
            cout << "*";
        }
        cout << " ";
        io::printInt(val, (GRAPH_WIDTH + 6 - barlength));
        cout << "|" << endl;
    }

    // prints a graph comparing the sample values visually 
    void printGraph(int samples[], int noOfSamples, const char* label) {
        int max = findMax(samples, noOfSamples);
        io::labelLine(GRAPH_WIDTH + 10, label);
        for (int i = 0; i < noOfSamples; i++) {
            printBar(samples[i], max);
        }
        io::line(GRAPH_WIDTH + 10);
    }
}