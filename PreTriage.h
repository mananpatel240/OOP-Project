//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.h
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

#ifndef SDDS_PRETRIAGEPATIENT_H
#define SDDS_PRETRIAGEPATIENT_H
#include "Time.h"
#include "Patient.h"
#include "Menu.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

namespace sdds 
{
    const int maxNoOfPatients = 100;
    class PreTriage 
    {
        Time
            m_averCovidWait,
            m_averTriageWait;
        Patient* m_lineup[maxNoOfPatients]{};
        char* m_dataFilename = nullptr;
        int m_lineupSize = 0;
        Menu
            m_appMenu,
            m_pMenu;
        void reg();
        void admit();
        const Time getWaitTime(const Patient& p)const;
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        int indexOfFirstInLine(char type) const;
        void load();
    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        void run(void);
    };
}
#endif // !SDDS_PRETRIAGEPATIENT_H