//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.9.16
//==============================================
// Worshop#1: (DIY)Vending Machine with File Reading     
//==============================================
#ifndef SDDS_DRINKE_H 
#define SDDS_DRINKE_H
namespace sdds{

	struct Drink{
		char name[10];
		int volume;
		double price;
		int quantity;
	};

	const int MAXDRINKS = 5;

	//void loadDrinks();  // static setof drinks

	void loadDrinksFromFile(const char* filename); // read the data from drink.txt file
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);

}

#endif // !SDDS_DRINKE_H