/*
* 1차원 배열 a와 2차원 배열 b에 포함된 모든 원소의 합을 각각 구할 수 있는 프로그램
*/

#include <stdio.h>

int arysum(int* p, int size);

int main(void) {
	int a[] = { 1, 2, 3, 4 };
	int b[][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };

	printf("배열 a 원소의 합 = %d\n", arysum(a, sizeof(a) / sizeof(int)));
	printf("배열 b 원소의 합 = %d\n", arysum(b, sizeof(b) / sizeof(int)));
	return 0;
}


int arysum(int* p, int size) {	// 행렬 원소 전체 합 함수
	int sum = 0;
	for (int i = 0; i < size; i++) {	// 전체 사이즈를
		sum += *p++;	// 포인터 연산을 통해 sum에 더함
	}
	return sum;
}
