/*
* 4 x 3�� ��Ŀ��� �� ��� x �� y�� �հ� ���� ���ϴ� ���α׷�
*/

#include <stdio.h>

#define COLS 3
#define ROWS 4

int main(void) {
	printf("4 x 3�� ��Ŀ��� �� ��� x �� y�� �հ� ���� ���\n\n");

	int x[][3] = { {46,79,78},{35,57,28},{43,68,76},{56,78,98} };	// �迭 �ʱ�ȭ
	int y[][3] = { {78,35,99},{85,82,34},{58,69,29},{34,59,35} };	// �迭 �ʱ�ȭ

	int(*px)[COLS] = x;	// x�� ����Ű�� �迭 ������ px ����;
	int(*py)[COLS] = y;	// y�� ����Ű�� �迭 ������ px ����;

	printf("��� x\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", x[i][j]);		// x ���
		}
		printf("|\n");
	}
	printf("----------------\n\n");

	printf("��� y\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", y[i][j]);		// y ���
		}
		printf("|\n");
	}
	printf("----------------\n\n");

	printf("�� ��� x + y ���\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", *(px[i]+j) + *(py[i]+j));		// x + y���

			// px�� 2���� �迭 �������̴�.
			// px[i]�� i��° �迭�� ����Ű�� p[i][j]�� i ��° �迭�� j�� ���Ҹ� ����Ų��.
		}
		printf("|\n");
	}
	printf("----------------\n\n");

	printf("�� ��� x - y ���\n----------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("| %3d", *(*(px + i)+j) - *(*(py + i) + j));		// x - y���
			
			// px�� 2���� �迭 �������̴�.
			// px�� �迭�� ����Ű�� ù �ּҸ� �����Ƿ�, px + i�� i��° row�� �ּҸ� ����Ų��.
			// �̶�, *(px+i)�� i��° row�� ���� �ּ� ���̴�.
			// ��, *(px+i) + j�� i��° �迭�� j�� ������ �ּҰ��̴�. 
			// �̶�, *(*px+i)+j)�� i, j�� ���� ���̴�.
		}
		printf("|\n");
	}
	printf("----------------\n\n");
	return 0;	
}