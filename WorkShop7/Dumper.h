/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper : public VehicleBasic
	{
		float m_maxload;   // kg, double precision
		float m_currentLoad;  // the load cannot exceed the capacity
	public:
		Dumper(const char* plateNumber, int builtYear, float maxload, const char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const Dumper& dumper);
	std::istream& operator>>(std::istream& istr, Dumper& dumper);
}
#endif
