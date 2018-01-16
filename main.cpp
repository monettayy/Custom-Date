#include <iostream>

#include "Date.h"
#include "MyStyle.h"

using namespace std;

int main()
{
    MyStyle::fullScreen();
    MyStyle::titleText("CUSTOM DATE");

    MyStyle::printLine();

    MyStyle::centerText("Using default ctor:");
    Date d1;
    MyStyle::centerTextAsk("", 6);
    cout << d1 << endl;
    MyStyle::centerTextAsk("Day of the week number: ");
    cout << d1.dayOfWeek() << endl;
    MyStyle::centerTextAsk("Day of the week string: ");
    cout << d1.dayOfWeekToString() << endl << endl;

    MyStyle::centerText("Using non-default ctor with 3 arguments:");
    Date d2(12, 3, 2014);
    MyStyle::centerTextAsk("", 6);
    cout << d2 << endl;
    MyStyle::centerTextAsk("Day of the week number: ");
    cout << d2.dayOfWeek() << endl;
    MyStyle::centerTextAsk("Day of the week string: ");
    cout << d2.dayOfWeekToString() << endl << endl;

    MyStyle::centerText("Using non-default ctor taking string:");
    Date d3("3/2/1996");
    MyStyle::centerTextAsk("", 6);
    cout << d3 << endl;
    MyStyle::centerTextAsk("Day of the week number: ");
    cout << d3.dayOfWeek() << endl;
    MyStyle::centerTextAsk("Day of the week string: ");
    cout << d3.dayOfWeekToString() << endl;

    MyStyle::printLine();

    do{
        Date d4(Date::askDate());
        MyStyle::centerTextAsk("", 6);
        cout << d4 << endl;
        MyStyle::centerTextAsk("Day of the week number: ");
        cout << d4.dayOfWeek() << endl;
        MyStyle::centerTextAsk("Day of the week string: ");
        cout << d4.dayOfWeekToString() << endl;

        MyStyle::printLine();
    }while(1);
}

