//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-26
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace seneca {
  class Text {
    char *m_filename {nullptr};
    char *m_content {nullptr};
    int getFileLength() const;

  protected:
    const char &operator[](int index) const;

  public:
    Text(const char *filename = nullptr);
    Text(const Text &src);
    Text &operator=(const Text &src);

    virtual ~Text();
    void read();
    virtual void write(std::ostream &os) const;
  };

  std::ostream &operator<< (std::ostream &os, const Text &src);
}
#endif // !SDDS_PERSON_H__
