//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
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
#include "TriagePatient.h"
#include <iostream>
#include <string>
#include <cstring>

namespace sdds 
{
	int nextTriageTicket = 1;
    
    TriagePatient::TriagePatient() :Patient(nextTriageTicket)
    {
        symptoms = nullptr;
        nextTriageTicket++;
    }
    
    char TriagePatient::type() const
    {
        return 'T';
    }
    
    std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
    {
        Patient::csvWrite(ostr);
        ostr << ',' << symptoms;
        return ostr;
    }

    std::istream& TriagePatient::csvRead(std::istream& istr)
    {
        delete[] symptoms;
        Patient::csvRead(istr);
        istr.ignore();
        std::string s;
        std::getline(istr, s, '\n');
        int len = s.length();
        symptoms = new char[len + 1];
        strcpy(symptoms, s.c_str());
        symptoms[len] = '\0';
        nextTriageTicket = Patient::number() + 1;
        return istr;
    }

    std::ostream& TriagePatient::write(std::ostream& ostr) const
    {
        if (fileIO())
        {
            csvWrite(ostr);
        }
        else
        {
            ostr << "TRIAGE" << std::endl;
            Patient::write(ostr);
            ostr << std::endl;
            ostr << "Symptoms: " << symptoms << std::endl;
        }
        return ostr;
    }

    std::istream& TriagePatient::read(std::istream& istr)
    {
        if (fileIO())
        {
            csvRead(istr);
        }
        else
        {
            delete[] symptoms;
            Patient::read(istr);
            std::cout << "Symptoms: ";
            std::string s;
            std::getline(istr, s, '\n');
            int len = s.length();
            symptoms = new char[len + 1];
            strcpy(symptoms, s.c_str());
            symptoms[len] = '\0';
        }
        return istr;
    }
    
    
    TriagePatient::~TriagePatient()
    {
        delete[] symptoms;
    }
}