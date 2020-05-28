#include <Windows.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#ifndef _UTILS_H_
#define _UTILS_H_

void gotoXY(int x, int y);
void gotoWeb(const char* str);
void color(int a);
void setWindows(int cols, int lines);
void showCursor(bool isShow);
void setEnglish();

#endif