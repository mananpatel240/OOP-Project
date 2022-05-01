//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include "utils.h"
#include <cstring>
#include <string>
namespace sdds 
{
    Patient::Patient(int ticket, bool flag) :t(ticket)
    {
        ioflag = flag;
    }

    Patient::~Patient()
    {
        delete[] pname;
    }

    bool Patient::fileIO() const
    {
        return ioflag;
    }

    void Patient::fileIO(bool flag)
    {
        ioflag = flag;
    }

    bool Patient::operator ==(char c) const
    {
        return c == type();
    }

    bool Patient::operator ==(const Patient& p) const
    {
        return type() == p.type();
    }

    void Patient::setArrivalTime()
    {
        t.resetTime();
    }
    Patient::operator Time() const
    {
        return Time(t);
    }

    int Patient::number() const
    {
        return t.number();
    }

    std::ostream& Patient::csvWrite(std::ostream& ostr) const
    {
        ostr << type() << ',';
        ostr << pname << ',';
        ostr << ohip << ',';
        return t.csvWrite(ostr);
    }

    std::istream& Patient::csvRead(std::istream& istr)
    {
        std::string s;
        istr.ignore();
        std::getline(istr, s, ',');
        int len = s.length();
        delete[] pname;
        pname = new char[len + 1];
        strcpy(pname, s.c_str());
        pname[len] = '\0';
        istr >> ohip;
        istr.ignore();
        return t.csvRead(istr);
    }

    std::ostream& Patient::write(std::ostream& ostr) const
    {
        ostr << t << '\n';
        for (int i = 0; i < 25 && pname[i]; i++)
        {
            ostr << pname[i];
        }
        ostr << ", OHIP: ";
        ostr << ohip;
        return ostr;
    }   

    std::istream& Patient::read(std::istream& istr)
    {
        std::cout << "Name: ";
        std::string s;
        std::getline(istr, s);
        int len = s.length();
        delete[] pname;
        pname = new char[len + 1];
        strcpy(pname, s.c_str());
        pname[len] = '\0';
        std::cout << "OHIP: ";
        ohip = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");
        return istr;
    }
}