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

//�����άƽ��
typedef struct _PointPlat_ {
	int x;
	int y;
}PointPlat;

//�������������
//
typedef struct _Snake_ {
	size_t segmentSize;				// �����ߵĽ���
	char direction;					// ���嵱ǰ�ߵ�ǰ������
	PointPlat segPlace[MAX_SEGMENT];// �����ߵĶ�����
}Snake;

//ʳ��
//
typedef struct _Food_ {
	PointPlat foodXY;
	int score;
	bool whetherFoodExist;
}Food;

//������ʲ�
//
typedef struct _LoseWeightFood_ {
	PointPlat loseWeightFoodXY;
	int score;
	bool whetherLWF_Exist;
}LoseWeightFood;

//����һ�·���
//
enum Directions {
	RIGHT = 77,
	LEFT = 75,
	DOWN = 80,
	UP = 72,//��Ӧkeypress
};

//Menu����
void menu();
int chooseSpeed(int input);

//����ʳ�ﺯ��
void randInitFoodPos(Food* pfood);
void randInitLWFoodPos(LoseWeightFood* pLWFood);


//���ɵ�ͼ����
void initBackGround();
void initSnake(Snake* psnake);

//����EasyX�Ļ滭����
void drawSnake(Snake* psnake);
void drawFood(Food* pfood);
void drawLWFood(LoseWeightFood* LWFood);

//������Ϊ
void moveSnake(Snake* psnake);
int eatFood(Snake* psnake, Food* pfood, int count);
void eatLWFood(Snake* psnake, LoseWeightFood* plossfood);
void keyReact(Snake* psnake);

//��Ϸ�ж�
int deathJudge(Snake* psnake);
