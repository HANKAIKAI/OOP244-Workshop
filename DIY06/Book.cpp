// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.10.
//==============================================
// Worshop#6: (DIY) Classes and resources, IO operators
// Version: 0.9
//==============================================
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h";
#include <iomanip>
using namespace std;
namespace sdds
{
	void Book::setEmpty() {
		m_title = nullptr;
		m_authName = nullptr;
	}

	bool Book::valid(const char* title, const char* authName, int bookNo, int shelfNo) const {
		return (title != nullptr && title[0] != '\0' && strlen(title) <= MaxTitleLen && authName != nullptr && authName[0] != '\0' && strlen(authName) <= MaxAuthorLen && 0 < bookNo && bookNo <= NoOfBookCases && 0 < shelfNo && shelfNo <= NoOfShelves);
	}

	void Book::allocateAndCopy(const char* title, const char* authName) {
		delete[] m_title;
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);

		delete[] m_authName;
		m_authName = new char[strlen(authName) + 1];
		strcpy(m_authName, authName);
	}

	void Book::extractChar(std::istream& istr, char ch)const {
		if (istr.peek() == ch) {
			istr.get();
		}
		else {
			istr.setstate(ios::failbit);
		}
	}

	void Book::set(const char* title, const char* authName, int bookNo, int shelfNo) {
		if (valid(title, authName, bookNo, shelfNo)) {
			allocateAndCopy(title, authName);
			m_bookNo = bookNo;
			m_shelfNo = shelfNo;
		}
		else{
			delete[] m_title;
			delete[] m_authName;
			setEmpty();
		}
	}

	//Default constructor
	Book::Book() {
		m_title = nullptr;
		m_authName = nullptr;
		m_bookNo = -1;
		m_shelfNo = -1;
	}

	Book::Book(const char* title, const char* authName, int bookNo, int shelfNo) {
		set(title, authName, bookNo, shelfNo);
	}

	//Rule of three
	Book::Book(const Book& book) {
		if (book.m_title && book.m_authName) {
			m_title = new char[strlen(book.m_title) + 1];
			strcpy(m_title, book.m_title);
			m_authName = new char[strlen(book.m_authName) + 1];
			strcpy(m_authName, book.m_authName);
			m_bookNo = book.m_bookNo;
			m_shelfNo = book.m_shelfNo;
		}
		else {
			setEmpty();
		}
	}

	Book& Book::operator=(const Book& book) {
		if (this != &book){
			delete[] m_title;
			delete[] m_authName;
			if (book.m_title && book.m_authName){
				m_title = new char[strlen(book.m_title) + 1];
				strcpy(m_title, book.m_title);
				m_authName = new char[strlen(book.m_authName) + 1];
				strcpy(m_authName, book.m_authName);
				m_bookNo = book.m_bookNo;
				m_shelfNo = book.m_shelfNo;
			}
			else{
				setEmpty();
			}
		}
		return *this;
	}

	Book::~Book() {
		delete[] m_title;
		delete[] m_authName;
		setEmpty();
	}
	
	Book::operator bool() const {
		return (m_title != nullptr && m_title[0] != '\0' && m_authName != nullptr && m_authName[0] != '\0');
	}

	ostream& Book::write(ostream& ostr, bool onScreen)const {
		if (onScreen){           
			if (*this){
				ostr.width(40);
				ostr.setf(ios::left);
				ostr << m_title;
				ostr << "|";
				ostr << " ";
				ostr.width(25);
				ostr << m_authName;
				ostr.unsetf(ios::left);
				ostr << "|";
				ostr << " ";
				ostr << m_shelfNo;
				ostr << "/";
				ostr.width(3);
				ostr.setf(ios::right);
				ostr.fill('0');
				ostr << m_bookNo;
				ostr.unsetf(ios::right);
			}
			else{
				ostr << "Invalid Book Record ................... | ........................ | .....";
			}
		}
		else{
			if (*this) {
				ostr << m_title;
				ostr << ",";
				ostr << m_authName;
				ostr << ",";
				ostr << m_shelfNo;
				ostr << "/";
				ostr << m_bookNo;
			}
			else{
				ostr << "Invalid Book Record";
			}
		}
		
		return ostr;
	}

	istream& Book::read(istream& istr) {
		char title[MaxTitleLen];
		char authName[MaxAuthorLen];
		int bookNo;
		int shelfNo;

		istr.get(title, MaxTitleLen, ',');
		extractChar(istr, ',');
		istr.get(authName, MaxAuthorLen, ',');
		extractChar(istr, ',');
		istr >> shelfNo;
		extractChar(istr, '/');
		istr >> bookNo;

		if (title[0] == '\n')
		{
			char title2[MaxTitleLen];
			int j = 0;
			for (unsigned int i = 0; i < strlen(title); i++)
			{
				if (title[i] == '\n') continue;
				else title2[j++] = title[i];
			}
			title2[j] = '\0';
			strcpy(title, title2);
		}

		if (istr) set(title, authName, bookNo, shelfNo);
		return istr;
	}

	//insertion and extraction operator overloads
	ostream& operator<<(ostream& ostr, const Book& book) {
		return book.write(ostr);;
	}

	istream& operator>>(istream& istr, Book& book) {
		return book.read(istr);
	}
}

