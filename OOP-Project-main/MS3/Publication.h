#pragma once
/* Citation and Sources...
Final Project Milestone 3
Module: Publication
Filename: Publication.h
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
#ifndef SENECA_PUBLICATION_H__
#define SENECA_PUBLICATION_H__

#include "Date.h"
#include "Lib.h"
#include "Utils.h"

namespace seneca {

	class Publication : public Streamable {

	
		char* m_title;
		char* m_shelfId;
		int m_membership;
		int m_libRef;
		Date m_date;

		void reset();

		bool isValidShelfID(const char* m_shelfId);

	public:
		Publication();

		~Publication();

		virtual void set(int member_id);

		void setRef(int value);

		void setTitle(const char* title);

		void setShelfId(const char* sheldIf);

		void resetDate();

		virtual char type() const;

		bool onLoan() const;

		Date checkoutDate() const;
		bool operator==(const char* title) const;

		operator const char* () const;

		int getRef() const;

		std::ostream& write(std::ostream& os = std::cout) const override;

		std::istream& read(std::istream& is = std::cin) override;

		bool conIO(std::ios& io) const override;

		operator bool() const override;

		Publication& operator=(const Publication&);

		Publication(const Publication&);
	};

}; 
#endif
