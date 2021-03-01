#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class unit
{
public:
	unit(int x = 0, int y = 0, char pic = '+');
	~unit();
	void show();
	void erase();
	static void gotoxy(int x, int y);

public:
	const static int KLEFT;
	const static int KUP;
	const static int KWIDTH;
	const static int KHEIGHT;
	int a_x;
	int a_y;
	char a_pic;
};