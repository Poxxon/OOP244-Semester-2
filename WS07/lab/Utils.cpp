//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NFF
// Date:           2024-07-03
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Utils.h"
namespace seneca
{
  // gets the length of the string
  int strLen(const char *s)
  {
    int length = 0;

    while (s[length])
      length++;

    return length;
  }

  // copies from source to destination
  void strCpy(char *des, const char *src)
  {
    int i = 0;

    while (src[i]) {
      // copies from source to destination
      des[i] = src[i];
      i++;
    }

    des[i] = '\0';
  }

  // compares two strings
  int strCmp(const char *s1, const char *s2)
  {
    int i = 0, result = 0;
    bool flag = false;

    // set the while loop to repeat until the comparison is complete
    while (!flag) {
      if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
        result = s1[i] - s2[i];
        flag = true;
      }

      i++;
    }

    return result;
  }
}