//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.9.16
//==============================================
// Worshop#1: (DIY)Vending Machine with File Reading     
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