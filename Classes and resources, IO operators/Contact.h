// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.10.21
//==============================================
// Worshop#6: (LAB) Classes and resources, IO operators
// Version: 0.9
//==============================================
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include <iostream>
namespace sdds
{
    const int MaxNameLength = 55;
    class Contact
    {
        char* m_name{}; // sets m_name to nullptr before any constructor invocation 
        int m_area;
        int m_exchangeCode;
        int m_number;

        // ****************** Private Methods ******************
        bool validPhone(int areaCode, int exchangeCode, int number)const;
        void setEmpty();
        void allocateAndCopy(const char* name);
        void extractChar(std::istream& istr, char ch)const;
        std::ostream& printPhoneNumber(std::ostream& istr)const;
        void set(const char* name, int areaCode, int exchangeCode, int number);
    public:
        // ****************** Constructor ******************
        Contact();
        Contact(const char* name, int areaCode, int exchangeCode, int number);
        // ****************** Copy Constructor ******************
        Contact(const Contact& cnt);
        // ****************** Copy Assignment operator overload ******************
        Contact& operator=(const Contact& cnt);

        // ****************** Boolean type conversion operator ******************
        operator bool() const;

        std::ostream& print(std::ostream& ostr, bool toFile) const;
        std::istream& read(std::istream& istr);

        // ****************** Destructor ******************
        ~Contact();
    };
    std::ostream& operator<<(std::ostream& ostr, const Contact& cnt);
    std::istream& operator>>(std::istream& istr, Contact& cnt);
}
#endif // !SDDS_CONTACT_H