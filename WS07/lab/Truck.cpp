//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-03
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Truck.h"

using namespace std;

namespace seneca
{
  Truck::Truck(const char *_license, int _year, double _capacity,
               const char *_address) : MotorVehicle(_license, _year)
  {
    if (_capacity > 0) m_MaxCapacity = _capacity;
    if (_address) this->moveTo(_address);
  }

  bool Truck::addCargo(const double cargo)
  {
    bool result = false;

    // If maximum is exceeded it is not going to be loaded
    if (cargo > 0 && (m_CurrCapacity != m_MaxCapacity)) {
      m_CurrCapacity += cargo;
      result = true;
      if (m_CurrCapacity > m_MaxCapacity) m_CurrCapacity = m_MaxCapacity;
    }

    return result;
  }

  bool Truck::unloadCargo()
  {
    bool result = false;

    // If capacity is empty it will not be unloaded.
    if (m_CurrCapacity > 0) {
      m_CurrCapacity = 0.00;
      result = true;
    }

    return result;
  }

  std::ostream& Truck::write(std::ostream &os) const
  {
    MotorVehicle::write(os);
    os << " | " << m_CurrCapacity << "/" << m_MaxCapacity;

    return os;
  }

  std::istream &Truck::read(std::istream &in)
  {
    MotorVehicle::read(in);

    cout << "Capacity: ";
    in >> m_MaxCapacity;
    while (!in) {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Invaild Max Capacity, Retry to enter: ";
      cin >> m_MaxCapacity;
    }

    cout << "Cargo: ";
    in >> m_CurrCapacity;
    while (!in) {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Invaild cargo amount, Retry to enter: ";
      cin >> m_CurrCapacity;
    }

    return in;
  }

  std::ostream &operator<<(std::ostream &ostr, const Truck &src)
  {
    return src.write(ostr);
  }

  std::istream &operator>>(std::istream &istr, Truck &src)
  {
    return src.read(istr);
  }
}