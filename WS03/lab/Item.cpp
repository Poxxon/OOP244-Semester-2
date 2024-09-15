//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <cstring>
#include "Item.h"
#include <iomanip>

using namespace std;

namespace seneca {
    void Item::setEmpty() {
        m_itemName[0] = '\0';
        m_price = 0.0;
        m_taxed = false;
    }

    void Item::setName(const char* name) {
        if (name != nullptr && name[0] != '\0') {
            strncpy(m_itemName, name, 20);
            m_itemName[20] = '\0';
        } else {
            setEmpty();
        }
    }

    void Item::set(const char* name, double price, bool taxed) {
        setEmpty();
        if (name != nullptr && name[0] != '\0' && price > 0) {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

     void Item::display() const {
        if (isValid()) {
            cout << "| " << left << setw(20) << setfill('.') << m_itemName << " | ";
            cout << right << setw(7) << setfill(' ') << fixed << setprecision(2) << m_price << " | ";
            cout << (m_taxed ? "Yes" : "No ") << " |" << endl;
        } else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

    bool Item::isValid() const {
        return m_itemName[0] != '\0' && m_price > 0;
    }

    double Item::price() const {
        return m_price;
    }

    double Item::tax() const {
        return m_taxed ? m_price * 0.13 : 0.0;
    }
}
