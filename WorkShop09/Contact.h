// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.11.24
//==============================================
// Worshop#9: (LAB) Derived Classes and Resources
// Version: 0.9
//==============================================
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include <iostream>
#include "Person.h"
#include "Utils.h"
namespace sdds
{
	const int PROVINCE_LENGTH = 2;
	const int POSTALCODE_LENGTH = 6;
	class Contact : public Person
	{
		char* m_address{};		 // Dynamic, unknown length
		char* m_city{};			 // Dynamic, unknown length		
		char m_province[PROVINCE_LENGTH + 1];         // 2 characters 
		char m_postalCode[POSTALCODE_LENGTH + 1];       // 6 characters
	public:
		Contact();
		// The rule of three
		Contact(const Contact& copyFrom);
		Contact& operator=(const Contact& RightOperand);
		~Contact();
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		operator bool()const;
		void operator~();
	};
}
#endif // !SDDS_CONTACT_H

