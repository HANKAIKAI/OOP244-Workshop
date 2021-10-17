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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "EggCarton.h"
using namespace std;

namespace sdds{
	void EggCarton::setBroken() {
		this->m_size = -1;
		this->m_noOfEggs = -1;
	}

	bool EggCarton::isBroken() const {
		return (m_size % 6 == 0 && m_size >= 6 && m_size <= 36 && m_noOfEggs >= 0 && m_noOfEggs <= m_size);
	}

	int EggCarton::getNoOfEgg()const {
		return this->m_noOfEggs;
	}

	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {
		if (!(size % 6 == 0 && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size)){
			setBroken();
		}else{
			this->m_size = size;
			this->m_noOfEggs = noOfEggs;
			this->m_jumbo = jumboSize;
		}
	}

	ostream& EggCarton::display(std::ostream& ostr) const {
		if (bool(*this)){
			// displays an Egg Carton
			int cartonWidth = m_size == 6 ? 3 : 6;
			for (int i = 0; i < m_size; i++) {
				cout << ((i < m_noOfEggs) ? (m_jumbo ? 'O' : 'o') : '~');
				if ((i + 1) % cartonWidth == 0) cout << endl;
			}
		}else{
			cout << "Broken Egg Carton!" << endl;
		}
		return ostr;
	}
	
	// Question1 
	istream& EggCarton::read(std::istream& istr) {
		m_jumbo = false;
		char ch = ' ';
		istr >> ch;
		/*ch == 'j' ? m_jumbo = true : m_jumbo = false;
		istr.ignore();
		istr >> m_size;
		istr.ignore();
		istr >> m_noOfEggs;
		if (bool(*this)){
			setBroken();
		}*/
		ch == 'j' ? m_jumbo = true : m_jumbo = false;
		istr.ignore();
		istr >> this->m_size;
		istr.ignore();
		istr >> this->m_noOfEggs;
		if (!(m_size % 6 == 0 && m_size >= 6 && m_size <= 36 && m_noOfEggs >= 0 && m_noOfEggs <= m_size)) {
			setBroken();
		}
		
		return istr;
	}

	// ****************** Type Conversion Operator ******************
	EggCarton::operator bool() const {
		return (isBroken() && m_size > 0);
	}

	EggCarton::operator int() const {
		if (bool(*this)){
			return m_noOfEggs;
		}
		else {
			return -1;
		}
	}

	EggCarton::operator double() const {
		if (bool(*this)) {
			if (m_jumbo){
				return (m_noOfEggs * JumboEggWieght) / 1000.0;
			}else{
				return (m_noOfEggs * RegularEggWieght) / 1000.0;
			}
		}
		else {
			return -1.0;
		}
		//return bool(this) && m_jumbo ? (m_noOfEggs * JumboEggWieght) / 1000.0 : bool(this) && !m_jumbo ? (m_noOfEggs * RegularEggWieght) / 1000.0 : -1;
	}

	// ****************** Unary Operator overloads ******************
	EggCarton& EggCarton::operator--(){
		if (bool(*this) && m_noOfEggs > 0) m_noOfEggs--;
		return *this;
	}

	EggCarton& EggCarton::operator++(){
		if (bool(*this)) m_noOfEggs++;
		if (m_noOfEggs >m_size)setBroken();
		return *this;
	}

	EggCarton EggCarton::operator--(int){
		EggCarton before = *this;
		--(*this);
		return before;
	}

	EggCarton EggCarton::operator++(int){
		EggCarton before = *this;
		++(*this);
		return before;
	}

	// ****************** Binary member operators *******************
	EggCarton& EggCarton::operator=(int value) {
		m_noOfEggs = value;
		if (m_noOfEggs > m_size)setBroken();
		return *this;    // Returns a reference to the current object at the end.
	}

	EggCarton& EggCarton::operator+=(int value) {
		if (bool(*this))m_noOfEggs += value;
		if (m_noOfEggs > m_size) setBroken();
		return *this;
	}

	// Question1
	EggCarton& EggCarton::operator+=(EggCarton& right) {
		if (bool(*this)){
			m_noOfEggs += right.m_noOfEggs;
			if (m_noOfEggs > m_size){
				  
				right.m_noOfEggs = m_noOfEggs - m_size;
				m_noOfEggs = m_size;
			}
			else {
				right.m_noOfEggs = 0;
			}
		}
		return *this;
	}

	bool EggCarton::operator==(const EggCarton& right) const {
		return (-0.001 <= double(*this) - double(right) && double(*this) - double(right) <= 0.001);
	}

	// ****************** Helper Binary Operator  *******************
	int operator+(int left, const EggCarton& right) {
		if (bool(right)){
			return (left + int(right.getNoOfEgg()));
		}else {
			return left;
		}
	}

	ostream& operator<<(ostream& ostr, const EggCarton& right) {
		return right.display(ostr);
	}

	istream& operator>>(istream& istr, EggCarton& right) {
		return right.read(istr);
	}
}