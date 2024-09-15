//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-26
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__

#include "Text.h"

namespace seneca {
  class HtmlText :  public Text {
    char* m_title {nullptr};

  public:
    HtmlText(const char* filename=nullptr, const char* title = nullptr);
    HtmlText(const HtmlText &src);
    HtmlText &operator=(const HtmlText &src);
    ~HtmlText();

    void write(std::ostream &os) const;
  };
}
#endif 
