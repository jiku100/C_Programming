#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mymacro.h"
// mymacro.h�� #define PI 3.141592�� ���� �Ǿ�����.

/*
* ǥ���Է����� ���� ������ ���� �Ǽ��� �Է� �޾� ������, ����, �ѷ� ����ϴ� ���α׷�
*/


int main(void) {
	printf("���� �������� �Է� �޾� ������, ����, �ѷ��� ���\n\n");

	float radius;
	printf("�������� �Է��ϼ���.: ");
	scanf("%f", &radius);		// �������� �Է� �޾� radius ������ ����

	printf("���� ������: %f, ���� ����: %f, ���� �ѷ�: %f", radius, PI*radius*radius, 2*PI*radius);
	// ������ ��� ����� ���
	return 0;
}
