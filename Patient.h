//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.h
Version 5.0
Author	Manan Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/03/20  Preliminary release
2021/03/27  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"
#include <iostream>
namespace sdds 
{
    class Patient : public IOAble
    {
        char* pname = nullptr;
        int ohip;
        Ticket t;
        bool ioflag;
    public:
        Patient(int ticket = 0, bool flag = false);
        ~Patient();
        Patient(const Patient&) = delete;
        void operator=(const Patient&) = delete;
        void getSpecs(std::istream&);
        virtual char type() const = 0;
        bool fileIO() const;
        void fileIO(bool);
        bool operator ==(char) const;
        bool operator ==(const Patient&) const;
        void setArrivalTime();
        operator Time() const;
        int number() const;
        std::ostream& csvWrite(std::ostream& ostr) const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
    };
}
#endif