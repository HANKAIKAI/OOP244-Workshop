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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;

namespace sdds{
	Book::Book(){
		this->m_name[0] = '\0';
		this->m_noOfChapter = -1;
		this->m_chapter = nullptr;
	}

	Book::Book(const char* name, int noOfChapter, const Chapter* chapter){
		if (name != nullptr && name[0] != '\0' && noOfChapter > 0 && chapter != nullptr) {
			strcpy(this->m_name, name);
			this->m_noOfChapter = noOfChapter;

			this->m_chapter = new Chapter[this->m_noOfChapter];
			for (int i = 0; i < this->m_noOfChapter; i++) {
				this->m_chapter[i].setChapterName(chapter[i].getChapterName());
				this->m_chapter[i].setNoOfPage(chapter[i].getNoOfPage());
			}
		}
		else {
			setEmpty();
		}
	}

	void Book::setEmpty(){
		this->m_name[0] = '\0';
		this->m_noOfChapter = -1;
		this->m_chapter = nullptr;
	}

	bool Book::isEmpty()const{
		return (this->m_name[0] == '\0' || this->m_noOfChapter == -1 || this->m_chapter == nullptr);
	}

	bool Book::isChapterValid()const{
		bool isValid = true;
		bool flag = true;
		for (int i = 0; i < this->m_noOfChapter && flag; i++) {
			if (this->m_chapter[i].isEmpty()) {
				isValid = false;
				flag = false;
			}
		}
		return isValid;
	}

	Book& Book::addChapter(const char* chapter_name, int noOfPages){
		if (chapter_name != nullptr && chapter_name[0] != '\0' && strlen(chapter_name) <= MAX_NAME_LEN && noOfPages > 0 && noOfPages <= MAX_PAGE_LEN) {
			Chapter* temp = new Chapter[this->m_noOfChapter + 1];
			for (int i = 0; i < this->m_noOfChapter; i++) {
				temp[i] = this->m_chapter[i];
				/*temp[i].setChapterName(this->m_chapter[i].getChapterName());
				temp[i].setNoOfPage(this->m_chapter[i].getNoOfPage());*/
			}

			temp[this->m_noOfChapter].setChapterName(chapter_name);
			temp[this->m_noOfChapter].setNoOfPage(noOfPages);
			delete[] this->m_chapter;
			this->m_chapter = temp;
			this->m_noOfChapter++;
		}
		
		return *this;
	}

	void Book::display()const{
		if (!isEmpty() && isChapterValid()) {
			cout << "Book Name: " << this->m_name << endl;
			cout << "No of Chapters: " << this->m_noOfChapter << endl;
			cout << "Chapter name                                       Pages" << endl;
			for (int i = 0; i < this->m_noOfChapter; i++) {
				this->m_chapter[i].display();
			}
		}
		else {
			cout << "Invalid Book object" << endl;
		}
	}

	Book::~Book() {
		delete[] m_chapter;
	}
}