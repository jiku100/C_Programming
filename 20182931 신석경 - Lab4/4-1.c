/*
* 배열 초기화 후 반복문으로 모든 원소 출력
*/
#include <stdio.h>

int main(void) {
	printf("double 배열 원소 출력\n\n");
	double degree[] = { -5.34, 3.67, 19.76, 28.76, 35.63 };
	int size = sizeof(degree) / sizeof(degree[0]);	// 첫 번째 원소의 타입으로 전체 size 나눔

	printf("원소 : ");
	for (int i = 0; i < size; i++)		// index를 하나씩 거쳐가며 원소 출력
		printf("%.2f ", degree[i]);

	printf("\n\n");
	return 0;
}