#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
* �� �Ǽ��� �Է� �޾� �簢��, �ﰢ�� ������ ��ü �� 12, �Ҽ� ���� 3�ڸ� ����, ���� ���ķ�
* ����ϴ� ���α׷�
*/

int main(void) {
	printf("�� �Ǽ��� �Է� �޾� �簢��, �ﰢ�� ���� ���\n\n");

	float width, height; // ���� ���� ���̸� ������ ���� ����
	printf("���θ� �Է��ϼ���: ");
	scanf("%f", &width);
	printf("���θ� �Է��ϼ���: ");
	scanf("%f", &height);

	printf("\n�簢���� ����: %12.3f\n", width * height);	// ��ü �� 12, �Ҽ� ���� 3�ڸ� ���� ���ķ� �簢�� ���� ���
	printf("�ﰢ���� ����: %-12.3f\n", 0.5 * width * height);		// ��ü �� 12, �Ҽ� ���� 3�ڸ� ���� ���ķ� �ﰢ�� ���� ���
	return 0;
}