/*
* 다음 4 x 3의 행렬에서 두 행렬 x 와 y의 합과 차를 구하는 프로그램
*/

#include <stdio.h>

#define COLS 3
#define ROWS 4


void displayarray(int (*ary)[COLS]);	//display array elemnet
void sumarray(int (*x)[COLS], int (*y)[COLS]);	// array sum
void subtractarray(int(*x)[COLS], int(*y)[COLS]);	// array subtract

int main(void) {
	int x[][3] = { {46,79,78},{35,57,28},{43,68,76},{56,78,98} };
	int y[][3] = { {78,35,99},{86,82,34},{58,69,29},{34,59,35} };

	int(*px)[COLS] = x;
	int(*py)[COLS] = y;

	printf("행렬 x\n");
	displayarray(px);	// 행렬 출력
	printf("행렬 y\n");
	displayarray(py);	// 행렬 출력

	printf("두 행렬 x + y 결과\n");
	sumarray(px, py);	// 행렬 덧셈 및 출력

	printf("두 행렬 x - y 결과\n");
	subtractarray(px, py);	// 행렬 뺄셈 및 출력
	return 0;
}


void displayarray(int(*ary)[COLS]) {	// 행렬 출력
	printf("\n----------------\n");
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				printf("| %3d", ary[i][j]);		// ary 출력
			}
			printf("|\n");
		}
	printf("----------------\n\n");
}

void sumarray(int(*x)[COLS], int(*y)[COLS]) {	// 행렬 덧셈
	printf("\n----------------\n");
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				printf("| %3d", *(x[i] + j) + *(y[i] + j));		// x + y출력
			}
			printf("|\n");
		}
	printf("----------------\n\n");
}

void subtractarray(int(*x)[COLS], int(*y)[COLS]) {	// 행렬 뺄셈
	printf("\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", *(*(x + i) + j) - *(*(y + i) + j));		// x + y출력
		}
		printf("|\n");
	}
	printf("----------------\n\n");
}
