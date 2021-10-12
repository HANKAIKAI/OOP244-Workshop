// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.10.
//==============================================
// Worshop#4: (DIY) Constructors, Destructors and Current object 
// Version: 0.9
//==============================================
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Chapter.h"
namespace sdds{
	class Book{
	private:
		char m_name[MAX_NAME_LEN + 1];
		int m_noOfChapter;
		Chapter* m_chapter;
	public:
		Book();
		Book(const char* name, int noOfChapter, const Chapter* chapter);
		bool isEmpty()const;
		void setEmpty();
		bool isChapterValid()const;
		Book& addChapter(const char* chapter_name, int noOfPages);
		void display()const;
		~Book();
	};
}
#endif // !SDDS_BOOK_H

