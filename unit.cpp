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
void unit:: show()//��ʾ����
{
	gotoxy(a_x, a_y);
	cout << a_pic;
}
void unit:: erase()//��������
{
	gotoxy(a_x, a_y);
	cout << " ";
}
void unit::gotoxy(int x,int y)//�ҵ�ָ������
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);//STDΪ�̶�������
	COORD position;    // position ��һ�� COORD �ṹ
	position.X = x;
	position.Y = y;
	//�����������Ȼ��ʼ��ӡ
	SetConsoleCursorPosition(screen, position);
}