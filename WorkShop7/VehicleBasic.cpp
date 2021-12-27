/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"
using namespace std;
namespace sdds
{
	VehicleBasic::VehicleBasic(const char* plateNumber, int builtYear) {
		if (plateNumber != nullptr && builtYear != 0)
		{
			strcpy(m_plateNumber, plateNumber);
			m_builtYear = builtYear;
			strcpy(m_address, "Factory");
		}
		else {
			cout << "INVALID DATA" << endl;
		}
	}

	void VehicleBasic::NewAddress(const char* address) {
		if (m_address != address && m_address[0] != '\0' && m_address != nullptr) {
			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << m_plateNumber << "| |";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_address << " ---> ";
			strcpy(m_address, address);
			cout.width(20);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << m_address << "|" << endl;
		}
	}

	ostream& VehicleBasic::write(ostream& os) const {
		os << "| " << m_builtYear << " | " << m_plateNumber << " | " << m_address;
		return os;
	}

	istream& VehicleBasic::read(istream& in) {
		char tempPlateNumber[9];
		char tempAddress[21];
		cout << "Built year: ";
		in >> m_builtYear;
		cout << "License plate: ";
		in >> tempPlateNumber;
		cout << "Current location: ";
		in >> tempAddress;
		strcpy(m_plateNumber, tempPlateNumber);
		strcpy(m_address, tempAddress);
		return in;
	}

	ostream& operator<<(ostream& ostr, const VehicleBasic& vehicle) {
		vehicle.write(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, VehicleBasic& vehicle) {
		return vehicle.read(istr);
	}
}
