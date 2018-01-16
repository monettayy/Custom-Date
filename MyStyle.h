#ifndef MYSTYLE_H
#define MYSTYLE_H

#include <string>

using namespace std;

class MyStyle
{
    public:
        MyStyle();

        static void fullScreen();
        static void titleText(string);
        static void centerText(string);
        static void centerText(string, int);
        static void centerTextAsk(string);
        static void centerTextAsk(string, int);
        static void printLine();

        virtual ~MyStyle();

    protected:

    private:
};

#endif // MYSTYLE_H

