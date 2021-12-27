/* Citation and Sources...
Final Project Milestone 5
Module: Seneca Library Application
Filename: LibApp.cpp
Version 1.0
Author	YuanKai Han
Revision History
-----------------------------------------------------------
Date      Reason
2021/12/  Preliminary release
2021/12/  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibApp.h"
#include "Utils.h"
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
namespace sdds
{
    LibApp::LibApp(const char* filename) {
        this->m_changed = false;
        m_mainMenu.setMenuTitle("Seneca Library Application");
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";
        m_exitMenu.setMenuTitle("Changes have been made to the data, what would you like to do?");
        m_exitMenu << "Save changes and exit"
            << "Cancel and go back to the main menu";

        // Milestone 5
        //this->m_fileName[0] = '\0';
        strncpy(this->m_fileName, filename, 256);
        this->NOLP = 0;
        this->LLRN = 0;

        // Publication Type Menu  
        m_publicationMenu.setMenuTitle("Choose the type of publication:");
        m_publicationMenu << "Book"
            << "Publication";
        load();
    }

    Publication* LibApp::getPub(int libRef) {
        for (int i = 0; i < NOLP; i++) {
            if (libRef == this->PPA[i]->getRef()) return this->PPA[i];
        }
        return 0;
    }
    bool LibApp::confirm(const char* message) {
        Menu menu(message);
        menu << "Yes";
        return menu.run() == 1;
    }

    void LibApp::load() {       
        cout << "Loading Data" << endl;
        fstream readFile;
        readFile.open(m_fileName, ios::in);    //read mode
        char type{};
        if (readFile.is_open()) {
            for (int i = 0; readFile; i++) {
                readFile >> type;
                readFile.ignore();
                if (readFile) {
                    if (type == 'P')
                        PPA[i] = new Publication;
                    else if (type == 'B')
                        PPA[i] = new Book;
                    if (PPA[i] && i < SDDS_LIBRARY_CAPACITY) {
                        readFile >> *PPA[i];
                        LLRN = PPA[i]->getRef();
                        NOLP++;
                    }
                }
            }
        }
        readFile.close();
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
        ofstream openFile(m_fileName);

        for (int i = 0; i < NOLP; i++) {
            if (PPA[i]->getRef() != 0) {
                openFile << *PPA[i] << endl;
            }
        }
        openFile.close();
    }

    // prints the publication with the library reference number "ref:
    void LibApp::prnPub(Publication* p[], int size, int ref) {
        int i;
        for (i = 0; i < size; i++) {
            if (ref == p[i]->getRef()) {
                if ('B' == p[i]->type()) {
                    cout << *((Book*)p[i]) << endl;
                }
                else {
                    cout << *p[i] << endl;
                }
                i = size; // Exit the loop.
            }
        }
    }

    int LibApp::search(int search_method, char type) {
        char title[256]{};
        int ref = 0;

        cout << "Publication Title: ";
        cin.get(title, 256, '\n');
        PublicationSelector ps("Select one of the following found matches:");

        switch (search_method) {
            case SEARCH_ALL:          
                for (int i = 0; i < NOLP; i++) {
                    if (PPA[i] && PPA[i]->type() == type && (strstr(*PPA[i], title)))
                        ps << PPA[i];
                }
                break;
            case SEARCH_ONLOAN:          
                for (int i = 0; i < NOLP; i++) {
                    if (PPA[i] && PPA[i]->type() == type && (strstr(*PPA[i], title)) && PPA[i]->onLoan())
                        ps << PPA[i];
                }
                break;
            case SEARCH_NOTLOAN:          
                for (int i = 0; i < NOLP; i++) {
                    if (PPA[i] && PPA[i]->type() == type && (strstr(*PPA[i], title)) && !PPA[i]->onLoan())
                        ps << PPA[i];
                }
                break;
            default:
                break;
        }

        if (ps) {
            ps.sort();      // sort them based on date and title
            ref = ps.run(); // display the publications and select one
            if (ref) 
                prnPub(PPA, 100, ref);
            else
                cout << "Aborted!" << endl;
        }
        else{
            cout << "No matches found!" << endl;
        }
        return ref;
    }

    void LibApp::returnPub() {
        cout << "Return publication to the library" << endl;
        int userSel = m_publicationMenu.run();
        char ch = (userSel == 1) ? 'B' : 'P';
        int referenceNum = search(SEARCH_ONLOAN, ch);

        if (referenceNum == 0) return;

        if (confirm("Return Publication?")) {
            Date today;
            int penDay = 0;
            Publication* p = getPub(referenceNum);
            penDay = today - p->checkoutDate() - SDDS_MAX_LOAN_DAYS;
            if (penDay > 0){
                double pay = (0.50 * penDay);
                cout << fixed << setprecision(2);
                cout << "Please pay $" << pay << " penalty for being " << penDay << " days late!" << endl;
            }
            p->set(0);
            m_changed = true;
            cout << "Publication returned" << endl;
        }
    }

    void LibApp::newPublication() {
        if (NOLP == SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl;
        }
        else {
            cout << "Adding new publication to the library" << endl;
            // get usr select  // 1 - Book 2 - Pub
            int userSel = m_publicationMenu.run();
            Publication* pd{};
            if (userSel == 1)
                pd = new Book;
            else if (userSel == 2)
                pd = new Publication;
            else if (userSel == 0) {
                cout << "Aborted!" << endl;
                return;
            }   
            cin >> *pd;
            if (cin){
                if (confirm("Add this publication to the library?")) {
                    if (pd){
                        LLRN++;
                        pd->setRef(LLRN);
                        PPA[NOLP] = pd;
                        NOLP++;
                        m_changed = true;
                        cout << "Publication added" << endl;
                    }
                    else{
                        cout << "Failed to add publication!" << endl;
                        delete pd;
                    }
                }else{
                    cout << "Aborted!" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Aborted!" << endl;
            } 
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from the library" << endl;
        int userSel = m_publicationMenu.run();
        char ch = (userSel == 1) ? 'B' : 'P';
        int referenceNum = search(SEARCH_ALL, ch);  // ALL

        if (referenceNum == 0) return;

        if (confirm("Remove this publication from the library?")) {
            Publication* p = getPub(referenceNum);
            p->setRef(0);
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub() {
        int membership = 0;
        char s[10];
        int invalid;
        cout << "Checkout publication from the library" << endl;

        int userSel = m_publicationMenu.run();
        char ch = (userSel == 1) ? 'B' : 'P';
        int referenceNum = search(SEARCH_NOTLOAN, ch);

        if (referenceNum == 0) return;

        if (confirm("Check out publication?")) {
            cout << "Enter Membership number: ";
            do{
                invalid = 0;
                cin >> s;
                cin.ignore(1000, '\n');
                // cout << "String Length: " << strlen(s) << endl;
                if (!isInt(s) || strlen(s) > 5) {
                    cout << "Invalid membership number, try again: ";
                    invalid = 1;
                }
                else {
                    membership = atoi(s);
                    Publication* p = getPub(referenceNum);
                    p->set(membership);
                    invalid = 0;
                }
            } while (invalid);
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }

    int LibApp::run() {
        int flag, option;
        int res = 1;
        do{
            res = 0;
            flag = 1;
            option = m_mainMenu.run();
            switch (option){
                case 1:
                    newPublication();
                    break;
                case 2:
                    removePublication();
                    break;
                case 3:
                    checkOutPub();
                    break;
                case 4:
                    returnPub();
                    break;
                case 0:
                    flag = 0;
                    if (m_changed == true) {         //if changed
                        option = m_exitMenu.run();
                        if (option == 1) {
                            save();
                        }
                        if (option == 2) {
                            flag = 1;
                        }
                        if (option == 0) {
                            flag = confirm("This will discard all the changes are you sure?") ? 0 : 1;
                        }
                    }
                    break;
                default:
                    break;
            }
            cout << endl;
        } while (flag);
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
        ifstream myFile(m_fileName);
        if (myFile.is_open()) {
            cout << myFile.rdbuf();
        }
        return res;
    }

    LibApp::~LibApp() {
        for (int i = 0; i < NOLP; i++) {
            delete PPA[i];
            PPA[i] = nullptr;
        }
    }
}