/***********************************************************************
// OOP244 Workshop #02 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date: September 25, 2023	
// Author: Yosef Ashibani, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Wing Ho Chau
//Senece Email: whchau1@myseneca.ca
//Student ID  : 150924231
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Room.h"
#include "Guest.h"
using namespace std;
using namespace seneca;


int main() {
   cout << "Testing Guest Functiosn:" << endl;
   Guest G;
   cout << "\nTesting bad setting\n---------------" << endl;
   set(G, nullptr, "ABC", 10);
   print(G);
   set(G, "ABC", nullptr, 10);
   print(G);
   set(G, "", "ABC", 10);
   print(G);
   set(G, "ABC", "", 10);
   print(G);
   cout << "\nTesting Good setting\n---------------" << endl;
   set(G, "Jane", "Doe", 30);
   print(G);
   vacate(G);
   print(G);
   cout << "------------------------" << endl 
        <<"\nTesting Guest booking:\n--- Enter the following:" << endl
      << "Jake\nDoe\n10" << endl 
      << "------------------------" << endl;
   book(G);
   print(G);
   vacate(G);
   print(G);
   cout << "\nTesting Room Functions: " << endl;
   Room A;
   set(A, 2, "A1010");
   print(A);
   vacate(A);
   print(A);
   cout << "------------------------" << endl 
      << "Testing Room booking:\n--- Enter the following:" << endl
      << "A1010\n2\nJane\nDoe\n30\nJake\nDoe\n10" << endl 
      << "------------------------" << endl;
   book(A);
   cout << "\nRoom booking data:" << endl
        << "------------------------" << endl;
   print(A);
   cout << "\nPrinting vacated Room:" << endl
      << "------------------------" << endl;
   vacate(A);
   print(A);
   return 0;
}



