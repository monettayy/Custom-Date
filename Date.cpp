#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>

#include "Date.h"
#include "MyStyle.h"

using namespace std;

string days[] = {"Monday", "Tuesday", "Wednesday",
                 "Thursday", "Friday", "Saturday", "Sunday"};
string months[] = {"January", "February", "March", "April",
                   "May", "June", "July", "August", "September",
                   "October", "November", "December"};
int maxDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date()
{
    setDayNumber(1);
}

Date::Date(int mm, int dd, int yy)
{
    setDayNumber(mm, dd, yy);
}

Date::Date(string mmddyy)
{
    setDayNumber(mmddyy);
}

void Date::setDayNumber(int mm, int dd, int yy)
{
    bool valid = validateDate(mm, dd, yy);

    if(valid)
        setDayNumber(toAbsoluteDayNumber(mm, dd, yy));
    else
        setDayNumber(1);
}

void Date::setDayNumber(string mmddyy)
{
    int numArr[] = {0, 0, 0};
    toIntArr(numArr, mmddyy);

    setDayNumber(numArr[0], numArr[1], numArr[2]);
}

string Date::askDate()
{
    string input;
    MyStyle::centerTextAsk("Input date: [MM/DD/YYYY] ", 34);
    cin >> input;
    return input;
}

int Date::toAbsoluteDayNumber(int mm, int dd, int yy)
{
    int yCtr=0, mCtr=0, dayCtr=0;

    for(yCtr=YEAR_START; yCtr<=yy; yCtr++)
    {
        int maxMM = yCtr == yy ? mm : 12;
        for(mCtr=0; mCtr<maxMM; mCtr++)
        {
            bool isLastMonth = yCtr == yy && mCtr == mm-1;
            dayCtr += isLastMonth ? dd : maxDays[mCtr];
        }

        if(isLeapYear(yCtr) && yCtr != yy)
            dayCtr++;
    }

    bool isMMGreaterFeb = mCtr > 2 || (mCtr == 2 && dd == 29);
    if(isLeapYear(yCtr) && yCtr == yy && isMMGreaterFeb)
        dayCtr++;

    return dayCtr;
}

void Date::toIntArr(int numArr[3], string date)
{
    string delim = "/";

    for(int i=0; i<3; i++)
    {
        string s = date.substr(0, date.find(delim));
        numArr[i] = atoi(s.c_str());
        date = date.substr(date.find(delim)+1, date.length());
    }
}

void Date::toString(int *mm, int *dd, int *yy)
{
    int dayCtr = 0;
    int yCtr, mCtr, dCtr;

    for(yCtr=YEAR_START; yCtr<=YEAR_END; yCtr++)
    {
        for(mCtr=0; mCtr<12; mCtr++)
        {
            int maxDD = isLeapYear(yCtr) && mCtr == 1 ? maxDays[mCtr]+1 : maxDays[mCtr];
            for(dCtr=0; dCtr<maxDD ; dCtr++)
            {
                dayCtr++;
                if(dayCtr == _dayNumber)
                {
                    *mm = mCtr+1;
                    bool isMMGreaterFeb = mCtr > 1 || (mCtr == 1 && dCtr == 29);
                    *dd = isLeapYear(yCtr) && isMMGreaterFeb ? dCtr+2 : dCtr+1;
                    *yy = yCtr;
                    return;
                }
            }
        }
    }
}

bool Date::isLeapYear(int year)
{
    bool isDivBy4 = year % 4 == 0;
    bool isDivBy100 = year % 100 == 0;
    bool isDivBy400 = year % 400 == 0;

    if((isDivBy4 && !isDivBy100) || (isDivBy4 && isDivBy400))
        return true;
    else
        return false;
}

bool Date::validateDate(int mm, int dd, int yy)
{
    bool isMonthValid = false;
    bool isDayValid = false;
    bool isYearValid = false;

    if(mm > 0 && mm < 13)
        isMonthValid = true;

    bool isNotLY = !isLeapYear(yy) && dd <= maxDays[mm-1];
    bool isLYFeb = isLeapYear(yy) && mm == 2 && dd <= 29;
    bool isLYNotFeb = isLeapYear(yy) && mm != 2 && dd <= maxDays[mm-1];

    if(dd > 0 && (isNotLY || (isLYFeb || isLYNotFeb)))
        isDayValid = true;

    if(yy >= YEAR_START && yy <= YEAR_END)
        isYearValid = true;

    return isMonthValid && isDayValid && isYearValid;
}

int Date::dayOfWeek()
{
    int i;
    for(i=_dayNumber; i>7; i-=7){}

    return i <= 1 ? 7 : i-1;
}

string Date::dayOfWeekToString()
{
    int dow = dayOfWeek();
    return days[dow-1];
}

ostream& operator << (ostream& os, const Date& date)
{
    int mm=0, dd=0, yy=0;
    Date d = date;
    d.toString(&mm, &dd, &yy);

    os << mm << "/" << dd  << "/" << yy;
    return os;
}

Date::~Date()
{
    //dtor
}

