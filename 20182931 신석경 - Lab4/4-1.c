/*
* �迭 �ʱ�ȭ �� �ݺ������� ��� ���� ���
*/
#include <stdio.h>

int main(void) {
	printf("double �迭 ���� ���\n\n");
	double degree[] = { -5.34, 3.67, 19.76, 28.76, 35.63 };
	int size = sizeof(degree) / sizeof(degree[0]);	// ù ��° ������ Ÿ������ ��ü size ����

	printf("���� : ");
	for (int i = 0; i < size; i++)		// index�� �ϳ��� ���İ��� ���� ���
		printf("%.2f ", degree[i]);

	printf("\n\n");
	return 0;
}