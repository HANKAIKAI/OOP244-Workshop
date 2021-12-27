/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	class VehicleBasic
	{
		char m_plateNumber[9];
		char m_address[21];
		int m_builtYear;
	public:
		VehicleBasic(const char* plateNumber, int builtYear);
		void NewAddress(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& vehicle);
	std::istream& operator>>(std::istream& istr, VehicleBasic& vehicle);
}

#endif