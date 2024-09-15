//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-26
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

namespace seneca
{
    template <typename T>
    void listArrayElements(const char* _title, const T* _arr, int _num) {
        cout << _title << endl;

        for (int i = 0; i < _num; i++) {
            cout << (i + 1) << ": ";
           
            cout << _arr[i] << endl;
        }
    }

    template <typename T1, typename T2>
    bool search(Collection<T1>& _obj, const T1* _arr, int _num, T2 _key) {
        bool result = false;

        for (int i = 0; i < _num; i++) {
            if (_arr[i] == _key) { 
                _obj.add(_arr[i]); 
                result = true;
            }
        }
        return result;
    }
}
#endif // !SDDS_SEARCHNLIST_H_