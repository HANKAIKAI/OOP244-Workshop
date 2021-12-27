/* Citation and Sources...
Final Project Milestone 5
Module: Seneca Library Application
Filename: Publication.cpp
Version 1.0
Author	YuanKai Han
Revision History
-----------------------------------------------------------
Date      Reason
2021/11/25  Preliminary release
2021/11/25  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include <iostream>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"
namespace sdds
{
	class Publication : public Streamable
	{
		char* m_title{};
		char m_shelfId[SDDS_SHELF_ID_LEN + 1] = { 0 };
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		Publication();

		//The Rule of three
		Publication(const Publication& publication);
		Publication& operator=(const Publication& publication);
		~Publication();

		// Modifiers
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();

		// Queries
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;

		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;
	};
}
#endif // !SDDS_PUBLICATION_H




