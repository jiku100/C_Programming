#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* ������ ������ �Է� �޾� ���� ū ���� ���ϴ� ���α׷�
*/

int main(void) {
	printf("������ ������ �Է� �޾� ���� ū ���� ���, ���� �����ڿ� ���ǹ�\n\n");

	int a, b, c;
	printf("�� ������ �Է��ϼ���(�� ���� ������ �Է��ϼ���) : ");
	scanf("%d %d %d", &a, &b, &c);
	
	// 1. ���� ������
	int max1;	// �ִ��� �����ϴ� ����

	max1 = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
	printf("���� �����ڷ� ���� ū �� : %d\n", max1);

	// 2. ���ǹ�
	int max2;
	if (a > b) {	// a > b �� ���
		if (a > c)	// a > b && a > c
			max2 = a;
		else		// a > b && a < c
			max2 = c;
	}
	else {			// a < b �� ���
		if (b > c)  // a < b && b > c
			max2 = b;
		else		// a < b && b < c
			max2 = c;
	}
	printf("���ǹ����� ���� ū �� : %d\n", max2);
	return 0;
}