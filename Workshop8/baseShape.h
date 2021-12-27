/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BASESHAPE_H_
#define SDDS_BASESHAPE_H_
#include <iostream>
namespace sdds
{
	class baseShape
	{
	public:
		virtual void drawShape(std::ostream& ostr) const = 0;
		virtual void readShape(std::istream& istr) = 0;
		virtual ~baseShape();
	};
	std::ostream& operator<<(std::ostream& ostr, const baseShape& baseshape);
	std::istream& operator>>(std::istream& istr, baseShape& baseshape);
}
#endif // !SDDS_BASESHAPE_H_

