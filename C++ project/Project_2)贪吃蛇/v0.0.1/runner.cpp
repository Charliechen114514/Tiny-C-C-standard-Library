#define _CRT_SECURE_NO_WARNINGS 1
#include"Structure.h"
int judge = MOVE_ON;
int total_score = 0;
int input_game_start = 0;
int count = 0;
Snake snake1;
Food food1;
LoseWeightFood lossfood1;
int main()
{
	menu();
	puts("请输入你想要的速度：>");
	//scanf_s("%d", &input_game_start);
	int input = chooseSpeed(input_game_start);
	//getchar();
	randInitFoodPos(&food1);
	randInitLWFoodPos(&lossfood1);
	food1.whetherFoodExist = true;
	lossfood1.whetherLWF_Exist = false;
	initBackGround();
	cleardevice();
	initSnake(&snake1);
	IMAGE pic;
	loadimage(&pic, _T(PATH), 640, 480);
	while (judge == MOVE_ON)
	{
		cleardevice();
		putimage(0, 0, &pic);
		if (!food1.whetherFoodExist)
		{
			randInitFoodPos(&food1);
		}
		drawFood(&food1);
		if (count == 1 || count % 10 == 0)
		{
			if (!lossfood1.whetherLWF_Exist)
			{
				randInitLWFoodPos(&lossfood1);
			}
		}
		if (lossfood1.whetherLWF_Exist)
		{
			drawLWFood(&lossfood1);
		}
		eatLWFood(&snake1, &lossfood1);
		count = eatFood(&snake1, &food1, count);
		drawSnake(&snake1);
		while (_kbhit())
		{
			keyReact(&snake1);
		}
		moveSnake(&snake1);
		judge = deathJudge(&snake1);
		Sleep(input);
		total_score = food1.score + lossfood1.score;
	}
	closegraph();
	printf("你得到了分数！：%d\n", food1.score + lossfood1.score);
	printf("敲击q退出游戏！\n");
	char quit = 0;
	while (quit != 'q') {
		scanf("%c", &quit);
		getchar();
	}
	return 0;
}