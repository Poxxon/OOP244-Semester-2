// Final Project Milestone 3
// Date Module
// File	Streamable.cpp
// Version 1.0
// Author	Haig McGarry
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Publication.h"

namespace sdds {
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