/* Citation and Sources...
Final Project Milestone 4
Module: Streamable
Filename: Streamable.cpp
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

#include "Streamable.h"

using namespace std;

namespace seneca {
    std::ostream &operator<<(std::ostream &os, const Streamable& streamable) {
        if (!streamable)
            return os;
        return streamable.write(os);
    }
    std::istream &operator>>(std::istream &is, Streamable& streamable) {
        return streamable.read(is);
    }
}
