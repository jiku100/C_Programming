/*
* ������ ���� 3 x 2�� 2 x 3�� �� ��� a, b���� ����� �� c�� ���ϴ� ���α׷�
*/

#include <stdio.h>

int main(void) {
	printf("�� ��� a, b���� ����� �� c ���\n\n");

	int a[][2] = { {3, 5},
					{4, 2},
					{5, 7} };	// a ��� �ʱ�ȭ

	int b[][3] = { {3,8,2}, {2,4,6} };	// b��� �ʱ�ȭ

	printf("��� a\n");		// a ���� ���
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("   %d   %d\n", a[i][0], a[i][1]);
	}

	printf("\n��� b\n");	// b ���� ���
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
		printf("   %d   %d   %d\n", b[i][0], b[i][1], b[i][2]);
	}

	printf("\n��� c = a x b\n");	// a x b ��� �� ���
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// ������ a�� row�� ���� b�� column�� ���� ��
			printf("   %d", a[i][0] * b[0][j] + a[i][1] * b[1][j]);	
			// a�� i ��° row �� b�� i ��° column ��
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}