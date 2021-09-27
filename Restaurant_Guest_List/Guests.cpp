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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Guests.h"
using namespace std;

namespace sdds{

    void read(char* str, int len) {
     // checks the incomming character, if it is newline, it will remove it
        if (cin.peek() == '\n') cin.ignore(); 
        cin.getline(str, len);
    }

    void read(PhoneNumber& thePhoneNumber) {
        cout << "Enter Phone Number [area] [number]: ";
        cin >> thePhoneNumber.m_areacode >> thePhoneNumber.m_number;
    }

    bool read(Guest& theGuest) {
        bool resp = false;
        cout << "Guest name: ";
        read(theGuest.m_name, 21);
        if (theGuest.m_name[0] != '\0') {
            resp = true;
            read(theGuest.m_phno);
        }
        return resp;
    }

    void print(const PhoneNumber& thePhoneNumber) {
        cout << "(" << thePhoneNumber.m_areacode << ")" << " " << thePhoneNumber.m_number << endl;
    }

    /*Prints the guest information as follows:
        name
        comma and space ", "
        phone number*/
    void print(const Guest& theGuest) {
        //cout << theGuest.m_name << ", " << theGuest.m_phno;
        cout << theGuest.m_name << ", ";
        print(theGuest.m_phno);
    }

    /*Prints all the guests in a list. It also adds a row number with a dash before each name.*/
    void print(const GuestList& theGuestList) {
        for (int i = 0; i < theGuestList.m_noOfGuests; i++){
            //cout << (i + 1) << "- " << theGuestList.m_gst[i];
            cout << i + 1 << "- ";
            print(theGuestList.m_gst[i]);
        }
    }

    void addGuest(GuestList& theGuestList, const Guest& aGuest) {

        Guest* temp = nullptr;
        temp =  new Guest[theGuestList.m_noOfGuests + 1];
        if (temp != nullptr) {
            for (int i = 0; i < theGuestList.m_noOfGuests; i++){
                strcpy(temp[i].m_name, theGuestList.m_gst[i].m_name);
                temp[i].m_phno = theGuestList.m_gst[i].m_phno;
            }
            strcpy(temp[theGuestList.m_noOfGuests].m_name, aGuest.m_name);
            temp[theGuestList.m_noOfGuests].m_phno = aGuest.m_phno;
            delete[] theGuestList.m_gst;
            theGuestList.m_gst = temp;
            theGuestList.m_noOfGuests += 1;
        }
    }
}
