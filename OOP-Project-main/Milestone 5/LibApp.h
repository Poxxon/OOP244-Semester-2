/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.h
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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "PublicationSelector.h"
#include "Book.h"
#include "Utils.h"
namespace sdds {
    class LibApp {
        bool m_changed{};
        Menu m_mainMenu={"Seneca Library Application"};
        Menu m_exitMenu={"Changes have been made to the data, what would you like to do?"};
        char m_filename[256]{};
        Publication* m_ppa[SENECA_LIBRARY_CAPACITY]{};
        int m_nolp{};
        int m_llrn{};
        Menu m_pub_type={"Choose the type of publication:"};
        Publication* getPub(int libRef);

        bool confirm(const char* message);

        void load();
        void save();
        int search(int);
        void returnPub();

        void newPublication();
        void removePublication();
        void checkOutPub();
    public:
        LibApp();
        explicit LibApp(const char*&);
        ~LibApp();
        void run();
    };
}
#endif // !SDDS_LIBAPP_H



