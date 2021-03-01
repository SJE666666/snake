#include "pch.h"
#include "unit.h"
#include "food.h"
#include "snake.h"
#include "WinUser.h"
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <iostream>
#include <windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
int score = 0;
int leve = 1;

void area();
void gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}
int main()
{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

	food my;	
	snake mysnake;
	my.CreatPos();
	while (mysnake.chfood(&my))
	{ 
		my.CreatPos();	

		break;
	}
		my.show();
	area();
	int key;
	

	while (true)
	{
			mysnake.move();

			if (_kbhit())//如果有按键按下，则_kbhit()函数返回真
			{
				key = _getch();
				if (key = 224)//改进停顿
				{
					key = _getch();//使用_getch()函数获取按下的键值
				}

				mysnake.movebody(key);//调用到方向更改函数
			}

			if (mysnake.eat(&my))
			{
				score = score + 10;
				if (score % 50 == 0)
				{
					leve++;
				}

				mysnake.speed();
				mysnake.growup();
				my.CreatPos();
				if (mysnake.chfood(&my))
					my.CreatPos();
				my.show();
				area();
			}
			if (mysnake.gameover())
			{
				PlaySound(TEXT("C:\\Users\\Lenovo\\Desktop\\2.wav"), NULL, SND_FILENAME | SND_ASYNC);
				int i = MessageBox(NULL, TEXT("小老板多捞哦~再来一把？"), TEXT("游戏结束"), MB_YESNO);
				if (i == IDNO)
				{
					int i = MessageBox(NULL, TEXT("不会吧不会吧,不会真有人就放弃了吧？"), TEXT("游戏结束"), MB_YESNO);
					if (i == IDYES)
					{
						int i = MessageBox(NULL, TEXT("彳亍"), TEXT("游戏结束"), MB_YESNO == IDYES);
						system("cls");
						system("pause");
					}
					if (i == IDNO)
					{

						score = 0;
						leve = 1;
						mysnake.rsnake(100, UP);
						my.erase();
						my.CreatPos();
						my.show();
						area();
						PlaySound(TEXT("C:\\Users\\Lenovo\\Desktop\\1.wav"), NULL, SND_FILENAME | SND_ASYNC);
					}
				}
				if (i == IDYES)
				{

					score = 0;
					leve = 1;
					mysnake.rsnake(100, UP);
					my.erase();
					my.CreatPos();
					my.show();
					if (mysnake.eat(&my))
					{
						score = score + 10;
						if (score % 50 == 0)
						{
							leve++;
						}

						mysnake.speed();
						mysnake.growup();
						my.CreatPos();
						if (mysnake.chfood(&my))
							my.CreatPos();
						my.show();
						area();
					}
					PlaySound(TEXT("C:\\Users\\Lenovo\\Desktop\\1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
		}
	PlaySound(TEXT("C:\\Users\\Lenovo\\Desktop\\1.wav"), NULL, SND_FILENAME | SND_LOOP);
	}



void area()//界面实现
{
	const int KWIDTH = 60;
	const int KHEIGHT = 30;
	const int KUP = 5;
	const int KLEFT = 10;
	gotoxy(KLEFT, KUP);//第一行
	for (int i = KLEFT; i < KLEFT + KWIDTH; i++)
	{
		cout << '-';
	}
	gotoxy(KLEFT, KUP + (KHEIGHT / 10));//中间行
	for (int i = KLEFT; i < KLEFT + KWIDTH; i++)
	{
		cout << '-';
	}
	gotoxy(KLEFT + 1, KUP + (KHEIGHT / 15));
	cout << "游戏名：贪吃蛇";
	gotoxy(KLEFT + (KWIDTH / 3), KUP + (KHEIGHT / 15));
	cout << "编写者：尹瑞麟";
	gotoxy(KLEFT + (KWIDTH / 3) * 2, KUP + (KHEIGHT / 15));
	cout << "关卡：" << leve << "   " << "得分:" << score;
	gotoxy(KLEFT, KUP + KHEIGHT);//最后一行
	for (int i1 = KLEFT; i1 < KLEFT + KWIDTH; i1++)
	{
		cout << '-';
	}
	gotoxy(KLEFT, KUP + 1);//左边
	for (int y = KUP; y < KUP + KHEIGHT; y++)
	{
		gotoxy(KLEFT, y + 1);
		cout << '|' << '\n';
	}
	gotoxy(KLEFT + KWIDTH, KUP + 1);//右边
	for (int y1 = KUP; y1 < KUP + KHEIGHT; y1++)
	{
		gotoxy(KLEFT + KWIDTH, y1 + 1);
		cout << '|' << '\n';
	}
}//界面
//界面实现

