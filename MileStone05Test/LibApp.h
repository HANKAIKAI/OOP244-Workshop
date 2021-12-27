/* Citation and Sources...
Final Project Milestone 5
Module: Seneca Library Application
Filename: LibApp.h
Version 1.0
Author	YuanKai Han
Revision History
-----------------------------------------------------------
Date      Reason
2021/12/6  Preliminary release
2021/12/6  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Publication.h"
#include "Menu.h"
#include "Book.h"
#include "PublicationSelector.h"
namespace sdds
{
    enum SAVE_METHOD
    {
        SEARCH_ALL, SEARCH_ONLOAN, SEARCH_NOTLOAN
    };

    class LibApp
    {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;
        // MileStone 5
        Menu m_publicationMenu;
        char m_fileName[256]{};
        Publication* PPA[SDDS_LIBRARY_CAPACITY]{};
        int NOLP;               // Number Of Loaded Publications
        int LLRN;               // Last Library Reference Number

        Publication* getPub(int libRef);
        bool confirm(const char* message);
        void load();
        void save();
        void prnPub(Publication* p[], int size, int ref);
        int search(int search_method, char type); // type: 'P' or 'B'       // DONE
        void returnPub();                                                   // DONE
        void newPublication();                                              // DONE
        void removePublication();                                           // DONE
        void checkOutPub();                                                 // DONE
    public:
        LibApp(const char* filename = NULL);  // set filename to NULL by default
        int run();
        ~LibApp();
    };
}
#endif // !SDDS_LIBAPP_H
