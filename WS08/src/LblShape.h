//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-19
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef LBLSHAPE_H
#define LBLSHAPE_H



#include "Shape.h"

namespace seneca
{
    class LblShape : public Shape
    {
        char* m_label{ nullptr };

    protected:
        const char* label() const;

    public:
        LblShape() {}
        LblShape(const char* _label);
        virtual ~LblShape();

        LblShape(const LblShape& src) = delete;
        LblShape& operator=(const LblShape& src) = delete;

        void getSpecs(std::istream& istr);
    };
}
#endif
