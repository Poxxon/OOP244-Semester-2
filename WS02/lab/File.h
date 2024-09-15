//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   
   // read function to point to the name of the employees
   bool read(char* m_name);
   // read function to refer to the employee number
   bool read(int& m_empNo);
   // read function to refer to salary of the employees
   bool read(double& m_salary);

}
#endif // !SENECA_FILE_H_
