/*
* �Էµ� �������� ������ �ڸ��� �ش��ϴ� ���� �ݴ�� ����ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	printf("�Է��� ������ �Ųٷ� ���\n\n");

	int num;	// ���� �Է� ����

	printf("�ݴ�� ����� ������ �Է� >> ");
	scanf("%d", &num);

	printf("�Է��� ���� �ݴ�� ��� >>> ");
	while (num) {
		printf("%d", num % 10);		// ������ ������ ���� �Ųٷ� ��°���
		num = num / 10;		// 10���� ���� �� ���ڸ� ���� ����
	}
	printf("\n\n");
	return 0;
}