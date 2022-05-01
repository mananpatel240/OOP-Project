//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 5.0
Author	Manan Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/04/01  Preliminary release
2021/04/10  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds 
{
    class Menu 
    {
        char* m_text;
        int m_noOfSel;
        void display()const;
        void setText(const char*);
    public:
        Menu(const char* MenuContent, int NoOfSelections);
        Menu(const Menu&);
        virtual ~Menu();
        int& operator>>(int& Selection);
        void operator=(const Menu&) = delete;
    };
}
#endif