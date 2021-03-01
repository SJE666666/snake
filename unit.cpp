#include "pch.h"
#include "unit.h"
#include <iostream>
const int unit::KWIDTH = 60;
const int unit::KHEIGHT = 30;
const int unit::KUP = 5;
const int unit::KLEFT = 10;


unit::unit(int x,int y,char pic)
{
	a_x=x;
	a_y=y;
	a_pic=pic;
}


unit::~unit()
{
}
void unit:: show()//显示函数
{
	gotoxy(a_x, a_y);
	cout << a_pic;
}
void unit:: erase()//擦除函数
{
	gotoxy(a_x, a_y);
	cout << " ";
}
void unit::gotoxy(int x,int y)//找到指定坐标
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);//STD为固定参数：
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}