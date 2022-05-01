//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.h
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

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"

namespace sdds 
{
    class CovidPatient : public Patient 
    {
    public:
        CovidPatient();
        char type() const;
        std::istream& csvRead(std::istream& istr); 
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
    };
}
#endif // !SDDS_COVIDPATIENT_H_
