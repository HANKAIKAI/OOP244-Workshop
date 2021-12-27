/* Citation and Sources...
Final Project Milestone 4
Module: Seneca Library Application
Filename: Publication.cpp
Version 1.0
Author	YuanKai Han
Revision History
-----------------------------------------------------------
Date      Reason
2021/11/25  Preliminary release
2021/11/25  Debugged DMA
2021/11/30  MS4
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"
#include <cstring>
using namespace std;
namespace sdds
{
	/********** Derived class **********/
	Publication::Publication() {
		this->m_title = nullptr;           // This attribute is null by default.
		this->m_shelfId[0] = '\0';        // This attribute is an empty string by default.
		this->m_membership = 0;            // This attribute is zero by default.
		this->m_libRef = -1;           // This attribute is -1 by default.
		this->m_date.setToToday();     // The Date, by default, is set to the current date.
	}

	// Modifiers
	void Publication::set(int member_id) {
		m_membership = member_id;
	}
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	void Publication::resetDate() {
		m_date.setToToday();
	}

	// Queries
	char Publication::type()const {
		return 'P';
	}
	bool Publication::onLoan()const {
		return m_membership != 0;
	}
	Date Publication::checkoutDate()const {
		return m_date;
	}
	bool Publication::operator==(const char* title)const {
		return strstr(m_title, title) != NULL;
	}
	Publication::operator const char* ()const {
		return m_title;
	}
	int Publication::getRef()const {
		return m_libRef;
	}

	bool Publication::conIO(ios& io)const {
		return (&io == &cin || &io == &cout);
	}

	ostream& Publication::write(ostream& os) const {
		if (conIO(os) && operator bool()) {

			char _title[SDDS_TITLE_WIDTH + 1];
			if (strlen(m_title) > SDDS_TITLE_WIDTH){
				for (int i = 0; i < SDDS_TITLE_WIDTH + 1; i++)
				{
					_title[i] = m_title[i];
				}
				_title[SDDS_TITLE_WIDTH] = '\0';
			}
			os << "|";
			os << " ";
			os << m_shelfId;
			os << " ";
			os << "|";
			os << " ";

			os.width(30);
			os.setf(ios::left);
			os.fill('.');
			os << (strlen(m_title) > 30 ? _title : m_title);
			os.unsetf(ios::left);

			os << " ";
			os << "|";
			os << " ";
			if (m_membership != 0) os << m_membership;
			else os << " N/A ";
			os << " ";
			os << "|";

			os << " ";
			os << m_date;
			os << " ";
			os << "|";
		}
		else if (!conIO(os)) {
			os << type() << "\t";
			os << m_libRef << "\t";
			os << m_shelfId << "\t";
			os << m_title << "\t";
			os << m_membership << "\t";
			os << m_date;
		}
		return os;
	}

	istream& Publication::read(istream& istr) {
		int membership = 0, libRef = -1;
		char shelfId[SDDS_SHELF_ID_LEN + 1];
		char title[255];
		Date date;
		delete[] *this;

		/******** for user input ********/
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.get(shelfId, SDDS_SHELF_ID_LEN + 1);

			if (istr.peek() != '\n' && strlen(shelfId) != SDDS_SHELF_ID_LEN + 1)
				istr.setstate(ios::failbit);

			istr.ignore(255, '\n');
			cout << "Title: ";
			istr.get(title, 256, '\n');

			cout << "Date: ";
			istr >> date;
			if (date.errCode() != 0)
				istr.setstate(ios::failbit);
		}
		/******** for file loading ********/
		else {
			istr >> libRef;
			istr.ignore();
			istr.get(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.ignore();
			istr.get(title, 255, '\t');
			istr.ignore();
			istr >> membership;
			istr.ignore();
			istr >> date;
			if (istr.peek() == EOF) istr.setstate(ios::failbit);
		}
		//assigning values to the current object
		if (istr) {
			m_libRef = libRef;
			strcpy(m_shelfId, shelfId);
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			m_membership = membership;
			m_date = date;
		}
		return istr;
	}

	Publication::operator bool() const {
		//return m_title != nullptr && strcmp(m_shelfId, "") == 1;
		return (m_title && m_title[0] && m_shelfId && m_shelfId[0]);
	}

	//The Rule of three
	Publication::Publication(const Publication& publication) {
		strcpy(m_shelfId, publication.m_shelfId);
		m_membership = publication.m_membership;
		m_libRef = publication.m_libRef;
		m_date = publication.m_date;
		//allocate dynamic memory for the new resource
		if (publication.m_title != nullptr) {
			m_title = new char[strlen(publication.m_title) + 1];
			strcpy(m_title, publication.m_title);
		}
		else m_title = nullptr;
	}
	Publication& Publication::operator=(const Publication& publication) {
		if (this != &publication) {
			delete[] m_title;
			strcpy(m_shelfId, publication.m_shelfId);
			m_membership = publication.m_membership;
			m_libRef = publication.m_libRef;
			m_date = publication.m_date;
			//allocate dynamic memory for the new resource
			if (publication.m_title != nullptr) {
				m_title = new char[strlen(publication.m_title) + 1];
				strcpy(m_title, publication.m_title);
			}
			else m_title = nullptr;
		}
		return *this;
	}
	Publication::~Publication() {
		delete[] m_title;
		m_title = nullptr;
	}
}

