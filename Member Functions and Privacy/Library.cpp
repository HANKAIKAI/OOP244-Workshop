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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Library.h"

using namespace std;

namespace sdds{
	void Library::setEmpty() {
		m_name[0] = '\0';
		m_book = nullptr;
		m_sizeOfBooksArray = 0;
		m_addedBooks = 0;
	}

	bool Library::isEmpty() const {
		return (m_book == nullptr || m_name[0] == 0) ;
	}

	void Library::header(const char* title) const {
		for (int i = 0; i <= 78; i++){
			cout << '-';
		}
		cout << endl;
		cout << "***** " << m_name << " *****" << endl;
		cout << *title << endl;
		for (int i = 0; i <= 78; i++) {
			cout << '-';
		}
		cout << endl;
		cout << "Row Book title                                       SKU     loan days penalty" << endl;
		cout << "--- ------------------------------------------------ ------- --------- -------" << endl;
	}

	void Library::footer() const {
		for (int i = 0; i <= 78; i++) {
			cout << '-';
		}
		cout << endl;
	}

	void Library::initialize(const char* name, int noOfBooks) {
		if (name != nullptr && noOfBooks > 0) {
			strcpy(m_name, name);
			m_sizeOfBooksArray = noOfBooks;
			
			// allocate a dynamic array of Books to the noOfBooks. 
			m_book = new Book[noOfBooks];
			// if the allocation fails it will set the Library into a safe empty state
			for (int i = 0; i < noOfBooks; i++){
				m_book[i].setEmpty();
				setEmpty();
			}
			m_addedBooks = 0;

		}else{
			setEmpty();
		}
	}

	bool Library::addBook(const char* book_title, int sku, int loanDays) {
		bool resp = false;
		if (m_addedBooks <= m_sizeOfBooksArray){
			m_book->set(book_title, sku, loanDays);
		}
		if (!m_book->isEmpty()){
			m_addedBooks++;
			resp = true;
		}
		return resp;
	}
	
	void Library::clear() {
		delete[] m_book;
		m_book = nullptr;
	}

	void Library::display(const char* substr) {
		int rowNum = 1;
		
		// if the Library is not in a safe empty state
		if (!isEmpty()){     
			cout << ">>> Searching for: \"";
			cout << substr;
			cout << "\" <<<" << endl;
			header("Substring search");
			int flag = 0;
			for (int i = 0; i < m_addedBooks && flag == 0; i++){
				if (m_book[i].subTitle(substr)){
					cout.width(4);
					cout.setf(ios::left);
					cout << rowNum;
					rowNum++;
					m_book[i].display();
					flag = 1;
				}
			}
			if (flag){
				cout << "No book title contains \"" << substr << "\"" << endl;
				footer();
			}
		}else{
			cout << "Invalid Library" << endl;
		}
	}

	void Library::display(bool overdueOnly) const {
		int rowNum = 1;
		if (!isEmpty()){
			if (overdueOnly){
				header("Overdue Books");
				for (int i = 0; i < m_addedBooks; i++){
					cout.width(4);
					cout.setf(ios::left);
					cout << rowNum;
					rowNum++;
					m_book[i].display();
				}
			}else{
				header("Books on Loan");
			}
			
		}else{
			cout << "Invalid Library" << endl;
		}
	}
}