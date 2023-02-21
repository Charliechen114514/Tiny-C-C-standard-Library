#define _CRT_SECURE_NO_WARNINGS 1
#include"Structure.h"
#include<stdio.h>

void randInitFoodPos(Food* pfood)
{
	srand((unsigned int)time(NULL));
	pfood->foodXY.x = rand() % 650 * (rand() % 30) / 30;
	pfood->foodXY.y = rand() % 480;
	pfood->whetherFoodExist = TRUE;
}
void randInitLWFoodPos(LoseWeightFood* pLWFood) 
{
	srand((unsigned int)time(NULL));
	pLWFood->loseWeightFoodXY.x = rand() % 650;
	pLWFood->loseWeightFoodXY.y = rand() % 480;
	pLWFood->whetherLWF_Exist = TRUE;
}