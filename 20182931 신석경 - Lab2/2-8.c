#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* ǥ���Է����� ���� �� �Ǽ��� �Էµ� ������ �����ϴ� ���α׷�
*/

int main(void) {
	printf("ǥ���Է����� ���� �� �Ǽ��� �Էµ� ������ �����ϰ� ���\n\n");

	float x, y; // �� �Ǽ��� �����ϱ� ���� ����

	printf("�� �Ǽ� �Է�: ");
	scanf("%f %f", &x, &y);

	char op;	// ���õ� ������ �����ϱ� ���� ����

	printf("�������� ����( +, -, *, / ) : ");
	scanf(" %c", &op);

	float result;   // ��� ����� �����ϴ� ����

	switch (op)		// ���õ� ����� ���� ����
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		result = x / y;
		break;
	default:
		break;
	}

	printf("%.2f %c %.2f = %.2f\n", x, op, y, result);
	return 0;
}