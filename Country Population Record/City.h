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
#ifndef SDDS_CITY_H
#define SDDS_CITY_H
namespace sdds{
	const int POPULATION = 20000; //max population of a city
	
	class City{
		char m_cityName[31];// holds the city name up to 30 chars
		int m_population;//number of people. A city can have zero population.
	public:
		City();
		City(const char* name, int population);
		void setEmpty();
		void setCityName(const char* name);
		void setPopulation(int population);
		void addPopulation(int population);
		bool isEmpty()const;
		int getPeople()const;
		void display()const;
	};
}
#endif // !SDDS_CITY_H

