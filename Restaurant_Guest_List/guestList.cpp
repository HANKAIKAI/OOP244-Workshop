//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NAA
// Date:           2021.9.
//==============================================
// Worshop#2: (DIY) Restaurant Guest List
// This file tests the DIY section of your workshop  
//==============================================
#include <iostream>
#include "Guests.h"
using namespace std;
using namespace sdds;

int main() {
    bool done = false;
    char resturantName[51];
    Guest gst = { "", {0,0} };
    GuestList gl = { nullptr, 0 };
    PhoneNumber phno;
    cout << "Please enter the name of the restaurant: ";
    read(resturantName, 50);
    read(phno);
    cout << "Guest entry..." << endl;
    while (!done) {
        cout << "Enter guest information or Enter to exit:" << endl;
        if (read(gst)) {
            addGuest(gl, gst);
        }
        else {
            done = true;
        }
    }
    cout << endl << endl << resturantName << ", Phone Number: ";
    print(phno);
    cout << "**********************************************" << endl;
    cout << "Guestlist and their contacts: " << endl;
    print(gl);
    delete[] gl.m_gst;
}

//Please enter the name of the restaurant : Seneca Cafe
//Enter Phone Number[area][number] : 416 4915050
//Guest entry...
//Enter guest information or Enter to exit :
//Guest name : Fred Soley
//Enter Phone Number[area][number] : 416 1112222
//Enter guest information or Enter to exit :
//Guest name : Homer Simpson
//Enter Phone Number[area][number] : 541 2223333
//Enter guest information or Enter to exit :
//Guest name : Barney Gumble
//Enter Phone Number[area][number] : 541 3332222
//Enter guest information or Enter to exit :
//Guest name : Edna Krabappel
//Enter Phone Number[area][number] : 541 4443333
//Enter guest information or Enter to exit :
//Guest name :
//
//
//Seneca Cafe, Phone Number : (416) 4915050
//* *********************************************
//Guestlist and their contacts :
//1 - Fred Soley, (416) 1112222
//2 - Homer Simpson, (541) 2223333
//3 - Barney Gumble, (541) 3332221
//4 - Edna Krabappel, (541) 4443333