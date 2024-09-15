/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.h
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
#ifndef DATE_H
#define DATE_H

#include <iostream>

namespace seneca {
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int DAY_ERROR = 4;
    const int MIN_YEAR = 1500;

    class Date {
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;
        int daysSince0001_1_1() const;
        bool validate();
        void errCode(int readErrorCode);
        int systemYear() const;
        bool bad() const;
        int mdays() const;
        void setToToday();
    public:
        Date();
        Date(int year, int mon, int day);
        int errCode() const;
        const char* dateStatus() const;
        int currentYear() const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;

        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        int operator-(const Date& rhs) const;
        operator bool() const;

        friend std::ostream& operator<<(std::ostream& os, const Date& RO);
        friend std::istream& operator>>(std::istream& is, Date& RO);
    };
}

#endif
// Menu.h
#ifndef MENU_H
#define MENU_H

#define MAX_MENU_ITEMS 20

namespace seneca {

class Menu;  // Forward declaration

class MenuItem {
    char* content;
    MenuItem(const char* itemContent = nullptr);
    MenuItem(const MenuItem&) = delete;
    MenuItem& operator=(const MenuItem&) = delete;
    ~MenuItem();
    operator bool() const;
    operator const char*() const;
    void display(std::ostream& os) const;
    friend class Menu;
};

class Menu {
    MenuItem* items[MAX_MENU_ITEMS];
    char* title;
    int itemCount;
public:
    Menu(const char* title = nullptr);
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    ~Menu();
    void displayTitle(std::ostream& os) const;
    void display(std::ostream& os) const;
    unsigned int run() const;
    Menu& operator<<(const char* menuItemContent);
    operator int() const;
    operator unsigned int() const;
    operator bool() const;
    const char* operator[](int index) const;
    unsigned int operator~() const;  // Overloaded operator~
    friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
};

} // namespace seneca

#endif // MENU_H