/*******************************************************
* ���ϸ�: varprint.c
* ���α׷� ����: ����, ����, ���� �迭, ���ڿ��� ����� �� �ִ� �Լ� ����
*	�ڷ� ���: printItems() ����
*	�� Ÿ�� Ȯ��: DTPYE ������ ����
* 
*	���: �� ��Ȳ�� �´� �� ���
*
* ��¥: 2020�� 11�� 24��
* ����: 1.0
* �ۼ���: 20182931 �ż���
*
*******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

enum DTYPE { INT, CHAR, INTARY, CHARSTR };
void printItems(void* p, int size, int datatype); // p�� �Ѿ�� �ڷḦ ����ϴ� �Լ�


int main(void) {
	int ary[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char* str = "abcdef";

	printItems((void*)ary, 0, INT); // INT�� ���� size ���� �������
	printItems((void*)str, 0, CHAR);// CHAR�� ���� size ���� �������
	printItems((void*)ary, sizeof(ary)/sizeof(int), INTARY);	// INTARY�� �Ѿ ���� size�� �Ѱ������
	printItems((void*)str, strlen(str), CHARSTR);	// CHARARY�� �Ѿ ���� ���̸� ���ؾ���.
	return 0;
}

void printItems(void* p, int size, int datatype) { // p�� �Ѿ�� �ڷḦ ����ϴ� �Լ�
	int* ary = NULL;	// int* �ʱ�ȭ
	char* str = NULL;	// char* �ʱ�ȭ
	switch (datatype)
	{
	case INT:	// datatype�� INT���
		ary = (int*)p;	// void*�� int*�� �ٲ㼭
		printf("ary[0] = %d\n", *ary);	// ù ���Ҹ� ���
		break;
	case CHAR:	// datatype�� CHAR���
		str = (char*)p;	// void*�� char*�� �ٲ㼭
		printf("*str = %c\n", *str);	// ù ���Ҹ� ���
		break;
	case INTARY:	// datatype�� INTARY���
		ary = (int*)p;	// void*�� int*�� �޾Ƽ�
		printf("ary = ");
		for (int i = 0; i < size; i++) {	// size ������ŭ ���
			if (i < size - 1)
				printf("%d, ", ary[i]);
			else
				printf("%d\n", ary[i]);
		}
		break;
	case CHARSTR:	// datatype�� CHARARY���
		str = (char*)p;	// void*�� char*�� �޾Ƽ�
		printf("str = ");
		for (int i = 0; i < size; i++) {	// size ������ŭ ���
			if (i < size - 1)
				printf("%c, ", str[i]);
			else
				printf("%c\n", str[i]);
		}
	default:
		break;
	}
}