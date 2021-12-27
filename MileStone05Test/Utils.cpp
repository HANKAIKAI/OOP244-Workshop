/* Citation and Sources...
Final Project Milestone 5
Module: Seneca Library Application
Filename: Utils.cpp
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
#include <ctype.h>
#include "Utils.h"

using namespace std;

namespace sdds
{
	bool isInt(const char s[]) {
		bool res = true;
		for (int i = 0; s[i] != '\0' && res; i++) {
			if (!isdigit(s[i])) {
				res = false;
			}
		}
		return res;
	}
}