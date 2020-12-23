#include <stdio.h>
#define COL 5
void print(int x[][COL], int rsize, int csize);
void increase(int(*ptr)[COL], int rsize, int csize, int num);


int main(void) {
	int x[][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	const int ROW = sizeof(x) / (sizeof(int) * COL);
	int num = 5;
	printf("행렬 x\n");
	print(x, ROW, COL);
	printf("\n행렬 x를 %d씩 증가 결과\n", num);
	increase(x, ROW, COL, num);
	print(x, ROW, COL);
	return 0;
}

void print(int x[][COL], int rsize, int csize) {
	printf("-------------------------------\n");
	for (int i = 0; i < rsize; i++) {
		printf("|");
		for (int j = 0; j < csize; j++) {
			printf("%4d |", x[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------\n");
}
void increase(int(*ptr)[COL], int rsize, int csize, int num) {
	for (int i = 0; i < rsize; i++) {
		for (int j = 0; j < csize; j++) {
			ptr[i][j] += num;
		}
	}
}
