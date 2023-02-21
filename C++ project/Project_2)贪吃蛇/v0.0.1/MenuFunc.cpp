#define _CRT_SECURE_NO_WARNINGS 1
#include"Structure.h"
#include<stdio.h>

#define DEFAULT 100
#define SLOW 50
#define FAST 20   

//MenuFunctions
void menu() {
	puts("----------------------------------------------------------------------------");
	puts("请选择你想要的难度！");
	puts("0:正常 1.放慢 2.加速 3.自定义");
	puts("----------------------------------------------------------------------------");
}

int chooseSpeed(int input)
{
	switch (input)
	{
	case 0: return DEFAULT;
	case 1: return SLOW;
	case 2: return FAST;
	default:return input;
	}
}