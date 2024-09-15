//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
//==============================================
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();

   public:
      Account();
      Account(int number, double balance);

      ~Account() {};

      std::ostream& display()const;

      operator bool() const;

      operator int() const;

      operator double() const;

      //returns true if account number is zero
      bool operator~() const;

      //function to add/depositing double value to account
      Account &operator+=(const double _into);

      //function to decrease/withdraw a double value
      Account &operator-=(const double _draw);

      //to transfer funds from left account to right
      Account &operator>>(Account &_move);

      //to transfer funds from right account to left
      Account &operator<<(Account &_move);

      Account &operator=(const int _acc);

      Account &operator=(Account &_move);

      //return the double value for sum of two balances of two accounts
      friend double operator+(const Account &_left, const Account &_right);

      //value of the balance on the right operand will be added to the left
      friend double operator+=(double &_value, const Account &_add);
   };
   
   
}
#endif // SENECA_ACCOUNT_H_