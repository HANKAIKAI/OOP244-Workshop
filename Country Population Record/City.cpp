// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.10.
//==============================================
// Worshop#4: (LAB) Constructors, Destructors and Current object 
// Version: 0.9
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "City.h"

using namespace std;

namespace sdds{
	City::City() {
		setEmpty();
	}

	City::City(const char* name, int population) {
		if (name != nullptr && name[0] != '\0' && population >= 0){      
			strncpy(m_cityName, name, 30);
			m_population = population;
		}else{
			setEmpty();
		}
	}

	void City::setEmpty() {
		m_cityName[0] = '\0';
		m_population = -1;
	}

	void City::setCityName(const char* name) {
		if (name != nullptr){
			strcpy(m_cityName, name);
		}else {
			setEmpty();
		}
	}

	void  City::setPopulation(int population) {
		if (population < POPULATION) {
			m_population = population;
		}else{
			setEmpty();
		}
	}

	void City::addPopulation(int population) {
		m_population += population;
		if(m_population > POPULATION){
			m_population = POPULATION;
		}
	}

	bool City::isEmpty()const {
		return (m_cityName[0] == '\0' || m_population < 0);
	}

	int City::getPeople()const{
		return m_population;
	}

	void City::display()const {
		if (!isEmpty()){
			cout << "|";
			cout.width(31);
			cout.setf(ios::left);
			cout << m_cityName;
			cout.unsetf(ios::left);
			cout << "|";
			cout.width(11);
			cout.setf(ios::right);
			cout << m_population;
			cout << " ";
			cout << "|";
			cout << " " << endl;
			cout.unsetf(ios::right);
		}else{
			cout << "invalid city" << endl;
		}
	}
}