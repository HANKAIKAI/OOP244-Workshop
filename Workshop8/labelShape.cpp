/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include "labelShape.h"
#include <cstring>
namespace sdds
{
	const char* labelShape::label() const {
		return m_label;
	}

	labelShape::labelShape() {
		m_label = nullptr;
	}

	labelShape::labelShape(const char* cstr) {
		delete[] m_label;
		m_label = new char[strlen(cstr) + 1];
		strcpy(m_label, cstr);
	}

	labelShape::~labelShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	void labelShape::readShape(std::istream& istr) {
		char temp[100];
		istr.get(temp, 100, ',');

		delete[] m_label;
		m_label = new char[strlen(temp) + 1];
		strcpy(m_label, temp);
		istr.ignore(1000, ',');

		temp[0] = '\0';
	}
}
