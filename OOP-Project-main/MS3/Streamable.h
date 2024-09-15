#pragma once
/* Citation and Sources...
Final Project Milestone 3
Module: Streamable
Filename: Streamable.h
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
#define _CRT_SECURE_NO_WARNINGS

namespace seneca {}

#ifndef SENECA_STREAMABLE_H__
#define SENECA_STREAMABLE_H__

#include <iostream>

namespace seneca {

	class Streamable {

	public:
		virtual std::ostream& write(std::ostream& os = std::cout) const = 0;

		virtual std::istream& read(std::istream& is = std::cin) = 0;

		virtual bool conIO(std::ios& io) const = 0;

	
		virtual operator bool() const = 0;

		~Streamable() {}
	};

	std::ostream& operator<<(std::ostream& os, const Streamable& s);

	std::istream& operator>>(std::istream& is, Streamable& s);

}

#endif
