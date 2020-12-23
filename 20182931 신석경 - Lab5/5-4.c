/*
* �Ǽ� r�� �Է� �޾� �� ���� ���������� �ϴ� ���� ������ �ѷ��� ���̸� ���ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PI 3.14

float area(float radius);	// ���� ����
float circumference(float radius);	// ���� �ѷ�

int main(void) {
	float radius;	// ������ ���� ����
	int n;	// scanf ���� ���� ����
	while (1) {
		printf("���� �������� �Է��ϸ� ���� ������ �ѷ��� ���̸� ���մϴ�.\n");
		printf("���� �������� �Է� �Ͻÿ� : ");
		n = scanf("%f", &radius);
		if (n == 1 && radius > 0) {
			printf(" >> ���� ������ %.3f, ���� �ѷ��� %.3f\n\n", area(radius), circumference(radius));
		}
		else {
			while (getchar() != '\n');		// �Է� ���� ����
			printf("���� �������� ����� �Է� �Ͻÿ� : ");
			n = scanf("%f", &radius);
			if (n == 1 && radius > 0) {
				printf(" >> ���� ������ %.3f, ���� �ѷ��� %.3f\n\n", area(radius), circumference(radius));
			}
			else {
				printf("�Է��� �߸��߽��ϴ�.\n\n");
				while (getchar() != '\n');		// �Է� ���� ����
			}
		}
	}
}

float area(float radius) {
	return PI * radius * radius;
}

float circumference(float radius) {
	return 2 * PI * radius;
}