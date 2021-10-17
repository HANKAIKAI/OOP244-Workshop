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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Bus.h"
using namespace std;

namespace sdds{
	void Bus::setOutOfService(){
		this->m_noOfSeat = -1;
		this->m_noOfPassenger = -1;
	}

	// draws a bus with 
	// seat = number of seats
	// psng = number of passengers
	// on ostream
	void Bus::drawBus(ostream& ostr, int seats, int psng) const{
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < psng ? '2' : ((p == psng) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
		ostr << "Total Fare Price: ";
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << double(*this) << endl;
		ostr.unsetf(ios::fixed);
	}

	Bus::Bus(int noOfSeat, int noOfPassenger) {
		if (!(noOfSeat % 2 == 0 && noOfSeat >= 10 && noOfSeat <= 40 && noOfPassenger >= 0 && noOfPassenger <= noOfSeat)) {
			setOutOfService();
		}
		else {
			this->m_noOfSeat = noOfSeat;
			this->m_noOfPassenger = noOfPassenger;
		}
	}

	bool Bus::isOutOfService() const{
		return (m_noOfSeat % 2 == 0 && m_noOfSeat >= 10 && m_noOfSeat <= 40 && m_noOfPassenger >= 0 && m_noOfPassenger <= m_noOfSeat);
	}

	int Bus::getNoOfPassenger()const {
		return this->m_noOfPassenger;
	}

	// Not sure
	ostream& Bus::display(std::ostream& ostr) const {
		if (bool(*this)){
			drawBus(ostr, m_noOfSeat, m_noOfPassenger);
		}else {
			cout << "Out of service!" << endl;
		}
		return ostr;
	}

	istream& Bus::read(std::istream& istr) {
		istr >> this->m_noOfSeat;
		istr.ignore();
		istr >> this->m_noOfPassenger;
		if (!(m_noOfSeat % 2 == 0 && m_noOfSeat >= 10 && m_noOfSeat <= 40 && m_noOfPassenger >= 0 && m_noOfPassenger <= m_noOfSeat)) {
			setOutOfService();
		}
		return istr;
	}

	// ****************** Type Conversion Operator ******************
	Bus::operator bool() const {
		return (isOutOfService() && m_noOfSeat > 0);
	}

	Bus::operator int() const {
		return (bool(*this) ? m_noOfPassenger : -1);
	}

	Bus::operator double() const {
		return (bool(*this) ? (double(m_noOfPassenger) * (PRICE_OF_BUSTICKET)) : -1.0);
	}

	// ****************** Unary Operator overloads ******************
	bool Bus::operator--() {
		bool resp = false;
		if ((bool(*this) && m_noOfPassenger > 0)){
			m_noOfPassenger--;
			resp = true;
		}
		return resp;
	}

	bool Bus::operator++() {
		bool resp = false;
		if (bool(*this) && m_noOfPassenger < m_noOfSeat) {
			m_noOfPassenger++;
			resp = true;
		}
		return resp;
	}

	bool Bus::operator--(int) {
		bool resp = false;
		if ((bool(*this) && m_noOfPassenger > 0)) {
			/*m_noOfPassenger--;*/
			--(*this);
			resp = true;
		}
		return resp;
	}

	bool Bus::operator++(int) {
		bool resp = false;
		if (bool(*this) && m_noOfPassenger < m_noOfSeat) {
			++(*this);
			resp = true;
		}
		return resp;
	}

	// ****************** Binary member operators *******************
	Bus& Bus::operator=(int value) {
		m_noOfPassenger = value;
		if (m_noOfPassenger > m_noOfSeat) setOutOfService();
		return *this;
	}

	Bus& Bus::operator+=(int value) {
		if (bool(*this)) m_noOfPassenger += value;
		if (m_noOfPassenger > m_noOfSeat) setOutOfService();
		return *this;
	}

	Bus& Bus::operator+=(Bus& right) {
		if (bool(*this) && bool(right)){
			m_noOfPassenger += right.m_noOfPassenger;
			if (m_noOfPassenger > m_noOfSeat){
				right.m_noOfPassenger = m_noOfPassenger - m_noOfSeat;
				m_noOfPassenger = m_noOfSeat;
			}else{
				right.m_noOfPassenger = 0;
			}
		}
		return *this;
	}

	bool Bus::operator==(const Bus& right) const {
		return (bool(*this) && bool(right) && this->m_noOfPassenger == right.m_noOfPassenger);
	}

	// ****************** Helper Binary Operator  *******************
	int operator+(int left, const Bus& right) {
		if (bool(right)){
			return (left + int(right.getNoOfPassenger()));
		}else{
			return left;
		}
	}

	ostream& operator<<(ostream& ostr, const Bus& right) {
		return (right.display(ostr));
	}

	istream& operator>>(istream& istr, Bus& right) {
		return (right.read(istr));
	}
}