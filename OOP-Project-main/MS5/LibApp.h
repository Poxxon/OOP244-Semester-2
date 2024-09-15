/*
* Name: Haig McGarry
* ID: 184770238
* Email: hmcgarry1@myseneca.ca
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>
#include "Menu.h"
#include "Book.h"
namespace sdds {
   class LibApp {
	   bool m_changed;
	   Menu m_mainMenu;
	   Menu m_exitMenu;
	   //MS5 Members:
	   char m_filename[256];
	   Publication* m_PPA[SENECA_LIBRARY_CAPACITY]; //Array of Publication Pointers to hold from file m_filename
	   int m_NOLP; //Number of loaded publication
	   int m_LLRN; //last library reference number; libref of the last loaded publication. When a new pub is added it is incremented by 1 so each pub has a unique llrn
	   Menu m_pubMenu; //Title of menu is "Choose type of publication". Provide two selections: Book and Publication. Same setup in the constructor as the main and exit menus
	   //
	   bool confirm(const char* message);
	   //CHANGE IMPLEMENTATION FOR MS5:
	   void load();
	   void save();
	   int search(int select = 0); //updated search to receive an int and return a libref (if 0 then the process was aborted)
	   void returnPub();
	   void newPublication();
	   void removePublication();
	   void checkOutPub();
   public:
	   LibApp(const char* filename = nullptr);
	   void run();
	   Publication* getPub(int libRef);
	   ~LibApp();
   };
}
#endif // !SDDS_LIBAPP_H



