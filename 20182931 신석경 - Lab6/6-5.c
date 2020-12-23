/*
* ǥ�� �Է����� ���� ���� ������ �� n�� ���Ͽ� ������ ���� ������ �迭�� �����ϴ� �Լ��� 
* �迭�� ���Ҹ� ����ϴ� �Լ��� �ۼ��ϰ� ����� ����Ͻÿ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void copyarray(int from[], int to[], int n);	// ��� ����
void display(int a[], int m);		// ��� ���


int main(void) {
	int a[] = { 4, 7, 9, 3, 6 };
	int b[] = { 10, 20, 30, 40, 50, 60 };

	int n;

	printf("a[] = ");	
	display(a, sizeof(a)/sizeof(int));	// ��� ���
	printf("b[] = ");
	display(b, sizeof(b) / sizeof(int)); // ��� ���

	do
	{
		printf("a[]���� b[]�� ������ ������ ���� �Է��Ͻÿ� : ");
		scanf("%d", &n);

		if (n < 0 || n > (sizeof(a) / sizeof(int)))	// n�� ���� �̰ų� a ��� ���� �̻��̸�
			printf(" ?? ������ ������ ������ �����̰ų� �ʹ� �����ϴ�.\n");
	} while (n<0 || n > (sizeof(a) / sizeof(int))); // n�� ���� �̰ų� a ��� ���� �̻��̸�	��� �ݺ�
	copyarray(a, b, n);	// a�� b�� n�� ��ŭ ����
	printf("������ ���� �迭 b[] = ");
	display(b, sizeof(b) / sizeof(int));	// ���� �� ��� ����

	return 0;
}

void copyarray(int from[], int to[], int n) {	// ��� ����
	for (int i = 0; i < n; i++)
		to[i] = from[i];
}

void display(int a[], int m) {	// ��� ���
	for (int i = 0; i < m; i++)
		printf("%d ", a[i]);
	printf("\n");
}