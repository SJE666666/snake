#include <time.h>
#include "pch.h"
#include <stdlib.h>
#include "food.h"

food::food()
{

}

food::~food()
{

}

void food::CreatPos()
{
	
	srand((int)time(0));//(n-m+1)+m
	a_x = KLEFT + 1 + rand() % (KWIDTH - 2);
	a_y = KUP + (KHEIGHT / 10) + rand() % (KHEIGHT - 2);
	
}