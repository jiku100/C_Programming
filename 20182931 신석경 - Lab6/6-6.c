/*
* ǥ�� �Է����� ���� ���� n�� ���Ͽ� 1���� n������ ���� ���ϴ� �Լ��� ����Լ��� �ۼ��ϰ�, 
* ���� ��µǴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur_sum(int n);


int main(void) {
	printf("1���� �Է� n ������ ���� ���ȣ�� �Լ��� �����Ͽ� ����մϴ�.\n");

	int n;
	printf("���� ���� n �� �Է��Ͻÿ� >> ");	scanf("%d", &n);
	printf("sum = %d\n", recur_sum(n));	// �Լ� ��� ���
	return 0;
}

int recur_sum(int n) {	// ��� �Լ� 
	if (n == 1)
		return 1;
	else
		return n + recur_sum(n - 1);
}