//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }

   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }

   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }

   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const {
      bool result = false;

      if(m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0){
         result = true;
      }

      return result;
   }

   Account::operator int() const {
      return m_number;
   }

   Account::operator double() const {
      return m_balance;
   }

   bool Account::operator~() const {
      return m_number == 0;
   }

   Account &Account::operator+=(const double _into) {
      if (m_number > 0 && m_balance >= 0.0 && _into > 0.0) {
         m_balance += _into;
      }
      return *this;
   }

   Account& Account::operator-=(const double _draw) {
      if(m_number > 0 && m_balance >= _draw && _draw >= 0.0) {
         m_balance -= _draw;
      }
      return *this;
   }

   Account& Account::operator>>(Account &_move) {
      if (this->m_number > 0 && _move.m_number > 0 && this->m_number != _move.m_number) {
         _move.m_balance += this->m_balance;
         this->m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator<<(Account &_move) {
      if (this->m_number > 0 && _move.m_number > 0 && this->m_number != _move.m_number) {
         this->m_balance += _move.m_balance;
         _move.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator=(const int _acc) {
      if (m_number == 0) {
         m_number = _acc;
      } else if (_acc < 0) {
         setEmpty();
      }

      return *this;
   }

   Account& Account::operator=(Account &_move) {
      if (this->m_number == 0 && _move.m_number > 0) {
         this->m_number = _move.m_number;
         this->m_balance = _move.m_balance;

         _move.m_number = 0;
         _move.m_balance = 0;
      }

      return *this;
   }

   double operator+(const Account &_left, const Account &_right) {
      double sum = 0.0;

      if (_left.m_number > 0 && _right.m_number > 0) {
         sum = _left.m_balance + _right.m_balance;
      }
      return sum;
   }

   double operator+=(double &_value, const Account &_add){
      if(_add.m_number > 0) {
         _value += _add.m_balance;
      }
      return _value;
   }
}