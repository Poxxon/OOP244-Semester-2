/* Citation and Sources...
Final Project Milestone 2
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
#include "Menu.h"
#include <iostream>

Menu::Menu(const std::string& title) : m_title(title) {}

void Menu::add(const std::string& option) {
    m_options.push_back(option);
}

int Menu::run() const {
    std::cout << m_title << std::endl;
    for (size_t i = 0; i < m_options.size(); ++i) {
        std::cout << " " << i + 1 << "- " << m_options[i] << std::endl;
    }
    std::cout << " 0- Exit" << std::endl;
    std::cout << "> ";
    int selection;
    std::cin >> selection;
    return selection;
}

