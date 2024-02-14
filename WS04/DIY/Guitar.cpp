/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Seneca Email: whchau1@myseneca.ca
// Seneca ID: 150924231
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca{
 //GuitarStr
   const char* GuitarStr::material() const {
      return m_material;
   }
   double GuitarStr::gauge() const {
      return m_gauge;
   }
   GuitarStr::GuitarStr() {};

   GuitarStr::GuitarStr(const char* ma, double ga) {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };

 //Guitar
   //Constructor
   Guitar::Guitar(const char* mod){
       strcpy(m_model, mod);
   }

   Guitar::Guitar(GuitarStr strs[], int ns, const char* mod){
       m_strings = new GuitarStr[ns];
       for (int i = 0; i < ns; i++) {
           m_strings[i] = strs[i];
       }
       m_numStrings = ns;
       strcpy(m_model, mod);
   }
   
   //Destructor
   Guitar::~Guitar() {
       if (m_strings) {
           delete[] m_strings;
       }
       m_strings = nullptr;
   }

   //Modifiers
   bool Guitar::changeString(const GuitarStr& gs, int sn) {
       if (sn < m_numStrings) {
           m_strings[sn] = gs;
       }
       return sn < m_numStrings;
   }

   void Guitar::reString(GuitarStr strs[], int ns){
       deString();
       m_strings = new GuitarStr[ns];
       for (int i = 0; i < ns; i++) {
           m_strings[i] = strs[i];
       }
       m_numStrings = ns;
   }

   void Guitar::deString(){
       if (m_strings) {
           delete[] m_strings;
       }
       m_strings = nullptr;
       m_numStrings = 0;
   }

   //Queries
   bool Guitar::strung() const{
       return m_strings;
   }

   bool Guitar::matchGauge(double ga) const{
       int result = 0;
       for (int i = 0; i < m_numStrings && !result; i++) {
           result = m_strings[i].gauge() == ga;
       }
       return result;
   }

   std::ostream& Guitar::display(std::ostream& os) const{
       if (!m_strings) {
           os << "***Empty Guitar***" << endl;
       }
       else {
           os << "Guitar Model: " << m_model
               << "\nStrings: " << m_numStrings << endl;
           for (int i = 0; i < m_numStrings; i++) {
               os << "#" << i + 1;
               os.width(MAT_LEN);
               os << m_strings[i].material() << " | ";
               os.setf(ios::fixed);
               os.precision(1);
               os << m_strings[i].gauge() << endl;
               os.unsetf(ios::fixed);
           }
       }
       return os;
   }


}
