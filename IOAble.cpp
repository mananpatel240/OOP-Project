//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp
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

#include "utils.h"
#include "IOAble.h"
#include <cstring>
using namespace std;
namespace sdds
{
	istream& operator>>(istream& ist, IOAble& obj)
	{
		return obj.read(ist);
	}

	ostream& operator<<(ostream& ost, const IOAble& obj)
	{
		return obj.write(ost);
	}
}