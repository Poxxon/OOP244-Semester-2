//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-19
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Shape.h"

namespace seneca
{
    std::ostream& operator<<(std::ostream& ostr, const Shape& src)
    {
        src.draw(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Shape& src)
    {
        src.getSpecs(istr);
        return istr;
    }
}
