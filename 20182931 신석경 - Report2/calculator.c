/*******************************************************
* ���ϸ�: calculator.c
* ���α׷� ����: ���ӵ� ����Ŀ��� �� ������ �� �� �������� ����ϴ� ���α׷�
*	��ū�и�: getToken �Լ� ����
*
*	�Է� : �����
*
*   ���: (+, -, *, %, /) ���� ���� �հ�
*
* ��¥: 2020�� 10�� 1��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int getToken(char* str, int* plus, int* minus, int* times, int* division, int* percentage);	// ��ū �и� �Լ�


int main(void) {
	printf("����(+,-,*,/,%)�� ������ ī��Ʈ�ϴ� ���α׷��Դϴ�.\n");

	int plus = 0, minus = 0, times = 0, division = 0, percentage = 0;
	char str[64];

	while (1) {
		printf("������� �Է��Ͻÿ� : ");
		if (fgets(str, 64, stdin) == NULL) {
			return 0;
		}

		if (getToken(str, &plus, &minus, &times, &division, &percentage) != 0) {	// ��ū �и� ����� �������̸�
			printf(" ?? ����� ����\n"); //while (getchar() != '\n');	// ���� ��� �� ���� ����
			continue;
		}
		else {		// �� ������ ������ 0 �̻��̸� ���
			if (plus > 0)
				printf(" + ���� �հ� : %d\n", plus);
			if (minus > 0)
				printf(" - ���� �հ� : %d\n", minus);
			if (times > 0)
 				printf(" * ���� �հ� : %d\n", times);
			if (division > 0)
				printf(" / ���� �հ� : %d\n", division);
			if (percentage > 0)
				printf(" %% ���� �հ� : %d\n", percentage);
			printf("\n");

		}
	}

	return 0;
}

int getToken(char* str, int* plus, int* minus, int* times, int* division, int* percentage) {

	int plus_temp = 0, minus_temp = 0, times_temp = 0, division_temp = 0, percentage_temp = 0;
	int i = 0;
	while (str[i] != '\n' && str[i] != NULL) {
		if (str[i] >= '0' && str[i] <= '9');	// 0 ~ 9 ���� ���ڸ� pass 
		else if (str[i] == ' ' || str[i] == '/t');	// ����, �ǹ����̸� pass
		else if (str[i] == '+')	// + �̸� plus_temp �� 1 ����
			plus_temp += 1;
		else if (str[i] == '-')	// - �̸� minus_temp �� 1 ����
			minus_temp += 1;
		else if (str[i] == '*')	// * �̸� times_temp �� 1 ����
			times_temp += 1;
		else if (str[i] == '/') // / �̸� division_temp �� 1 ����
			division_temp += 1;
		else if (str[i] == '%') // % �̸� percentage_temp �� 1����
			percentage_temp += 1;
		else
			return -1;	// �ƹ��͵� �ƴϸ� -1 ��ȯ

		i++;  // �������̸� ���� ���� �˻�
	}
	*plus += plus_temp;		// �������� ������� ���, plus �� ����
	*minus += minus_temp;	// �������� ������� ���, minus �� ����
	*times += times_temp;	// �������� ������� ���, times �� ����
	*division += division_temp;	// �������� ������� ���, division �� ����
	*percentage += percentage_temp;	// �������� ������� ���, percentage �� ����

	return 0;	// ���� ������ ��� 0 ��ȯ
}