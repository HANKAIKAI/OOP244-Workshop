// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.10.14
//==============================================
// Worshop#5: (LAB) Member and Helper operators
// Version: 0.9
//==============================================
#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>

namespace sdds{
	const int RegularEggWieght = 50;
	const int JumboEggWieght = 75;
	
	class EggCarton{
		int m_size;
		int m_noOfEggs;
		bool m_jumbo;
		void setBroken();
	public:
		bool isBroken() const;
		int getNoOfEgg()const;
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
		std::ostream& display(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);

		// ****************** Type Conversion Operator ******************
		operator bool() const;
		operator int() const;
		operator double() const;

		// ****************** Unary Operator overloads ******************
		EggCarton& operator--() ;
		EggCarton& operator++() ;
		EggCarton operator--(int) ;
		EggCarton operator++(int) ;

		// ****************** Binary member operators *******************
		EggCarton& operator=(int value);
		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);
		bool operator==(const EggCarton& right) const;
	};
	// ****************** Helper Binary Operator  *******************
	int operator+(int left, const EggCarton& right);
	std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
	std::istream& operator>>(std::istream& istr, EggCarton& right);
}
#endif