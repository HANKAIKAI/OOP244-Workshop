/* Citation and Sources...
Final Project Milestone 4
Module: Seneca Library Application
Filename: Publication.cpp
Version 1.0
Author	YuanKai Han
Revision History
-----------------------------------------------------------
Date      Reason
2021/11/30  Preliminary release
2021/11/30  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include "Publication.h"
namespace sdds
{
	class Book : public Publication
	{
		char* m_authorName{};            // hold an author's name Dynamically
	public:
		Book();

		char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool() const;

		//The rule of three
		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();
	};
}
#endif // !SDDS_BOOK_H

