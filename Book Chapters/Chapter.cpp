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
#include "Chapter.h"
using namespace std;
namespace sdds{
	Chapter::Chapter(){
		this->m_name[0] = '\0';
		this->m_noOfPage = -1;
	}

	Chapter::Chapter(const char* name, int noOfPage){
		if (name != nullptr && name[0] != '\0' && strlen(name) <= MAX_NAME_LEN && noOfPage > 0 && noOfPage <= MAX_PAGE_LEN) {
			strcpy(this->m_name, name);
			this->m_noOfPage = noOfPage;
		}
		else {
			setEmpty();
		}
	}

	void Chapter::setEmpty(){
		this->m_name[0] = '\0';
		this->m_noOfPage = -1;
	}

	bool Chapter::isEmpty() const{
		return (this->m_name[0] == '\0' || this->m_noOfPage == -1);
	}

	void Chapter::setChapterName(const char* name){
		strcpy(this->m_name, name);
	}

	void Chapter::setNoOfPage(int noOfPage){
		this->m_noOfPage = noOfPage;
	}

	const char* Chapter::getChapterName()const{
		return this->m_name;
	}

	int Chapter::getNoOfPage() const{
		return this->m_noOfPage;
	}

	void Chapter::display() const{
		if (!isEmpty()) {
			cout.width(50);
			cout.fill('.');
			cout.setf(ios::left);
			cout << this->m_name;
			cout.unsetf(ios::left);
			cout << " ";
			cout.width(3);
			cout.fill(' ');
			cout.setf(ios::right);
			cout << this->m_noOfPage;
			cout.unsetf(ios::right);
			cout << endl;
		}
		else {
			cout << "invalid Chapter" << endl;
		}
	}
}