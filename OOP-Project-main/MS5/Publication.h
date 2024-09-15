// Final Project Milestone 3
// Date Module
// File	Publication.h
// Version 1.0
// Author	Haig McGarry
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
//I have done all the coding by myself and only copied the code 
//that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include <iostream>
#include <cstring>
#include <string>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

namespace sdds{

	class Publication : public Streamable {
		char* m_title;
		char m_shelfid[SENECA_SHELF_ID_LEN + 1];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		Publication(); //sets datamembers to default values
		//modifiers
		virtual void set(int member_id); //sets member id
		void setRef(int value); //sets libref member
		void resetDate(); //sets the date to current system date
		//queries
		virtual char type()const; //returns 'P' to identify object as Publication 
		bool onLoan()const; //returns true if publication is checkout (membership != 0)
		Date checkoutDate()const; //returns date member
		bool operator==(const char* title)const; //returns true if parameter string is found in publication title (so not a complete match but as long as title is in m_title return true). Use strstr() in <cstring>
		operator const char* () const; //return m_title
		int getRef() const; //return m_libRef
		//NEW TO MS4
		int getMember() const; //Introducing this member to return m_membership
		const char* getID()const;
		void setTitle(const char* title);
		void setDate(const Date& date);
		void setID(const char* id);
		//
		//Streamable pure virtual implementations
		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		operator bool() const;

		//Rule of Three
		Publication(const Publication& src);
		Publication& operator=(const Publication& src);
		~Publication();

	};

	
}
#endif