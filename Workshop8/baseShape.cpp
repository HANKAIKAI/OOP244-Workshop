/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "baseShape.h"
using namespace std;
namespace sdds
{
	baseShape::~baseShape() {
		;
	};

	ostream& operator<<(ostream& ostr, const baseShape& baseshape) {
		baseshape.drawShape(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, baseShape& baseshape) {
		baseshape.readShape(istr);
		return istr;
	}
}