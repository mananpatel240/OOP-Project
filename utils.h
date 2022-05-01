//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: utils
Filename: utils.h
Version 5.0
Author	Manan Patel
Revision History
-----------------------------------------------------------
Date      Reason
2021/03/07  Preliminary release
2021/03/16  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds
{
    extern bool debug;
    int getTime();
    int getInt(const char* prompt = nullptr);

    int getInt(
        int min,
        int max,
        const char* prompt = nullptr,
        const char* errorMessage = nullptr,
        bool showRangeAtError = true
    );

    char* getcstr(
        const char* prompt = nullptr,   // User entry prompt
        std::istream& istr = std::cin,  // the Stream to read from
        char delimiter = '\n'    // Delimiter to mark the end of data
    );

    template <typename type>
    void removeDynamicElement(type* array[], int index, int& size) {
        delete array[index];
        for (int j = index; j < size; j++) {
            array[j] = array[j + 1];
        }
        size--;
    }

}
#endif // !SDDS_UTILS_H_

