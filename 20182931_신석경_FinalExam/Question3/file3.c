#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

double vafunc(char* type, int count, ...);

int main(void) {
	int ary[] = { 15, 57, 39, 21, 32, 44 };
	vafunc("d", 5, 72, 21, 36, 43, 58);
	vafunc("f", 4, 5.8, 7.3, 2.8, 3.5, 1.9);
	vafunc("a", 6, ary);
	return 0;
}

double vafunc(char* type, int count, ...)
{
	va_list argp;	// ���� ���� ���� ����

	va_start(argp, count);	// ���� ���ڸ� count ���� �ں��� ����
	double result = 0;
	if (strcmp(type, "d") == 0) {	// type�� "d" �̸�
		printf("������ : ");
		float total = 0;
		int temp;
		for (int i = 0; i < count; i++) {
			temp = va_arg(argp, int);	// ������ �����ͼ�
			total += temp;
			printf("%4d ", temp);	// ��� �� ����
		}
		result = total / count;	// ���� ��հ� ���
	}
	else if (strcmp(type, "f") == 0) {	// type�� "f"�̸�
		printf("������ : ");
		float total = 0;
		float temp;
		for (int i = 0; i < count; i++) {
			temp = va_arg(argp, double);	// double�� �����ͼ�
			total += temp;
			printf("%6.2f ", temp);	// ��� �� ����
		}
		result = total / count;	// ���� ��հ� ���
	}
	else if (strcmp(type, "a") == 0) {	// type�� "a"�̸�
		printf("������ : ");
		int* ary = va_arg(argp, int*);	// ���� ���ڷκ��� int*�� ������ �迭ó�� ���
		float total = 0;
		int temp;
		for (int i = 0; i < count; i++) {
			temp = ary[i];	// �迭�ν� ����
			total += temp;
			printf("%4d ", temp);	// ��� �� ����
		}
		result = total / count;	// ���� ��հ� ���
	}
	else {
		printf("�˸��� Ÿ���� �ƴմϴ�.");
		return 0;	// �˸��� Ÿ���� �ƴϸ� 0 ��ȯ
	}
	printf("\n��� %.2f\n\n", result);	// �˸��� ����� �Ǹ� ��հ� ���
	return result;
}