/*
* 표준 입력으로 받은 정수 n에 대하여 1부터 n까지의 합을 구하는 함수를 재귀함수로 작성하고, 
* 합이 출력되는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur_sum(int n);


int main(void) {
	printf("1부터 입력 n 까지의 합을 재귀호출 함수를 정의하여 계산합니다.\n");

	int n;
	printf("양의 정수 n 을 입력하시오 >> ");	scanf("%d", &n);
	printf("sum = %d\n", recur_sum(n));	// 함수 결과 출력
	return 0;
}

int recur_sum(int n) {	// 재귀 함수 
	if (n == 1)
		return 1;
	else
		return n + recur_sum(n - 1);
}