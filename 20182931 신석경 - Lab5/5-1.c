/*
* ������ �Ǽ��� ����, m �� n�� �Է� �޾� ������ ���� mypow() �Լ��� �ۼ��Ͽ�
* mn�� ����� ����ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double mypow(double m, int n);	// ���� �Լ�����

int main(void) {
	printf("�Ǽ� m�� n�� �����մϴ�.\n\n");

	double m;
	int n;	// ���� ���� 

	printf("�Ǽ��� ������ ���ʷ� �Է��Ͻÿ�. >> ");
	scanf("%lf %d", &m, &n);
	printf("pow<%.2f, %d> ȣ�� : %.2f�� %d ������ %.2f\n", m, n, m, n, pow(m, n));
	printf("mypow<%.2f, %d> ȣ�� : %.2f�� %d ������ %.2f\n", m, n, m, n, mypow(m, n));

	return 0;
}

double mypow(double m, int n) {
	double temp = 1;
	for (int i = 0; i < n; i++) {	// m�� n����
		temp *= m;
	}
	return temp;
}