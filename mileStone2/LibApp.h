/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.h
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
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds
{
    class LibApp : public Menu
    {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

        bool confirm(const char* message);

        void load();
        void save();
        void search();
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();
    public:
        /**** Constructor ****/
        LibApp();

        /**** The run method ****/
        int run();
    };
}
#endif // !SDDS_LIBAPP_H




