// Final Project Milestone 3
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Publication.h"
#include "Streamable.h"

namespace sdds {


	//--Publication--

	Publication::Publication() {
		m_title = nullptr;
		m_shelfid[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		//m_date; //should by default make current date as no-arg date constructor does this
	}

	void Publication::set(int member_id) {
		int dividend = member_id / 10000;
		if (dividend >= 1 && dividend < 10) //checking if param is 5 digits
		{
			m_membership = member_id;
		}
		else
		{
			m_membership = 0;
		}
	}

	void Publication::setRef(int value) {
		m_libRef = value;
	}

	void Publication::resetDate() {
		Date curDate;
		if (m_date != curDate)
		{
			m_date = curDate;
		}
	}

	char Publication::type() const {
		return 'P';
	}

	bool Publication::onLoan() const {
		return m_membership != 0;
	}

	Date Publication::checkoutDate()const {
		return m_date;
	}

	bool Publication::operator ==(const char* title)const {
		bool flag = false;
		if (strstr(m_title, title) != nullptr)
		{
			flag = true;
		}

		return flag;
	}

	Publication::operator const char* () const {
		return m_title;
	}

	int Publication::getRef()const {
		return m_libRef;
	}

	bool Publication::conIO(std::ios& io)const {
		bool flag = false;
		if (&io == &std::cout || &io == &std::cin)
		{
			flag = true;
		}

		return flag;
	}

	std::ostream& Publication::write(std::ostream& os)const {
		if (conIO(os))
		{
			os << "| " << m_shelfid << " | ";
			
			os.fill('.');
			os.setf(std::ios::left);
			//os << std::setw(SENECA_TITLE_WIDTH) << m_title; This wasn't cutting off titles longer than the width so to fix this I do the following:
			if (strlen(m_title) > SENECA_TITLE_WIDTH)
			{
				for (int i = 0; i < SENECA_TITLE_WIDTH; i++)
				{
					os << m_title[i];
				}
			}
			else
			{
				os.width(SENECA_TITLE_WIDTH);
				os << m_title;
			}
			os.unsetf(std::ios::left);
			os.fill(' ');
			os << " | ";
			if (m_membership == 0)
			{
				os << " N/A ";
			}
			else
			{
				os << m_membership;
			}
			 os << " | " << m_date << " |";
			//no newline
		}
		else
		{
			os << type() << "\t" << m_libRef << "\t" << m_shelfid << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
		}

		return os;
	}

	std::istream& Publication::read(std::istream& is) {
		delete[] m_title; //maybe comment-out
		m_title = nullptr;
		m_shelfid[0] = '\0';
		m_membership = 0;
		m_libRef = -1;

		char title[255] = { '\0' };
		std::string shelfid;
		int membership = 0;
		int libRef = -1;
		Date tempDate;

		if (conIO(is))
		{
			std::cout << "Shelf No: ";
			is >> shelfid;
			if (shelfid.length() != SENECA_SHELF_ID_LEN)
			{
				//is.clear();
				is.setstate(std::ios::failbit); //manually setting is to fail-state
			}
			is.ignore(1000, '\n');
			std::cout << "Title: ";
			is.get(title, 255, '\n');
			is.ignore(1000, '\n');
			std::cout << "Date: ";
			is >> tempDate;
			//is.ignore(1000, '\n');
		}
		else
		{
			is.ignore(1000, '\t');
			is >> libRef;
			if (is)
			{
				is.ignore(1000, '\t'); //ignore the tab
				is >> shelfid;
				if (shelfid.length() != 4)
				{
					is.setstate(std::ios::failbit); //manually setting is to fail-state
				}
				if (is)
				{
					is.ignore(1000, '\t');
					is.get(title, 255, '\t');
					is.ignore(1000, '\t');
					is >> membership;
					is.ignore(1000, '\t');
					is >> tempDate;
				}
			}
		}

		//Check validity of date
		if (!tempDate)
		{
			is.clear();
			is.setstate(std::ios::failbit);
		}

		if (is)
		{
			if (title != NULL) //I get a warning if I don't include the conditional
			{
				m_title = new char[strlen(title) + 1];
				strcpy(m_title, title);
			}
			

			strcpy(m_shelfid, shelfid.c_str());
			
			m_membership = membership;
			
			m_date = tempDate;

			m_libRef = libRef;
		}

		return is;
	}

	Publication::operator bool()const {
		return (m_title != nullptr && m_shelfid[0] != '\0');
	}

	//Rule of Three
	Publication::Publication(const Publication& src) {
		if (src)
		{
			//dynamically allocate title then statically copy the rest of the attributes
			delete[] m_title;
			m_title = new char[strlen(src.m_title) + 1];
			strcpy(m_title, src.m_title);
			
			strcpy(m_shelfid, src.m_shelfid);
			m_membership = src.m_membership;
			m_libRef = src.m_libRef;
			m_date = src.m_date;
		}
	}

	Publication& Publication::operator=(const Publication& src) {
		if (src)
		{
			//dynamically allocate title then statically copy the rest of the attributes
			delete[] m_title;
			m_title = new char[strlen(src.m_title) + 1];
			strcpy(m_title, src.m_title);

			strcpy(m_shelfid, src.m_shelfid);
			m_membership = src.m_membership;
			m_libRef = src.m_libRef;
			m_date = src.m_date;
		}
		return *this;
	}

	Publication::~Publication() {
		delete[] m_title;
	}

	//---------------
	//--NEW TO MS4--
	int Publication::getMember() const {
		return m_membership;
	}
	const char* Publication::getID() const {
		return m_shelfid;
	}
	void Publication::setTitle(const char* title) {
		if (title != nullptr)
		{
			delete[] m_title;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}

	void Publication::setDate(const Date& date) {
		m_date = Date(date);
	}
	void Publication::setID(const char* id) {
		if (id != nullptr && strlen(id) == SENECA_SHELF_ID_LEN)
		{
			//delete[] m_shelfid;
			strcpy(m_shelfid, id);
		}
	}
}