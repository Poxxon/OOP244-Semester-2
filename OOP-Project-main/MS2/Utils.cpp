/* Citation and Sources...
Final Project Milestone 2
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Pouya Rad
Revision History
-----------------------------------------------------------
Date      Reason
2024/7/1  Preliminary release
2024/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Utils.h"
#include <iostream>

void clearScreen() {
	std::cout << "\033[2J\033[1;1H";
}
