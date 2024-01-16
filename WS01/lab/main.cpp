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
Wing Ho Chau    1/15/2024       
***********************************************************************/


#include <iostream>
#include <iomanip>
#include "io.h"
using namespace std;

// Maximum number of samples in an graph
const int MAX_NO_OF_SAMPLES = 20; 
const int GRAPH_WIDTH = 65;
// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);
// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70. 
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples, const char* label);




// prints samples error message
void samplesFirst();



// SeneGraph program
int main() {
   int noOfSamples = 0;
   int samples[MAX_NO_OF_SAMPLES] = { 0 };
   bool done = false;
   io::labelLine(33, "Welcome to SeneGraph");
   while (!done) {
      switch (io::menu(noOfSamples)) {
      case 1:
         cout << "Enter number of available samples: ";
         noOfSamples = io::getInt(1, MAX_NO_OF_SAMPLES);
         break;
      case 2:
         if (noOfSamples == 0) {
            samplesFirst();
         }
         else {
            cout << "Please enter the sample values: " << endl;
            getSamples(samples, noOfSamples);
         }
         break;
      case 3:
         if (noOfSamples == 0) {
            samplesFirst();
         }
         else if (samples[0] == 0) {
            cout << "Samples missing. Please enter the sample values!" << endl;
         }
         else {
            printGraph(samples, noOfSamples, " SeneGraph ");
         }
         break;
      case 0:
         cout << "Thanks for using SeneGraph" << endl;
         done = true;
      }
   }
   return 0;
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
int findMax(int samples[], int noOfSamples){
  int max = samples[0];
  int i;
  for (i = 1; i < noOfSamples; i++){
    if (max < samples[i]) max = samples[i];
  }
  return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
}

// prints samples error message
void samplesFirst() {
   cout << "Number of Samples must be set first!" << endl;
}
