/* Citation and Sources...
Final Project Milestone 1
Module: Seneca Library Application
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Menu.h"
using namespace std;

namespace sdds
{

	MenuItem::MenuItem() {
		m_menuItem = nullptr;
	}

	MenuItem::MenuItem(const char* menuItem) {
		m_menuItem = nullptr;

		if (menuItem != nullptr && menuItem[0] != '\0') {
			delete[] m_menuItem;
			m_menuItem = new char[strlen(menuItem) + 1];
			strcpy(m_menuItem, menuItem);
		}
		else {
			delete[] m_menuItem;
			m_menuItem = nullptr;
		}
	}

	MenuItem::~MenuItem() {
		delete[] m_menuItem;
		m_menuItem = nullptr;
	}

	MenuItem::operator bool() const {
		return (m_menuItem != nullptr && m_menuItem[0] != '\0');
	}

	MenuItem::operator const char* () const {
		return (const char*)m_menuItem;
	}

	ostream& MenuItem::displayMenuItem(ostream& output)const {
		if (m_menuItem != nullptr && m_menuItem[0] != '\0') {
			output << m_menuItem;
		}
		return output;
	}

	Menu::Menu() {
		m_menuTitle = nullptr;
		m_noOfmenuItems = 0;
	}

	Menu::Menu(const char* menuTitle) {
		if (menuTitle != nullptr && menuTitle[0] != '\0') {
			m_menuTitle = new char[strlen(menuTitle) + 1];
			strcpy(m_menuTitle, menuTitle);
		}
		else {
			m_menuTitle = nullptr;
		}
		m_noOfmenuItems = 0;
	}

	Menu::~Menu() {
		delete[] m_menuTitle;
		m_menuTitle = nullptr;
		for (unsigned int i = 0; i < m_noOfmenuItems; i++) {
			delete m_menuItems[i];
			m_menuItems[i] = nullptr;
		}
	}

	ostream& Menu::displayTitle(ostream& output) {
		if (m_menuTitle != nullptr) {
			output << m_menuTitle;
		}
		return output;
	}

	ostream& Menu::displayEntireMenu(ostream& output)const {
		if (m_menuTitle != nullptr) {
			output << m_menuTitle << endl;            // Remove the colon (":") 
		}
		for (unsigned int i = 0; i < m_noOfmenuItems; i++) {
			output.width(2);
			output.setf(ios::right);
			output.fill(' ');
			output << i + 1;
			output.unsetf(ios::right);
			output << "-";
			output << " ";
			m_menuItems[i]->displayMenuItem();
			output << endl;
		}
		output << " 0- Exit" << endl;
		output << "> ";

		return output;
	}

	unsigned int Menu::run() const {
		unsigned int selection = 0;
		displayEntireMenu();
		if (m_menuItems[0] != nullptr) {
			char s[100];
			int invalid;
			do
			{
				invalid = 0;
				cin >> s;
				cin.ignore(1000, '\n');
				if (!isInt(s)) {
					cout << "Invalid Selection, try again: ";
					invalid = 1;
				}
				else {
					selection = atoi(s);
					if (selection < 0 || selection > m_noOfmenuItems) {
						cout << "Invalid Selection, try again: ";
						invalid = 1;
					}
				}
			} while (invalid);
		}
		return selection;
	}

	unsigned int Menu::operator~() {
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemConent) {

		if (m_noOfmenuItems < MAX_MENU_ITEMS) {
			if (menuitemConent != nullptr && menuitemConent[0] != '\0') {
				m_menuItems[m_noOfmenuItems] = new MenuItem(menuitemConent);
				m_noOfmenuItems++;
			}
		}
		return *this;
	}

	Menu::operator unsigned int() const {
		return (unsigned int)m_noOfmenuItems;
	}

	Menu::operator bool() const {
		return (m_noOfmenuItems >= 1);
	}

	ostream& operator<<(std::ostream& output, Menu& obj) {
		return obj.displayTitle(output);
	}

	const char* Menu::operator[](int index) const {
		return m_menuItems[index % m_noOfmenuItems]->m_menuItem;
	}

	void Menu::setMenuTitle(const char* menuTitle) {
		if (menuTitle != nullptr && menuTitle[0] != '\0') {
			m_menuTitle = new char[strlen(menuTitle) + 1];
			strcpy(m_menuTitle, menuTitle);
		}
		else {
			m_menuTitle = nullptr;
		}
		m_noOfmenuItems = 0;
	}
}