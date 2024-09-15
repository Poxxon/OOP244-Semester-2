// Final Project Milestone 1 
// Date Module
// File	Menu.cpp
// Version 1.0
// Author	Haig McGarry
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
#include "Menu.h"
namespace sdds {
	MenuItem::MenuItem(const char* item) {
		if (item)
		{
			itemName = new char[strlen(item) + 1];
			strcpy(itemName, item);
		}
		else
		{
			itemName = nullptr;
		}
		
	}
	MenuItem::~MenuItem() {
		delete[] itemName;
	}

	MenuItem::operator bool() const {
		return itemName != nullptr;
	}

	MenuItem::operator const char* () const {
		return itemName;
	}

	std::ostream& MenuItem::display(std::ostream& os)const {
		if (itemName != nullptr)
		{
			os << itemName;
		}

		return os;
	}
	//END OF MENUITEM CLASS
	//START OF MENU CLASS IMPLEMENTATION

	Menu::Menu() : title(nullptr), itemNum(0) {
		unsigned int i;
		for ( i = 0; i < MAX_MENU_ITEMS; i++)
		{
			items[i] = nullptr;
		}
	}

	Menu::Menu(const char* name) : Menu() {
		//delete[] title.itemName;
		if (name != NULL)
		{
			title = new MenuItem(name);
		}
		
	}

	Menu::~Menu() {
		unsigned int i;
		delete title;
		for ( i = 0; i < itemNum; i++)
		{
			delete items[i];
		}
	}


	void Menu::displayTitle(std::ostream& os)const {
		if (title)
		{
			title->display(os);
		}
	}

	void Menu::display(std::ostream& os)const {
		unsigned int i;
		if (title)
		{
			displayTitle(os);
			//os << ":" << endl; Removed for MS2
			os << endl; //added so there's a newline after title
		}

		for ( i = 0; i < itemNum; i++)
		{
			if (items[i])
			{
				os.width(2);
				os.setf(ios::right);
				os << i + 1 << "- ";
				items[i]->display(os); //MenuItem display shadows here
				os << endl;
				os.unsetf(ios::right);
			}
		}
		os << " 0- Exit" << endl;
		os << "> ";

	}

	unsigned int Menu::run() {
		unsigned int select;
		bool flag = false;
		display(std::cout);

		while (!flag) {
			cin >> select;
			if (cin.fail() || select > itemNum)
			{
				cout << "Invalid Selection, try again: ";
				cin.clear();
			}
			else
			{
				flag = true;
			}
			while (getchar() != '\n');
		}
	
		return select;
	}

	unsigned int Menu::operator~() {
		return run();
	}

	Menu& Menu::operator<<(const char* menuItemContent) {
		if (itemNum < MAX_MENU_ITEMS && menuItemContent != NULL)
		{
			delete[] items[itemNum];
			items[itemNum] = new MenuItem(menuItemContent);
			itemNum++;
		}

		return *this;
	}

	Menu::operator unsigned int() const {
		return itemNum;
	}

	Menu::operator int() const {
		return itemNum;
	}

	Menu::operator bool()const {
		return itemNum > 0;
	}

	const char* Menu::operator[](int idx)const {
		return items[idx % itemNum]->itemName;
	}

	std::ostream& operator<<(std::ostream& os, const Menu& item) {
		item.displayTitle(os);
		return os;
	}

	//MS2 copy members


	

}