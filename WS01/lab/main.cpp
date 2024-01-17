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
#include <iomanip>
#include "io.h"
#include "graph.h"
using namespace std;

// Maximum number of samples in an graph
const int MAX_NO_OF_SAMPLES = 20;

// prints samples error message
void samplesFirst();

// SeneGraph program
int main() {
   int noOfSamples = 0;
   int samples[MAX_NO_OF_SAMPLES] = { 0 };
   bool done = false;
   seneca::labelLine(33, "Welcome to SeneGraph");
   while (!done) {
      switch (seneca::menu(noOfSamples)) {
      case 1:
         cout << "Enter number of available samples: ";
         noOfSamples = seneca::getInt(1, MAX_NO_OF_SAMPLES);
         break;
      case 2:
         if (noOfSamples == 0) {
            samplesFirst();
         }
         else {
            cout << "Please enter the sample values: " << endl;
            seneca::getSamples(samples, noOfSamples);
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
            seneca::printGraph(samples, noOfSamples, " SeneGraph ");
         }
         break;
      case 0:
         cout << "Thanks for using SeneGraph" << endl;
         done = true;
      }
   }
   return 0;
}

// prints samples error message
void samplesFirst() {
   cout << "Number of Samples must be set first!" << endl;
}
