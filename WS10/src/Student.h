//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-26
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#ifndef SENECA_STUDENT_H_
#define SENECA_STUDENT_H_
#include "ReadWrite.h"
namespace seneca {
   class Student : public ReadWrite {
      int m_stno;
      char m_name[41];
      double m_gpa;
   public:
      Student();
      Student(int stno, const char* name, double gpa);
      void set(int stno, const char* name, double gpa);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(double gpa)const;
   };
}
#endif // !SENECA_STUDENT_H_

