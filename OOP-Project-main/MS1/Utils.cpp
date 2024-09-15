/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Pouya Rad
Revision History
-----------------------------------------------------------
Date      Reason
2024/7/1  Preliminary release
2024/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Utils.h"
#include <iostream>

namespace seneca {
    unsigned int getUnsignedInt(unsigned int min, unsigned int max) {
        unsigned int value;
        bool done = false;
        while (!done) {
            std::cin >> value;
            if (std::cin.fail() || value < min || value > max) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid Selection, try again: ";
            }
            else {
                done = true;
            }
        }
        return value;
    }
}
