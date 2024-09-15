//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-19
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "LblShape.h"

namespace seneca
{
    class Rectangle : public LblShape
    {
        unsigned int m_width{ 0 };
        unsigned int m_height{ 0 };

    public:
        Rectangle() {}
        Rectangle(const char* _label, int _width, int _height);
        virtual ~Rectangle() {}

        void getSpecs(std::istream& istr);
        void draw(std::ostream& ostr) const;
    };
}
#endif