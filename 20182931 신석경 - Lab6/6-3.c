/*
* 1���� �迭 a�� 2���� �迭 b�� ���Ե� ��� ������ ���� ���� ���� �� �ִ� ���α׷�
*/

#include <stdio.h>

int arysum(int* p, int size);

int main(void) {
	int a[] = { 1, 2, 3, 4 };
	int b[][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };

	printf("�迭 a ������ �� = %d\n", arysum(a, sizeof(a) / sizeof(int)));
	printf("�迭 b ������ �� = %d\n", arysum(b, sizeof(b) / sizeof(int)));
	return 0;
}


int arysum(int* p, int size) {	// ��� ���� ��ü �� �Լ�
	int sum = 0;
	for (int i = 0; i < size; i++) {	// ��ü �����
		sum += *p++;	// ������ ������ ���� sum�� ����
	}
	return sum;
}
