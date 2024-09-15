// Final Project Milestone 1 
// Date Module
// File	Menu.h
// Version 1.0
// Author	Haig McGarry
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds{
	const unsigned int MAX_MENU_ITEMS = 20;
	class MenuItem {
		char* itemName;
		MenuItem(const char* item = nullptr);
		~MenuItem();

		operator const char* () const;
		operator bool() const;
		std::ostream& display(std::ostream& os) const;
	public:
		friend class Menu;
		MenuItem(const MenuItem& src) = delete;
		MenuItem& operator=(const MenuItem& src) = delete;
		//MS2
		friend class LibApp;
	};

	class Menu {
		MenuItem* title; //optional
		MenuItem* items[MAX_MENU_ITEMS];
		unsigned int itemNum; //must be between 0 and 20
	public:
		Menu(); //sets to safe-empty
		Menu(const char* name); //Calls menu() and then sets the title
		~Menu(); //Loops through the array of pointers items. Deletes each pointer up to the value of itemNum
		void displayTitle(std::ostream& os)const; //displays the title if object has one
		void display(std::ostream& os)const;
		unsigned int run();
		unsigned int operator~();
		Menu& operator<<(const char* menuItemContent);
		operator unsigned int() const;
		operator int() const;
		operator bool()const;
		const char* operator[](int idx) const;
		Menu(const Menu& src) = delete;
		Menu& operator=(const Menu& src) = delete;
		//MS2
		friend class LibApp;


	};
	std::ostream& operator<<(std::ostream& os, const Menu& item);
}
#endif // SENECA_MENU_H
