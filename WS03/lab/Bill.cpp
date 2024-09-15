//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <cstring>
#include "Bill.h"
#include <iomanip>

using namespace std;

namespace seneca {
    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
        m_noOfItems = 0;
        m_itemsAdded = 0;
    }

    void Bill::init(const char* title, int noOfItems) {
        setEmpty();
        if (title != nullptr && title[0] != '\0' && noOfItems > 0) {
            strncpy(m_title, title, 36);
            m_title[36] = '\0';
            m_noOfItems = noOfItems;
            m_items = new Item[noOfItems];
            for (int i = 0; i < noOfItems; i++) {
                m_items[i].setEmpty(); 
            }
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        return false;
    }

    void Bill::Title() const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| " << left << setw(36) << setfill(' ') << m_title << " |" << endl;
        } else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << "|                Total Tax: " << setw(10) << right << fixed << setprecision(2) << totalTax() << " |" << endl;
            cout << "|              Total Price: " << setw(10) << right << fixed << setprecision(2) << totalPrice() << " |" << endl;
            cout << "|          Total After Tax: " << setw(10) << right << fixed << setprecision(2) << totalPrice() + totalTax() << " |" << endl;
        } else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    double Bill::totalTax() const {
        double tax = 0.0;
        for (int i = 0; i < m_noOfItems; ++i) {
            tax += m_items[i].tax();
        }
        return tax;
    }

    double Bill::totalPrice() const {
        double price = 0.0;
        for (int i = 0; i < m_noOfItems; ++i) {
            price += m_items[i].price();
        }
        return price;
    }

    bool Bill::isValid() const {
        for (int i = 0; i < m_noOfItems; ++i) {
            if (!m_items[i].isValid()) {
                return false;
            }
        }
        return true;
    }

    void Bill::display() const {
        Title();
        for (int i = 0; i < m_noOfItems; ++i) {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }
}
