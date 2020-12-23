#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* 세개의 정수를 입력 받아 가장 큰 수를 구하는 프로그램
*/

int main(void) {
	printf("세개의 정수를 입력 받아 가장 큰 수를 출력, 삼항 연산자와 조건문\n\n");

	int a, b, c;
	printf("세 정수를 입력하세요(한 번에 세개를 입력하세요) : ");
	scanf("%d %d %d", &a, &b, &c);
	
	// 1. 조건 연산자
	int max1;	// 최댓값을 저장하는 변수

	max1 = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
	printf("조건 연산자로 구한 큰 수 : %d\n", max1);

	// 2. 조건문
	int max2;
	if (a > b) {	// a > b 인 경우
		if (a > c)	// a > b && a > c
			max2 = a;
		else		// a > b && a < c
			max2 = c;
	}
	else {			// a < b 인 경우
		if (b > c)  // a < b && b > c
			max2 = b;
		else		// a < b && b < c
			max2 = c;
	}
	printf("조건문으로 구한 큰 수 : %d\n", max2);
	return 0;
}