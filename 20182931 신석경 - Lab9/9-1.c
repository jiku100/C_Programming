#include <stdio.h>

extern int number;		// 9-1_sub.c�� ���ǵ� number -> 1
static double data = 4;	// 9-1.c������ ��� ������ data ���� ���� ����

void function(void);
int main(void) {
	register int count = 5;	// main �Լ������� ��� ������ count �������� ���� ����

	printf("number: %d\n", number);	// 9-1_sub.c�� ����� number ���
	subOne();	// �ܺ� ���� �Լ�
	subTwo();	// �ܺ� ���� �Լ�
	printf("data: %lf\n", data);		// �� ���Ͽ����� ���ǵ� data ���
	printf("count: %d\n", count);	// main scope�� ����� count ���
	function();	// �� file���� ���ǵ� �Լ�
	
	return 0;
}

void function(void) {
	static int amount = 6;	// function scope������ ��� ������ amount ���� ���� ���� 
	printf("amount: %d\n", amount);
}