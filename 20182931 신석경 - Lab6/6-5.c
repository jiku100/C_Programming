/*
* 표준 입력으로 받은 복사 원소의 수 n에 대하여 다음과 같이 일차원 배열을 복사하는 함수와 
* 배열의 원소를 출력하는 함수를 작성하고 결과를 출력하시오
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void copyarray(int from[], int to[], int n);	// 행렬 복사
void display(int a[], int m);		// 행렬 출력


int main(void) {
	int a[] = { 4, 7, 9, 3, 6 };
	int b[] = { 10, 20, 30, 40, 50, 60 };

	int n;

	printf("a[] = ");	
	display(a, sizeof(a)/sizeof(int));	// 행렬 출력
	printf("b[] = ");
	display(b, sizeof(b) / sizeof(int)); // 행렬 출력

	do
	{
		printf("a[]에서 b[]로 복사할 원소의 수를 입력하시오 : ");
		scanf("%d", &n);

		if (n < 0 || n > (sizeof(a) / sizeof(int)))	// n이 음수 이거나 a 행렬 길이 이상이면
			printf(" ?? 복사할 원소의 개수가 음수이거나 너무 많습니다.\n");
	} while (n<0 || n > (sizeof(a) / sizeof(int))); // n이 음수 이거나 a 행렬 길이 이상이면	계속 반복
	copyarray(a, b, n);	// a를 b로 n개 만큼 복사
	printf("복사한 후의 배열 b[] = ");
	display(b, sizeof(b) / sizeof(int));	// 복사 후 행렬 복사

	return 0;
}

void copyarray(int from[], int to[], int n) {	// 행렬 복사
	for (int i = 0; i < n; i++)
		to[i] = from[i];
}

void display(int a[], int m) {	// 행렬 출력
	for (int i = 0; i < m; i++)
		printf("%d ", a[i]);
	printf("\n");
}