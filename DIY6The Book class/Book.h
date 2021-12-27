#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
namespace sdds{
	const int NoOfBookCases = 132;
	const int NoOfShelves = 7;
	const int MaxTitleLen = 40;
	const int MaxAuthorLen = 25;
	
	class Book{
		char* m_bookTitle{};
		char* m_authorName{};
		int m_bookNo;
		int m_shelfNo;
		bool valid(const char* bookTitle, const char* authorName, int bookNo, int shelfNo)const;
		void allocateAndCopy(const char* bookTitle, const char* authorName);
		void setEmpty();
		void set(const char* bookTitle, const char* authorName, int bookNo, int shelfNo);
		void extractChar(std::istream& istr, char ch)const;
	public:
		//Default constructor
		Book();
		//Four argument constructor
		Book(const char* bookTitle, const char* authorName, int bookNo, int shelfNo);
		//Rule of three
		Book(const Book& book);
	};
	
}

#endif // !SDDS_BOOK_H
