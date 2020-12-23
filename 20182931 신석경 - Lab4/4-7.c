/*
* 다음과 같이 3 x 2와 2 x 3의 두 행렬 a, b에서 행렬의 곱 c를 구하는 프로그램
*/

#include <stdio.h>

int main(void) {
	printf("두 행렬 a, b에서 행렬의 곱 c 출력\n\n");

	int a[][2] = { {3, 5},
					{4, 2},
					{5, 7} };	// a 행렬 초기화

	int b[][3] = { {3,8,2}, {2,4,6} };	// b행렬 초기화

	printf("행렬 a\n");		// a 원소 출력
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("   %d   %d\n", a[i][0], a[i][1]);
	}

	printf("\n행렬 b\n");	// b 원소 출력
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
		printf("   %d   %d   %d\n", b[i][0], b[i][1], b[i][2]);
	}

	printf("\n행렬 c = a x b\n");	// a x b 행렬 곱 출력
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// 각각의 a의 row에 대한 b의 column의 곱의 합
			printf("   %d", a[i][0] * b[0][j] + a[i][1] * b[1][j]);	
			// a의 i 번째 row 와 b의 i 번째 column 곱
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}