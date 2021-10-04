// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.9.
//==============================================
// Worshop#3: (LAB) Member Functions and Privacy 
//==============================================
#ifndef SDDS_LIBRARY_H
#define SDDS_LIBRARY_H
#include "Book.h"
namespace sdds{
	class Library{
	private:
		char m_name[31];
		Book* m_book;       // A Book pointer to hold a dynamic array of Book objects
		int m_sizeOfBooksArray; // An integer to hold the size of the dynamic array of books
		int m_addedBooks; // An integer to keep track of the number of books that are set to valid values in the books array.
		void setEmpty();
		bool isEmpty() const;
		void header(const char* title) const;
		void footer() const;
	public:
		void initialize(const char* name, int noOfBooks);
		bool addBook(const char* book_title, int sku, int loanDays);
		void clear();
		void display(bool overdueOnly = false) const;
		void display(const char* substr);
		
	};

}
#endif /* SDDS_LIBRARY_H */
