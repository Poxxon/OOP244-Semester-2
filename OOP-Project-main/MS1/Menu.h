/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	Pouya Rad
Revision History
-----------------------------------------------------------
Date      Reason
2024/7/1  Preliminary release
2024/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef MENU_H
#define MENU_H

#include <iostream>

namespace seneca {
    const unsigned int MAX_MENU_ITEMS = 20;

    class Menu;  

    class MenuItem {
        char* content;
        MenuItem(const char* content = nullptr);  
        ~MenuItem(); 
        MenuItem(const MenuItem&) = delete;  
        MenuItem& operator=(const MenuItem&) = delete;  
        operator bool() const;
        operator const char* () const;
        std::ostream& display(std::ostream& os) const;

        friend class Menu;  
    };

    class Menu {
        MenuItem* title;
        MenuItem* items[MAX_MENU_ITEMS];
        unsigned int numItems;
        void displayTitle(std::ostream& os) const;
        std::ostream& displayMenu(std::ostream& os) const;
    public:
        Menu();
        Menu(const char* title);
        ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        Menu& operator<<(const char* menuitemContent);
        unsigned int run() const;
        unsigned int operator~() const;
        operator bool() const;
        operator unsigned int() const;
        operator int() const;
        const char* operator[](int index) const;
        friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
    };
}

#endif
