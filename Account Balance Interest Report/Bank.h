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
#ifndef SDDS_BANK_H
#define SDDS_BANK_H
#include "Account.h"
namespace sdds
{
	class Bank
	{
		Account* m_arrOfAcc;
		char m_name[50];
		int m_addIndex;
		int m_noOfAcc;
		void setEmpty();
		bool isEmpty() const;
		void header(const char* title) const;
		void footer() const;
	public:
		void initialize(const char* bank_name, int noOfAccounts);
		bool addAccount(int account_number, double balance, int daysSinceLastPayment);
		double total() const;
		void clear();
		void display(bool intrestOnly = false)const;

	};
}
#endif // !SDDS_BANK_H

