//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.9.14
//==============================================
// Worshop#1: Modules     
//==============================================
#ifndef SDDS_DRINKE_H 
#define SDDS_DRINKE_H
namespace sdds{

	struct Drink
	{
		char name[10];
		int volume;
		double price;
		int quantity;
	};

	const int MAXDRINKS = 5;

	void loadDrinks();
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);
}

#endif // !SDDS_DRINKE_H