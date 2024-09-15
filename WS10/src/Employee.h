//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-26
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#ifndef SENECA_EMPLOYEE_H_
#define SENECA_EMPLOYEE_H_
#include "ReadWrite.h"
namespace seneca {
   class Employee : public ReadWrite {
      int m_empno;
      int m_office;
      char m_name[41];
      double m_salary;
   public:
      Employee();
      Employee(int stno, const char* name, double salary, int office);
      void set(int stno, const char* name, double salary, int office);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(int office)const;
   };


}
#endif // !SENECA_EMPLOYEE_H_