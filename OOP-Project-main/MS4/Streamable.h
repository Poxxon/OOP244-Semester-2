/* Citation and Sources...
Final Project Milestone 4
Module: Streamable
Filename: Streamable.h
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

#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H

#include <iostream>

namespace seneca {
    class Streamable {
    public:
        virtual std::ostream &write(std::ostream &os = std::cout) const = 0;
        virtual std::istream &read(std::istream &is = std::cin) = 0;
        virtual bool conIO(std::ios &io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable() = default;
        virtual std::ostream &operator<<(std::ostream &os) = 0;
        virtual std::istream &operator>>(std::istream &is) = 0;
    };
    std::ostream &operator<<(std::ostream &os, const Streamable& streamable);
    std::istream &operator>>(std::istream &is, Streamable& streamable);
}

#endif 
