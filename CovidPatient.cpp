//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.cpp
Version 5.0
Author	Manan Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/03/26  Preliminary release
2021/04/01  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "CovidPatient.h"
#include <iostream>

namespace sdds 
{
    int nextCovidTicket = 1;
    
    CovidPatient::CovidPatient() :Patient(nextCovidTicket)
    {
        nextCovidTicket++;
    }
    
    char CovidPatient::type() const
    {
        return 'C';
    }
    
    std::istream& CovidPatient::csvRead(std::istream& istr)
    {
        Patient::csvRead(istr);
        nextCovidTicket = Patient::number() + 1;
        return istr;
    }
    
    std::ostream& CovidPatient::write(std::ostream& ostr) const
    {
        if (fileIO())
        {
            csvWrite(ostr);
        }
        else
        {
            ostr << "COVID TEST" << std::endl;
            Patient::write(ostr);
            ostr << std::endl;
        }
        return ostr;
    }

    std::istream& CovidPatient::read(std::istream& istr)
    {
        if(fileIO())
        {
            csvRead(istr);
        }
        else 
        {
            Patient::read(istr);
        }
        return istr;
    }  
}