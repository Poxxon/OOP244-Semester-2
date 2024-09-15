//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-26
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include "Text.h"
#include <cstring>

using namespace std;

namespace seneca { 

  int Text::getFileLength() const {
    int len = 0; 
    ifstream fin(m_filename);

    while (fin) {
      fin.get(); 
      len += !!fin;
    }

    return len;
  }

  const char &Text::operator[](int index) const {
    if (index >= 0 || index < getFileLength())
      return m_content[index]; 
    else
      return m_content[getFileLength()]; 
  }
  Text::Text(const char *filename) {
    if (filename) {
        m_filename = new char[strlen(filename) + 1]; 
        strcpy(m_filename, filename); 
        read(); 
    } else {
        m_filename = nullptr;
        m_content = nullptr; 
    }
  }

  Text::Text(const Text &src) {
    *this = src; 
  }

  Text& Text::operator=(const Text &src) {
    if (this != &src) { 
      if (m_filename) delete[] m_filename; 

      if (src.m_filename) { 
          m_filename = new char[strlen(src.m_filename) + 1];
          strcpy(m_filename, src.m_filename); 
          read();
      } else {
        m_filename = nullptr;
        m_content = nullptr; 
      }
    }

    return *this; 
  }

  Text::~Text() {
    if (m_filename) { 
      delete[] m_filename; 
      m_filename = nullptr;
    }

    if (m_content) { 
      delete[] m_content; 
      m_content = nullptr; 
    }
  }

  void Text::read() {
    char temp;
    int index = 0; 
    ifstream _read(m_filename);

    if (m_content) delete[] m_content;

    if (_read.is_open()) {
      m_content = new char[getFileLength() + 1];

      while (_read.get(temp)) {
        m_content[index] = temp; 
        index++; 
      }

      m_content[index] = '\0';
    } else {
        m_content = nullptr; 
    }
  }

  void Text::write(std::ostream &os) const {
    if (m_content) os << m_content;
  }

  std::ostream &operator<<(std::ostream &os, const Text &src) {
    src.write(os); 
    return os; 
  }
}
