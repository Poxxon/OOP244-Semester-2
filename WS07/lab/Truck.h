//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-03
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_TRUCK_H
#define SENECA_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"

namespace seneca
{
  class Truck : public MotorVehicle
  {
    double m_MaxCapacity{0.00};
    double m_CurrCapacity{0.00};

  public:
    Truck(){}
    Truck(const char *_license, int _year, double _capacity,
          const char *_address = nullptr);
    ~Truck(){}

    bool addCargo(const double cargo);
    bool unloadCargo();

    // Display the info on MotorVehicle
    std::ostream &write(std::ostream &os) const;

    // get new information from the user
    std::istream &read(std::istream &in);
  };
  std::ostream &operator<<(std::ostream &ostr, const Truck &src);
  std::istream &operator>>(std::istream &istr, Truck &src);
}

#endif