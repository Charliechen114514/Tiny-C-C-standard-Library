#define _CRT_SECURE_NO_WARNINGS 1
#include"Structure.h"
void moveSnake(Snake* psnake)
{
	//分批次处理：
	//使用For递归处理2~N节数 的蛇
	for (int i = psnake->segmentSize - 1; i > 0; i--)
	{
		psnake->segPlace[i].x = psnake->segPlace[i - 1].x;
		psnake->segPlace[i].y = psnake->segPlace[i - 1].y;
	}
	switch (psnake->direction)
	{
		//72上 80下 75左 77右
		case 77:psnake->segPlace[0].x += 10; break;
		case 75:psnake->segPlace[0].x -= 10; break;
		case 80:psnake->segPlace[0].y += 10; break;
		case 72:psnake->segPlace[0].y -= 10; break;
		default:break;
	}
	if (psnake->segPlace[0].x > 640)
	{
		psnake->segPlace[0].x = 0;
	}
	if (psnake->segPlace[0].x < 0)
	{
		psnake->segPlace[0].x = 640;
	}
	if (psnake->segPlace[0].y > 480)
	{
		psnake->segPlace[0].y = 0;
	}
	if (psnake->segPlace[0].y < 0)
	{
		psnake->segPlace[0].y = 480;
	}

}

void eatLWFood(Snake* psnake, LoseWeightFood* plossfood)
{
	if (psnake->segPlace[0].x - plossfood->loseWeightFoodXY.x<10 && psnake->segPlace[0].y - plossfood->loseWeightFoodXY.y<10 && psnake->segPlace[0].x - plossfood->loseWeightFoodXY.x > -10 && psnake->segPlace[0].y - plossfood->loseWeightFoodXY.y >-10)
	{
		psnake->segmentSize--;
		plossfood->score += 100;
		plossfood->whetherLWF_Exist = false;
	}
}


int eatFood(Snake* psnake, Food* pfood, int count)
{
	srand((unsigned)time(NULL));
	if (psnake->segPlace[0].x - pfood->foodXY.x<10 && psnake->segPlace[0].y - pfood->foodXY.y<10 && psnake->segPlace[0].x - pfood->foodXY.x > -10 && psnake->segPlace[0].y - pfood->foodXY.y >-10)
	{
		psnake->segmentSize++;
		pfood->score += 10;
		pfood->whetherFoodExist = false;
		return count + 1;
	}
}

void keyReact(Snake* psnake)
{
	char key = 0;
	key = _getch();
	switch (key)
	{
	case RIGHT:
		if (psnake->direction != LEFT)
		{
			psnake->direction = RIGHT;//禁止掉头
		}
		break;
	case LEFT:
		if (psnake->direction != RIGHT)
		{
			psnake->direction = LEFT;//禁止掉头
		}
		break;
	case UP:
		if (psnake->direction != DOWN)
		{
			psnake->direction = UP;//禁止掉头
		}
		break;
	case DOWN:
		if (psnake->direction != UP)
		{
			psnake->direction = DOWN;//禁止掉头
		}
		break;
	default: break;
	}
}