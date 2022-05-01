//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h
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

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds 
{
    class TriagePatient : public Patient 
    {
    private:
        char* symptoms;
    public:
        TriagePatient();
        char type() const;
        std::ostream& csvWrite(std::ostream& ostr) const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        ~TriagePatient();
    };
}
#endif // !SDDS_TRIAGEPATIENT_H

