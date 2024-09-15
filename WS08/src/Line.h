//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-19
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef LINE_H
#define LINE_H


#include "LblShape.h"

namespace seneca
{
    class Line : public LblShape
    {
        unsigned int m_length{ 0 };

    public:
        Line() {}
        Line(const char* _label, int _length);
        virtual ~Line() {}

        void getSpecs(std::istream& istr);

        void draw(std::ostream& ostr) const;
    };
}
#endif