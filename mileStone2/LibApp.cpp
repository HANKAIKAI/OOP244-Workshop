/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author	YuanKai Han
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/?  Preliminary release
2020/11/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibApp.h"
using namespace std;
namespace sdds
{
    LibApp::LibApp() {
        this->m_changed = false;

 
        m_mainMenu.setMenuTitle("Seneca Library Application");
      
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";

        m_exitMenu.setMenuTitle("Changes have been made to the data, what would you like to do?");
        m_exitMenu << "Save changes and exit"
            << "Cancel and go back to the main menu";
        load();
    }

    bool LibApp::confirm(const char* message) {
        Menu menu(message);
        menu << "Yes";
        return menu.run() == 1;
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }

    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added" << endl;
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }

    /**** The run method ****/
    int LibApp::run() {
        int flag, option;
        int res = 1;
        do
        {
            res = 0;
            flag = 1;
            option = m_mainMenu.run();
            switch (option)
            {
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
            default:
                break;
            }
            cout << endl;
            
        } while (flag);

        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
        return res;
    }

}
