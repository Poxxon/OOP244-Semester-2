//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace seneca {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& employees) {
      bool ok = false;
      char name[128];
      int empNo;
      double salary;
      if (read(empNo) && read(salary) && read(name)) {
         int length = strlen(name) + 1;
         employees.m_name = new char[length];
         strcpy(employees.m_name, name);
         employees.m_empNo = empNo;
         employees.m_salary = salary;
         ok = true;
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
         noOfEmployees = noOfRecords();
         employees = new Employee[noOfEmployees];
         for (i = 0; i < noOfEmployees; ++i) {
            if (!load(employees[i])){
               cout << "Number of employees did not load as expected!" << endl; //error message in case it did not load properly
               closeFile();
               return false;
            }
         }
         ok = true;
         closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   // displays a employee record on the screen
   void display(const Employee& employees){
      cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
   }

   // first sorts the employees then displays all the employees on the screen
   void display(){
      cout << "Employee Salary report, sorted by employee number" << endl;
      cout << "no- Empno, Name, Salary" << endl;
      cout << "------------------------------------------------" << endl;
      sort();
      for (int i = 0; i < noOfEmployees; ++i) {
         cout << i + 1 << "- ";
         display(employees[i]);
      }
   }


   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory(){
      for (int i = 0; i < noOfEmployees; ++i) {
         delete[] employees[i].m_name;
      }
      delete[] employees;
   }


}