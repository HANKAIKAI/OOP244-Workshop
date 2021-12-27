// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.11.24
//==============================================
// Worshop#9: (LAB) Derived Classes and Resources
// Version: 0.9
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"

namespace sdds
{
	Contact::Contact() :Person(){};
	Contact::Contact(const Contact& copyFrom) : Person(copyFrom){
		operator=(copyFrom);
	}
	Contact& Contact::operator=(const Contact& RightOperand) {
		if (this != &RightOperand) {
			Person::operator=(RightOperand);
			delAlloCopy(m_address, RightOperand.m_address);
			delAlloCopy(m_city, RightOperand.m_city);
			strCpy(m_province, RightOperand.m_province);
			strCpy(m_postalCode, RightOperand.m_postalCode);
		}
		return *this;
	}
	Contact::~Contact() {
		~*this;
	}
	std::istream& Contact::read(std::istream& istr) {
		~*this;
		Person::read(istr);
		m_address = dynRead(istr, ',');
		m_city = dynRead(istr, ',');
		istr.getline(m_province, PROVINCE_LENGTH + 1, ',');
		istr.getline(m_postalCode, POSTALCODE_LENGTH + 1);
		if (istr.fail()) ~*this;
		return istr;
	}
	std::ostream& Contact::write(std::ostream& ostr)const {
		Person::write(ostr);
		if (*this) {
			ostr << std::endl;
			ostr << m_address << std::endl;
			ostr << m_city << " " << m_province << std::endl;
			for (int i = 0; i < POSTALCODE_LENGTH; i++) {
				ostr << m_postalCode[i];
				if (i == 2) ostr << " ";
			}
			ostr << std::endl;
		}
		return ostr;
	}
	Contact::operator bool()const {
		return m_address && m_address[0] && m_city && m_city[0];
	}
	void Contact::operator~() {
		Person::operator~();
		delete[] m_address;
		delete[] m_city;
		m_address = m_city = nullptr;
	}
}