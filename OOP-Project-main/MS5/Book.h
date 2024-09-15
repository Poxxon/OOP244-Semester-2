// Final Project Milestone 5
// Date Module
// File	Publication.cpp
// Version 1.0
// Author	Haig McGarry
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "Publication.h"


namespace sdds {
	class Book : public Publication {
		char* m_author; //dynamically allocate char array for author name
	public:
		Book(); //set to safe-empty
		Book(const Book& src);
		Book& operator=(const Book& src);
		~Book();

		char type() const;
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& is);
		void set(int member_id);
		operator bool() const;
	};

	
}
#endif

