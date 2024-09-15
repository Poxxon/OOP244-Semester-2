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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Book.h"

namespace sdds {
	Book::Book() : Publication::Publication() {
		m_author = nullptr;
	}

	char Book::type()const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os)const {
		Publication::write(os);
		if (Publication::conIO(os))
		{
			os << " ";
			os.setf(std::ios::left);
			//os.width(SENECA_AUTHOR_WIDTH); .width() wasn't cutting off long names so instead:
			if (strlen(m_author) > SENECA_AUTHOR_WIDTH)
			{
				for (int i = 0; i < SENECA_AUTHOR_WIDTH; i++)
				{
					os << m_author[i];
				}
			}
			else
			{
				os.width(SENECA_AUTHOR_WIDTH);
				os << m_author;
			}
			os << " |";
		}
		else
		{
			os << "\t"; 
			os << m_author;
		}

		return os;
	}

	std::istream& Book::read(std::istream& is){
		Publication::read(is);

		char author[256] = { '\0' };
		
		/*m_author = nullptr;*/

		if (Publication::conIO(is))
		{
			is.ignore();
			std::cout << "Author: ";
			is.get(author, 255, '\n');
			
			
		}
		else
		{
			is.ignore(1000,'\t');
			is.get(author, 255, '\n');
			//std::cout << "Author is: " << author << std::endl;

			
		}
		if (is)
		{
			delete[] m_author;
			m_author = nullptr;
			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
			//std::cout << "M_Author is:" << m_author << std::endl;
		}
		else
		{
		}
		return is;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool()const {

		return m_author != nullptr && Publication::operator bool(); //i dont know if this is how we call that
	}


	//RULE OF THREE
	Book::Book(const Book& src) {
		this->m_author = nullptr;

		if (this->m_author != src.m_author)
		{
			this->setRef(src.getRef());
			this->set(src.getMember());
			this->setTitle((const char*)src);
			this->setDate(src.checkoutDate());
			this->setID(src.getID());
			delete[] this->m_author;

			if (src.m_author != nullptr)
			{
				this->m_author = new char[strlen(src.m_author) + 1];
				strcpy(this->m_author, src.m_author);
			}
			else
			{
				this->m_author = nullptr;
			}

			
		}
		else
		{
			this->m_author = nullptr;
		}
	}

	Book& Book::operator=(const Book& src) {
		if (this->m_author != src.m_author)
		{

			delete[] this->m_author;

			//No static members of Book, only inherited ones from Publication
			this->setRef(src.getRef());
			this->set(src.getMember());
			this->setTitle((const char*)src);
			this->setDate(src.checkoutDate());
			this->setID(src.getID());

			if (src.m_author != nullptr)
			{
				this->m_author = new char[strlen(src.m_author) + 1];
				strcpy(this->m_author, src.m_author);
				
			}
			else
			{
				this->m_author = nullptr;
			}

			/*std::cout << "Info copied: " << this->getID() << this->getMember() << this->getRef() << this->checkoutDate() << (const char*)*this;*/
		}
		else
		{
			this->m_author = nullptr;
		}
		return *this;
	}

	Book::~Book() {
		delete[] m_author;
	}
}