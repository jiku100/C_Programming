/*
* 5���� ������ ������ ���� ��, �迭 �����͸� int *pary[SIZE]
* �� �̿��Ͽ� 5�� �������� ���� ����ϴ� ���α׷�
*/

#include <stdio.h>

#define SIZE 5

int main(void) {
	int a = 10, b = 20, c = 30, d = 40, e = 50;

	int* pary[SIZE] = { &a, &b, &c, &d, &e };	// ������ �迭�� ���Ҹ� �� ������ �ּҰ����� �ʱ�ȭ
	int sum = 0;

	for (int i = 0; i < SIZE; i++) {
		sum += *pary[i]; // �� �迭�� ���Ҵ� �ּҰ�, �׷��Ƿ� * ������ ���� ���� ���
	}

	printf("sum = %d\n", sum);
	return 0;
}