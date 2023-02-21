#define _CRT_SECURE_NO_WARNINGS 1
#include"Structure.h"
#include<stdio.h>

void initBackGround()
{
	IMAGE pic;
	initgraph(640, 480);
	loadimage(&pic, _T("D:/Clion/default.png"),640,480);
	putimage(0, 0, &pic);
	
}
void initSnake(Snake* psnake)
{
	psnake->segPlace[2].x = 20;
	psnake->segPlace[2].y = 0;
	psnake->segPlace[1].x = 30;
	psnake->segPlace[1].y = 0;
	psnake->segPlace[0].x = 40;
	psnake->segPlace[0].y = 0;
	psnake->segmentSize = 3;
	psnake->direction = right;
}