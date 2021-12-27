// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.10.21
//==============================================
// Worshop#6: (LAB) Classes and resources, IO operators
// Version: 0.9
//==============================================
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
namespace sdds
{
	// ****************** Private Methods ******************
	bool Contact::validPhone(int areaCode, int exchangeCode, int number)const {
		return (100 <= areaCode && areaCode <= 999 && 100 <= exchangeCode && exchangeCode <= 999 && 0 <= number && number <= 9999);
	}

	void Contact::setEmpty() {
		m_name = nullptr;
	}

	void Contact::allocateAndCopy(const char* name) {
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	// extracting and throwing away a specific character.
	void Contact::extractChar(std::istream& istr, char ch)const {
		if (istr.peek() == ch){
			istr.get();
		}
		else {
			istr.setstate(ios::failbit);
		}
	}

	ostream& Contact::printPhoneNumber(ostream& istr)const {
		istr << "(" << m_area << ")";
		istr << " ";
		istr << m_exchangeCode << "-";
		istr.width(4);
		istr.setf(ios::right);
		istr.fill('0');
		istr << m_number;
		istr.unsetf(ios::right);
		return istr;
	}

	void Contact::set(const char* name, int areaCode, int exchangeCode, int number) {
		if (name != nullptr && name[0] != '\0' && validPhone(areaCode, exchangeCode, number)){
			allocateAndCopy(name);
			m_area = areaCode;
			m_exchangeCode = exchangeCode;
			m_number = number;
		}
		else{
			delete[] m_name;
			setEmpty();
		}
	}

	// ****************** Constructor ******************
	Contact::Contact() {
		m_name = nullptr;
		m_area = -1;
		m_exchangeCode = -1;
		m_number = -1;
	}

	Contact::Contact(const char* name, int areaCode, int exchangeCode, int number) {
		set(name, areaCode, exchangeCode, number);
	}

	// ****************** Copy Constructor ******************
	Contact::Contact(const Contact& cnt) {
		
		if (cnt.m_name){
			m_area = cnt.m_area;
			m_exchangeCode = cnt.m_exchangeCode;
			m_number = cnt.m_number;
			
			m_name = new char[strlen(cnt.m_name) + 1];
			strcpy(m_name, cnt.m_name);
		}
		else{
			m_name = nullptr;
		}
	}

	// ****************** Copy Assignment operator overload ******************
	Contact& Contact::operator=(const Contact& cnt) {
		
		if (this != &cnt){  //make sure that this is not a "self copy"
			delete[] m_name;
			if (cnt.m_name) {
				m_area = cnt.m_area;
				m_exchangeCode = cnt.m_exchangeCode;
				m_number = cnt.m_number;

				m_name = new char[strlen(cnt.m_name) + 1];
				strcpy(m_name, cnt.m_name);
			}
			else {
				m_name = nullptr;
			}
		}
		
		return *this;
	}

	// ****************** Boolean type conversion operator ******************
	Contact::operator bool() const {
		return (m_name != nullptr && m_name[0] != '\0');
	}

	ostream& Contact::print(ostream& ostr, bool toFile = true) const {
		if (this){   //the current object is in a valid state
			if (toFile) {
				ostr << m_name;
				ostr << ",";
				printPhoneNumber(ostr);
			}
			else{
				ostr.width(50);
				ostr.setf(ios::left);
				ostr.fill('.');
				ostr << m_name;
				printPhoneNumber(ostr);
				ostr.unsetf(ios::left);
			}
		}
		return ostr;
	}

	istream& Contact::read(istream& istr) {
		int area;
		int exchangeCode;
		int number;
		char name[MaxNameLength];

		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		extractChar(istr, '(');
		istr >> area;
		extractChar(istr, ')');
		extractChar(istr, ' ');
		istr >> exchangeCode;
		extractChar(istr, '-');
		istr >> number;
		extractChar(istr, '\n');
		if (istr) {
			set(name, area, exchangeCode, number);
		}
		return istr;
	}

	// ****************** Destructor ******************
	Contact::~Contact() {
		delete[] m_name;
	}

	ostream& operator<<(ostream& ostr, const Contact& cnt) {
		if (cnt){
			cnt.print(ostr, false);
		}
		else{
			ostr << "Invalid Phone Record";
		}
		return ostr;
	}

	istream& operator>>(istream& istr, Contact& cnt) {
		return cnt.read(istr);
	}
}

