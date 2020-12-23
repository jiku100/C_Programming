#include <stdio.h>
#define ROWS 2
#define COLS 3
typedef double matrixa[ROWS][COLS];
typedef double matrixb[ROWS][COLS];
typedef double resultc[ROWS][COLS];
void plus(resultc r, matrixa a, matrixb b, int rows, int cols);
void minus(resultc r, matrixa a, matrixb b, int rows, int col);
void display(resultc r, int rows, int cols);


int main(void) {
	matrixa a = { {4.20, 4.30, 3.80},{3.70, 1.50, 0.70} };
	matrixb b = { {5.20, 2.10, 1.80},{3.20, 1.40, 2.90} };
	resultc c;

	printf("행렬 a\n");
	display(a, ROWS, COLS);
	printf("\n\n행렬 b\n");
	display(b, ROWS, COLS);
	plus(c, a, b, ROWS, COLS);
	printf("\n\n행렬 a + b 결과\n");
	display(c, ROWS, COLS);
	minus(c, a, b, ROWS, COLS);
	printf("\n\n행렬 a - b 결과\n");
	display(c, ROWS, COLS);

}


void plus(resultc r, matrixa a, matrixb b, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			r[i][j] = a[i][j] + b[i][j];
		}
	}
}
void minus(resultc r, matrixa a, matrixb b, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			r[i][j] = a[i][j] - b[i][j];
		}
	}
}
void display(resultc r, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%8.2f", r[i][j]);
		}
		printf("\n");
	}
}