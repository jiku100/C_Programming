#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur_sum(int n);

int main(void) {
	int n;
	printf("1 부터 n 까지의 합을 재귀호출 함수로 계산합니다.\n");
	printf("양의 정수<n>를 입력하시오 >> ");	scanf("%d", &n);
	printf("sum = %d\n\n", recur_sum(n));
	return 0;
}

int recur_sum(int n) {
	static int i = 1;		// 정적 변수 선언
	printf("%d번 호출\n", i++);	// 호출 횟수 출력 및 i++
	if (n == 1)
		return 1;
	else
		return n + recur_sum(n - 1);
}