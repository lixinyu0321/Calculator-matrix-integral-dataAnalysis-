#include "utils.h"
#include "utils.h"

void gotoXY(int x, int y)      //设定输出位置
{
	COORD c;   //光标位置
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//获取句柄，设置位置
	showCursor(false);   //取消光标闪烁
}
void color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
void setWindows(int cols, int lines) {
	system("title Calculator");
	char ch[30];
	sprintf_s(ch, "mode con cols=%d lines=%d", cols, lines);
	system(ch);
}
void showCursor(bool isShow) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;   //控制台光标信息结构类型
	cci.dwSize = 1;   //光标大小
	cci.bVisible = isShow;      //是否显示光标  true显示
	SetConsoleCursorInfo(hOutStd, &cci);   //设置控制台屏幕光标大小和可见性
}
void setEnglish() {        //输入法切换为英文输入状态
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}
void gotoWeb(const char* str)
{
	ShellExecute(NULL, "open", str, NULL,NULL,SW_SHOWNORMAL);
}