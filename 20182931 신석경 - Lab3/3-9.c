/*
* ǥ���Է����� ���� int���� �� ������ ��Ģ ������ �����ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	printf("double �� ������ int 2���� �����Ͽ� ��Ģ���� ����\n\n");

	double input;	// double �� 8����Ʈ ���� ����
	int* p = (int*)&input;	// ����ȯ�� ���� input�� int�� �����ͷ� ����


	printf("�� ���� �Է�: ");
	scanf("%d %d", p, p+1);	// int* �̹Ƿ� p + 1�� 4����Ʈ �̵��� ������ ����

	// ������ ��Ģ������ ����
	// *p �� ���� 4����Ʈ ����, *(p+1)�� ���� 4����Ʈ ������ ������
	printf("%d + %d = %d\n", *p, *(p+1), *p + *(p + 1));
	printf("%d - %d = %d\n", *p, *(p + 1), *p - *(p + 1));
	printf("%d * %d = %d\n", *p, *(p + 1), *p * *(p + 1));
	printf("%d / %d = %d\n\n", *p, *(p + 1), *p / *(p + 1));

	return 0;
}