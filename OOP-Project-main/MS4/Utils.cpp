/* Citation and Sources...
Final Project Milestone 4
Module: Book
Filename: Book.h
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

#include "Utils.h"

using namespace std;

namespace seneca {
    int getIntMM(int min, int max) {
        int input = -1;
        do {
            cin >> input;
            if (cin.fail() || input < min || input > max) {
                cout << "Invalid Selection, try again: ";
                input = -1;
            }

            cin.clear();
            char ch = 'x';
            while (ch != '\n') {
                ch = cin.get();
            }
        } while (cin.fail() || input < min || input > max);

        return input;
    }
}