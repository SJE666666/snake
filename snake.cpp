#include "pch.h"
#include "snake.h"
#include <conio.h>


snake::snake(int x,int y,int len,int speed,Dir dir,char pic)
{
	s_Headx = x;
	s_Heady = y;
	s_Lenth = len;
	s_Speed = speed;
	s_dir = dir;

	for (int i=0; i < s_Lenth; i++)
	{
		unit myunit(s_Headx, s_Heady, pic);
		s_Body.push_back(myunit);
		switch (dir)
		{
		case UP:
			s_Body[i].a_x = s_Headx;
			s_Body[i].a_y = s_Heady+i;
			break;
		case KDOWN:
			s_Body[i].a_x = s_Headx; 
			s_Body[i].a_y = s_Heady-i;
			break;
		case LEFT:
			s_Body[i].a_x = s_Headx+i; 
			s_Body[i].a_y = s_Heady;
			break;
		case KRIGHT:
			s_Body[i].a_x = s_Headx-i;
			s_Body[i].a_y = s_Heady;
			break;
		
		}
	}
}


snake::~snake()
{
}

void snake::showSnake()
{
	for (int i = 0; i < s_Lenth; i++)
	{
		s_Body[i].show();
	}
}
void snake::eraseSnake()
{
	for (int i = 0; i < s_Lenth; i++)
	{
		s_Body[i].erase();
	}
}
bool snake::eat(food *my)
{
	if (s_Body[0].a_x == my->a_x && s_Body[0].a_y == my->a_y)
	{
		return true;
	}
	return false;
}
void snake::growup()
{
		unit myunit(s_Headx, s_Heady, '*');
		s_Body.push_back(myunit);
		s_Lenth++;

}
void snake::move()
{
	
	for (int i = s_Lenth-1; i > 0; i--)
	{
		s_Body[i].a_x = s_Body[i - 1].a_x;
		s_Body[i].a_y = s_Body[i - 1].a_y;
	}
	switch (s_dir)
	{
	case UP:
		s_Body[0].a_y--;
		break;
	case KDOWN:
		s_Body[0].a_y++;
		break;
	case LEFT:
		s_Body[0].a_x--;
		break;
	case KRIGHT:
		s_Body[0].a_x++;
		break;
	}
	showSnake();
	Sleep(s_Speed);
	eraseSnake();
}
void snake::movebody(int ch)
{
	switch (ch)
	{
	case 72:
		if (s_dir == LEFT || s_dir == KRIGHT)//判断方向是否可以移动
		{
			s_dir = UP;
		}
		break;
	case 80:
		if (s_dir == LEFT || s_dir == KRIGHT)
		{
			s_dir = KDOWN;
		}
		break;
	case 75:
		if (s_dir == UP || s_dir == KDOWN)
		{
			s_dir = LEFT;
		}
		break;
	case 77:
		if (s_dir == UP || s_dir == KDOWN)
		{
			s_dir = KRIGHT;
		}
		break;
	}
}
bool snake::gameover()
{
	int i = 1;
	if (s_Body[0].a_x == KLEFT || s_Body[0].a_x == KLEFT + KWIDTH || s_Body[0].a_y == KUP + (KHEIGHT / 10) || s_Body[0].a_y == KUP + KHEIGHT)
	{
		return true;
	}
	for(int i=1;i<s_Lenth-1;i++)
	{
		if (s_Body[0].a_x == s_Body[i].a_x && s_Body[0].a_y == s_Body[i].a_y)
		{
			return true;
		}
	}
	return false;
}
void snake::speed()
{
	s_Speed = s_Speed - 1;
}
void snake::rsnake(int speed,Dir dir)
{
	s_Headx = (KLEFT + KWIDTH) / 2;
	s_Heady = (KUP + KHEIGHT) / 2;
	s_Lenth = 5;
	s_Speed = speed;
	s_dir = dir;

		for (int i = 0; i < s_Lenth; i++)
		{
			unit myunit(s_Headx, s_Heady,dir );
			s_Body.push_back(myunit);
			switch (dir)
			{
			case UP:
				s_Body[i].a_x = s_Headx;
				s_Body[i].a_y = s_Heady + i;
				break;
			case KDOWN:
				s_Body[i].a_x = s_Headx;
				s_Body[i].a_y = s_Heady - i;
				break;
			case LEFT:
				s_Body[i].a_x = s_Headx + i;
				s_Body[i].a_y = s_Heady;
				break;
			case KRIGHT:
				s_Body[i].a_x = s_Headx - i;
				s_Body[i].a_y = s_Heady;
				break;
			}
		}
}
bool snake::chfood(food *my)
{
	for (int i = 1; i < s_Lenth - 1; i++)
	{
		if (s_Body[i].a_x == my->a_x && s_Body[i].a_y == my->a_y)
		{
			return true;
		}
		return false;
	}
}
