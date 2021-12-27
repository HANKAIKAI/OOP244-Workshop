/* Citation and Sources...
Final Project Milestone 3
Module: Seneca Library Application
Filename: Streamable.cpp
Version 1.0
Author	YuanKai Han
Revision History
-----------------------------------------------------------
Date      Reason
2021/11/25  Preliminary release
2021/11/25  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Streamable.h"
using namespace std;
namespace sdds
{
	/********** Base class **********/
	Streamable::~Streamable() {
		;
	}

	ostream& operator<<(ostream& ostr, const Streamable& streamable) {
		streamable.write(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Streamable& streamable) {
		streamable.read(istr);
		return istr;
	}
}