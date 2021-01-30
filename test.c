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
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1) {
		//����ƶ�
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if ('c' != ret) {
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if ('c' != ret) {
			break;
		}
	}
	if (ret == '*') {
		printf("���Ӯ\n");
	}
	else if(ret == '#'){
		printf("����Ӯ\n");
	}
	else {
		printf("ƽ��\n");
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
		printf("������ָ��:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("������Ϸ\n");
			break;
		default:
			printf("��������ȷָ��\n");
			break;
		}
	} while (input);
}

int main() {
	test();
	return 0;
}