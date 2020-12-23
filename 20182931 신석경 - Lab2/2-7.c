#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* Red, Green, Blue를 의미하는 하나의 정수를 입력하고,
* 입력에 따라 “Red”, “Green”, “Blue”를 출력하는 프로그램
*/


int main(void) {
	printf("입력에 따라 Red, Green, Blue 문자열 출력\n\n");

	enum color {RED, GREEN, BLUE};		// 열거형 정의
	int op;
	printf("세 정수(R[0], G[1], B[2]) 중의 하나를 입력: ");
	scanf("%d", &op);
	switch (op)
	{
	case RED:		// op == 0 인 경우
		printf("Red\n");
		break;
	case GREEN:		// op == 1 인 경우
		printf("Green\n");
		break;
	case BLUE:		// op == 2 인 경우
		printf("Blue\n");
		break;
	default:		// 잘못된 입력의 경우
		printf("Wrong Input!!\n");
		break;
	}
	return 0;
}