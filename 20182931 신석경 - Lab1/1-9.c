#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* �� ������ �Է� �޾� ���� ������ ����� �Ǽ��� ����ϴ� ���α׷�
*/

int main(void) {
	printf("�� ������ �Է� �޾� �հ� ����� ���\n\n");

	int input_1, input_2; // �� ������ �Է� ���� ���� ����
	printf("ù ��° ������ �Է��ϼ���.: ");
	scanf("%d", &input_1);
	printf("�� ��° ������ �Է��ϼ���.: ");
	scanf("%d", &input_2);

	printf("�� ������ ��: %d\n", input_1 + input_2);	// �� ������ ���� ������ ���
	printf("�� ������ ���: %f\n", (input_1 + input_2) / 2.); // �� ������ ����� �Ǽ��� ���
	return 0;
}