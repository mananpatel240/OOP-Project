//Name - Manan Patel
//Email - mspatel45@myseneca.ca
//Student ID - 148603194

/* Citation and Sources...
Final Project Milestone 5
Module: utils
Filename: utils.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"

using namespace std;

namespace sdds
{
    bool debug = false;
    int getTime()
    {
        int mins = -1;
        if (debug)
        {
            Time t(0);
            cout << "Enter current time: ";
            do
            {
                cin.clear();
                cin >> t;
                if (!cin)
                {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else
                {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt(const char* prompt)
    {
        int flag = 0;
        bool int_found = false, flagNegative = false;
        int num;
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        string line;
        getline(cin, line);
        line = line + '\n';

        while (flag != 2)
        {
            num = 0;
            flagNegative = false;
            int_found = false;
            int i = 0;
            while (line[i])
            {
                if (line[i] == '-')
                {
                    flagNegative = true;
                }
                else if (line[i] < '0' || line[i] > '9')
                {
                    if (!int_found)
                    {
                        flag = 0;
                    }
                    else if (line[i] == '\n')
                    {
                        flag = 2;
                    }
                    else
                    {
                        flag = 1;
                    }
                    break;
                }
                else
                {
                    int_found = true;
                    num = num * 10 + line[i] - '0';
                }
                i++;
            }
            if (flagNegative)
            {
                num = 1 * num;
            }
            if (flag != 2)
            {
                if (flag == 0)
                {
                    cout << "Bad integer value, try again: ";
                }
                else
                {
                    cout << "Enter only an integer, try again: ";
                }
                getline(cin, line);
                line = line + '\n';
            }
        }
        return num;
    }

    int getInt(
        int min,
        int max,
        const char* prompt,
        const char* errorMessage,
        bool showRangeAtError
    )
    {
        int flag = 0;
        bool int_found = false, flagNegative = false;
        int num;
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        string line;
        getline(cin, line);
        line = line + '\n';

        while (flag != 2)
        {
            num = 0;
            flagNegative = false;
            int_found = false;
            int i = 0;
            while (line[i])
            {
                if (line[i] == '-')
                {
                    flagNegative = true;
                }
                else if (line[i] < '0' || line[i] > '9')
                {
                    if (!int_found)
                    {
                        flag = 0;
                    }
                    else if (line[i] == '\n')
                    {
                        flag = 2;
                    }
                    else
                    {
                        flag = 1;
                    }
                    break;
                }
                else
                {
                    int_found = true;
                    num = num * 10 + line[i] - '0';
                }
                i++;
            }
            if (flagNegative)
            {
                num = -1 * num;
            }
            if (flag != 2)
            {
                if (flag == 0)
                {
                    cout << "Bad integer value, try again: ";
                }
                else
                {
                    cout << "Enter only an integer, try again: ";
                }
                getline(cin, line);
                line = line + '\n';
            }
            else if (num < min || num > max)
            {
                flag = 0;
                if (errorMessage != nullptr)
                {
                    cout << errorMessage;
                }
                if (showRangeAtError)
                {
                    cout << "[" << min << " <= value <= " << max << "]: ";
                }
                getline(cin, line);
                line = line + '\n';
            }
        }
        return num;
    }

    char* getcstr(
        const char* prompt,
        std::istream& istr,
        char delimiter
    )
    {
        if (prompt != nullptr)
        {
            cout << prompt;
        }
        string input;
        getline(istr, input);
        int len = input.length();
        char* str = new char[len + 1];
        strcpy(str, input.c_str());
        str[len] = '\0';
        return str;
    }
}