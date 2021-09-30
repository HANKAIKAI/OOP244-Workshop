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
	const double PENALTY = 1.5; // Penalty in dollars for each day a book's return is overdue
	const int MAXLOAN = 15; // Maximum number of days to loan a book witout penalty.

	class Book{
	private:
		char m_title[51];  // an array of 51 characters to hold a Cstring of a maximum of 50 characters
		int m_SKU;         // Stock Keeping Unit number
		double m_daysOnLoan;
		void setEmpty();
		double penalty() const;
	public:
		void set(const char* title, int SKU, double daysOnLoan);
		bool isEmpty() const;
		bool hasPenalty() const;
		bool subTitle(const char* title);
		void display() const;
		
	};

}
#endif /* SDDS_BOOK_H */