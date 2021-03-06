#include "stat.h"
#include "matrix_cal.h"
#include "regress.h"
#include "utils.h"
#include "basic_cal.h"
#include "calculus.h"

int main()
{
	//color(10); //7灰白色 10绿色 11蓝色 12红色 13紫色 14黄色

	setWindows(200,60);
	setEnglish();
	ShowCursor(false);
	char ch;
	while (1)
	{
		color(10);       // 主界面绿色
		gotoXY(80, 13);
		cout << "              一个不错的计算器            " << endl;
		gotoXY(80, 15);
		cout << "       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
		gotoXY(80, 17);
		cout << "     -----* - * - * - * - * - * - *----   " << endl;
		gotoXY(80, 19);
		cout << "   《  ▁▁▁▁▁▁▁▁▁▁▁▁▁▁   》     " << endl;
		gotoXY(80, 20);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 21);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 22);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 23);
		cout << "   《  ▏       1.矩阵计算         ▏ 》     " << endl;
		gotoXY(80, 24);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 25);
		cout << "   《  ▏       2.基础计算         ▏ 》     " << endl;
		gotoXY(80, 26);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 27);
		cout << "   《  ▏       3.微积分           ▏ 》     " << endl;
		gotoXY(80, 28);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 29);
		cout << "   《  ▏       4.数据统计         ▏ 》     " << endl;
		gotoXY(80, 30);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 31);
		cout << "   《  ▏       5.说明文档         ▏ 》     " << endl;
		gotoXY(80, 32);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 33);
		cout << "   《  ▏       6.开发人员介绍     ▏ 》     " << endl;
		gotoXY(80, 34);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 35);
		cout << "   《  ▏       7.退出             ▏ 》     " << endl;
		gotoXY(80, 36);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 37);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 38);
		cout << "   《  ▏                          ▏ 》     " << endl;
		gotoXY(80, 39);
		cout << "   《  ▔▔▔▔▔▔▔▔▔▔▔▔▔▔   》     " << endl;
		gotoXY(80, 41);
		cout << "     -----* - * - * - * - * - * - *----   " << endl;
		gotoXY(80, 43);
		cout << "       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
		gotoXY(80, 45);
		cout << "请输入的你的操作选项：";
		cin >> ch;

		if (ch == '1')
		{
			system("cls");
			//color(11);

			myMatrix a;
			a.mat_run();

			system("pause");
			system("cls");
			continue;
		}


		else if (ch == '2')
		{
			system("cls");
			
			basic_cal_display();

			system("pause");
			system("cls");
			continue;
		}


		else if (ch == '3')//待完善
		{
			system("cls");

			getchar();
			calculus_display();
			//derivative_trigonometric();

			system("pause");
			system("cls");
			continue;
		}
		else if (ch == '4') 
		{
			system("cls");
			getchar();
			color(11);
			stat_run();

			system("pause");
			system("cls");
			continue;
		}
		else if (ch == '5')
		{
			system("cls");
			color(14);

			gotoWeb("www.github.com/lixinyu0321/sneaky-snake-with-music-");
			gotoXY(92, 12);
			cout<<"请给颗星星吧！谢谢啦！"<<endl; 
			gotoXY(95, 20);
			system("pause");
			system("cls");
			continue;
		}
		else if (ch == '6') 
		{
			system("cls");
			color(7);

			gotoXY(80, 20);
			cout << "     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
			gotoXY(80, 22);
			cout << "               C H E E R S !            " << endl;
			gotoXY(80, 24);
			cout << "     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
			gotoXY(80, 26);
			cout << "     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
			gotoXY(80, 28);
			cout << "       开发者名单（排名不分先后）       " << endl;
			gotoXY(80, 30);
			cout << "     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
			gotoXY(80, 32);
			cout << "                黄千驰                  " << endl;
			gotoXY(80, 35);
			cout << "                王紫泫                  " << endl;
			gotoXY(80, 38);
			cout << "                 马赛                   " << endl;
			gotoXY(80, 41);
			cout << "                李新宇                  " << endl;
			gotoXY(80, 44);
			cout << "     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     " << endl;
			gotoXY(80, 47);
			system("pause");
			system("cls");
		}
		
		else if (ch == '7')
		{
			system("cls");
			exit(0);
		}
		else
		{
			system("cls");
			gotoXY(95, 10);
			color(13);
			cout << "请重新输入！" << endl;
			continue;
		}
	}
}


