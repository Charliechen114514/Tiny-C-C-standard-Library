#define _CRT_SECURE_NO_WARNINGS 1
#include"Structure.h"


void drawSnake(Snake* psnake)
{
	for (int i = 0; i < psnake->segmentSize; i++)
	{
		setlinecolor(YELLOW);//±ß¿òÉ«
		setfillcolor(RED);
		fillrectangle(psnake->segPlace[i].x, psnake->segPlace[i].y, psnake->segPlace[i].x + 10, psnake->segPlace[i].y + 10);
	} 
}
void drawFood(Food* pfood)
{
	setlinecolor(RED);//±ß¿òÉ«
	setfillcolor(YELLOW);
	solidcircle(pfood->foodXY.x, pfood->foodXY.y, 5);
}
void drawLWFood(LoseWeightFood* LWFood)
{
	setlinecolor(GREEN);//±ß¿òÉ«
	setfillcolor(GREEN);
	solidcircle(LWFood->loseWeightFoodXY.x, LWFood->loseWeightFoodXY.y, 5);
}