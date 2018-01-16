#include <iostream>
#include <string>
#include <windows.h>

#include "MyStyle.h"

using namespace std;

MyStyle::MyStyle()
{
    //ctor
}

void MyStyle::fullScreen()
{
    /*** works on laptop or medium screens only ***/
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void MyStyle::titleText(string prompt)
{
    centerText("");
    centerText("***************************");
    centerText(prompt);
    centerText("***************************");
    cout << endl;
}

void MyStyle::centerText(string line)
{
    centerText(line, line.length());
}

void MyStyle::centerText(string line, int len)
{
    centerTextAsk(line, len);
    cout << endl;
}

void MyStyle::centerTextAsk(string line)
{
    centerTextAsk(line, line.length() + 1);
}

void MyStyle::centerTextAsk(string line, int len)
{
    /*** print at the center of the console ***/
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int winWidth = csbi.srWindow.Right - csbi.srWindow.Left; //get screen width
    int pos = (int)((winWidth - len) / 2);
    for(int i=0; i<pos; i++) //print spaces before the target position
        cout << " ";
    cout << line;
}

void MyStyle::printLine()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int winWidth = csbi.srWindow.Right - csbi.srWindow.Left; //get screen width
    int pos = (int)(winWidth / 2);
    string line;
    for(int i=0; i<pos; i++)
        line += "-";

    centerTextAsk(line, line.length());
    cout << endl;
}

MyStyle::~MyStyle()
{
    //dtor
}

