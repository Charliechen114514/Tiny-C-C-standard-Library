#define _CRT_SECURE_NO_WARNINGS 1
#include"Structure.h"

int deathJudge(Snake* psnake)
{
	for (int i = 1; i < psnake->segmentSize; i++)
	{
		if (psnake->segPlace[0].x == psnake->segPlace[i].x && psnake->segPlace[0].y == psnake->segPlace[i].y )//
		{
			return QUIT;
		}
	}
	return MOVE_ON;
}