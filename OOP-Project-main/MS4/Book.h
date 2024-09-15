/* Citation and Sources...
Final Project Milestone 4
Module: Book
Filename: Book.h
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

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "Publication.h"

namespace seneca {
    class Book : public Publication {
        char* m_authorName;

    public:
        Book();

        ~Book();
        Book(const Book& b);
        Book& operator=(const Book& b);

        virtual char type() const override;

        std::ostream &write(std::ostream &os) const override;
        std::istream &read(std::istream &is) override;

        virtual void set(int member_id);
        operator bool() const override;

        std::ostream &operator<<(std::ostream &os) override;
        std::istream &operator>>(std::istream &is) override;
    };

    std::ostream &operator<<(std::ostream &os, const Book& right);
    std::istream &operator>>(std::istream &is, Book& right);
}


#endif 
