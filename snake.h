#pragma once
#include<vector>
#include "unit.h"
#include "food.h"
typedef enum Dir
{
	UP,KDOWN,LEFT,KRIGHT
};
class snake :
	public unit
{
public:
	int s_Headx;
	int s_Heady;
	int s_Speed;
	int s_Lenth;
	Dir s_dir;
	int ch;
	vector <unit> s_Body;
public:
	snake(int x=(KLEFT+KWIDTH)/2,int y=(KUP+KHEIGHT)/2,int len=5,int speed=100,Dir dir=KRIGHT,char pic='*');
	~snake();
	void showSnake();
	void eraseSnake();
	void move();
	void movebody(int key);
	void growup();
	bool eat(food *my);
	bool chfood(food *my);
	void rsnake(int speed,Dir dir);
	bool gameover();
	void speed();
};

