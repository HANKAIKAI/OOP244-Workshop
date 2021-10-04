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
#include <cstring>
#include <iomanip>
#include "Bank.h"

using namespace std;

namespace sdds
{
	void Bank::setEmpty() {
		m_name[0] = '\0';
		m_arrOfAcc = nullptr;
		m_addIndex = 0;
		m_noOfAcc = 0;
	}

	bool Bank::isEmpty() const {
		return (m_arrOfAcc == nullptr);
	}

	void Bank::header(const char* title) const {
		cout << "----------------------------------------" << endl;
		cout << ">>> " << title << " <<<" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Row Accnt No       Balance  Days Interest" << endl;
		cout << "--- ---------- ------------ ---- --------" << endl;
	}

	void Bank::footer() const {
		cout << "-----------------------------------------" << endl;
		//cout << right << setw(32) << fixed << setprecision(2) << "Total interest: " << total() << endl << endl;
		cout.width(29);
		cout.setf(ios::right);
		cout << "Total interest:";

		cout.unsetf(ios::right);
		cout.setf(ios::right);
		cout.fill(' ');
		cout.setf(ios::fixed);
		cout.precision(2);
		cout.width(12);
		cout << total();
		 
		
		cout << endl << endl;
	}

	void Bank::initialize(const char* bank_name, int noOfAccounts) {
		if (bank_name != nullptr && bank_name[0] != '\0' && noOfAccounts > 0) {
			strcpy(m_name, bank_name);
			m_noOfAcc = noOfAccounts;
			m_arrOfAcc = new Account[noOfAccounts];
			m_addIndex = 0;
		}
		else {
			setEmpty();
		}
	}

	bool Bank::addAccount(int account_number, double balance, int daysSinceLastPayment) {
		bool resp = false;
		if (m_addIndex < m_noOfAcc) {
			m_arrOfAcc[m_addIndex].set(account_number, balance, daysSinceLastPayment);
		}
		if (!m_arrOfAcc[m_addIndex].isEmpty()) {
			m_addIndex++;
			resp = true;
		}
		return resp;
	}

	double Bank::total() const {
		double total = 0;
		for (int i = 0; i < m_noOfAcc; i++) {
			if (m_arrOfAcc[i].hasInterest()) {
				total += m_arrOfAcc[i].interest();
			}
		}
		return total;
	}

	void Bank::clear() {
		delete[] m_arrOfAcc;
		m_arrOfAcc = nullptr;
	}

	void Bank::display(bool intrestOnly)const {
		int rowNum = 1;
		if (!isEmpty()) {

			if (!intrestOnly) {
				header(m_name);
				for (int i = 0; i < m_addIndex; i++) {
					/*cout.width(4);
					cout.unsetf(ios::right);
					cout.setf(ios::left);
					cout << rowNum;*/
					printf("%-4d", rowNum);
					rowNum++;
					m_arrOfAcc[i].display();
				}
				footer();

			}
			else {
				cout << "INTEREST ONLY LIST!" << endl;
				header(m_name);
				for (int i = 0; i < m_addIndex; i++) {
					if (m_arrOfAcc[i].hasInterest()) {
						/*cout.width(4);
						cout.unsetf(ios::right);
						cout.setf(ios::left);
						cout << rowNum;*/
						printf("%-4d", rowNum);
						rowNum++;
						m_arrOfAcc[i].display();
					}
				}
				footer();
			}

		}
		else {
			cout << "Invalid Bank" << endl;
		}
	}
}

