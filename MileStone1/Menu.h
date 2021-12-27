/* Citation and Sources...
Final Project Milestone 1
Module: Seneca Library Application
Filename: Menu.h
Version 1.0
Author	YuanKai Han
Revision History
-----------------------------------------------------------
Date      Reason
2021/11/7  Preliminary release
2021/11/7  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#include <cstring>
namespace sdds
{
	class MenuItem
	{
	private:
		char* m_menuItem;          // menuTester.cpp Line#28

		MenuItem();
		MenuItem(const char* menuItem);
		MenuItem(const MenuItem& menuItemcnt) = delete;
		MenuItem& operator=(const MenuItem& menuItemcnt) = delete;
		~MenuItem();
		operator bool() const;          //bool type conversion
		operator const char* () const;  //const char* type conversion
		std::ostream& displayMenuItem(std::ostream& output = std::cout)const;   // recoding 0:38:26
		friend class Menu;
	};

	const int MAX_MENU_ITEMS = 20;

	class Menu      // recoding 0:40:00
	{
		char* m_menuTitle;
		MenuItem* m_menuItems[MAX_MENU_ITEMS]{};
		unsigned int m_noOfmenuItems;

	public:
		Menu();
		Menu(const char* menuTitle);
		//Rule of Three
		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu& menu) = delete;
		~Menu();

		//************ Methods ************
		/*bool isEmpty() const;*/
		std::ostream& displayTitle(std::ostream& output = std::cout);
		//display Function recording 0:47:41
		std::ostream& displayEntireMenu(std::ostream& output = std::cout)const;

		//Not finish
		unsigned int run() const;
		unsigned int operator~();

		//Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
		Menu& operator<<(const char* menuitemConent);

		operator unsigned int() const;
		operator bool() const;

		//Overload the insertion operator to print the title of the Menu using cout
		/*std::ostream& operator<< (std::ostream& output, Menu& obj);*/
		//Overload the indexing operator 
		const char* operator[](int index) const;
	};
	std::ostream& operator<<(std::ostream& output, Menu& obj);
}
#endif // !SDDS_MENU_H__