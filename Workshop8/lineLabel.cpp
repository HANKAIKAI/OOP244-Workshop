/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "lineLabel.h"
#include <cstring>
using namespace std;
namespace sdds
{
	lineLabel::lineLabel() : labelShape(){
		m_length = 0;
	}
	
	lineLabel::lineLabel(const char* cstr, int lengthLine) : labelShape(cstr) {
		m_length = lengthLine;
	}

	void lineLabel::readShape(istream& istr) {
		labelShape::readShape(istr);
		istr >> m_length;
		istr.ignore(100, '\n');
	}

	void lineLabel::drawShape(ostream& ostr) const {
		if (m_length > 0 && label() != nullptr){
			ostr << label() << endl;
			for (int i = 0; i < m_length; ++i){
				ostr << '=';
			}
		}
	}
}