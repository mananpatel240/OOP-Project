//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
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

#include "Menu.h"
#include "utils.h"
#include <cstring>
using namespace std;
namespace sdds 
{
    void Menu::display()const
    {
        cout << m_text << endl;
        cout << "0- Exit" << endl;
    }
    
    void Menu::setText(const char* text)
    {
        int len = strlen(text);
        m_text = new char[len + 1];
        strcpy(m_text, text);
        m_text[len] = '\0';
    }
    
    Menu::Menu(const char* MenuContent, int NoOfSelections)
    {
        setText(MenuContent);
        m_noOfSel = NoOfSelections;
    }

    Menu::Menu(const Menu& copy)
    {
        setText(copy.m_text);
        m_noOfSel = copy.m_noOfSel;
    }

    Menu::~Menu()
    {
        delete[] m_text;
    }
    
    int& Menu::operator>>(int& Selection)
    {
        display();
        int i = getInt(0, m_noOfSel, "> ", "Invalid option ");
        Selection = i;
        return Selection;
    }
}