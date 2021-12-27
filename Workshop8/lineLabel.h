/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LINELABEL_H
#define SDDS_LINELABEL_H
#include "labelShape.h"

namespace sdds
{
	class lineLabel : public labelShape
	{
		int m_length;      //hold the length of the lineLabel in characters
	public:
		lineLabel();
		lineLabel(const char* cstr, int lengthLine);
		void readShape(std::istream& istr);
		void drawShape(std::ostream& ostr) const;
	};

}
#endif // !SDDS_LINELABEL_H

