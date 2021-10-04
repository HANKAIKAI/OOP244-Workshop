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
#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
namespace sdds
{
	const int INFRPAYDAYS = 30;
	const double INRA = 0.285;

	class Account
	{
		int m_accNo;
		double m_BLN;
		int m_days;
		void setEmpty();
	public:
		void set(const int title, double BLN, int days);
		bool isEmpty()const;
		bool hasInterest() const;
		double interest() const;
		void display() const;
	};
}
#endif // !SDDS_ACCOUNT_H

