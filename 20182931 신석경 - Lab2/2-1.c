#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* ǥ���Է����� �� ������ �Է� �޾� ū ���� ���� ���� ���� ��� �������� 
* ���� ����ϴ� ���α׷�
*/

int main(void) {
	printf("�� ������ �Է� �޾� ū ���� ���� ���� ���� ��� ������ ���\n\n");
	int x, y;  // �Է� ���� �� ����

	printf("ù ��° ���ڸ� �Է��ϼ���: ");
	scanf("%d", &x);
	printf("�� ��° ���ڸ� �Է��ϼ���: ");
	scanf("%d", &y);		// �� ���� �Է�

	if (x > y) {	// x > y �̸� x/y�� ���
		printf("\n%d �� %d �� ���� ���\n", x, y);
		printf("��: %d, ������: %d\n", x / y, x % y);
	}
	else {		// ������ ��� ( x <= y)
		printf("\n%d �� %d �� ���� ���\n", y, x);
		printf("��: %d, ������: %d\n", y / x, y % x);
	}

	return 0;
}