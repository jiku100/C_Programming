#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur_sum(int n);

int main(void) {
	int n;
	printf("1 ���� n ������ ���� ���ȣ�� �Լ��� ����մϴ�.\n");
	printf("���� ����<n>�� �Է��Ͻÿ� >> ");	scanf("%d", &n);
	printf("sum = %d\n\n", recur_sum(n));
	return 0;
}

int recur_sum(int n) {
	static int i = 1;		// ���� ���� ����
	printf("%d�� ȣ��\n", i++);	// ȣ�� Ƚ�� ��� �� i++
	if (n == 1)
		return 1;
	else
		return n + recur_sum(n - 1);
}