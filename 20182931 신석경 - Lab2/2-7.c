#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* Red, Green, Blue�� �ǹ��ϴ� �ϳ��� ������ �Է��ϰ�,
* �Է¿� ���� ��Red��, ��Green��, ��Blue���� ����ϴ� ���α׷�
*/


int main(void) {
	printf("�Է¿� ���� Red, Green, Blue ���ڿ� ���\n\n");

	enum color {RED, GREEN, BLUE};		// ������ ����
	int op;
	printf("�� ����(R[0], G[1], B[2]) ���� �ϳ��� �Է�: ");
	scanf("%d", &op);
	switch (op)
	{
	case RED:		// op == 0 �� ���
		printf("Red\n");
		break;
	case GREEN:		// op == 1 �� ���
		printf("Green\n");
		break;
	case BLUE:		// op == 2 �� ���
		printf("Blue\n");
		break;
	default:		// �߸��� �Է��� ���
		printf("Wrong Input!!\n");
		break;
	}
	return 0;
}