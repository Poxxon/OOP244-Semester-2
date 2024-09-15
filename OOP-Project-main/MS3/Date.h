#pragma once
/* Citation and Sources...
Final Project Milestone 3
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
#ifndef SENECA_DATE_H__
#define SENECA_DATE_H__
#include <iostream>
namespace seneca {

    extern bool seneca_test;
    extern int seneca_year;
    extern int seneca_mon;
    extern int seneca_day;

    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int DAY_ERROR = 4;
    const char DATE_ERROR[5][16] = { "No Error", "cin Failed", "Bad Year Value",
                                    "Bad Month Value", "Bad Day Value" };
    const int MIN_YEAR = 1500;
    class Date {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;
        int daysSince0001_1_1()
            const; 
        bool
            validate();            
        void errCode(int);      
        int systemYear() const;
        bool bad() const;      
        int mdays() const;     
        void setToToday();    
    public:
        Date();                          
        Date(int year, int mon, int day); 
        int errCode() const; 
        const char* dateStatus()
            const;
        int currentYear() const; 

        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;

        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator>=(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;

        int operator-(const Date& other) const;
        operator bool();
    };
    std::ostream& operator<<(std::ostream& os, const Date& RO);
    std::istream& operator>>(std::istream& is, Date& RO);
} 
#endif
