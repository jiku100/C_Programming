#include<stdio.h>
#include <stdlib.h>

int** make2dArray(int rows, int cols);  // row�� col ũ���� 2���� �迭�� ���� �Ҵ�
void copyarray(int x[][3], int** y, int rowsize, int colsize);  // x���� y�� ����
void printarray1(int x[][3], int rowsize, int colsize);  // ������ �迭 ���
void printarray2(int** y, int rowsize, int colsize);  // ���� ������ �迭 ���


int main(void) {
	int x[2][3] = { 1, 3, 5, 2, 4, 6 };
	int** y;
	int rows = sizeof(x) / sizeof(x[0]);
	int cols = sizeof(x[0]) / sizeof(int);
	y = make2dArray(rows, cols);
	copyarray(x, y, rows, cols);
	printarray1(x, rows, cols);
	printarray2(y, rows, cols);
	return 0;	
}

int** make2dArray(int rows, int cols) {  // row�� col ũ���� 2���� �迭�� ���� �Ҵ�
	int** temp = malloc(sizeof(int *) * rows);
	for (int i = 0; i < rows; i++) {
		temp[i] = malloc(sizeof(int) * cols);
	}
	return temp;
}

void copyarray(int x[][3], int** y, int rowsize, int colsize){  // x���� y�� ����
	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < colsize; j++) {
			y[i][j] = x[i][j];
		}
	}
}

void printarray1(int x[][3], int rowsize, int colsize) {  // ������ �迭 ���
	printf("������ �迭 x\n");
	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < colsize; j++) {
			printf("%3d", x[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printarray2(int** y, int rowsize, int colsize){  // ���� ������ �迭 ���
	printf("������ �迭 y\n");
	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < colsize; j++) {
			printf("%3d", y[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


