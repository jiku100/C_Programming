#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Iter_GCD(int a, int b);
int Recur_GCD(int a, int b);

int main(void) {
	int a, b;
	
	do
	{
		printf("2개의 정수를 입력하시오 >> ");
		while (scanf("%d %d", &a, &b) != 2) {	// 제대로 된 입력이 아닌 경우
			while (getchar() != '\n');
			printf("2개의 정수를 입력하시오 >> ");
		}

		printf("%d와 %d의 Recursion GCD = %d\n", a, b, Recur_GCD(a, b));		// 재귀 버전
		printf("%d와 %d의 Recursion GCD = %d\n\n", a, b, Iter_GCD(a, b));	// 반복 버전
	} while (1);

	return 0;
}

int Iter_GCD(int a, int b) {	// 반복 버전
	int temp, n;
	if (a < b) {	// a를 항상 크게 유지
		temp = a;
		a = b;
		b = temp;
	}

	while (b != 0) {	// 나머지가 0일 때 까지
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int Recur_GCD(int a, int b) {	// 재귀 버전
	if (b == 0) {
		return a;
	}
	else {
		return Recur_GCD(b, a % b);
	}
}