/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
#include <cstring>
#define MAX_MENU_ITEMS 20
namespace sdds{

    class MenuItem{
        char* m_itemName{};
        MenuItem();
        MenuItem(const char*);
        ~MenuItem();
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;

        operator bool()const;
        operator const char*()const;

        void display()const;
        friend class Menu;
    };
    class Menu{
        char* m_menuTitle{};
        MenuItem* m_menuItem[MAX_MENU_ITEMS]{};
        unsigned int noOfItems{};
    public:
        Menu();
        Menu(const std::string);
        ~Menu();

        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        Menu(MenuItem*) = delete;

        void display()const;
        unsigned int run()const;
        unsigned int operator~()const;
        Menu& operator<<(const char*);
        operator int()const;
        operator unsigned int()const;
        operator bool()const;
        const char* operator[](unsigned index) const;
        friend std::ostream& operator<<( std::ostream&, const Menu&);
    };
}

#endif //SDDS_MENU_H