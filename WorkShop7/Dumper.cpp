/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"
using namespace std;
namespace sdds
{
	Dumper::Dumper(const char* plateNumber, int builtYear, float maxload, const char* address) : VehicleBasic(plateNumber, builtYear) {
		m_maxload = maxload;
		m_currentLoad = 0.0;
		NewAddress(address);
	}

	bool Dumper::loaddCargo(double cargo) {
		bool loadd = false;
		if (cargo + m_currentLoad <= m_maxload)
		{
			m_currentLoad += cargo;
			loadd = true;
		}
		else {
			loadd = false;
		}
		return loadd;
	}

	bool Dumper::unloadCargo() {
		bool changed = false;
		if (m_currentLoad != 0)
		{
			if (m_currentLoad != 0)
			{
				m_currentLoad = 0;
				changed = true;
			}
		}
		return changed;
	}

	ostream& Dumper::write(ostream& os) const {
		VehicleBasic::write(os) << " | " << m_currentLoad << "/" << m_maxload;
		return os;
	}

	istream& Dumper::read(istream& in) {
		VehicleBasic::read(in);
		cout << "Capacity: ";
		in >> m_maxload;
		cout << "Cargo: ";
		in >> m_currentLoad;
		return in;
	}

	ostream& operator<<(ostream& ostr, const Dumper& dumper) {
		return dumper.write(ostr);
	}

	istream& operator>>(istream& istr, Dumper& dumper) {
		return dumper.read(istr);
	}
}
