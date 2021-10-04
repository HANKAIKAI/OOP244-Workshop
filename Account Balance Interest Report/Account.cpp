// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.9.
//==============================================
// Worshop#3: (DIY) Member Functions and Privacy 
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Account.h"
using namespace std;

namespace sdds
{
	void Account::setEmpty() {
		m_accNo = 0;
		m_BLN = 0.0;
		m_days = 0;
	}

	double Account::interest() const {
		double m_inter;
		m_inter = (m_days * (INRA / 365) * m_BLN);
		return m_inter;
	}

	void Account::set(const int accNo, double balance, int days) {
		m_accNo = accNo;
		m_BLN = balance;
		m_days = days;
	}

	bool Account::isEmpty()const {
		return (m_accNo == 0 || m_BLN == 0.0);
	}

	bool Account::hasInterest() const {
		return (m_days > INFRPAYDAYS);
	}

	void Account::display() const {
		if (!isEmpty()) {
			printf("%9d", m_accNo);
			printf("%14.2lf", m_BLN);
			printf(" ");
			printf(" ");
			printf("%-4d", m_days);

			/*cout.unsetf(ios::left);
			cout << " ";
			cout << m_accNo;
			cout << " ";

			cout.width(13);
			cout.setf(ios::right);
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << m_BLN;

			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << "  ";
			cout.width(3);
			cout.fill(' ');
			cout << m_days;*/

			if (hasInterest()) {
				printf("%8.2lf", interest());
				/*cout.width(9);
				cout.setf(ios::right);
				cout.fill(' ');
				cout << interest();*/
			}
			cout << endl;

		}
		else {
			cout << "Invalid Bank" << endl;
		}
	}
}