/*
* ���� 4 x 3�� ��Ŀ��� �� ��� x �� y�� �հ� ���� ���ϴ� ���α׷�
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

	printf("��� x\n");
	displayarray(px);	// ��� ���
	printf("��� y\n");
	displayarray(py);	// ��� ���

	printf("�� ��� x + y ���\n");
	sumarray(px, py);	// ��� ���� �� ���

	printf("�� ��� x - y ���\n");
	subtractarray(px, py);	// ��� ���� �� ���
	return 0;
}


void displayarray(int(*ary)[COLS]) {	// ��� ���
	printf("\n----------------\n");
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				printf("| %3d", ary[i][j]);		// ary ���
			}
			printf("|\n");
		}
	printf("----------------\n\n");
}

void sumarray(int(*x)[COLS], int(*y)[COLS]) {	// ��� ����
	printf("\n----------------\n");
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				printf("| %3d", *(x[i] + j) + *(y[i] + j));		// x + y���
			}
			printf("|\n");
		}
	printf("----------------\n\n");
}

void subtractarray(int(*x)[COLS], int(*y)[COLS]) {	// ��� ����
	printf("\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", *(*(x + i) + j) - *(*(y + i) + j));		// x + y���
		}
		printf("|\n");
	}
	printf("----------------\n\n");
}
