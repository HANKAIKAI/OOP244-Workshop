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
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
namespace sdds{
	const double PENALTY = 1.5; 
	const int MAXLOAN = 15; 

	class Book{
	private:
		char m_title[51];  
		int m_SKU;         
		int m_daysOnLoan;
		void setEmpty();
		double penalty() const;
	public:
		void set(const char* title, int SKU, int daysOnLoan);
		bool isEmpty() const;
		bool hasPenalty() const;
		bool subTitle(const char* title);
		void display() const;
		
	};

}
#endif /* SDDS_BOOK_H */