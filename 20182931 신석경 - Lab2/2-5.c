#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
* ���� ������ ax^2 + bx + c = 0 �� ���� ����ϴ� ���α׷�
*/
int main(void) {
	printf("���� ������ ax^2 + bx + c = 0  �� �ظ� ���Ͻÿ�.\n\n");

	float a, b, c; // ������ ����� �����ϴ� ����
	printf("��� a�� �Է��Ͻÿ�: "); scanf("%f", &a);
	printf("��� b�� �Է��Ͻÿ�: "); scanf("%f", &b);
	printf("��� c�� �Է��Ͻÿ�: "); scanf("%f", &c);

	float x1, x2;

	if (a == 0) {	// a �� 0 �̸� ���� -c/b
		x1 = -c / b;
		printf("���� �������� �� x = %.2f �Դϴ�.\n", x1);
	}
	else if (b * b - 4 * a * c < 0) {		// b^2 - 4ac < 0 �̐� �Ǳ� ���� X
		printf("���� �������� �ش� �������� �ʽ��ϴ�.\n");
	}
	else {		// ���� �������� �� ���� �����ϴ� ���
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		printf("���� �������� �� x = %.2f, x = %.2f �Դϴ�. \n", x1, x2);
	}

	return 0;
}