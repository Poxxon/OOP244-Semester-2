/* Citation and Sources...
Final Project Milestone 4
Module: Publication
Filename: Publication.h
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

#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H

#include <iostream>
#include <cstring>
#include "Lib.h"
#include "Date.h"
#include "Streamable.h"
#include "Utils.h"

namespace seneca {
    class Publication : public Streamable {
        char *m_title;
        char m_shelfId[SENECA_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();

        Publication(const Publication& p);
        Publication& operator=(const Publication& p);
        ~Publication();

        
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();
      
        virtual char type()const;
        bool onLoan()const;
        Date checkoutDate()const;
        bool operator==(const char* title)const;
   
        operator const char* ()const;
        int getRef()const;

        std::ostream &write(std::ostream &os) const override;
        std::istream &read(std::istream &is) override;
        bool conIO(std::ios &io) const override;
        operator bool() const override;
        std::ostream &operator<<(std::ostream &os) override;
        std::istream &operator>>(std::istream &is) override;
    };

    std::ostream &operator<<(std::ostream &os, const Publication& right);
    std::istream &operator>>(std::istream &is, Publication& right);
}


#endif 
