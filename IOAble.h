//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.h
Version 5.0
Author	Manan Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/03/17  Preliminary release
2021/03/22  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
namespace sdds
{
    class IOAble
    {
    public:
        virtual std::ostream& csvWrite(std::ostream&) const = 0;
        virtual std::istream& csvRead(std::istream&) = 0;
        virtual std::ostream& write(std::ostream&) const = 0;
        virtual std::istream& read(std::istream&) = 0;
        virtual ~IOAble() {};
    };
    std::ostream& operator<<(std::ostream& ost, const IOAble& obj);
    std::istream& operator>>(std::istream& ist, IOAble& obj);
}
#endif