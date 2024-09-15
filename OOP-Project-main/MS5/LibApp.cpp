/*
* Name: Haig McGarry
* ID: 184770238
* Email: hmcgarry1@myseneca.ca
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "LibApp.h"
#include "PublicationSelector.h"
namespace sdds {
	bool LibApp::confirm(const char* message) {
		bool flag = false;
		Menu cnfrmMenu(message);
		cnfrmMenu << "Yes";

		if (cnfrmMenu.run() == 1)
		{
			flag = true;
		}

		return flag;
   }

	//----Temp Functions---
	void LibApp::load() {
		std::cout << "Loading Data" << std::endl;
		std::ifstream fin(m_filename);
		char type;
		if (fin.is_open() && m_filename[0] != '\0')
		{
			for (int i = 0; fin; i++)
			{
				fin.get(type);
					if (type == 'B')
					{
						m_PPA[m_NOLP] = new Book;
						m_PPA[m_NOLP]->read(fin);//maybe? We're trying to set the instance to the 
						m_NOLP++;
					}
					else if (type == 'P')
					{
						m_PPA[m_NOLP] = new Publication;
						m_PPA[m_NOLP]->read(fin);
						m_NOLP++;
					}
			}
			
			m_LLRN = m_PPA[m_NOLP - 1]->getRef();
		}
		else
		{
			std::cout << "ERROR OPENING FILE OR INVALID FILENAME" << std::endl;
		}
	}
	void LibApp::save() {
		std::cout << "Saving Data" << std::endl;
		std::ofstream fout(this->m_filename); //opening file for OVERwriting

		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i] != nullptr && m_PPA[i]->getRef() != 0)
			{
				fout << *m_PPA[i] << std::endl;
			}
			
		}
	}
	int LibApp::search(int select) {
		int libRef = 0;
		int choice;
		bool flag = false;
		char title[256] = { '\0' };
		//1 = Search all 2 = Search Checkout items (only items that are on loan) 3 = Search Available items (only items that aren't on loan
		//std::cout << "Searching for publication" << std::endl;
		PublicationSelector srchSelector("Select one of the following found matches:");

		if (select == 1) //search all
		{
			//search all
			if ((choice = m_pubMenu.run()) != 0) //parends around pubMenu.run() to prevent a warning
			{
				std::cout << "Publication Title: ";
				std::cin.get(title, 255, '\n');				
				std::cin.ignore(1000, '\n'); //ignore newline
				if (choice == 1) //search all books
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i] != nullptr && m_PPA[i]->type() == 'B') //if book append to PublicationSelector instance
						{
							if (*m_PPA[i] == title) //checking if the title the user enters matches any titles in ppa
							{
								srchSelector << m_PPA[i];
								flag = true;
							}
							
						}
					}
				}
				else if (choice	== 2) //search all publications
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i] != nullptr && m_PPA[i]->type() == 'P') //if publication append to PublicationSelector instance
						{
							if (*m_PPA[i] == title) //checking if the title the user enters matches any titles in ppa
							{
								srchSelector << m_PPA[i];
								flag = true;
							}
						}
					}
				}

				if (flag)
				{
					if (!std::cin)
					{
						//std::cout << "CIN ERROR" << std::endl;
						std::cin.clear();
						std::cin.ignore(1000, '\n');
					}
					srchSelector.sort();
					libRef = srchSelector.run();
					if (libRef == 0)
					{
						std::cout << "Aborted!" << std::endl;
					}
					
				}
				else
				{
					std::cout << "No matches found!" << std::endl;
				}
			}
			

			else //user aborts function
			{
				std::cout << "Aborted!" << std::endl;
			}

		}
		else if (select == 2)//checkout items
		{
			if ((choice = m_pubMenu.run()) != 0)
			{
				std::cout << "Publication Title: ";
				std::cin.get(title, 255, '\n');
				std::cin.ignore(1000, '\n'); //ignore newline
				if (choice == 1) //search checkout books
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i] != nullptr && m_PPA[i]->type() == 'B' && m_PPA[i]->getMember() == 0) //if book append to PublicationSelector instance
						{
							if (*m_PPA[i] == title) //checking if the title the user enters matches any titles in ppa
							{
								srchSelector << m_PPA[i];
								flag = true;
							}

						}
					}
				}
				else if (choice == 2) //search all publications
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i] != nullptr && m_PPA[i]->type() == 'P' && m_PPA[i]->getMember() == 0) //if publication append to PublicationSelector instance
						{
							if (*m_PPA[i] == title) //checking if the title the user enters matches any titles in ppa
							{
								srchSelector << m_PPA[i];
								flag = true;
							}
						}
					}
				}

				if (flag)
				{
					if (!std::cin)
					{
						//std::cout << "CIN ERROR" << std::endl;
						std::cin.clear();
						std::cin.ignore(1000, '\n');
					}
					srchSelector.sort();
					libRef = srchSelector.run();
					if (libRef == 0)
					{
						std::cout << "Aborted!" << std::endl;
					}
				}
				else
				{
					std::cout << "No matches found!" << std::endl;
				}
			}


			else //user aborts function
			{
				std::cout << "Aborted!" << std::endl;
			}
		}

		else if (select == 3)
		{
			if ((choice = m_pubMenu.run()) != 0)
			{
				std::cout << "Publication Title: ";
				std::cin.get(title, 255, '\n');
				std::cin.ignore(1000, '\n'); //ignore newline
				if (choice == 1) //search all books
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						//std::cout << "Member ID: " << m_PPA[i]->getMember() << std::endl;
						if (m_PPA[i] != nullptr && m_PPA[i]->type() == 'B' && m_PPA[i]->getMember() != 0) //if book append to PublicationSelector instance
						{
							if (*m_PPA[i] == title) //checking if the title the user enters matches any titles in ppa
							{
								srchSelector << m_PPA[i];
								flag = true;
							}

						}
					}
				}
				else if (choice == 2) //search all publications
				{
					for (int i = 0; i < m_NOLP; i++)
					{
						if (m_PPA[i] != nullptr && m_PPA[i]->type() == 'P' && m_PPA[i]->getMember() != 0) //if publication append to PublicationSelector instance
						{
							if (*m_PPA[i] == title) //checking if the title the user enters matches any titles in ppa
							{
								srchSelector << m_PPA[i];
								flag = true;
							}
						}
					}
				}

				if (flag)
				{
					if (!std::cin)
					{
						//std::cout << "CIN ERROR" << std::endl;
						std::cin.clear();
						std::cin.ignore(1000, '\n');
					}
					srchSelector.sort();
					libRef = srchSelector.run();
					if (libRef == 0)
					{
						std::cout << "Aborted!" << std::endl;
					}
				}
				else
				{
					std::cout << "No matches found!" << std::endl;
				}
			}


			else //user aborts function
			{
				std::cout << "Aborted!" << std::endl;
			}
		}
		else
		{
			std::cout << "ERROR: Invalid use of Search(), aborting process" << std::endl;
		}
		return libRef;
	}
	void LibApp::returnPub() {
		int libRef, index = 0;
		Date curDate;
		int daysLate;
		double lateFee;
		std::cout << "Return publication to the library" << std::endl;
		libRef = search(3);
		if (libRef != 0)
		{
			for (int i = 0; i < m_NOLP; i++)
			{
				if (m_PPA[i]->getRef() == libRef)
				{
					std::cout << *m_PPA[i] << std::endl;
					index = i;
				}
			}
			if (confirm("Return Publication?"))
			{
				if ((daysLate = (curDate - m_PPA[index]->checkoutDate())) > 15)
				{
					lateFee = (daysLate - 15) * 0.50; //50 cents per day late
					std::cout << "Please pay $";
					std::cout.setf(std::ios::fixed);
					std::cout.precision(2);
					if (lateFee < 10.0)
					{
						std::cout.width(3);
					}
					else
					{
						std::cout.width(4);
					}
					std::cout.fill('0');
					std::cout << lateFee << " penalty for being " << (daysLate - 15) << " days late!" << std::endl;
					std::cout.unsetf(std::ios::fixed);
					std::cout.fill(' ');
				}
				m_PPA[index]->set(0);
				m_changed = true;
				std::cout << "Publication returned" << std::endl;
			}

		}
	}
	//-------------------

	void LibApp::newPublication() {
		bool abort = false;
		if (m_NOLP == SENECA_LIBRARY_CAPACITY)
		{
			std::cout << "Library is at its maximum capacity!" << std::endl;
		}
		else
		{
			std::cout << "Adding new publication to the library" << std::endl;

			switch (m_pubMenu.run())
			{
			case 1: 
				//book code here
				this->m_PPA[m_NOLP] = new Book;
				this->m_PPA[m_NOLP]->read(std::cin);
				break;
			case 2:
				this->m_PPA[m_NOLP] = new Publication;
				this->m_PPA[m_NOLP]->read(std::cin);
				break;
			default:
				abort = true;
				break; //don't think we do anything just break the menu
			}

			if (!std::cin || abort )
			{
				std::cout << "Aborted!" << std::endl;
			}
			else
			{
				if (confirm("Add this publication to the library?")) {
					if (this->m_PPA[m_NOLP])
					{
						this->m_PPA[m_NOLP]->setRef(++m_LLRN);
						this->m_changed = true;
						this->m_NOLP++;
						std::cout << "Publication added" << std::endl;
					}
					else
					{
						std::cout << "Failed to add publication!" << std::endl;
					}
					
				}
				else
				{
					std::cout << "Aborted!" << std::endl;
				}
			}
		}

	}

	void LibApp::removePublication() {
		int libRef;
		int index = 0;
		std::cout << "Removing publication from the library" << std::endl;
		if ((libRef = search(1)) != 0) { //searching all publications
			for (int i = 0; i < m_NOLP; i++)
			{
				if (m_PPA[i]->getRef() == libRef)
				{
					std::cout << *m_PPA[i] << std::endl;
					index = i;
					
				}
			}
			if (confirm("Remove this publication from the library?") == true) {

				m_changed = true;
				for (int i = 0; i < m_NOLP; i++)
				{
					m_PPA[index]->setRef(0);

				}
				std::cout << "Publication removed" << std::endl;

			}
		}
		
	}

	void LibApp::checkOutPub() {
		int libRef, index = 0;
		int memID, dividend;
		bool flag = false;
		std::cout << "Checkout publication from the library" << std::endl;
		libRef = search(2);
		if (libRef != 0) //if search is aborted it returns 0
		{
			for (int i = 0; i < m_NOLP; i++)
			{
				if (m_PPA[i]->getRef() == libRef)
				{
					index = i;

				}
			}
			std::cout << *m_PPA[index] << std::endl;
			if (confirm("Check out publication?"))
			{
				std::cout << "Enter Membership number: ";
				while (!flag) //looping until valid memID is entered
				{
					
					std::cin >> memID;
					dividend = memID / 10000;
					if (!std::cin || (dividend < 1 || dividend > 10))
					{
						std::cout << "Invalid membership number, try again: ";
					}
					else
					{
						flag = true;
					}
				}
				
				
				m_PPA[index]->set(memID);
				m_changed = true;
				std::cout << "Publication checked out" << std::endl;

			}
		}

	}

	LibApp::LibApp(const char* filename) {
		//Note that since copying menu objects is deleted, the only solution I could think of was to make LibApp a friend class of MenuItem and Menu as I wasn't sure how else to do it
		m_changed = false;
		m_mainMenu.title = new MenuItem("Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
		m_exitMenu.title = new MenuItem("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

		//MS5:
		if (filename == nullptr)
		{
			m_filename[0] = '\0';
		}
		else
		{
			strncpy(m_filename, filename, 255);
		}
		for (size_t i = 0; i < SENECA_LIBRARY_CAPACITY; i++)
		{
			m_PPA[i] = nullptr;
		}
		m_NOLP = 0;
		m_LLRN = 0;
		m_pubMenu.title = new MenuItem("Choose the type of publication:");
		m_pubMenu << "Book" << "Publication";
		load();
	}

	void LibApp::run() {
		bool exit = false;
		unsigned option;
		while (!exit)
		{
			option = m_mainMenu.run();
			switch (option)
			{
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			case 0:
				exit = true;
				break;
			}

			if (exit)
			{
				if (m_changed)
				{
					option = m_exitMenu.run();
					switch (option)
					{
					case 1:
						save();
						break;
					case 2:
						exit = false;
						break;
					case 0:
						if (!confirm("This will discard all the changes are you sure?")) //if 0 is selected
						{
							exit = false;
						}
					}

				}
				//Check if user has changed anything. Nested in while loop because there's an option to go back to the main menu
				
			}
			std::cout << std::endl; //I'm missing some newlines so this is here to fix that
		}

		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "Thanks for using Seneca Library Application" << std::endl;
		
	}

	Publication* LibApp::getPub(int libref) {
		int match = 0;
		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() == libref)
			{
				match = i;
			}
		}
		return m_PPA[match];
	}
	
	LibApp::~LibApp() {
		//std::cout << "erm...one ticket to deconstructorville please" << std::endl;
		for (int i = 0; i < m_NOLP; i++)
		{
			delete m_PPA[i];
		};
	}
}
