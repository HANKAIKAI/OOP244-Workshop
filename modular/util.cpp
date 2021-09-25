//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.9.14
//==============================================
// Worshop#1: Modules     
//==============================================
#include "util.h"
#include<iostream>
using namespace std;

namespace sdds{

	bool confirm() {
		char choice = cin.get();
		clearBuffer();
		return choice == 'Y';
	}

	void clearBuffer() {
		while (cin.get() != '\n');
	}
}