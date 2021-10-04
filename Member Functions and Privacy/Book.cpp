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
#include <iomanip>
#include "Book.h"
using namespace std;

namespace sdds{
	void Book::setEmpty() {
		m_title[0] = '\0';
		m_SKU = 0;
		m_daysOnLoan = 0;
	}

	double Book::penalty() const {
		double overDueDay = 0.0;
		overDueDay = (m_daysOnLoan - MAXLOAN) * PENALTY;
		return  overDueDay;
	}

	void Book::set(const char* title, int SKU, int daysOnLoan) {
		
		if (title != nullptr && title[0] != '\0' && SKU > 0 && daysOnLoan > 0) {
			strcpy(m_title, title);
			m_SKU = SKU;
			m_daysOnLoan = daysOnLoan;
		}
		else {
			setEmpty();
		}
	}

	bool Book::isEmpty() const {
		return (m_title[0] == '\0');
	}

	bool Book::hasPenalty() const {
		return (m_daysOnLoan > MAXLOAN);
	}

	bool Book::subTitle(const char* title) {
		return strstr(m_title, title) ? true : false;
	}

	void Book::display() const{
		if (!isEmpty()){
			/*cout.width(49);
			cout.setf(ios::left);
			cout << m_title;*/
			printf("%-49s", m_title);

			/*cout.width(8);
			cout.setf(ios::left);
			cout << m_SKU;*/
			printf("%-8d", m_SKU);

			/*cout.width(10);
			cout.setf(ios::left);
			cout << m_daysOnLoan;*/
			printf("%-10d", m_daysOnLoan);
			if (hasPenalty()){
				
				/*cout << right << setw(7) << fixed << setprecision(2) << penalty();*/
				printf("%7.2lf", penalty());
			}
			cout << endl;
			
		}else{
			cout << "Invalid library book" << endl;
		}
	}
}