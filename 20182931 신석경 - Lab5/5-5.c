/*
* ���� ������� ����� ������ �ش��ϴ� �Լ��� �����, ǥ���Է����� ����, ������, �Ⱓ(��)�� �Է��ϸ� 
* �Ѿ��� ���� ��µǴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double mypow(double m, int n);	// ���� �Լ�����
double simpleRate(int money, int years, double rate);	// �ܸ� ���
double compoundRate(int money, int years, double rate);	// ���� ���


int main(void) {
	int money;	// ����
	int years;		// ���
	double rate;		// ����

	while (1) {
		printf("���ڸ� ����� ���� �� �׸��� �Է��ϼ���.\n");
		printf("1. ���� -> "); scanf("%d", &money);
		printf("2. �� -> "); scanf("%d", &years);
		printf("3. ����<%%> -> "); scanf("%lf", &rate);

		printf("�ܸ� ��� �Ѿ��� %.2lf �Դϴ�.\n", simpleRate(money, years, rate));
		printf("���� ��� �Ѿ��� %.2lf �Դϴ�.\n\n", compoundRate(money, years, rate));
	}
}

double mypow(double m, int n) {
	double temp = 1;
	for (int i = 0; i < n; i++) {	// m�� n����
		temp *= m;
	}
	return temp;
}

double simpleRate(int money, int years, double rate) {	// �ܸ� �� ���
	return money * (1 + (rate/100.) * years);
}
double compoundRate(int money, int years, double rate) {	// ���� �� ���
	return money * mypow((1 + (rate / 100.)), years);
}
