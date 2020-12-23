/*******************************************************
* ���ϸ�: calculation.c
* ���α׷� ����: ǥ�� �Է����� ���� �� �Ǽ��� ��Ģ ����
*	��Ģ ����: calculation �Լ��� ����
*
*	�Է� 1: ������ �� �Ǽ�
*   �Է� 2: ���� ���� ����
*
*   ���: ���� ���� �� ���� ���
*
* ��¥: 2020�� 9�� 14��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float calculation(float x, float y, char op);	// ��Ģ ������ �ϴ� �Լ� ����

int main(void) {
	float x, y;	// �Է��� ���� �� �Ǽ�;
	char op;	// ��Ģ ���� ������ �����ϴ� ����

	int n;	// �Է� ���� ���� ���� ����
	float result; // ��� ����� �����ϴ� ����

	while (1) {
		printf("�� �Ǽ��� �Է�(����� 0 0 �Է�) >> ");
		n = scanf("%f %f", &x, &y);		// �� �Ǽ��� �Է� ����

		if (n == 2 && !(x == 0 && y == 0)) {	// �� �Ǽ��� ���������� ������ x, y ��� 0�� �ƴ� ���
			printf("�������� ��ȣ���� [+, -, *, /] >> ");
			scanf(" %c", &op);
			if (op == '+' || op == '-' || op == '*' || op == '/') {	// �Է��� ��Ģ ������ ��쿡��
				result = calculation(x, y, op);		// ��Ģ���� ����
				printf("%.2f %c %.2f = %.2f\n\n", x, op, y, result);
			}
			else {
				printf("�����ڸ� �߸� �����߽��ϴ�.\n\n");	 // ���� ���
				while (getchar() != '\n');		// �Է� ���� ����
			}
		}
		else if (n == 2 && (x == 0 && y == 0)) {	// x, y�� 0 0 �� ���
			printf("**** ���α׷��� �����մϴ�. **** \n\n");
			break;		// while�� Ż��
		}
		else {	// �� �Ǽ��� �߸� �Էµ� ���
			while (getchar() != '\n');		// �Է� ���� ����
			printf("�� �Ǽ��� �ٽ� �Է��Ͻÿ�(����� 0 0 �Է�) : ");	// �ٽ� �Է�
			n = scanf("%f %f", &x, &y);		// �� �Ǽ��� �ٽ� �Է� ����

			if (n == 2 && !(x == 0 && y == 0)) {	// �� �Ǽ��� ���������� ������ x, y ��� 0�� �ƴ� ���
				printf("�������� ��ȣ���� [+, -, *, /] >> ");
				scanf(" %c", &op);
				if (op == '+' || op == '-' || op == '*' || op == '/') {	// �Է��� ��Ģ ������ ��쿡��
					result = calculation(x, y, op);
					printf("%.2f %c %.2f = %.2f\n\n", x, op, y, result);
				}
				else {
					printf("�����ڸ� �߸� �����߽��ϴ�.\n\n");	 // ���� ���
					while (getchar() != '\n');		// �Է� ���� ����
				}
			}
			else if (n == 2 && (x == 0 && y == 0)) {	// x, y�� 0 0 �� ���
				printf("**** ���α׷��� �����մϴ�. **** \n\n");
				break;		// while�� Ż��
			}
			else {	// �� �ٽ� �߸� �Էµ� ���
				printf("�Ǽ��� �߸� �Է��߽��ϴ�.\n\n");	// ���� ���
				while (getchar() != '\n');		// �Է� ���� ����
			}
		}
	}
	return 0;
}

float calculation(float x, float y, char op) {
	float result;
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
	return result;
}
