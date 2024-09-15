//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-26
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "HtmlText.h"
#include <cstring>

namespace seneca { 

  HtmlText::HtmlText(const char *filename, const char *title) : Text(filename) {
    if (title) { 
        m_title = new char[strlen(title) + 1]; 
        strcpy(m_title, title); 
    } else {
        m_title = nullptr;
    }
  }

  HtmlText::HtmlText(const HtmlText &src) {
    *this = src; 
  }

 
  HtmlText &HtmlText::operator=(const HtmlText &src) {
    if (this != &src) {
      (Text&)*this = src;

      if (m_title) delete[] m_title; 

      if (src.m_title) { 
          m_title = new char[strlen(src.m_title) + 1]; 
          strcpy(m_title, src.m_title); 
      } else {
          m_title = nullptr; 
      }
    }

    return *this; 
  }

  HtmlText::~HtmlText() {
    if (m_title) { 
      delete[] m_title; 
      m_title = nullptr; 
    }
  }

  void HtmlText::write(std::ostream &os) const {
    bool MS = false; 
    char temp; 

    os << "<html><head><title>";
    m_title != nullptr ? os << m_title : os << "No title"; 
    os << "</title></head>\n<body>\n";

    if (m_title) { 
      int index = 0;
      os << "<h1>" << m_title << "</h1>\n"; 

    
      while (Text::operator[](index) != '\0') {
        temp = Text::operator[](index); 
        switch (temp) {
          case ' ': 
            if (MS) os << "&nbsp;"; 
            else {
              os << temp; 
              MS = true;
            }
            break;

          case '<':
            os << "&lt;"; 
            MS = false;
            break;

          case '>': 
            os << "&gt;"; 
            MS = false;
            break;

          case '\n': 
            os << "<br />\n"; 
            MS = false; 
            break;

          default:
            os << temp; 
            MS = false;
            break;
        }

        index++; 
      }
    }
    os << "</body>\n</html>"; 
  }
} 