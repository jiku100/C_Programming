/*
* 1 ~ 100 ������ ������ �Ҽ��� ã�� ���α׷�
*/

#include <stdio.h>

int main(void) {
	printf("1���� 100������ �Ҽ� ���\n\n");

	// �����佺�׳׽��� ü �˰��� ���

	int arr[101];	// 0���� ������ 101���� ���� �迭 ����
	for (int i = 0; i < 101; i++)
		arr[i] = i;	// �迭�� 0 ~ 100���� �ʱ�ȭ

	for (int i = 0; i < 101; i++) {	// �����佺�׳׽��� ü ����
		if (arr[i] == 1) {
			arr[i] = 0;	// 0�� 1�� ��� ����
			continue;
		}
		else if (arr[i] == 0)	// �̹� ���ܵ� ���
			continue;
		else {	// ���ܵ��� ���� ���
			printf("%d ", arr[i]);
			for (int j = 2 * i; j < 101; j = j + i) {	// arr[i]�� ����� �� 0���� �ٲ�
				arr[j] = 0;
			}
		}
	}
	printf("\n");
	return 0;
}