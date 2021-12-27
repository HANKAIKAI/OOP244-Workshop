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
		char* m_menuItem;

		MenuItem();
		MenuItem(const char* menuItem);
		MenuItem(const MenuItem& menuItemcnt) = delete;
		MenuItem& operator=(const MenuItem& menuItemcnt) = delete;
		~MenuItem();
		operator bool() const;
		operator const char* () const;
		std::ostream& displayMenuItem(std::ostream& output = std::cout)const;
		friend class Menu;
	};

	const int MAX_MENU_ITEMS = 20;

	class Menu
	{
		char* m_menuTitle;
		MenuItem* m_menuItems[MAX_MENU_ITEMS]{};
		unsigned int m_noOfmenuItems;

	public:
		Menu();
		Menu(const char* menuTitle);
		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu& menu) = delete;
		~Menu();

		std::ostream& displayTitle(std::ostream& output = std::cout);
		std::ostream& displayEntireMenu(std::ostream& output = std::cout)const;

		unsigned int run() const;
		unsigned int operator~();
		Menu& operator<<(const char* menuitemConent);
		operator unsigned int() const;
		operator bool() const;

		const char* operator[](int index) const;

		void setMenuTitle(const char* menuTitle);
	};
	std::ostream& operator<<(std::ostream& output, Menu& obj);
}
#endif // !SDDS_MENU_H__


