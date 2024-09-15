/* Citation and Sources...
Final Project Milestone 5
Module: Utils
Filename: Utils.cpp
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

#include <iostream>
#include "Utils.h"

using namespace std;
namespace sdds {


    size_t Utils::getInt(size_t min, size_t max) {
        size_t val{};
        cin >> val;
        while ( cin.fail() || val < min || val >max) {
            cout << "Invalid Selection, try again: ";
            cin.clear( );
            cin.ignore( 12000, '\n' );
            cin >> val;
        }
        cin.ignore( 12000, '\n' );
        return val;
    }

    int Utils::getMemberNum() {
        int val{};
        cin >> val;
        while ( cin.fail() || val < 10000 || val >99999) {
            cout << "Invalid membership number, try again: ";
            cin.clear( );
            cin.ignore( 12000, '\n' );
            cin >> val;
        }
        cin.ignore( 12000, '\n' );
        return val;
    }

    char Utils::getType(unsigned int num) {
        char ch = 'X';
        switch(num){
            case 1:
                ch = 'B';
                break;
            case 2:
                ch = 'P';
                break;
            default:
                ch = 'X';
                break;
        }
        return ch;
    }
}