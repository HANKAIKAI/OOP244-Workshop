//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.9.16
//==============================================
// Worshop#1: (DIY)Vending Machine with File Reading     
//==============================================
#include <iostream>
#include "drink.h"
#include "util.h"

using namespace std;
using namespace sdds;

int main() {

    bool done = false;
    //loadDrinks();
    loadDrinksFromFile("drinks.txt"); // for DIY
    cout << "Welcome to the Seneca Vending Machine" << endl << endl;
    while (!done) {
        drinkMenu();
        chooseDrink();
        cout << "\nDo you want to order another drink? (Y)es or (N)o: ";
        done = !confirm();
        cout << endl;
    }
    drinkMenu();
    cout << "\nThank you and come again" << endl;
    return 0;
}