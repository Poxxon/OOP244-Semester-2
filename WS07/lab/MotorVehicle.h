//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-03
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_MOTORVEHICLE_H
#define SENECA_MOTORVEHICLE_H

#include <iostream>

namespace seneca
{
  class MotorVehicle
  {
    char m_license[9]{'\0'};
    char m_address[64]{'\0'};
    unsigned int m_year{0};

  public:
    MotorVehicle(){}
    MotorVehicle(const char *_license, int _year, const char *_location = "Factory");
    ~MotorVehicle(){}

    // moves vehicle to new address
    void moveTo(const char* _address);

    // Display the info on MotorVehicle module
    std::ostream &write(std::ostream &os) const;

    // get new information from the user
    std::istream &read(std::istream &in);
  };

  std::ostream &operator<<(std::ostream &ostr, const MotorVehicle &src);
  std::istream &operator>>(std::istream &istr, MotorVehicle &src);
}
#endif