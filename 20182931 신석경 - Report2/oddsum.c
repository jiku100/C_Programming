/*******************************************************
* ���ϸ�: password.c
* ���α׷� ����: ��ȣ�� �Է¹ް�, ��ȣ�� �������� �˻��ϴ� ���α׷�
*	Ȧ���� �� : recur_sum �Լ� ����
*	�ùٸ� �Է� �˻�: isInteger �Լ� ����
* 
*	�Է� : �˻��� ����
*
*   ��� : Ȧ�� ��
*
* ��¥: 2020�� 10�� 4��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur_sum(int n);	// Ȧ���� ���ϴ� �Լ� ����
int isInteger(int check, int* n);	// �Էµ� ������ �ùٸ� �������� �Ǵ��ϰ� �ƴϸ� ���Է� �޴� �Լ�

int main(void) {
	int n;	// �Է� ���� ����
	int check;	// �ùٸ� �Է� �Ǵ� ����
	int odd_sum;	// Ȧ�� ���� �� ����
	while (1) {
		printf("1���� n���� Ȧ���� ���� ���ϴ� ���ȣ�� ���α׷��Դϴ�.\n");
		printf("���� n�� �Է��Ͻÿ� >> ");
		check = scanf("%d", &n);
		if (isInteger(check, &n) == 0) {
			odd_sum = recur_sum(n);		// Ȧ�� �� ���
			printf("1���� %d���� Ȧ�� ��: %d\n\n", n, odd_sum);
		}
	}
}


int recur_sum(int n) {
	if (n == 1)		// n�� 1�̸� 1��ȯ
		return 1;
	else if (n % 2 == 0)	// n�� ¦�� �̸�
		return recur_sum(n - 1);	// Ȧ���� �ٲ� �Լ� ����
	else
		return n + recur_sum(n - 2); // n�� Ȧ���̸� 2�� ���鼭 Ȧ���� �Լ� ����
}

int isInteger(int check, int* n) {
	do
	{
		if (check != 1)		// �Է��� ������ �ƴϸ�
			printf(" ?? ������ �ƴմϴ�. �ٽ� �Է��Ͻÿ� >> ");
		else if (*n < 0)	// �Է��� 0���� ������
			printf(" ?? 0 ���� ū ������ �Է��Ͻÿ� >> ");
		else	// �Է��� ������ 0 ���� ũ��
			break;
		while (getchar() != '\n');	// ���� ����
		check = scanf("%d", n);	// �ٽ� �Է� �ޱ�
	} while (1);
	return 0;
}