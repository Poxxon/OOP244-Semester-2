/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Pouya Rad
Student ID#: 164382228
Email      : prad@myseneca.ca
Section    : NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"

using namespace std;
namespace seneca {
    const double PI = 3.14159265;
    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_diameter = 10.0;
        m_height = 13.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    void Canister::setName(const char* Cstr) {
        if (Cstr != nullptr && m_usable) {
            delete[] m_contentName;
            m_contentName = new char[strlen(Cstr) + 1];
            strcpy(m_contentName, Cstr);
        }
    }

    bool Canister::isEmpty() const {
        return m_contentVolume < 0.00001;
    }

    bool Canister::hasSameContent(const Canister& C) const {
        if (m_contentName == nullptr && C.m_contentName == nullptr) {
            return false;
        } return strcmp(m_contentName, C.m_contentName);
    }

    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0.0;

            if (contentName != nullptr) {
            m_contentName = new char[strlen(contentName) + 1];
            strcpy(m_contentName, contentName);
        } else {
            m_contentName = nullptr;
        }
    } else {
        m_usable = false;
    }
    }

    Canister::~Canister() {
        delete[] m_contentName;
    }

    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr || !m_usable) {
            m_usable = false;
        } else if (isEmpty()) {
            setName(contentName);
        } else if (m_contentName && strcmp(m_contentName, contentName) != 0) {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(double quantity) {
        if (m_usable && quantity > 0 && (quantity + volume()) <= capacity()) {
            m_contentVolume += quantity;
        } else {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(Canister& C) {
        setContent(C.m_contentName); 
        if (C.volume() > capacity() - volume()) { 
            C.m_contentVolume -= capacity() - volume(); 
            m_contentVolume = capacity();
        } else {
            pour(C.m_contentVolume); 
            C.m_contentVolume = 0.0; 
        }
        return *this; 
    }


    double Canister::volume() const {
        return m_contentVolume;
    }

    ostream& Canister::display() const {
        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
        cout << capacity();
        cout << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable) {
            cout << " of Unusable content, discard!";
        } else if (m_contentName != nullptr) {
            cout << " of " << right << setw(7) << volume() << "cc   " << m_contentName;
        }
        return cout;
    }

    double Canister::capacity() const {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    void Canister::clear() {
        delete[] m_contentName;
        m_contentName = nullptr;
        
        m_contentVolume = 0.0;
        m_usable = true;
    }
}
