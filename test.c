#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |   
void game() {
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1) {
		//玩家移动
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if ('c' != ret) {
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if ('c' != ret) {
			break;
		}
	}
	if (ret == '*') {
		printf("玩家赢\n");
	}
	else if(ret == '#'){
		printf("电脑赢\n");
	}
	else {
		printf("平局\n");
	}
}
void menu() {
	printf("*************************\n");
	printf("******1.Play 0.Exit******\n");
	printf("*************************\n");
}

void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请输入指令:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("结束游戏\n");
			break;
		default:
			printf("请输入正确指令\n");
			break;
		}
	} while (input);
}

int main() {
	test();
	return 0;
}