#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Iter_GCD(int a, int b);
int Recur_GCD(int a, int b);

int main(void) {
	int a, b;
	
	do
	{
		printf("2���� ������ �Է��Ͻÿ� >> ");
		while (scanf("%d %d", &a, &b) != 2) {	// ����� �� �Է��� �ƴ� ���
			while (getchar() != '\n');
			printf("2���� ������ �Է��Ͻÿ� >> ");
		}

		printf("%d�� %d�� Recursion GCD = %d\n", a, b, Recur_GCD(a, b));		// ��� ����
		printf("%d�� %d�� Recursion GCD = %d\n\n", a, b, Iter_GCD(a, b));	// �ݺ� ����
	} while (1);

	return 0;
}

int Iter_GCD(int a, int b) {	// �ݺ� ����
	int temp, n;
	if (a < b) {	// a�� �׻� ũ�� ����
		temp = a;
		a = b;
		b = temp;
	}

	while (b != 0) {	// �������� 0�� �� ����
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int Recur_GCD(int a, int b) {	// ��� ����
	if (b == 0) {
		return a;
	}
	else {
		return Recur_GCD(b, a % b);
	}
}