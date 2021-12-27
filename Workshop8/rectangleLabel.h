/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RECTANGLELABEL_H
#define SDDS_RECTANGLELABEL_H
#include "labelShape.h"
namespace sdds
{
	class rectangleLabel : public labelShape
	{
		int m_width = 0;
		int m_spaces = 0;
	public:
		rectangleLabel();
		rectangleLabel(const char* cstr, int width, int spaces);
		void readShape(std::istream& istr);
		void drawShape(std::ostream& ostr) const;
	};
}
#endif // !SDDS_RECTANGLELABEL_H
