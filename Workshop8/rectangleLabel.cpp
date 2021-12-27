/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "rectangleLabel.h"
#include <cstring>
using namespace std;
namespace sdds
{
	rectangleLabel::rectangleLabel() : labelShape(){
		m_width = 0;
		m_spaces = 0;
	}

	rectangleLabel::rectangleLabel(const char* cstr, int width, int spaces) : labelShape(cstr) {
		m_width = width;
		m_spaces = spaces;
		if (m_width < int(strlen(label())) + 2 + m_spaces)
		{
			m_width = 0;
			m_spaces = 0;
		}
	}

	void rectangleLabel::readShape(std::istream& istr) {
		labelShape::readShape(istr);
		istr >> m_width;
		istr.ignore(100, ',');
		istr >> m_spaces;
		istr.ignore(100, '\n');
	}

	void rectangleLabel::drawShape(std::ostream& ostr) const {
		if (m_width > 0 && m_spaces > 0 && label() != nullptr)
		{
			ostr << "+";
			for (int i = 0; i < m_width - 2; ++i) {
				ostr << '-';
			}
			ostr << "+" << "\n";

			ostr << "|";
			ostr.width(m_spaces);
			ostr << " ";
			ostr.setf(ios::left);
			ostr.width(m_width - 2 - m_spaces);
			ostr << label();
			ostr << "|" << "\n";

			ostr << "+";
			for (int i = 0; i < m_width - 2; ++i) {
				ostr << '-';
			}
			ostr << "+";
		}
	}
}