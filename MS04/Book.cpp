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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds
{
	Book::Book(){
		this->m_authorName = nullptr;
	}

	char Book::type()const {
		return 'B';
	}

	ostream& Book::write(ostream& os) const {
		Publication::write(os);
		if (conIO(os) && operator bool()){
			char _authorName[SDDS_AUTHOR_WIDTH + 1];
			os << " ";
			if (strlen(m_authorName) > SDDS_AUTHOR_WIDTH){
				for (int i = 0; i < SDDS_AUTHOR_WIDTH + 1; i++){
					_authorName[i] = m_authorName[i];
				}
				_authorName[SDDS_AUTHOR_WIDTH] = '\0';
			}
			else{
				strcpy(_authorName, m_authorName);
			}
			os.width(SDDS_AUTHOR_WIDTH);
			os.fill(' ');
			os.setf(ios::left);
			os << _authorName;
			os.unsetf(ios::left);
			os << " |";
		}
		else if (!conIO(os)){
			os << '\t';
			os << m_authorName;
		}
		return os;
	}
	istream& Book::read(istream& istr) {
		char _authorName[255]{};
		Publication::read(istr);
		delete[] m_authorName;
		if (conIO(istr)){
			istr.ignore();
			cout << "Author: ";
			istr.get(_authorName, 255);
		}
		else {
			istr.ignore();
			istr.get(_authorName, 255);
		}
		if (!istr.fail()){
			m_authorName = new char[strlen(_authorName) + 1];
			strcpy(m_authorName, _authorName);
		}
		return istr;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool() const {
		return (m_authorName && m_authorName[0] && Publication::operator bool());
	}

	//The rule of three
	Book::Book(const Book& book): Publication(book) {
		//delete[] m_authorName;
		if (book.m_authorName != nullptr) {
			this->m_authorName = new char[strlen(book.m_authorName) + 1];
			strcpy(this->m_authorName, book.m_authorName);
		}
		else m_authorName = nullptr;
	}
	Book& Book::operator=(const Book& book) {
		if (this != &book && book.m_authorName != nullptr){
			Publication::operator=(book);
			delete[] m_authorName;
			this->m_authorName = new char[strlen(book.m_authorName) + 1];
			strcpy(this->m_authorName, book.m_authorName);
			//else m_authorName = nullptr; //***if added, memory leak***
		}
		return *this;
	}
	Book::~Book() {
		delete[] m_authorName;
		m_authorName = nullptr;
	}
}

