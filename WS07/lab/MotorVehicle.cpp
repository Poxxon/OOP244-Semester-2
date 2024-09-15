//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-03
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "MotorVehicle.h"
#include "Utils.h"

using namespace std;

namespace seneca
{
  MotorVehicle::MotorVehicle(const char *_license, int _year, const char *_location)
  {
    if (_license) strCpy(m_license, _license);
    m_year = _year;
    strCpy(m_address, _location);
  }

  void MotorVehicle::moveTo(const char* _address)
  {
    if (strCmp(m_address, _address) != 0) {
      cout << "|";
      cout.width(8);
      cout << m_license << "| |";

      cout.width(20);
      cout << m_address << " ---> ";

      cout.width(20);
      cout << left << _address << "|" << right << endl;

      strCpy(m_address, _address);
    }
  }

  std::ostream &MotorVehicle::write(std::ostream &os) const
  {
    os << "|";
    os.width(5);
    os << m_year << " | " << m_license << " | " << m_address;

    return os;
  }

  std::istream &MotorVehicle::read(std::istream &in)
  {
    cout << "Built year: ";
    in >> m_year;
    while (!in) {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Invaild year, Retry to enter: ";
      cin >> m_year;
    }

    cout << "License plate: ";
    in >> m_license;

    cout << "Current location: ";
    in >> m_address;
    while (m_address[0] < 65 || m_address[0] > 122) {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Invaild location, Retry to enter: ";
      cin >> m_address;
    }

    return in;
  }

  std::ostream &operator<<(std::ostream &ostr, const MotorVehicle &src)
  {
    return src.write(ostr);
  }

  std::istream &operator>>(std::istream &istr, MotorVehicle &src)
  {
    return src.read(istr);
  }

}