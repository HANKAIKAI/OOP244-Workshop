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
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
namespace sdds
{
	const int MaxTitleLen = 40;
	const int MaxAuthorLen = 25;
	const int NoOfBookCases = 132;
	const int NoOfShelves = 7;
	class Book
	{
		char* m_title{};
		char* m_authName{};
		int m_bookNo;
		int m_shelfNo;

		void setEmpty();
		bool valid(const char* title, const char* authName, int bookNo, int shelfNo) const;
		void allocateAndCopy(const char* title, const char* authName);
		void extractChar(std::istream& istr, char ch)const;
		void set(const char* title, const char* authName, int bookNo, int shelfNo);
	public:
		//Default constructor
		Book();
		//Four argument constructor
		Book(const char* title, const char* authName, int bookNo, int shelfNo);
		//Rule of three
		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();
		operator bool() const;
		std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Book& book);
	std::istream& operator>>(std::istream& istr, Book& book);
}
#endif // ! SDDS_BOOK_H
