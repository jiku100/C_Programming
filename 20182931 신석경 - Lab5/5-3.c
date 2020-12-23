/*
* 세 개의 임의 정수를 입력 받아 가장 큰 수를 반환하는 함수를 구현하고, 그 결과를 출력하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int a, int b, int c);	// 3개의 정수 중 제일 큰 숫자를 반환하는 함수

int main(void) {
	int a, b, c;	// 3 개의 정수 정의

	while (1) {
		printf("세 개의 정수 중 가장 큰 정수를 출력합니다.\n");
		printf("세 개의 정수를 차례로 입력하시오 : ");
		scanf("%d %d %d", &a, &b, &c);
		printf(" >> 입력한 세 개 정수 %d, %d, %d 중 가장 큰 정수는 %d 입니다.\n\n", a, b, c, max(a, b, c));
	}
}

int max(int a, int b, int c) {
	if (a > b) {
		if (a > c)
			return a;
		else
			return c;
	}
	else {
		if (b > c)
			return b;
		else
			return c;
	}
}