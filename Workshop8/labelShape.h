/*
Name: YUANKAI HAN
Email: yhan77@myseneca.ca
Student ID: 154477194
Data: 2021/11/
Section: NAA
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LABELSHAPE_H
#define SDDS_LABELSHAPE_H
#include "baseShape.h"
#include <iostream>
namespace sdds
{
	class labelShape : public baseShape
	{
		char* m_label = nullptr;   // to hold the dynamically allocated label for the baseShape
	protected:
		const char* label() const;
	public:
		labelShape();
		labelShape(const char* cstr);
		~labelShape();
		labelShape(const labelShape&) = delete;
		labelShape& operator=(const labelShape&) = delete;
		void readShape(std::istream& istr);
	};
}
#endif // !SDDS_LABELSHAPE_H
