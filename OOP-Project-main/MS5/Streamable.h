// Final Project Milestone 3
// Date Module
// File	Streamable.h
// Version 1.0
// Author	Haig McGarry
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H	
#include <iostream>
#include <cstring>
#include <string>
#include "Date.h"
#include "Lib.h"

namespace sdds{

	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool conIO(std::ios& ios)const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() = default;


	};
	std::ostream& operator<<(std::ostream& os, const Streamable& src); //writes Streamable object only if it's valid
	std::istream& operator>>(std::istream& is, Streamable& src); //reads to Streamable object from stdin

}

#endif
