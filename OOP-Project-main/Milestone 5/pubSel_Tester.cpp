/* Citation and Sources...
Final Project Milestone 5
Module: Tester
Filename: Tester.cpp
Version 1.0
Author	Pouya Rad
Revision History
-----------------------------------------------------------
Date      Reason
2024/?/?  Preliminary release
2024/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"

using namespace std;
using namespace sdds;

void prnPub(Publication* p[], int size, int ref) {
   int i;
   for (i = 0; i < size; i++) {
      if (ref == p[i]->getRef()) {
         cout << *p[i] << endl;
         i = size; 
      }
   }
}
