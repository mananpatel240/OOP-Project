//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
namespace sdds 
{
    PreTriage::PreTriage(const char* dataFilename) :
        m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
        m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
    {
        int len = strlen(dataFilename);
        m_dataFilename = new char[len + 1];
        strcpy(m_dataFilename, dataFilename);
        m_dataFilename[len] = '\0';
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        load();
    }

    PreTriage::~PreTriage()
    {
        ofstream os(m_dataFilename);
        cout << "Saving Average Wait Times," << endl;
        cout << "   COVID Test: " << m_averCovidWait << endl;
        cout << "   Triage: " << m_averTriageWait << endl;
        os << m_averCovidWait << "," << m_averTriageWait << endl;
        cout << "Saving m_lineup..." << endl;
        for (int i = 0; i < m_lineupSize; i++)
        {
            cout << i + 1 << "- ";
            m_lineup[i]->csvWrite(cout) << endl;
            m_lineup[i]->csvWrite(os) << endl;
        }
        for (int i = 0; i < m_lineupSize; i++)
        {
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
        cout << "done!" << endl;
        os.close();
    }

    const Time PreTriage::getWaitTime(const Patient& p)const
    {
        Time temp;
        unsigned int count = 0;
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (p.type() == m_lineup[i]->type())
            {
                count++;
            }
        }
        if (p.type() == 'C')
        {
            temp = m_averCovidWait * count;
        }
        else
        {
            temp = m_averTriageWait * count;
        }
        return temp;
    }

    void PreTriage::setAverageWaitTime(const Patient& p)
    {
        Time CT = Time(getTime());
        Time PTT = Time(p);
        Time AWT = p.type() == 'C' ? m_averCovidWait : m_averTriageWait;
        unsigned int PTN = p.number();
        AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
        if (p.type() == 'C')
        {
            m_averCovidWait = AWT;
        }
        else
        {
            m_averTriageWait = AWT;
        }
    }

    void PreTriage::removePatientFromLineup(int index)
    {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }

    int PreTriage::indexOfFirstInLine(char type) const
    {
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (type == m_lineup[i]->type())
            {
                return i;
            }
        }
        return -1;
    }

    void PreTriage::load()
    {
        cout << "Loading data..." << endl;
        ifstream is(m_dataFilename);
        is >> m_averCovidWait;
        is.ignore();
        is >> m_averTriageWait;
        is.ignore();
        Patient* p = NULL;
        for (int i = 0; i < maxNoOfPatients && is.peek() != EOF; i++)
        {
            char c;
            is >> c;
            if (c == 'C')
            {
                p = new CovidPatient();
            }
            if (c == 'T')
            {
                p = new TriagePatient();
            }
            if (p != NULL)
            {
                p->fileIO(true);
                is >> *p;
                p->fileIO(false);
                m_lineup[i] = p;
                m_lineupSize++;
            }
        }

        if (is.peek() != EOF)
        {
            cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
        }
        else if (m_lineupSize == 0)
        {
            cout << "No data or bad data file!" << endl;
        }

        if (m_lineupSize > 0)
        {
            cout << m_lineupSize << " Records imported..." << endl;
        }
        cout << endl;
    }

    void PreTriage::reg()
    {
        if (m_lineupSize == maxNoOfPatients)
        {
            cout << "Line up full!" << endl;
            return;
        }
        int sel;
        m_pMenu >> sel;
        if (sel == 1)
        {
            m_lineup[m_lineupSize] = new CovidPatient();
        }
        if (sel == 2)
        {
            m_lineup[m_lineupSize] = new TriagePatient();
        }
        if (sel == 0)
        {
            return;
        }
        m_lineup[m_lineupSize]->setArrivalTime();
        cout << "Please enter patient information: " << endl;
        m_lineup[m_lineupSize]->fileIO(false);
        m_lineup[m_lineupSize]->read(cin);
        cout << endl << "******************************************" << endl;
        cout << *m_lineup[m_lineupSize];
        cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]);
        cout << endl << "******************************************" << endl << endl;
        m_lineupSize++;
    }

    void PreTriage::admit()
    {
        int sel;
        m_pMenu >> sel;
        char type = '\0';
        if (sel == 1)
        {
            type = 'C';
        }
        if (sel == 2)
        {
            type = 'T';
        }
        if (sel == 0)
        {
            return;
        }
        int index = indexOfFirstInLine(type);
        if (index == -1)
        {
            return;
        }
        cout << endl << "******************************************" << endl;
        m_lineup[index]->fileIO(false);
        cout << "Calling for ";
        cout << *m_lineup[index];
        cout << "******************************************" << endl << endl;
        setAverageWaitTime(*m_lineup[index]);
        removePatientFromLineup(index);
    }

    void PreTriage::run(void)
    {
        while (true)
        {
            int sel;
            m_appMenu >> sel;
            if (sel == 0)
            {
                return;
            }
            if (sel == 1)
            {
                reg();
            }
            if (sel == 2)
            {
                admit();
            }
        }
    }
}