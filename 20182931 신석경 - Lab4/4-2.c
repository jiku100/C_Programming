/*
* ������ �迭�� �����Ͽ� ����� �˾ƺ��� ���α׷�
*/
#include <stdio.h>

int main(void) {
	printf("������ �迭�� ����\n\n");

	int a[] = { 4, 7, 9, 3, 6 };
	int b[] = { 10, 20, 30, 40, 50, 60 };

	printf("�迭 a[] : ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)	// a�� ���� ���
		printf("%d ", a[i]);

	printf("\n�迭 b[] : ");
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)	// b�� ���� ���
		printf("%d ", b[i]);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)	// a�� ���� b�� ����
		b[i] = a[i];	// a[i]�� ���Ҹ� b[i] ���ҷ� ����

	printf("\n���� �� �迭 b[] : ");
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)	// b�� ���� ���
		printf("%d ", b[i]);
	printf("\n");
	return 0;

}