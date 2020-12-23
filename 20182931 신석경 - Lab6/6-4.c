/*
* 5개의 정수형 변수가 있을 때, 배열 포인터를 int *pary[SIZE]
* 를 이용하여 5개 변수들의 합을 계산하는 프로그램
*/

#include <stdio.h>

#define SIZE 5

int main(void) {
	int a = 10, b = 20, c = 30, d = 40, e = 50;

	int* pary[SIZE] = { &a, &b, &c, &d, &e };	// 포인터 배열의 원소를 각 변수의 주소값으로 초기화
	int sum = 0;

	for (int i = 0; i < SIZE; i++) {
		sum += *pary[i]; // 각 배열의 원소는 주소값, 그러므로 * 연산을 통해 합을 계산
	}

	printf("sum = %d\n", sum);
	return 0;
}