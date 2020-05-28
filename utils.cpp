#include "utils.h"
#include "utils.h"

void gotoXY(int x, int y)      //�趨���λ��
{
	COORD c;   //���λ��
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//��ȡ���������λ��
	showCursor(false);   //ȡ�������˸
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
	CONSOLE_CURSOR_INFO cci;   //����̨�����Ϣ�ṹ����
	cci.dwSize = 1;   //����С
	cci.bVisible = isShow;      //�Ƿ���ʾ���  true��ʾ
	SetConsoleCursorInfo(hOutStd, &cci);   //���ÿ���̨��Ļ����С�Ϳɼ���
}
void setEnglish() {        //���뷨�л�ΪӢ������״̬
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}
void gotoWeb(const char* str)
{
	ShellExecute(NULL, "open", str, NULL,NULL,SW_SHOWNORMAL);
}