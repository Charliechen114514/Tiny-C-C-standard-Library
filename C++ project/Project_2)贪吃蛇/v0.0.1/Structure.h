#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_SEGMENT 256
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>


//config
#define QUIT 2
#define MOVE_ON 1
#define PATH "D:/Clion/default.png"

//定义二维平面
typedef struct _PointPlat_ {
	int x;
	int y;
}PointPlat;

//定义蛇这个对象
//
typedef struct _Snake_ {
	size_t segmentSize;				// 定义蛇的节数
	char direction;					// 定义当前蛇的前进方向
	PointPlat segPlace[MAX_SEGMENT];// 定义蛇的段坐标
}Snake;

//食物
//
typedef struct _Food_ {
	PointPlat foodXY;
	int score;
	bool whetherFoodExist;
}Food;

//来点减肥餐
//
typedef struct _LoseWeightFood_ {
	PointPlat loseWeightFoodXY;
	int score;
	bool whetherLWF_Exist;
}LoseWeightFood;

//定义一下方向
//
enum Directions {
	RIGHT = 77,
	LEFT = 75,
	DOWN = 80,
	UP = 72,//对应keypress
};

//Menu函数
void menu();
int chooseSpeed(int input);

//生成食物函数
void randInitFoodPos(Food* pfood);
void randInitLWFoodPos(LoseWeightFood* pLWFood);


//生成地图函数
void initBackGround();
void initSnake(Snake* psnake);

//基于EasyX的绘画函数
void drawSnake(Snake* psnake);
void drawFood(Food* pfood);
void drawLWFood(LoseWeightFood* LWFood);

//对象行为
void moveSnake(Snake* psnake);
int eatFood(Snake* psnake, Food* pfood, int count);
void eatLWFood(Snake* psnake, LoseWeightFood* plossfood);
void keyReact(Snake* psnake);

//游戏判定
int deathJudge(Snake* psnake);
