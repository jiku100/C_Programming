#include <stdio.h>
#define ConvertToSquareMeter(x) ((x)*3.305785) // �� ������ �������� ������ �ٲٱ� ���� ��ũ��

/*
* �Էµ� �� ������ ���� �������� ������ ��ȯ�Ͽ� ����ϴ� ���α׷�
*/
int main(void) {
	int area[5] = { 18, 25, 32, 44, 52 };	// ������ �� ������ �迭�� ����

	printf("������ �� ���� �������� ����\n\n");

	for (int i = 0; i < sizeof(area) / sizeof(int); i++) {	// �� ���� �迭�� ũ�⸸ŭ �迭 �ݺ�
		printf("%d���� ��������: %f (m^2)\n", area[i], ConvertToSquareMeter(area[i]));	// ������ �� ���� �������� ���� ���
	}
	return 0;
}