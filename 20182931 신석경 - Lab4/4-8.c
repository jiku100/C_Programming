/*
* 4 x 3의 행렬에서 두 행렬 x 와 y의 합과 차를 구하는 프로그램
*/

#include <stdio.h>

#define COLS 3
#define ROWS 4

int main(void) {
	printf("4 x 3의 행렬에서 두 행렬 x 와 y의 합과 차를 출력\n\n");

	int x[][3] = { {46,79,78},{35,57,28},{43,68,76},{56,78,98} };	// 배열 초기화
	int y[][3] = { {78,35,99},{85,82,34},{58,69,29},{34,59,35} };	// 배열 초기화

	int(*px)[COLS] = x;	// x를 가리키는 배열 포인터 px 선언;
	int(*py)[COLS] = y;	// y를 가리키는 배열 포인터 px 선언;

	printf("행렬 x\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", x[i][j]);		// x 출력
		}
		printf("|\n");
	}
	printf("----------------\n\n");

	printf("행렬 y\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", y[i][j]);		// y 출력
		}
		printf("|\n");
	}
	printf("----------------\n\n");

	printf("두 행렬 x + y 결과\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", *(px[i]+j) + *(py[i]+j));		// x + y출력

			// px는 2차원 배열 포인터이다.
			// px[i]는 i번째 배열을 가리키고 p[i][j]는 i 번째 배열의 j번 원소를 가리킨다.
		}
		printf("|\n");
	}
	printf("----------------\n\n");

	printf("두 행렬 x - y 결과\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", *(*(px + i)+j) - *(*(py + i) + j));		// x - y출력
			
			// px는 2차원 배열 포인터이다.
			// px가 배열을 가리키는 첫 주소를 가지므로, px + i는 i번째 row의 주소를 가리킨다.
			// 이때, *(px+i)는 i번째 row의 시작 주소 값이다.
			// 즉, *(px+i) + j는 i번째 배열의 j번 원소의 주소값이다. 
			// 이때, *(*px+i)+j)는 i, j의 원소 값이다.
		}
		printf("|\n");
	}
	printf("----------------\n\n");
	return 0;	
}