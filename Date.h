#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

using namespace std;

class Date
{
    public:
        Date();
        Date(int, int, int);
        Date(string);

        void setDayNumber(int, int, int);
        void setDayNumber(string);
        void setDayNumber(int d)        { _dayNumber = d; }
        int getDayNumber()              { return _dayNumber; }

        static string askDate();
        int toAbsoluteDayNumber(int, int, int);
        int toAbsoluteDayNumber(string);
        void toIntArr(int [3], string);
        void toString(int *, int *, int *);
        bool validateDate(int, int, int);
        int dayOfWeek();
        string dayOfWeekToString();

        friend ostream& operator << (ostream&, const Date&);
        virtual ~Date();

    protected:

    private:
        int _dayNumber;

        const int YEAR_START = 1950;
        const int YEAR_END = 2025;

        bool isLeapYear(int);
};

#endif // DATE_H

