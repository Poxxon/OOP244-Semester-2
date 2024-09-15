/* Citation and Sources...
Final Project Milestone 5
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

namespace sdds{

    std::ostream& operator<<(std::ostream& os, const Streamable& src) {
		if (src)
		{
			src.write(os);
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& src) {
		src.read(is);

		return is;
	}
}
