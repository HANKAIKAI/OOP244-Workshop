/* Citation and Sources...
Final Project Milestone 3
Module: Seneca Library Application
Filename: Streamable.h
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
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds
{
	// Streamable Pure Virtual funcitons
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios& io) const = 0;   // pure virtual function
		virtual operator bool() const = 0;
		virtual ~Streamable();
	};
	std::ostream& operator<<(std::ostream& ostr, const Streamable& Rightstreamable);
	std::istream& operator>>(std::istream& istr, Streamable& Rightstreamable);
}
#endif // !SDDS_STREAMABLE_H




