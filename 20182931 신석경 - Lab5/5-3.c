/*
* �� ���� ���� ������ �Է� �޾� ���� ū ���� ��ȯ�ϴ� �Լ��� �����ϰ�, �� ����� ����ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int a, int b, int c);	// 3���� ���� �� ���� ū ���ڸ� ��ȯ�ϴ� �Լ�

int main(void) {
	int a, b, c;	// 3 ���� ���� ����

	while (1) {
		printf("�� ���� ���� �� ���� ū ������ ����մϴ�.\n");
		printf("�� ���� ������ ���ʷ� �Է��Ͻÿ� : ");
		scanf("%d %d %d", &a, &b, &c);
		printf(" >> �Է��� �� �� ���� %d, %d, %d �� ���� ū ������ %d �Դϴ�.\n\n", a, b, c, max(a, b, c));
	}
}

int max(int a, int b, int c) {
	if (a > b) {
		if (a > c)
			return a;
		else
			return c;
	}
	else {
		if (b > c)
			return b;
		else
			return c;
	}
}