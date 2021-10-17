// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.10.15
//==============================================
// Worshop#5: (DIY) Member and Helper operators
// Version: 0.9
//==============================================
#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>
namespace sdds{
	const double PRICE_OF_BUSTICKET = 125.34;

	class Bus{
		int m_noOfSeat;
		int m_noOfPassenger;  // In bus
		void setOutOfService();
		void drawBus(std::ostream& ostr, int seats, int psng) const;
	public:
		Bus(int noOfSeat = 20, int noOfPassenger = 0);
		bool isOutOfService() const;
		int getNoOfPassenger()const;
		std::ostream& display(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);

		// ****************** Type Conversion Operator ******************
		operator bool() const;
		operator int() const;
		operator double() const;

		// Have problem
		// ****************** Unary Operator overloads ******************
		bool operator--();
		bool operator++();
		bool operator--(int);
		bool operator++(int);
		
		// ****************** Binary member operators *******************
		Bus& operator=(int value);
		Bus& operator+=(int value);
		Bus& operator+=(Bus& right);
		bool operator==(const Bus& right) const;
		
	};
	// ****************** Helper Binary Operator  *******************
	int operator+(int left, const Bus& right);
	std::ostream& operator<<(std::ostream& ostr, const Bus& right);
	std::istream& operator>>(std::istream& istr, Bus& right);
}
#endif