/*
* ������ �����͸� ����Ͽ� ǥ�� �Է��� �ް� �׿� ���� ��Ģ������ �����ϴ� ���α׷� 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	printf("������ �����͸� ����Ͽ� ǥ�� �Է��� �ް� �׿� ���� ��Ģ������ ����\n\n");

	double x, y;	// �� ���� ����
	double* px = &x;	// x�� ����ų ������ ���� ����
	double* py = &y;	// y�� ����ų ������ ���� ����

	printf("�� �Ǽ� �Է�: ");
	scanf("%lf %lf", px, py);		// px, py�� ���� x, y�� �ּҰ��̹Ƿ� x, y�� �ش� �Ǽ� ����

	// ������ ��Ģ������ ����

	printf("%.2f + %.2f = %.2f\n", *px, *py, *px + *py);
	printf("%.2f - %.2f = %.2f\n", *px, *py, *px - *py);
	printf("%.2f * %.2f = %.2f\n", *px, *py, *px * *py);
	printf("%.2f / %.2f = %.2f\n\n", *px, *py, *px / *py);

	return 0;
}