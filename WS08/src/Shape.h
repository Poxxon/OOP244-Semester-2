//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-19
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

namespace seneca
{
    class Shape
    {
    public:
        virtual ~Shape() {}
        virtual void draw(std::ostream& ostr) const = 0;
        virtual void getSpecs(std::istream& istr) = 0;
    };

    std::ostream& operator<<(std::ostream& ostr, const Shape& src);
    std::istream& operator>>(std::istream& istr, Shape& src);
}

#endif
