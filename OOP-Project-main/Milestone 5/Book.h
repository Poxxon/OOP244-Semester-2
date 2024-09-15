/* Citation and Sources...
Final Project Milestone 5
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

#ifndef MS4_BOOK_H
#define MS4_BOOK_H
#include "Publication.h"
namespace sdds{
    class Book : public Publication{
        char* m_authorName{};
    public:
        Book();
        Book& operator=(const Book&);
        Book(const Book&);
        ~Book() override;

        char type()const override;
        std::ostream& write(std::ostream&) const override;
        std::istream& read(std::istream&) override;
        void set(int member_id) override;
        operator bool() const override;

        std::ostream &operator<<(std::ostream &os) override;
        std::istream &operator>>(std::istream &is) override;
    };
    std::ostream &operator<<(std::ostream &os, const Book& right);
    std::istream &operator>>(std::istream &is, Book& right);
}
#endif //MS4_BOOK_H
