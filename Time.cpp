//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.cpp
Version 5.0
Author	Manan Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/03/07  Preliminary release
2021/04/01  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Time.h"
#include "utils.h"
#include <string>
using namespace std;
namespace sdds
{
    Time& Time::setToNow()
    {
        m_min = getTime();
        return *this;
    }

    Time::Time(unsigned int min)
    {
        m_min = min;
    }

    std::ostream& Time::write(std::ostream& ostr) const
    {
        unsigned int hours = m_min / 60;
        unsigned int mins = m_min % 60;
        if (hours < 10)
        {
            ostr << "0";
        }
        ostr << hours << ":";
        if (mins < 10)
        {
            ostr << "0";
        }
        ostr << mins;
        return ostr;
    }

    std::istream& Time::read(std::istream& istr)
    {
        int hours = 0;
        int minutes = 0;
        char c = '\0';

        istr >> hours;
        if (hours < 0)
        {
            istr.setstate(ios::failbit);
            return istr;
        }

        istr >> c;
        if (c != ':')
        {
            istr.setstate(ios::failbit);
            return istr;
        }

        istr >> minutes;
        if (minutes < 0)
        {
            istr.setstate(ios::failbit);
            return istr;
        }

        m_min = hours * 60 + minutes;
        return istr;
    }

    Time& Time::operator-= (const Time& D)
    {
        int totalMins = 24 * 60;
        int min1 = (int)(*this);
        int min2 = (int)(D);
        int diff = (((min1 - min2) % totalMins) + totalMins) % totalMins;
        m_min = diff;
        return *this;
    }

    Time Time::operator-(const Time& D)const
    {
        int totalMins = 24 * 60;
        Time temp;
        int min1 = (int)(*this);
        int min2 = (int)(D);
        int diff = (((min1 - min2) % totalMins) + totalMins) % totalMins;
        temp.m_min = diff;
        return temp;
    }

    Time& Time::operator+=(const Time& D)
    {
        m_min += D.m_min;
        return *this;
    }

    Time Time::operator+(const Time& D)const
    {
        Time temp;
        temp.m_min = m_min + D.m_min;
        return temp;
    }

    Time& Time::operator=(unsigned int val)
    {
        m_min = val;
        return *this;
    }

    Time& Time::operator *= (unsigned int val)
    {
        m_min *= val;
        return *this;
    }

    Time Time::operator *(unsigned int val) const
    {
        Time temp;
        temp.m_min = m_min * val;
        return temp;
    }

    Time& Time::operator /= (unsigned int val)
    {
        m_min /= val;
        return *this;
    }

    Time Time::operator /(unsigned int val)const
    {
        Time temp;
        temp.m_min = m_min / val;
        return temp;
    }

    Time::operator int()const
    {
        return (int)m_min;
    }

    Time::operator unsigned int()const
    {
        return m_min;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {
        D.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Time& D)
    {
        D.read(istr);
        return istr;
    }
}