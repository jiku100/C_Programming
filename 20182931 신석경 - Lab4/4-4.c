/*
* �迭�� ����Ͽ� �迭�� ���հ� ����� ���Ͽ� ����ϴ� ���α׷��� 
*/

#include <stdio.h>

int main(void) {
	printf("�迭�� ����Ͽ� �迭�� ���հ� ����� ���Ͽ� ���\n\n");

	float a[] = { 98.56, 78.62, 78.69, 89.32, 95.29 };

	float sum = 0, mean = 0;	// ���հ� ��� �ʱ�ȭ
	printf("�迭�� ���� :  ");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%.2f ", a[i]);		// a���� ���
		sum += a[i];	// ���տ� ���Ұ� �߰�
	}

	mean = sum / (sizeof(a) / sizeof(a[0]));	// ������ ���� ������ ���� ��� ���ϱ�
	printf("\n�迭�� �� = %.2f", sum);
	printf("\n��� = %.2f\n\n", mean);
	
	return 0;
}