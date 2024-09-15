/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include <iostream>

namespace seneca {

    MenuItem::MenuItem(const char* content) {
        if (content) {
            this->content = new char[strlen(content) + 1];
            strcpy(this->content, content);
        }
        else {
            this->content = nullptr;
        }
    }

    MenuItem::~MenuItem() {
        delete[] content;
    }

    MenuItem::operator bool() const {
        return content != nullptr;
    }

    MenuItem::operator const char* () const {
        return content;
    }

    std::ostream& MenuItem::display(std::ostream& os) const {
        if (content) {
            os << content;
        }
        return os;
    }

    Menu::Menu() : title(nullptr), numItems(0) {
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
            items[i] = nullptr;
        }
    }

    Menu::Menu(const char* titleContent) : Menu() {
        if (titleContent && titleContent[0] != '\0') {
            title = new MenuItem(titleContent);
        }
    }

    Menu::~Menu() {
        delete title;
        for (unsigned int i = 0; i < numItems; i++) {
            delete items[i];
        }
    }

    void Menu::displayTitle(std::ostream& os) const {
        if (title) {
            title->display(os);
        }
    }

    std::ostream& Menu::displayMenu(std::ostream& os) const {
        displayTitle(os);
        if (title) {
            os << ":" << std::endl;
        }
        for (unsigned int i = 0; i < numItems; i++) {
            os << " " << (i + 1) << "- ";
            items[i]->display(os);
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";
        return os;
    }

    Menu& Menu::operator<<(const char* menuitemContent) {
        if (numItems < MAX_MENU_ITEMS && menuitemContent) {
            items[numItems++] = new MenuItem(menuitemContent);
        }
        return *this;
    }

    unsigned int Menu::run() const {
        displayMenu(std::cout);
        unsigned int selection;
        while (!(std::cin >> selection) || selection > numItems) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid Selection, try again: ";
        }
        std::cin.ignore(10000, '\n');
        return selection;
    }

    unsigned int Menu::operator~() const {
        return run();
    }

    Menu::operator bool() const {
        return numItems > 0;
    }

    Menu::operator unsigned int() const {
        return numItems;
    }

    Menu::operator int() const {
        return numItems;
    }

    const char* Menu::operator[](int index) const {
        return items[index % numItems]->content;
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu) {
        menu.displayTitle(os);
        return os;
    }
}
