/*******************************************************
* ���ϸ�: complexnum.c
* ���α׷� ����: ���Ҽ��� ���ϱ�, ����, ���ϱ� �� ������ ���ϴ� ���α׷�
*	���Ҽ� ���ϱ�: complex_sum() ����
*	���Ҽ� ����: complex_sub() ����
*	���Ҽ� ���ϱ�: complex_mul() ����
*	���Ҽ� ����: complex_abs() ����
*	���Ҽ� ���: complex_print() ����
*
*	�Է� 1: ���Ҽ��� ��Ÿ���� �� ���� �Ǽ� �Է�
*	�Է� 2: ���Ҽ��� ��Ÿ���� �� ���� �Ǽ� �Է�
* 
*	���: ���ϱ�, ����, ���ϱ�, ������ ��� ���
*
* ��¥: 2020�� 11�� 04��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct mycomplex {	// ���Ҽ� ����ü
	float real;		// �Ǽ� �κ�
	float imagine;	// ��� �κ�
};
typedef struct mycomplex mycomplex;

void complex_sum(mycomplex c1, mycomplex c2, mycomplex* dst);	// ���Ҽ� ���ϱ�
void complex_sub(mycomplex c1, mycomplex c2, mycomplex* dst);	// ���Ҽ� ����
void complex_mul(mycomplex c1, mycomplex c2, mycomplex* dst);	// ���Ҽ� ���ϱ�
float complex_abs(mycomplex c);	// ���Ҽ� ����
void complex_print(mycomplex c);	// ���Ҽ� ���

int main(void) {
	mycomplex c1, c2, result;	// ���Ҽ� ����ü 3�� ����
	printf("���Ҽ� ������ �����մϴ�.\n");
	printf("ù ��° ���Ҽ��� �� ���� �Ǽ��� �Է��Ͻÿ�. >> ");
	scanf("%f %f", &c1.real, &c1.imagine);	// c1 ���Ҽ� �Է�
	printf("�� ��° ���Ҽ��� �� ���� �Ǽ��� �Է��Ͻÿ�. >> ");
	scanf("%f %f", &c2.real, &c2.imagine);	// c2 ���Ҽ� �Է�

	printf("\n����\n");
	complex_sum(c1, c2, &result);	// ���� ��� 
	complex_print(c1); printf(" + "); complex_print(c2); printf(" = "); complex_print(result); printf("\n");	// ���

	printf("\n����\n");
	complex_sub(c1, c2, &result);	// ���� ��� 
	complex_print(c1); printf(" - "); complex_print(c2); printf(" = "); complex_print(result); printf("\n");	// ���
	
	printf("\n����\n");
	complex_mul(c1, c2, &result);	// ���� ��� 
	complex_print(c1); printf(" * "); complex_print(c2); printf(" = "); complex_print(result); printf("\n");	// ���
	
	printf("\n����\n"); 
	printf("|"); complex_print(c1); printf("|"); printf(" = ");  printf("%.3f\n", complex_abs(c1));	// ���
	printf("|"); complex_print(c2); printf("|"); printf(" = ");  printf("%.3f\n", complex_abs(c2));	// ���
	return 0;
}


void complex_sum(mycomplex c1, mycomplex c2, mycomplex* dst) {	// ���Ҽ� ���ϱ�
	(*dst).real = c1.real + c2.real;	// �Ǽ��׳��� ���Ͽ� ����� ����
	(*dst).imagine = c1.imagine + c2.imagine;	// ����׳��� ����
}

void complex_sub(mycomplex c1, mycomplex c2, mycomplex* dst) {	// ���Ҽ� ����
	(*dst).real = c1.real - c2.real;	// �Ǽ��׳��� �� ����� ����
	(*dst).imagine = c1.imagine - c2.imagine;	// ����׳��� ��
}

void complex_mul(mycomplex c1, mycomplex c2, mycomplex* dst) {	// ���Ҽ� ���ϱ�
	(*dst).real = (c1.real*c2.real) - (c1.imagine * c2.imagine); // �Ǽ��׳��� ���� ���� ����׳��� ���� ���� ��
	(*dst).imagine = (c1.real*c2.imagine) + (c1.imagine*c2.real);	// �Ǽ��� * ����� ���� ����
}

float complex_abs(mycomplex c) {	// ���Ҽ� ����
	return sqrt(c.real * c.real + c.imagine * c.imagine);	// ���� ���
}

void complex_print(mycomplex c) {	// ���Ҽ� ���
	printf("< %.2f ", c.real);
	if (c.imagine < 0) {
		printf("- %.2fi >", fabs(c.imagine));	
		// c.imagine�� �����̸� - ����(���) �� �����
		// �̴� �ܼ��� ���� ���ϰ� ����ϱ� ����, ��� ��� ����.
	}
	else {
		printf("+ %.2fi >", c.imagine);
	}
}