/*
* ǥ���Է����� �Է� ���� ���ڿ��� ���̸� ���ϴ� �Լ� mystrlen()�� �����Ͽ� 
* ���̺귯�� strlen()�� ����� ���ϴ� ���α׷�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int mystrlen(const char* str);	// ���ڿ� ���̸� ���ϴ� �Լ�

int main(void) {
	printf("Enter any string >> ");
	char str[64];	// �Է� ����
	gets(str, 64);
	printf("strlen<> : %d\n", strlen(str));
	printf("mystrlen<> : %d\n", mystrlen(str));
	return 0;
}

int mystrlen(char* str) {
	int n;
	for (n = 0; str[n]; n++);	// str[n]�� '\n' Ȥ�� NULL�� ���� �� ����	n���� ������Ŵ
	return n;
}