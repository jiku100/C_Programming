#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define False 0
#define True 1
/*
* �Է� ���� �⵵�� ���� �̿��� ���� ������ ����ϴ� ���α׷�
*/


int main(void) {
	printf("��� ���� �Է��ϸ� �� ���� ������ �˷��帳�ϴ�.\n\n");

	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	// �� ���� �� ���� ������ �迭

	int year, month;	// �Է� ���� �⵵�� ���� ������ ����
	printf("�Է�(��: 2020 2) >> ");
	scanf("%d %d", &year, &month);

	int isLeap = False;

	if (year % 400 == 0)		// 400���� ������ �������� ����
		isLeap = True;
	else if (year % 4 == 0) {	// �ϴ� 4�� ������ ����
		isLeap = True;	// �ϴ� �������� ����
		if (year % 100 == 0)	// 4�� ������ �������� 100���ε� ������ �������� (400�� �� if������ ���ܵ�)
			isLeap = False;
	}

	if (isLeap)		// �����̸�
		days[1] = 29;	// 2�� ���� 29�Ϸ� �ٲ�

	printf("%d�� %d���� ������ %d���Դϴ�.\n", year, month, days[month - 1]);
	return 0;
}